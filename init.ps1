# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# initialise the repo by building all necessary projects etc

. ./settings.ps1

New-Item -ItemType Directory -Force -Path $moddir\cl_dll\
New-Item -ItemType Directory -Force -Path $moddir\dlls\
New-Item -ItemType Directory -Force -Path $moddir\maps\
New-Item -ItemType Directory -Force -Path $moddir\models\
New-Item -ItemType Directory -Force -Path $moddir\sprites\

Pop-Location
