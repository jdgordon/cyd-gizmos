SET(SOURCES screens/ui_main.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_Font1.c
    fonts/ui_font_shantelbignumbers123.c)

add_library(ui ${SOURCES})
