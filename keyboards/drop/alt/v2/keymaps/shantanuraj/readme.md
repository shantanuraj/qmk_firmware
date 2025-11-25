# Shantanuraj's Drop ALT v2 Keymap

This is a custom keymap for the Drop ALT v2 keyboard, ported from the original massdrop/alt configuration.

## Features

- **Caps Lock = Ctrl/Esc** - Tap for Escape, hold for Control (game changer!)
- Grave/Tilde on top-left
- Media controls on right column (Volume Up/Down, Play/Pause, Fast Forward)
- **Right Shift acts as Fn key** - Hold Right Shift to access Layer 1
- Function layer with:
  - F1-F12 keys
  - **Vim-style arrow keys on H, J, K, L** (Left, Down, Up, Right)
  - RGB Matrix controls (speed, brightness, hue, saturation)
  - NK Toggle (N-Key Rollover)
  - Debug Toggle
  - Bootloader access (hold Fn+B for 500ms)
  - Navigation keys (Home/End/PgUp/PgDn)

## Changes from Original

The original keymap was designed for the older massdrop/alt keyboard. This version has been updated for the Drop ALT v2 with the following changes:

1. **RGB Matrix Keycodes**: Updated from `RGB_*` to `RM_*` keycodes (e.g., `RGB_TOG` → `RM_TOGG`, `RGB_VAI` → `RM_VALU`)
2. **Removed USB Control**: The old `U_T_AUTO` and `U_T_AGCR` keycodes for USB port control are not available in v2
3. **Removed Debug Keycodes**: The old `DBG_MTRX`, `DBG_KBD`, `DBG_MOU` keycodes have been replaced with the standard `DB_TOGG`
4. **Custom Keycode Range**: Updated to use `QK_KB_0` instead of `SAFE_RANGE` for better compatibility
5. **Bootloader**: The v2 uses TinyUF2 bootloader instead of the old mdloader

## Building

```bash
qmk compile -kb drop/alt/v2 -km shantanuraj
```

## Flashing

### Method 1: QMK Flash Command

```bash
qmk flash -kb drop/alt/v2 -km shantanuraj
```

Then put your keyboard into bootloader mode (see below).

### Method 2: Manual UF2 Flash

1. Build the firmware (see above)
2. Put your keyboard into bootloader mode:
   - **Keycode method**: Press and hold `Fn + B` for 500ms
   - **Physical method**: Double-tap the reset button under the spacebar
   - **Bootmagic**: Unplug keyboard, hold Escape (top-left key), plug in keyboard
3. Your keyboard will appear as a USB drive named "ALT-V2"
4. Copy the `drop_alt_v2_shantanuraj.uf2` file to the drive
5. The keyboard will automatically reboot with the new firmware

## RGB Toggle Behavior

The RGB toggle key (`Fn + Z`) cycles through four modes:
1. All LEDs on (keylights + underglow)
2. Keylights only
3. Underglow only
4. All LEDs off

## Layout

### Layer 0 (Base)
```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bkspc │V+ │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │V- │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
│Esc/Ctl│A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │Ply│
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Fn*  │ ↑ │FF │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
│Ctrl│GUI │Alt │        Space           │Alt │ Fn │ │ ← │ ↓ │ → │
└────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘

Special Keys:
* Esc/Ctl (Caps Lock position) = Tap for Escape, Hold for Control
* Right Shift = Fn (Layer 1)
```

### Layer 1 (Function - Hold Right Shift or Fn)
```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
│   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │Mut│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
│     │Sp-│Br+│Sp+│Hu+│Sa+│   │   │   │   │PSc│SLk│Pau│     │Pau│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
│      │Prv│Br-│Nxt│Hu-│Sa-│ ← │ ↓ │ ↑ │ → │   │   │        │   │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
│        │Tog│   │   │   │Boo│NKT│Dbg│   │   │   │      │PgU│Rwd│
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
│    │    │    │                        │    │    │ │Hom│PgD│End│
└────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
```

**Vim Navigation**: Hold Right Shift (or Fn) + H/J/K/L for Left/Down/Up/Right arrows!

Legend:
- Sp+/Sp-: RGB Speed Up/Down
- Br+/Br-: RGB Brightness Up/Down
- Hu+/Hu-: RGB Hue Up/Down
- Sa+/Sa-: RGB Saturation Up/Down
- Prv/Nxt: RGB Mode Previous/Next
- Tog: RGB Toggle
- Boo: Bootloader (hold 500ms)
- NKT: N-Key Rollover Toggle
- Dbg: Debug Toggle

