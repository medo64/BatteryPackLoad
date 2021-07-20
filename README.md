# Battery Pack Load

The only task this device has is to load USB every 10 seconds with about 200 mA
for 20 ms in order to give battery pack reason to live.

There is a simpler version that doesn't use microcontroller available at
[Dorkbot PDX](https://dorkbotpdx.org/blog/paul/battery_pack_load/) but I love
to complicate things.

This device will pulse load every 10 seconds thus having 0.2& duty cycle for
average consumption of 0.5 mA.

---

See also:
* [Plug version](Hardware/src/BatteryPackLoad.md)
* [Pass-through version](Hardware/src/BatteryPackLoad-PT.md)
