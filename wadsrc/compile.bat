
call ..\settings.bat

:: %%d is a variable - why isn't %%dir valid?
for /D %%d in (*) do (
	echo Compiling %%~nd
	..\utils\makels\Release\makels.exe %%~nd %%~nd %%~nd.ls
	sleep 1
	..\utils\qlumpy\Release\qlumpy %%~nd.ls
	sleep 1

	copy %%~nd.wad ..\%moddir%\
)

:: clean up the generated files
del *.wad
