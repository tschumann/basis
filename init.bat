:: initialise the repo by building all necessary projects etc

call settings.bat

:: need to create these, otherwise the compile scripts don't copy correctly
mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\
mkdir %moddir%\maps\
mkdir %moddir%\models\
mkdir %moddir%\sprites\

:: compile the utilities - build as release as they shouldn't need to be debugged
%visualstudio%\%vsbindir%\devenv.exe utils\qcsg\qcsg.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\qbsp2\qbsp2.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\qrad\qrad.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\vis2x\vis.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\makels\makels.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\qlumpy\qlumpy.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\sprgren\sprgen.sln /Build Release
%visualstudio%\%vsbindir%\devenv.exe utils\studiomdl\studiomdl.sln /Build Release

:: make sure qrad has a lights file
mkdir utils\qrad\Release
copy mapsrc\lights.rad utils\qrad\Release
