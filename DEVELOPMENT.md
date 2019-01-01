
dlls/hl.dll
===========

Any method of a class that inherits from CBaseEntity and that is passed to SetThink, SetTouch, SetUse or SetBlocked should have the EXPORT macro as part of its definition in order for save-restore to work correctly.


gfx/colormap.lmp
================

64 light-adjusted RGB colour values for the 256 colours in palette.lmp
Light-adjusted RGB colours 0 to 31 are brightly lit (with 0 being the brightest), 32 is the original colour and 33 to 63 are darkly lit (with 63 being black).


gfx/palette.lmp
===============

256 RGB colour values.


overviews/
==========

To generate an overview, make sure the game is running with the -dev parameter.
Start the map and type dev_overview 1 in the console.
Centre the view using movement keys and the mouse wheel.
Once the map is centered copy down the text that is getting printed to the console.
Type r_drawviewmodel 0 and hud_draw 0 in the console.
Take a screenshot.


liblist.gam
===========

Update mod and developer details here.


*.wad
=====

Luma textures/fullbrights
-------------------------
The last 32 colours in a texture's palette will be displayed as fullbright for certain textures.


Adding a new key bind
=====================

default.cfg and gfx/shell/kb_def.lst both look like they should store default bindings to be populated if nothing is present in config.cfg but neither actually seems to do that.
