# QMK configuration with querty and dvorak layouts for durgor taurus k3x0

## Layers

### Layout #1

This is the querty layout with the Apple command key next to the space bar key.

### Layout #2

The dvorak layout with the Apple command key next to the space bar.

### Layout #3

This is a placeholder for the Programmer Dvorak layout that hasn't been implemented because
of the custom shift complexity. This implemantation should be tackled in future development.

## Switching layers

Each layer can be toggled using the Fn + {layout_id}. The id of the layer is shown
by the status LEDs in a binary representation
 - layer 1               -> 0001
 - layer 2               -> 0010
 - layer 3               -> 0011

## Non-standard mappings

1. CapsLock is remapped to LCTL and a single tap will send `ESC`
2. Double tap on LSFT will lock the caps
3. In both dvorak layouts, the `'` and `;` keys are swapped.

## Macros

1. Double tap `q` will send the `:q<cr>`
   Triple tap `q` will send the `:q!<cr>`
