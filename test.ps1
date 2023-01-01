# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

New-Item -Path "cl_dll" -Name "run_tests.hxx" -ItemType "file" -Force
# build the solution
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Configuration=Debug "cl_dll\cl_dll-2019.sln"
Remove-Item cl_dll\run_tests.hxx

New-Item -Path "dlls" -Name "run_tests.hxx" -ItemType "file" -Force
# build the solution
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Configuration=Debug "dlls\hl-2019.sln"
Remove-Item dlls\run_tests.hxx

# copy across the .dll files that client.dll depends on
Copy-Item "C:\Program Files (x86)\Steam\steamapps\common\Half-Life\SDL2.dll" -Destination "cl_dll\Debug"
Copy-Item "C:\Program Files (x86)\Steam\steamapps\common\Half-Life\steam_api.dll" -Destination "cl_dll\Debug"
Copy-Item "C:\Program Files (x86)\Steam\steamapps\common\Half-Life\vgui.dll" -Destination "cl_dll\Debug"

# run the tests - add --diag:out.txt to get extra information if required
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" cl_dll\Debug\client.dll --logger:"console;verbosity=Normal"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" dlls\debughl\hl.dll --logger:"console;verbosity=Normal"

Pop-Location