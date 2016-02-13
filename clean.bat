
:: code related stuff
rmdir /s /q cl_dll\Debug
rmdir /s /q cl_dll\Release
rmdir /s /q dlls\Debug
rmdir /s /q dlls\debughl
rmdir /s /q dlls\Releasehl

:: map related stuff
del mapsrc\*.bsp
del mapsrc\*.rmx
del mapsrc\*.max

:: wad-related stuff
del wadsrc\*.wad
del wadsrc\dev.ls
del wadsrc\tools.ls