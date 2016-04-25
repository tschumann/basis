:: TODO: build everything

call settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile the utilities - build as release as they shouldn't need to be debugged
%visualstudio%\Common7\IDE\devenv.exe  utils\makels\makels-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qlumpy\qlumpy-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\sprgren\sprgen-2008.sln /Build Release

:: compile the code
%visualstudio%\Common7\IDE\devenv.exe cl_dll\cl_dll-2008.sln /Build %codeconfiguration%
%visualstudio%\Common7\IDE\devenv.exe dlls\hl-2008.sln /Build %codeconfiguration%

:: compile maps
cd mapsrc
compile.bat %moddir%
cd ..

:: compile models
cd modelsrc
compile.bat %moddir%
cd ..

:: compile sprites
cd spritesrc
compile.bat %moddir%
cd ..

:: compile wads
cd wadsrc
compile.bat %moddir%
cd ..