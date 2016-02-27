:: TODO: compile necessary tools etc

call settings.bat

mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\

mkdir utils\qrad\Release
copy mapsrc\lights.rad utils\qrad\Release

pause
