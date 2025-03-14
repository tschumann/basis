# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# pull in the latest upstream changes

# make sure the remote is correct
git remote rm valve
git remote add valve https://github.com/ValveSoftware/halflife
# pull in the latest upstream changes
git pull valve master

Pop-Location
