#include "gladeprogram.h"

GtkWidget *window;
GtkWidget *record_btn;
GtkWidget *recording_label;
GtkWidget *builder;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("GPP2_Demo_Template.glade");

    return 0;
}
