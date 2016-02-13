:: TODO: build everything

:: don't break any global variables
SETLOCAL

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

SET visualstudio="C:\Program Files (x86)\Microsoft Visual Studio 9.0\"

:: compile the code
%visualstudio%\Common7\IDE\devenv.exe cl_dll\cl_dll-2008.sln /Build %codeconfiguration%
%visualstudio%\Common7\IDE\devenv.exe dlls\hl-2008.sln /Build %codeconfiguration%

:: compile maps
cd mapsrc
compile.bat
cd ..

:: compile wads
cd wadsrc
compile.bat
cd ..