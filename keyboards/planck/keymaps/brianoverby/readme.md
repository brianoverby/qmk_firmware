# 40% (Planck) with nordic/danish + gaming
I'm using US layout with danish keyboard in Windows.
~~It's done using a modified version of [SpacebarRacecars userspace](https://github.com/qmk/qmk_firmware/tree/master/users/spacebarracecar)~~
Now made it a bit simpler with help of [siguls code](https://github.com/qmk/qmk_firmware/tree/master/users/sigul). A lot of the code is now in my userspace

![](http://brianoverby.dk/files/keymap_planck.png)

# Build and flash
    make planck/rev6:brianoverby:dfu-util

# TODO
- ~~Merge userspace to Planck config (I only have Planck keyboards)~~
- Set persistent layer using custom keycode (Basic,Game,...)
- ~~Toggle Win key on off~~
- ~~Add a Caps Lock to 'System' layer (and rename/rework the 'System' layer)~~
- Shortcut to CTRL+/CTRL- (zoom)
- ~~Shift/Enter combo?~~ not really needed
- Switch to line navigation cluster instead of t-shaped
