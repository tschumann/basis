
dlls/hl.dll
-----------

Any method of a class that inherits from CBaseEntity and that is passed to SetThink, SetTouch, SetUse or SetBlocked should have the EXPORT macro as part of its definition in order for save-restore to work correctly.

enginefuncs_t
=============
pfnAllocString - can modify the passed in string if there are characters preceeded by a \ (see https://github.com/ValveSoftware/halflife/issues/2388)

pfnPEntityOfEntIndex - will return NULL for the last player

pfnGetModelPtr - studiohdr_t.textureindex will be 0 if textures are stored in an external *T.mdl

pfnPEntityOfEntIndexAllEntities - will not return NULL for the last player


gfx/colormap.lmp
----------------

64 light-adjusted RGB colour values for the 256 colours in palette.lmp

Light-adjusted RGB colours 0 to 31 are brightly lit (with 0 being the brightest), 32 is the original colour and 33 to 63 are darkly lit (with 63 being black).


gfx/palette.lmp
---------------

256 RGB colour values.


maps/
-----

globalname - used to synchronise entities between maps

targetname - used to target entities in a map


overviews/
----------

To generate an overview, make sure the game is running with the `-dev` parameter.

Start the map and type `dev_overview 1` in the console.

Centre the view using movement keys and the mouse wheel.

Once the map is centered copy down the text that is getting printed to the console.

Type `r_drawviewmodel 0` and `hud_draw 0` in the console.

Take a screenshot.


liblist.gam
-----------

Update mod and developer details here.


game.tga
--------

16x16 32-bit .tga (used in Steam's Small Mode and as the game icon when running).


game_big.tga
------------

32x32 32-bit .tga (used in Steam's Large Mode)


*.tga
-----

RLE or uncompressed .tga with y-origin set to image height, image description bit 5 set and pixel rows in reversed order. The engine expects these three things and if even one is not done the game icon will be vertically inverted when the game runs.


*.wad
-----

Luma textures/fullbrights
=========================
The last 32 colours in a texture's palette will be displayed as fullbright for certain textures.


Adding a new key bind
---------------------

default.cfg and gfx/shell/kb_def.lst both look like they should store default bindings to be populated if nothing is present in config.cfg but neither actually seems to do that.
