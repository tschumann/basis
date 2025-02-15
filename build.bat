
call settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile the code
%visualstudio%\%vsbindir%\devenv.exe cl_dll\cl_dll.sln /Build %codeconfiguration%
%visualstudio%\%vsbindir%\devenv.exe dlls\hl.sln /Build %codeconfiguration%

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