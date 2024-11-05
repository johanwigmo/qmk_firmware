ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

MOUSEKEY_ENABLED  = yes

BACKLIGHT_ENABLE = no
LED_MATRIX_ENABLE = no
