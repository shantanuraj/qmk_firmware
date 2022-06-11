# Shantanuraj's Drop CTRL v2 Keymap

This is a custom keymap for the Drop CTRL v2 keyboard (TKL), ported from the original massdrop/ctrl configuration.

## Features

### Tap Dance - Double Tap for CMD+Key
The standout feature of this keymap is extensive tap dance support for macOS users. Almost every alphanumeric key can be **double-tapped** to send CMD+key:

- **Single tap**: Normal key (e.g., `A` sends A)
- **Double tap**: CMD+key (e.g., double-tap `A` sends CMD+A for Select All)

This works for:
- All letters (A-Z)
- All numbers (0-9)
- Special keys: Tab, Space, Enter, Backspace, Grave/Tilde

**Tapping term**: 150ms (configurable in `config.h`)

### Other Features
- **Escape on Caps Lock**: More ergonomic Escape key placement
- **RGB Matrix Controls**: Full control over keyboard lighting
- **Media Controls**: Play/pause, next/prev, volume on function layer
- **Bootloader Access**: Hold Fn+B for 500ms to enter bootloader mode
- **N-Key Rollover Toggle**: Fn+N to toggle NKRO
- **Debug Toggle**: Fn+M for debugging

## Changes from Original

The original keymap was designed for the older massdrop/ctrl keyboard. This version has been updated for the Drop CTRL v2 with the following changes:

1. **RGB Matrix Keycodes**: Updated from `RGB_*` to `RM_*` keycodes
   - `RGB_TOG` → `RM_TOGG` (with custom toggle behavior preserved)
   - `RGB_SPD/RGB_SPI` → `RM_SPDD/RM_SPDU`
   - `RGB_VAI/RGB_VAD` → `RM_VALU/RM_VALD`
   - `RGB_HUI/RGB_HUD` → `RM_HUEU/RM_HUED`
   - `RGB_SAI/RGB_SAD` → `RM_SATU/RM_SATD`
   - `RGB_RMOD/RGB_MOD` → `RM_PREV/RM_NEXT`

2. **Removed USB Control**: The old `U_T_AUTO` and `U_T_AGCR` keycodes for USB port control are not available in v2

3. **Removed Debug Keycodes**: The old `DBG_TOG`, `DBG_MTRX`, `DBG_KBD`, `DBG_MOU` keycodes have been replaced with the standard `DB_TOGG`

4. **Fixed Scroll Lock**: `KC_SLCK` → `KC_SCRL` (keycode name changed in QMK)

5. **Tap Dance Implementation**: Completely rewritten to work with the new QMK tap dance system, using custom functions instead of the deprecated `ACTION_TAP_DANCE_DOUBLE` macro with modifier combinations

6. **Custom Keycode Range**: Updated to use `QK_KB_0` instead of `SAFE_RANGE` for better compatibility

7. **Bootloader**: The v2 uses TinyUF2 bootloader instead of the old mdloader

## Building

```bash
qmk compile -kb drop/ctrl/v2 -km shantanuraj
```

## Flashing

### Method 1: QMK Flash Command

```bash
qmk flash -kb drop/ctrl/v2 -km shantanuraj
```

Then put your keyboard into bootloader mode (see below).

### Method 2: Manual UF2 Flash

1. Build the firmware (see above)
2. Put your keyboard into bootloader mode:
   - **Keycode method**: Press and hold `Fn + B` for 500ms
   - **Physical method**: Double-tap the reset button under the spacebar
   - **Bootmagic**: Unplug keyboard, hold Escape (top-left key), plug in keyboard
3. Your keyboard will appear as a USB drive named "CTRL-V2"
4. Copy the `drop_ctrl_v2_shantanuraj.uf2` file to the drive
5. The keyboard will automatically reboot with the new firmware

## RGB Toggle Behavior

The RGB toggle key (`Fn + Z`) cycles through four modes:
1. All LEDs on (keylights + modifiers + indicators + underglow)
2. Keylights, modifiers, and indicators only
3. Underglow only
4. All LEDs off

## Layout

### Layer 0 (Base)
```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┐
│Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │PSc│SLk│Pau│
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘   └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bkspc │ │Ins│Hom│PgU│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Esc  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  Shift   │     │ ↑ │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl│GUI │Alt │         Space          │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
```

**Note**: All alphanumeric keys, Tab, Space, Enter, Backspace, and Grave support double-tap for CMD+key.

### Layer 1 (Function)
```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┐
│   │   │   │   │   │   │   │   │   │   │   │   │   │   │Mut│   │   │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘   └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │Ply│Stp│V+ │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│     │Sp-│Br+│Sp+│Hu+│Sa+│   │   │   │   │   │   │   │     │ │Prv│Nxt│V- │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│      │Prv│Br-│Nxt│Hu-│Sa-│   │   │   │   │   │   │        │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
│        │Tog│   │   │   │Boo│NKT│Dbg│   │   │   │          │     │   │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│    │    │    │                        │    │    │    │    │ │   │   │   │
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
```

**Legend**:
- **Sp+/Sp-**: RGB Speed Up/Down
- **Br+/Br-**: RGB Brightness Up/Down
- **Hu+/Hu-**: RGB Hue Up/Down
- **Sa+/Sa-**: RGB Saturation Up/Down
- **Prv/Nxt**: RGB Mode Previous/Next
- **Tog**: RGB Toggle (cycles through 4 modes)
- **Boo**: Bootloader (hold 500ms)
- **NKT**: N-Key Rollover Toggle
- **Dbg**: Debug Toggle
- **Mut**: Mute
- **Ply/Stp**: Play/Stop
- **Prv/Nxt**: Previous/Next Track
- **V+/V-**: Volume Up/Down

## Tap Dance Examples

Here are some useful CMD+key combinations you can trigger with double-tap:

**macOS Shortcuts**:
- Double-tap `A`: Select All (CMD+A)
- Double-tap `C`: Copy (CMD+C)
- Double-tap `V`: Paste (CMD+V)
- Double-tap `X`: Cut (CMD+X)
- Double-tap `Z`: Undo (CMD+Z)
- Double-tap `S`: Save (CMD+S)
- Double-tap `F`: Find (CMD+F)
- Double-tap `T`: New Tab (CMD+T)
- Double-tap `W`: Close Tab (CMD+W)
- Double-tap `Q`: Quit (CMD+Q)
- Double-tap `N`: New Window (CMD+N)
- Double-tap `Tab`: Switch Apps (CMD+Tab)
- Double-tap `Space`: Spotlight (CMD+Space)
- Double-tap `1-9`: Switch to Tab 1-9 in browsers
- Double-tap `Backspace`: Delete word (CMD+Backspace)

## Files

- `keymap.c`: Main keymap with tap dance and RGB control
- `config.h`: Configuration (tapping term = 150ms)
- `rules.mk`: Build rules (enables tap dance)
- `readme.md`: This file

## Customization

### Adjusting Tap Dance Timing

Edit `config.h` and change the `TAPPING_TERM` value:
```c
#define TAPPING_TERM 150  // Increase for slower double-taps, decrease for faster
```

### Adding More Tap Dance Keys

To add tap dance to other keys, follow this pattern in `keymap.c`:

1. Add enum entry:
```c
enum {
    // ... existing entries
    TD_NEW_KEY,
};
```

2. Create tap dance function:
```c
CREATE_CMD_TAP_DANCE(td_newkey, KC_NEWKEY)
```

3. Add to tap_dance_actions array:
```c
[TD_NEW_KEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_newkey_finished, td_newkey_reset),
```

4. Use in keymap:
```c
TD(TD_NEW_KEY)
```

## Troubleshooting

**Double-tap not registering**: Increase `TAPPING_TERM` in `config.h`

**Accidental double-taps**: Decrease `TAPPING_TERM` in `config.h`

**RGB not working**: Make sure you're using the correct keycodes (`RM_*` not `RGB_*`)

**Bootloader not activating**: Make sure you hold Fn+B for at least 500ms

