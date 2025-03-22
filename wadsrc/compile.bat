
call ..\settings.bat

if "%1" == "Release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: %%d is a variable - why isn't %%dir valid?
for /D %%d in (*) do (
	echo Compiling %%~nd
	..\utils\makels\%codeconfiguration%\makels.exe %%~nd %%~nd %%~nd.ls
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL
	..\utils\qlumpy\%codeconfiguration%\qlumpy %%~nd.ls
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL

	xcopy /y %%~nd.wad ..\%moddir%\
)

:: clean up the generated files
del *.wad
