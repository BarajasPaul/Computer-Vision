#include <stdlib.h>
#include <gtk/gtk.h>
#include "gui_interface.h"

/*
 * gui_interface.c
 * Copyright (C) 2015 Barajas D. Paul <Paul.Barajas@linux.com>
 *
*/

Common vara={ .count = 0 };
Common *var=&vara;


void increase(gtk_struct *widgets, gpointer label){
    var->count++;

    sprintf(var->buf, "%d", var->count);
    gtk_label_set_text(GTK_LABEL(label), var->buf);
}

void decrease(gtk_struct *widgets, gpointer label)
{
  var->count--;

  sprintf(var->buf, "%d", var->count);
  gtk_label_set_text(GTK_LABEL(label), var->buf);
}

void GUI_start(){

    gtk_struct *widgets;

    widgets=(gtk_struct *)malloc(sizeof(gtk_struct));
    if (widgets == NULL){
        exit(1);
    }
    widgets->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widgets->window), "Center");
    gtk_window_set_default_size(GTK_WINDOW(widgets->window), 1024, 720);
    gtk_window_set_position(GTK_WINDOW(widgets->window), GTK_WIN_POS_CENTER);
    gtk_widget_show(widgets->window);

    g_signal_connect_swapped(G_OBJECT(widgets->window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);

    widgets->frame = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(widgets->window), widgets->frame);

    widgets->plus = gtk_button_new_with_label("+");
    gtk_widget_set_size_request(widgets->plus, 80, 35);
    gtk_fixed_put(GTK_FIXED(widgets->frame), widgets->plus, 50, 20);

    widgets->minus = gtk_button_new_with_label("-");
    gtk_widget_set_size_request(widgets->minus, 80, 35);
    gtk_fixed_put(GTK_FIXED(widgets->frame), widgets->minus, 50, 80);

    widgets->label = gtk_label_new("0");
    gtk_fixed_put(GTK_FIXED(widgets->frame), widgets->label, 110, 58);

    gtk_widget_show_all(widgets->window);

    g_signal_connect(widgets->window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);

    g_signal_connect(widgets->plus, "clicked", 
      G_CALLBACK(increase), widgets->label);

    g_signal_connect(widgets->minus, "clicked", 
      G_CALLBACK(decrease), widgets->label);

    gtk_main();
}
