
:: check that a mod directory has been passed in
if "%~1"=="" (
	echo No mod directory specified!
	exit /B
)

:: %%d is a variable - why isn't %%dir valid?
for /D %%d in (*) do (
	echo Compiling %%~nd
	
	..\utils\makels\Release\makels.exe %%~nd %%~nd %%~nd.ls
	..\utils\qlumpy\Release\qlumpy %%~nd.ls

	copy %%~nd.wad ..\%1
)
