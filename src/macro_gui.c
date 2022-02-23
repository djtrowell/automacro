#include "./macro_gui.h"

#include <gtk/gtk.h>
#include <stdlib.h>

#include "./main_gui.h"

GtkWidget *new_button;
GtkWidget *load_button;
GtkWidget *save_button;
GtkWidget *record_button;

GtkWidget *macro_stack;

GtkWidget *macro_stack_item;
GtkWidget *load_macros_stack_item;

GtkWidget *macro_list;
GtkWidget *action_list;
GtkWidget *load_macro_list;

GtkWidget *load_macro_row;

void load_rows() {
	GtkBuilder *builder;
	char glade_path[PATH_MAX]; realpath("./gui/list_box_rows.glade", glade_path);
	builder = gtk_builder_new_from_file(glade_path);
	gtk_builder_connect_signals(builder, NULL);

	load_macro_row = GTK_WIDGET(gtk_builder_get_object(builder, "load_macro_row"));

	g_object_unref(builder);
}

void macro_gui_init(GtkBuilder *builder, GtkWidget *window) {
	load_rows();

	new_button = GTK_WIDGET(gtk_builder_get_object(builder, "new_button"));
	load_button = GTK_WIDGET(gtk_builder_get_object(builder, "load_button"));
	save_button = GTK_WIDGET(gtk_builder_get_object(builder, "save_button"));
	record_button = GTK_WIDGET(gtk_builder_get_object(builder, "record_button"));

	macro_stack = GTK_WIDGET(gtk_builder_get_object(builder, "macro_stack"));
	
	load_macros_stack_item = GTK_WIDGET(gtk_builder_get_object(builder, "load_macros"));
	macro_stack_item = GTK_WIDGET(gtk_builder_get_object(builder, "macro"));

	macro_list = GTK_WIDGET(gtk_builder_get_object(builder, "macro_list"));
	action_list = GTK_WIDGET(gtk_builder_get_object(builder, "action_list"));
	load_macro_list = GTK_WIDGET(gtk_builder_get_object(builder, "load_macro_list"));	
}

void load_button_clicked_cb() {
	gtk_stack_set_visible_child(GTK_STACK(macro_stack), load_macros_stack_item);

	main_buttons_set_sensitive(FALSE);

	gtk_widget_set_sensitive(load_button, FALSE);
	gtk_widget_set_sensitive(save_button, FALSE);
	gtk_widget_set_sensitive(record_button, FALSE);
}

void back_button_clicked_cb() {
	gtk_stack_set_visible_child(GTK_STACK(macro_stack), macro_stack_item);

	main_buttons_set_sensitive(TRUE);

	gtk_widget_set_sensitive(load_button, TRUE);
	gtk_widget_set_sensitive(save_button, TRUE);
	gtk_widget_set_sensitive(record_button, TRUE);
}
