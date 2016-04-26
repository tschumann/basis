:: TODO: build everything

call settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile the code
%visualstudio%\Common7\IDE\devenv.exe cl_dll\cl_dll-2008.sln /Build %codeconfiguration%
%visualstudio%\Common7\IDE\devenv.exe dlls\hl-2008.sln /Build %codeconfiguration%

:: compile maps
cd mapsrc
compile.bat
cd ..

:: compile models
cd modelsrc
compile.bat
cd ..

:: compile sprites
cd spritesrc
compile.bat
cd ..

:: compile wads
cd wadsrc
compile.bat
cd ..