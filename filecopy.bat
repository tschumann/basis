
call settings.bat

if "%1" == "release" (
	copy cl_dll\Release\client.dll %moddir%\cl_dlls\
	copy dlls\Release\hl.dll %moddir%\dlls\
) else (
	copy cl_dll\Debug\client.dll %moddir%\cl_dlls\
	copy dlls\debughl\hl.dll %moddir%\dlls\
)
