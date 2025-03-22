
call ..\settings.bat

if "%1" == "Release" (
	SET codeconfiguration=Release
) else (
	SET codeconfiguration=Debug
)

:: %%f is a variable - why isn't %%map valid?
for %%f in (*.map) do (
	echo Compiling %%~nf
	..\utils\qcsg\%codeconfiguration%\qcsg.exe %%~nf.map
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL
	..\utils\qbsp2\%codeconfiguration%\qbsp2.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL
	..\utils\visx2\%codeconfiguration%\vis.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL
	..\utils\qrad\%codeconfiguration%\qrad.exe %%~nf.bsp
	:: hack - sleep so it can finish writing the file before starting the next process
	timeout /t 1 /nobreak > NUL

	xcopy /y %%~nf.bsp ..\%moddir%\maps
)

:: clean up the generated files
del *.bsp
del *.lin
del *.p*
