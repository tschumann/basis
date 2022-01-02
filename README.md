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


Compiling on Windows
--------------------

Build all required projects.

Windows Command Prompt:
```
init.bat
```

Windows Git Bash:
```
MSYS_NO_PATHCONV=1 cmd /c init.bat
```

Build the code and assets.

Windows Command Prompt:
```
build.bat
```

Windows Git Bash:
```
MSYS_NO_PATHCONV=1 cmd /c build.bat
```

Cleaning the project:

Windows Command Prompt:
```
clean.bat
```

Windows Git Bash:
```
powershell ./clean.ps1
```
```
MSYS_NO_PATHCONV=1 cmd /c clean.bat
```


Compiling on Linux
------------------

```
sudo apt-get install gcc-multilib g++-multilib mesa-common-dev
cd linux
make
```

Pulling in upstream changes
---------------------------

Pull in the latest changes from https://github.com/ValveSoftware/halflife

Windows Command Prompt:
```
update.bat
```

Windows Git Bash:
```
powershell ./update.ps1
```
```
MSYS_NO_PATHCONV=1 cmd /c update.bat
```