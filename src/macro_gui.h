#ifndef MACRO_GUI
#define MACRO_GUI

#include <gtk/gtk.h>

void macro_gui_init(GtkBuilder *builder, GtkWidget *window);

void load_button_clicked_cb();
void back_button_clicked_cb();

#endif
