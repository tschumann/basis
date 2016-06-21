
call ..\settings.bat

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\studiomdl\Release\studiomdl.exe %%~nf.qc
	sleep 1

	copy %%~nf.mdl ..\%moddir%\models
)

:: clean up the generated files
del *.mdl
