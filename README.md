# Marlin-blot
This is a fork of Marlin designed to run on the [Hack Club Blot](https://blot.hackclub.com). More specifically, it's a fork of [thinkyhead's WIP HAL for RP2040 @5ac522b](https://github.com/thinkyhead/Marlin/commit/5ac522b07955802094096c6e67d391eccea7f40e).
I've made non-configuration code changes to convince Marlin to work, so this is not buildable for anything other than a Blot. To see what I've changed, check out [this diff](https://github.com/thinkyhead/Marlin/compare/bf2_wip_rp2040_skr_pico_PR...rivques:Marlin-blot:6942cb3e0f51ec6c747fb5f91eb4973db3b11e8d).
## Usage
**IMPORTANT NOTE: _NEVER_ ATTEMPT TO HOME THE MACHINE! Blot has no endstops, but Marlin thinks it does for Reasons. This means that if you start a homing routine, you'll never stop and will just crash instead. Use M18 and G92 instead.**
The Blot is configured as a 2-axis, 0-extruder CoreXY machine with a servo-controlled spindle. This means the pen can be raised and lowered with M3/M4 and M5. There is support for specifying the exact servo angle with `M3 S<angle>`. By default 0 is pen up and 90 is pen down.

The Blot control board is a custom board named `BOARD_HC_BLOT`. If you want to edit this (maybe to add assignments for the unused GPIOs), note that the pin numbers are the "micropython numbers" on the XIAO, not the Arduino mappings. (i.e. they're the actual RP2040 GPIO names.)

You can build this yourself with the help of the Auto Build Marlin VS Code extension, or you can check the Releases section for a ready-to-go UF2.

## Configuration to tweak
You might find it interesting to tweak the `SERVO_DELAY`, which controls how long the blot waits for the servo to get to its new location, for a pretty easy speed-up. In theory the NeoPixel should be useable with M150, but I haven't had any success with it.

Changing `SPEED_POWER_STARTUP` in `spindle_laser_types.h` will adjust the default M3 servo position on a scale from 0-30000 mapping to 0-180. Don't ask.

`DEACTIVATE_SERVOS_AFTER_MOVE` is turned on because there was lots of jitter otherwise. This is fine with the stock setup but if you have a heavier toolhead you might need to turn this back off.

## Why?
Mostly because this makes your Blot speak GCode, which means it can be used with tools like https://sameer.github.io/svg2gcode. It also means you get access to Marlin's quality-of-life and high-performance features (like easier speed adjustment). On that note, I've been running very comfortably at 2000 mm/min, but I bet it can go way higher.

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.
