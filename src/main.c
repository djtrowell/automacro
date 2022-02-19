#include <gtk/gtk.h>
#include <stdlib.h>

#include "./clicker_gui.h"

GtkBuilder *builder;
GtkWidget  *window;

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	char glade_path[PATH_MAX]; realpath("./gui/window_main.glade", glade_path);
	builder = gtk_builder_new_from_file(glade_path);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder, NULL);

	clicker_gui_init(builder, window);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	return EXIT_SUCCESS;
}
