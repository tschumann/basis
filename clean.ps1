# clean the project by deleting all generated files

. ./settings.ps1

# tidy up the mod directory
Remove-Item $moddir\voice_ban.dt -ErrorAction Ignore

# code-related stuff
Remove-Item -Recurse cl_dll\Debug\ -ErrorAction Ignore
Remove-Item -Recurse cl_dll\Release\ -ErrorAction Ignore
Remove-Item -Recurse dlls\Debug\ -ErrorAction Ignore
Remove-Item -Recurse dlls\debughl\ -ErrorAction Ignore
Remove-Item -Recurse dlls\Releasehl\ -ErrorAction Ignore

Remove-Item -Recurse utils\makels\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\makels\Release -ErrorAction Ignore
Remove-Item -Recurse utils\qbsp2\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\qbsp2\Release -ErrorAction Ignore
Remove-Item -Recurse utils\qcsg\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\qcsg\Release -ErrorAction Ignore
Remove-Item -Recurse utils\qlumpy\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\qlumpy\Release -ErrorAction Ignore
Remove-Item -Recurse utils\qrad\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\qrad\Release -ErrorAction Ignore
Remove-Item -Recurse utils\sprgen\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\sprgen\Release -ErrorAction Ignore
Remove-Item -Recurse utils\visx2\Debug -ErrorAction Ignore
Remove-Item -Recurse utils\visx2\Release -ErrorAction Ignore

# map-related stuff
Remove-Item mapsrc\*.bsp
Remove-Item mapsrc\*.rmx
Remove-Item mapsrc\*.max

# sprite-related stuff
Remove-Item spritesrc\*.spr

# wad-related stuff
Remove-Item wadsrc\*.wad
Remove-Item wadsrc\dev.ls -ErrorAction Ignore
Remove-Item wadsrc\tools.ls -ErrorAction Ignore

# filesystem testing stuff
Remove-Item -Recurse mod\ -ErrorAction Ignore
