
call ..\settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile sprgen
%visualstudio%\Common7\IDE\devenv.exe ..\utils\sprgen\sprgen-2019.sln /Build %codeconfiguration%

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\sprgen\%codeconfiguration%\sprgen.exe %%~nf.qc
	sleep 1

	xcopy /y %%~nf.spr ..\%moddir%\sprites\
)

:: clean up the generated files
del *.spr
