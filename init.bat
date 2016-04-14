:: TODO: compile necessary tools etc

call settings.bat

mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\

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
