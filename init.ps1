# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# initialise the repo by building all necessary projects etc

. ./settings.ps1

# need to create these, otherwise the compile scripts don't copy correctly
New-Item -ItemType Directory -Force -Path ${moddir}\cl_dlls\
New-Item -ItemType Directory -Force -Path ${moddir}\dlls\
New-Item -ItemType Directory -Force -Path ${moddir}\maps\
New-Item -ItemType Directory -Force -Path ${moddir}\models\
New-Item -ItemType Directory -Force -Path ${moddir}\sprites\

# compile the utilities - build as release as they shouldn't need to be debugged
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\qcsg\qcsg.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\qbsp2\qbsp2.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\qrad\qrad.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\visx2\vis.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\makels\makels.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\qlumpy\qlumpy.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\sprgen\sprgen.sln"
& "MSBuild.exe" /t:Build /p:Configuration=Release "utils\studiomdl\studiomdl.sln"

# make sure qrad has a lights file
New-Item -ItemType Directory -Force -Path utils\qrad\Release
Copy-Item mapsrc\lights.rad -Destination utils\qrad\Release

Pop-Location
