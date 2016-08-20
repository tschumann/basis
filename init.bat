
call settings.bat

mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\
:: need to create these, otherwise the compile scripts don't copy correctly
mkdir %moddir%\maps\
mkdir %moddir%\models\
mkdir %moddir%\sprites\

:: compile the utilities - build as release as they shouldn't need to be debugged
%visualstudio%\Common7\IDE\devenv.exe  utils\qcsg\qcsg-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qbsp2\qbsp2-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qrad\qrad-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\vis2x\vis-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\makels\makels-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qlumpy\qlumpy-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\sprgren\sprgen-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\studiomdl\studiomdl-2008.sln /Build Release

:: make sure qrad has a lights file
mkdir utils\qrad\Release
copy mapsrc\lights.rad utils\qrad\Release

:: create directories for filsystem testing assets
mkdir mod\
mkdir mod\maps\
mkdir mod\models\
mkdir mod\sprites\
mkdir mod\sounds\

:: create filesystem testing assets
copy %moddir%\maps\empty.bsp mod\maps\test.bsp
copy %moddir%\models\null.mdl mod\models\test.mdl
copy %moddir%\sprites\null.spr mod\sprites\test.spr
copy %moddir%\sounds\empty.wav mod\sounds\test.wav

:: TODO: check that files with the same names as the filesystem testing assets don't exist in %moddir%

pause
