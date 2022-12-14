#include <iostream>
#include <Window.h>
#include <String.h>
#include <Logger.h>
#include <Event.h>

int main(void) {
  String app_name = "Tridme Engine";
  LOG(LOG_TYPE::INFO, app_name);
  Tridme::Window* window = new Tridme::Window(800, 600, "Tridme Engine");

  String os_type = window->GetOSImplementation()->GetName().get();
  LOG(LOG_TYPE::INFO, "Running on %s", os_type.get());

  while (window->IsOpen()) {
    while (window->PollEvents()) {
      Tridme::Event event = window->GetHandler();

      if (event.type == Tridme::EVENT_KEYBOARD_PRESSED && 
          event.keyCode == Tridme::KEY(TRIDME_KEY_B)) {
        // window->Close();
        LOG(INFO, "A IS PRESSED");
      }
    }

    glClearColor(0.8, 0.6, 0.7, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    window->Display();
  }

  window->Close();
  return 0;
}