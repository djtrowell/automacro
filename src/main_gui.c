#include "./main_gui.h"

#include <gtk/gtk.h>

#include "./macro_gui.h"

GtkWidget *start_button;
GtkWidget *stop_button;

void main_gui_init(GtkBuilder *builder, GtkWidget *window) {
	start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
	stop_button = GTK_WIDGET(gtk_builder_get_object(builder, "stop_button"));
}

void main_buttons_set_sensitive(gboolean sensitive) {
	gtk_widget_set_sensitive(start_button, sensitive);
	gtk_widget_set_sensitive(stop_button, sensitive);
}

void notebook_switch_page_cb() { 
	back_button_clicked_cb();
}
