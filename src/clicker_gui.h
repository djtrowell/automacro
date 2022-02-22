#ifndef CLICKER_GUI_INIT
#define CLICKER_GUI_INIT

#include <gtk/gtk.h>

#define CLICKER_SPIN_DIGIT 0.5

void clicker_gui_init(GtkBuilder *builder, GtkWidget *window);

void mb_button_clicked_cb(GtkButton *button);

#endif
