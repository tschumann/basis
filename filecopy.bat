
call settings.bat

SET wd=%cd%

:: if this is being called as a custom build step (and as a result is being called from inside cl_dll or dlls)
if not exist %moddir% (
	SET cded
	cd ..
)

:: TODO: check ConfigurationName instead? it's under Macros in Visual Studio when editing a Custom Build Step's Command Line
if "%1" == "release" (
	echo Copying release binaries
	copy /Y cl_dll\Release\client.dll %moddir%\cl_dlls\
	copy /Y dlls\Release\hl.dll %moddir%\dlls\
) else (
	echo Copying debug binaries
	copy /Y cl_dll\Debug\client.dll %moddir%\cl_dlls\
	copy /Y dlls\debughl\hl.dll %moddir%\dlls\
)

:: if the working directory was changed, change it back to what it was
if "%cded%" == "" (
	cd %wd%
)
