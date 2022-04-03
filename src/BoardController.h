
#ifndef TETRIS_CPP_BOARDCONTROLLER_H
#define TETRIS_CPP_BOARDCONTROLLER_H

#include <memory>
#include "header.h"
#include "Controller.h"
#include "Board.h"
#include "BoardView.h"
#include "BoardInputHandler.h"

class BoardController : public Controller {
public:
    BoardController();
    ~BoardController() override = default;

    void update() override;
    void draw(SDL_Renderer* renderer) override;
    void handleEvents(SDL_Event& ev) override;

private:
    BoardInputHandler m_input_handler;
    Board m_board;
    BoardView m_view;

};

#endif
