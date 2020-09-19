# 40% (Planck) with nordic/danish + gaming
I'm using US layout with danish keyboard language in Windows.    
~~It's done using a modified version of [SpacebarRacecars userspace](https://github.com/qmk/qmk_firmware/tree/master/users/spacebarracecar)~~    
Now made it a bit simpler with help of [siguls code](https://github.com/qmk/qmk_firmware/tree/master/users/sigul). A lot of the code is now in [my userspace](https://github.com/brianoverby/qmk_firmware/tree/master/users/brianoverby)


![](http://brianoverby.dk/files/keymap_planck.png)

# Build and flash
    make planck/rev6:brianoverby:dfu-util
    make planck/ez:brianoverby:dfu-util

# TODO
- Shortcut to CTRL+/CTRL- (zoom)
- ~~Shift/Enter combo?~~ not really needed
