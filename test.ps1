# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# build and run the tests

New-Item -Path "cl_dll" -Name "run_tests.hxx" -ItemType "file" -Force
# build the solution
& "MSBuild.exe" /t:Build /p:Configuration=Debug "cl_dll\cl_dll.sln"
Remove-Item cl_dll\run_tests.hxx

New-Item -Path "dlls" -Name "run_tests.hxx" -ItemType "file" -Force
# build the solution
& "MSBuild.exe" /t:Build /p:Configuration=Debug "dlls\hl.sln"
Remove-Item dlls\run_tests.hxx

# adjust the path so that SDL2.dll, steam_api.dll and vgui.dll are visible
$env:Path = "C:\Program Files (x86)\Steam\steamapps\common\Half-Life\;" + $env:Path

# run the tests - add --diag:out.txt to get extra information if required
& "vstest.console.exe" cl_dll\Debug\client.dll --logger:"console;verbosity=Normal"
& "vstest.console.exe" dlls\debughl\hl.dll --logger:"console;verbosity=Normal"

Pop-Location
