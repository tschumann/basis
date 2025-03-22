
call ..\settings.bat

if "%1" == "Release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\studiomdl\%codeconfiguration%\studiomdl.exe %%~nf.qc
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL

	xcopy /y %%~nf.mdl ..\%moddir%\models\
)

:: clean up the generated files
del *.mdl
