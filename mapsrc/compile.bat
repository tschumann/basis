
call ..\settings.bat

if "%1" == "release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: compile qcsg
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qcsg\qcsg-2019.sln /Build %codeconfiguration%
:: compile qbsp2
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qbsp2\qbsp2-2019.sln /Build %codeconfiguration%
:: compile vis
%visualstudio%\Common7\IDE\devenv.exe ..\utils\visx2\vis-2019.sln /Build %codeconfiguration%
:: compile qrad
%visualstudio%\Common7\IDE\devenv.exe ..\utils\qrad\qrad-2019.sln /Build %codeconfiguration%

xcopy /y lights.rad ..\utils\qrad\%codeconfiguration%
xcopy /y valve.rad ..\utils\qrad\%codeconfiguration%

:: %%f is a variable - why isn't %%map valid?
for %%f in (*.map) do (
	echo Compiling %%~nf
	..\utils\qcsg\%codeconfiguration%\qcsg.exe %%~nf.map
	:: hack - sleep so it can finish writing the file before starting the next process
	sleep 1
	..\utils\qbsp2\%codeconfiguration%\qbsp2.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	sleep 1
	..\utils\visx2\%codeconfiguration%\vis.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	sleep 1
	..\utils\qrad\%codeconfiguration%\qrad.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	sleep 1

	xcopy /y %%~nf.bsp ..\%moddir%\maps
)

:: clean up the generated files
del *.bsp
del *.lin
del *.p*
