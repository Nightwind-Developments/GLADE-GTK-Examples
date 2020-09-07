#include "gladeprogram.h"

using namespace Gtk;

Window* mainWindow = nullptr;
Button* recordBtn = nullptr;
Label* label = nullptr;

void Record_Btn_clicked(){
    //std::cout << "button pushed!" << std::endl;
    label->set_label("Hello World");
}

int main(int argc, char *argv[]) {

    auto app = Application::create(argc, argv, "nz.nightwind.journeyeye");
    auto builder = Builder::create();


    try {
        builder->add_from_file(gladeFilePath);
    }
    catch (const Glib::FileError& e) {
        std::cerr << "Glade File Failed to Open: " << e.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& ex) {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Gtk::BuilderError& ex) {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    builder->get_widget("MainWindow", mainWindow);
    builder->get_widget("Record_Btn", recordBtn);
    builder->get_widget("Status_Label", label);

    recordBtn->signal_clicked().connect(sigc::ptr_fun(&Record_Btn_clicked));

    app->run(*mainWindow);

    return 0;
}
