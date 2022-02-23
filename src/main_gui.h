#ifndef MAIN_GUI
#define MAIN_GUI

#include <gtk/gtk.h>

void main_gui_init(GtkBuilder *builder, GtkWidget *window);

void main_buttons_set_sensitive(gboolean sensitive);

#endif
