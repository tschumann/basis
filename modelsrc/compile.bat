
call ..\settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile studiomdl
%visualstudio%\Common7\IDE\devenv.exe ..\utils\studiomdl\studiomdl-2017.sln /Build %codeconfiguration%

:: %%f is a variable - why isn't %%qc valid?
for %%f in (*.qc) do (
	echo Compiling %%~nf
	..\utils\studiomdl\%codeconfiguration%\studiomdl.exe %%~nf.qc
	sleep 1

	xcopy %%~nf.mdl ..\%moddir%\models\
)

:: clean up the generated files
del *.mdl
