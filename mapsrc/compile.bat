
call ..\settings.bat

:: %%f is a variable - why isn't %%map valid?
for %%f in (*.map) do (
	echo Compiling %%~nf
	..\utils\qcsg\Release\qcsg.exe %%~nf.map
	..\utils\qbsp2\Release\qbsp2.exe %%~nf.bsp
	..\utils\visx2\Release\vis.exe %%~nf.bsp
	..\utils\qrad\Release\qrad.exe %%~nf.bsp

	copy %%~nf.bsp ..\%moddir%\maps
)

:: clean up the generated files
del *.bsp
del *.lin
del *.p*
