
call settings.bat

:: tidy up the mod directory
del %moddir%\voice_ban.dt

:: code-related stuff
rmdir /s /q cl_dll\Debug\
rmdir /s /q cl_dll\Release\
rmdir /s /q dlls\Debug\
rmdir /s /q dlls\debughl\
rmdir /s /q dlls\Releasehl\

rmdir /s /q utils\makels\Debug
rmdir /s /q utils\makels\Release
rmdir /s /q utils\qbsp2\Debug
rmdir /s /q utils\qbsp2\Release
rmdir /s /q utils\qcsg\Debug
rmdir /s /q utils\qcsg\Release
rmdir /s /q utils\qlumpy\Debug
rmdir /s /q utils\qlumpy\Release
rmdir /s /q utils\qrad\Debug
rmdir /s /q utils\qrad\Release
rmdir /s /q utils\sprgen\Debug
rmdir /s /q utils\sprgen\Release
rmdir /s /q utils\visx2\Debug
rmdir /s /q utils\visx2\Release

:: map-related stuff
del mapsrc\*.bsp
del mapsrc\*.rmx
del mapsrc\*.max

:: sprite-related stuff
del spritesrc\*.spr

:: wad-related stuff
del wadsrc\*.wad
del wadsrc\dev.ls
del wadsrc\tools.ls

:: filesystem testing stuff
rmdir /s /q mod\
