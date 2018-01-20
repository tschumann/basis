Basis
=====

Something like Spirit of Half-Life.


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


Compiling on Linux
------------------

$ sudo apt-get install gcc-multilib g++-multilib mesa-common-dev

$ cd linux

$ make

Setting up local development
----------------------------

$ # clone the repo

$ git clone https://github.com/tschumann/basis

$ # create a new remote to link back to Valve's halflife repo

$ git remote add valve https://github.com/ValveSoftware/halflife

$ # pull the latest changes from halflife

$ git pull valve master
