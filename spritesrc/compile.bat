
call ..\settings.bat

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\sprgen\Release\sprgen.exe %%~nf.qc
	sleep 1

	copy %%~nf.spr ..\%moddir%\sprites
)

:: clean up the generated files
del *.spr
