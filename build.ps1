# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# build all the code and assets

. ./settings.ps1

if ($args.Count -ge 1)
{
	$code_configuration = $args[0]
}
else
{
	$code_configuration = 'Debug'
}

& "MSBuild.exe" /t:Build /p:Configuration=${code_configuration} "cl_dll\cl_dll.sln"
& "MSBuild.exe" /t:Build /p:Configuration=${code_configuration} "dlls\hl.sln"

Copy-Item "cl_dll\${code_configuration}\client.dll" -Destination "${moddir}\cl_dlls\"

if ($code_configuration -eq "Release")
{
	Copy-Item "dlls\Release\hl.dll" -Destination "${moddir}\dlls\"
}
else
{
	Copy-Item "dlls\debughl\hl.dll" -Destination "${moddir}\dlls\"
}

# compile maps
cd mapsrc
cmd /c "compile.bat Release"
cd ..

# compile models
cd modelsrc
cmd /c "compile.bat Release"
cd ..

# compile sprites
cd spritesrc
cmd /c "compile.bat Release"
cd ..

# compile wads
cd wadsrc
cmd /c "compile.bat Release"
cd ..

Pop-Location
