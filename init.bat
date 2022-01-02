:: initialise the repo by building all necessary projects

call settings.bat

:: need to create these, otherwise the compile scripts don't copy correctly
mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\
mkdir %moddir%\maps\
mkdir %moddir%\models\
mkdir %moddir%\sprites\

:: compile the utilities - build as release as they shouldn't need to be debugged
%visualstudio%\%vsbindir%\devenv.exe  utils\qcsg\qcsg-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\qbsp2\qbsp2-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\qrad\qrad-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\vis2x\vis-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\makels\makels-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\qlumpy\qlumpy-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\sprgren\sprgen-2019.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe  utils\studiomdl\studiomdl-2019.sln /Build Release

:: make sure qrad has a lights file
mkdir utils\qrad\Release
copy mapsrc\lights.rad utils\qrad\Release
