
call settings.bat

if "%1" == "" (
	echo "No file specified."
) else (
	call %visualstudio%\VC\vcvarsall.bat x86
	%visualstudio%\VC\bin\dumpbin.exe /EXPORTS %1
)
