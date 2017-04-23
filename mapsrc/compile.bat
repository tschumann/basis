
call ..\settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile qcsg
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qcsg\qcsg-2017.sln /Build %codeconfiguration%
:: compile qbsp2
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qbsp2\qbsp2-2017.sln /Build %codeconfiguration%
:: compile vis
%visualstudio%\Common7\IDE\devenv.exe ..\utils\visx2\vis-2017.sln /Build %codeconfiguration%
:: compile qrad
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qrad\qrad-2017.sln /Build %codeconfiguration%

xcopy lights.rad ..\utils\qrad\%codeconfiguration%
xcopy valve.rad ..\utils\qrad\%codeconfiguration%

:: %%f is a variable - why isn't %%map valid?
for %%f in (*.map) do (
	echo Compiling %%~nf
	..\utils\qcsg\%codeconfiguration%\qcsg.exe %%~nf.map
	sleep 1
	..\utils\qbsp2\%codeconfiguration%\qbsp2.exe %%~nf.bsp
	sleep 1
	..\utils\visx2\%codeconfiguration%\vis.exe %%~nf.bsp
	sleep 1
	..\utils\qrad\%codeconfiguration%\qrad.exe %%~nf.bsp
	sleep 1

	xcopy %%~nf.bsp ..\%moddir%\maps
)

:: clean up the generated files
del *.bsp
del *.lin
del *.p*
