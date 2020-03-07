:: TODO: build everything

call settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile the code
%visualstudio%\Common7\IDE\devenv.exe cl_dll\cl_dll-2019.sln /Build %codeconfiguration%
%visualstudio%\Common7\IDE\devenv.exe dlls\hl-2019.sln /Build %codeconfiguration%

xcopy /Y cl_dll\%codeconfiguration%\client.dll %moddir%\cl_dlls\
if "%1" == "release" (
	xcopy /Y dlls\%codeconfiguration%\hl.dll %moddir%\dlls\
) else (
	xcopy /Y dlls\debughl\hl.dll %moddir%\dlls\
)

:: compile maps
cd mapsrc
compile.bat %codeconfiguration%
cd ..

:: compile models
cd modelsrc
compile.bat %codeconfiguration%
cd ..

:: compile sprites
cd spritesrc
compile.bat %codeconfiguration%
cd ..

:: compile wads
cd wadsrc
compile.bat %codeconfiguration%
cd ..