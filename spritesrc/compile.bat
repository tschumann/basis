
:: check that a mod directory has been passed in
if "%~1"=="" (
	echo No mod directory specified!
	exit /B
)

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\sprgen\Release\sprgen.exe %%~nf.qc

	copy %%~nf.spr ..\%moddir%\sprites
)

:: clean up the generated files
del *.spr
