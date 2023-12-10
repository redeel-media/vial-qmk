SRC += muse.c
LTO_ENABLE = yes
MIDI_ENABLE = yes
VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
VIALRGB_ENABLE = no

BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglo w
AUDIO_ENABLE = yes          # Audio output
CUSTOM_MATRIX = yes
ENCODER_ENABLE = no
DIP_SWITCH_ENABLE = no

# Do not enable RGB_MATRIX_ENABLE together with RGBLIGHT_ENABLE
RGB_MATRIX_ENABLE = no

SRC += matrix.c
