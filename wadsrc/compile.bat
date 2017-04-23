
call ..\settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile makels
%visualstudio%\Common7\IDE\devenv.exe ..\utils\makels\makels-2017.sln /Build %codeconfiguration%
:: compile qlumpy
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qlumpy\qlumpy-2017.sln /Build %codeconfiguration%

:: %%d is a variable - why isn't %%dir valid?
for /D %%d in (*) do (
	echo Compiling %%~nd
	..\utils\makels\%codeconfiguration%\makels.exe %%~nd %%~nd %%~nd.ls
	sleep 1
	..\utils\qlumpy\%codeconfiguration%\qlumpy %%~nd.ls
	sleep 1

	xcopy %%~nd.wad ..\%moddir%\
)

:: clean up the generated files
del *.wad
