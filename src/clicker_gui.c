#include "./clicker_gui.h"

#include <math.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

GtkWidget *leftmb_button;
GtkWidget *middlemb_button;
GtkWidget *rightmb_button;

GtkWidget *cps_button;
GtkWidget *time_button;
GtkWidget *cps_label;
GtkWidget *time_label;

GtkWidget *full_speed_button;


double click_time;

void clicker_gui_init(GtkBuilder *builder, GtkWidget *window) {
	leftmb_button = GTK_WIDGET(gtk_builder_get_object(builder, "leftmb_button"));
	middlemb_button = GTK_WIDGET(gtk_builder_get_object(builder, "middlemb_button"));
	rightmb_button = GTK_WIDGET(gtk_builder_get_object(builder, "rightmb_button"));

	cps_button = GTK_WIDGET(gtk_builder_get_object(builder, "cps_button"));
	time_button = GTK_WIDGET(gtk_builder_get_object(builder, "time_button"));
	cps_label = GTK_WIDGET(gtk_builder_get_object(builder, "cps_label"));
	time_label = GTK_WIDGET(gtk_builder_get_object(builder, "time_label"));

	full_speed_button = GTK_WIDGET(gtk_builder_get_object(builder, "fsp_button"));
}

void mb_button_toggled_cb(GtkButton *button) {
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(leftmb_button)) == TRUE) g_print("Left Mouse Button\n");
	else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(middlemb_button)) == TRUE) g_print("Middle Mouse Button\n");
	else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(rightmb_button)) == TRUE) g_print("Right Mouse Button\n");
}

void cps_button_value_changed_cb() {
	click_time = 1000 / gtk_spin_button_get_value(GTK_SPIN_BUTTON(cps_button));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(time_button), click_time - fmod(click_time, CLICKER_SPIN_DIGIT));
}

void time_button_value_changed_cb() {
	click_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(time_button));
	double cps = 1000 / click_time;
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(cps_button), cps - fmod(cps, CLICKER_SPIN_DIGIT));
}

void fsp_button_toggled_cb() {
	gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(full_speed_button));
	if (active) {
		gtk_widget_set_sensitive(cps_button, FALSE);
		gtk_widget_set_sensitive(cps_label, FALSE);
		gtk_widget_set_sensitive(time_button, FALSE);	
		gtk_widget_set_sensitive(time_label, FALSE);	
	}
	else if (!active) {
		gtk_widget_set_sensitive(cps_button, TRUE);
		gtk_widget_set_sensitive(cps_label, TRUE);
		gtk_widget_set_sensitive(time_button, TRUE);	
		gtk_widget_set_sensitive(time_label, TRUE);	
	}
}
