#include "draw.h"
#include <gtk/gtk.h>

extern GtkWidget *drawing_area;

void redraw() {
    gtk_widget_queue_draw(drawing_area);
}
