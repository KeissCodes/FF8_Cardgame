#include <gtk/gtk.h>
#include <cairo.h>
#include <string>
#include <vector>
#include <memory>
#include "game.h"
#include "card.h"
#include "deck.h"

std::unique_ptr<Game> game;
GtkWidget *drawing_area; // Globale Variable

// Zeichenfunktion
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    if (game) {
        game->draw(cr);
    }
    return FALSE;
}

// Initialisierung der Spiel-Logik
void initialize_game() {
    game = std::make_unique<Game>();
}

// Maus-Klick-Ereignis
static gboolean on_mouse_click(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    if (game) {
        game->handle_click(event->x, event->y);
    }
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Triple Triad");
    gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);

    // Setze das Fenster unveränderlich (nicht in der Größe änderbar)
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(G_OBJECT(drawing_area), "button-press-event", G_CALLBACK(on_mouse_click), NULL);
    gtk_widget_add_events(drawing_area, GDK_BUTTON_PRESS_MASK);

    initialize_game();

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
