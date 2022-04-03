
#ifndef TETRIS_CPP_APP_H
#define TETRIS_CPP_APP_H

#include <memory>
#include "BoardController.h"
#include "header.h"
#include "RenderWindow.h"

class App {
public:
    explicit App();
    void run();

private:
    std::unique_ptr<Controller> m_current_controller;
    bool m_running;

};


#endif
