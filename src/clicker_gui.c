#include "./clicker_gui.h"

#include <gtk/gtk.h>
#include <gdk/gdk.h>

GtkWidget *leftmb_button;
GtkWidget *middlemb_button;
GtkWidget *rightmb_button;

void clicker_gui_init(GtkBuilder *builder, GtkWidget *window) {
	leftmb_button = GTK_WIDGET(gtk_builder_get_object(builder, "leftmb_button"));
	middlemb_button = GTK_WIDGET(gtk_builder_get_object(builder, "middlemb_button"));
	rightmb_button = GTK_WIDGET(gtk_builder_get_object(builder, "rightmb_button"));
}

void mb_button_clicked_cb(GtkButton *button) {
	GdkRGBA color; gdk_rgba_parse(&color, "#100255255");
	gtk_widget_override_background_color(GTK_WIDGET(button), GTK_STATE_NORMAL, &color);
}
