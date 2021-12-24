Basis
=====

Something like Spirit of Half-Life. The intent is to add more features to the Half-Life SDK and better documenting the engine's features while maintaining the same style.


How to fork this without using GitHub's forking
-----------------------------------------------

$ # clone the repo

$ git clone --mirror https://github.com/tschumann/basis

$ cd basis

$ # push the checkout of Basis into a repo that you have created

$ git push --mirror https://github.com/you/basis-mirror


$ # clone your repo

$ git clone https://github.com/you/repo

$ # note that similar steps are in update.bat too

$ # create a new remote that points to Basis

$ git remote add basis https://github.com/you/basis-mirror

$ # pull and merge the latest changes from Basis

$ git pull basis master


Compiling on Windows
--------------------

If you're using Command Prompt:
```
build.bat
```

If you're using Git Bash
```
MSYS_NO_PATHCONV=1 cmd /c build.bat
```


Compiling on Linux
------------------

```
sudo apt-get install gcc-multilib g++-multilib mesa-common-dev
cd linux
make
```

Setting up local development
----------------------------

$ # clone the repo

$ git clone https://github.com/tschumann/basis

$ # create a new remote to link back to Valve's halflife repo

$ git remote add valve https://github.com/ValveSoftware/halflife

$ # pull the latest changes from Valve's halflife repo

$ git pull valve master
