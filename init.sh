
sh ./settings.sh

mkdir $MODDIR/cl_dlls/
mkdir $MODDIR/dlls/

# create directories for filsystem testing assets
mkdir mod/
mkdir mod/maps/
mkdir mod/models/
mkdir mod/sprites/
mkdir mod/sounds/

# create filesystem testing assets
cp $MODDIR/maps/empty.bsp mod/maps/test.bsp
cp $MODDIR/models/null.mdl mod/models/test.mdl
cp $MODDIR/sprites/null.spr mod/sprites/test.spr
cp $MODDIR/sounds/empty.wav mod/sounds/test.wav

# TODO: check that files with the same names as the filesystem testing assets don't exist in $MODDIR
