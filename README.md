Basis
=====

Something like Spirit of Half-Life. The intent is to add more features to the Half-Life SDK and better documenting the engine's features while maintaining the same style.


How to fork this without using GitHub's forking
-----------------------------------------------

```
# clone the repo
git clone --mirror https://github.com/tschumann/basis
cd basis
# push the checkout of Basis into a repo that you have created
git push --mirror https://github.com/you/basis-mirror

# clone your repo
git clone https://github.com/you/repo
# create a new remote that points to Basis
git remote add basis https://github.com/tschumann/basis
# pull and merge the latest changes from Basis
git pull basis master
```


Getting started
---------------

Clone and get the submodules.
```
git clone https://github.com/tschumann/basis
git submodule init
git submodule update
```

Change the values in `settings.bat`/`settings.ps1`/`settings.sh` as required.

Build all the required projects.

Powershell:
```
./init.ps1
```

Linux bash:
```
sudo apt-get install gcc-multilib g++-multilib mesa-common-dev libgl-dev
./init.sh
```


Compiling
---------

Build the code and assets.

Powershell:
```
./build.ps1
```

Linux bash:
```
cd linux
make
```


Cleaning
--------

PowerShell:
```
./clean.ps1
```

Linux bash:
```
./clean.sh
```


Tests
-----

Developer PowerShell for VS:
```
./test.ps1
```


Updating Steamworks SDK
-----------------------

The current required version of the Steamworks SDK is 1.53a

The version of the Steamworks SDK to build with needs to match `steamapps/common/Half-Life/steam_api.dll`: go to https://partner.steamgames.com/downloads/list and find the version whose `sdk\redistributable_bin\steam_api.dll` has the same version as `steamapps/common/Half-Life/steam_api.dll`

Copy `sdk/redistributable_bin/steam_api.lib` to `lib/public/`, copy `sdk/redistributable_bin/linux32/libsteam_api.so` to `linux/` and copy `sdk/public/steam/*.h` to `public/steam/`



Pulling in upstream changes
---------------------------

Pull in the latest changes from https://github.com/ValveSoftware/halflife

```
# make sure the remote is correct
git remote rm valve
git remote add valve https://github.com/ValveSoftware/halflife
# pull in the latest upstream changes
git pull valve master
```
