#include <iostream>
#include "window.h"

int main() {
    Window* pwindow = new Window();

    std::cout << "Creating Window" << std::endl;

    bool running = true;
    while (running) {
        if (pwindow->processMessages() == false) {
            std::cout << "Closing Window" << std::endl;
            running = false;
        }

        Sleep(10);
    }

    delete pwindow;

    return 0;
}