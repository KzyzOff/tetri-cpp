target_sources(sources
                PUBLIC
                    main.cpp
                    types.cpp
                    header.h
                    CONSTANT.h
                    App.cpp App.h
                    FontManager.cpp FontManager.h
                    Color.h
                    Button.cpp Button.h
                    RenderWindow.cpp RenderWindow.h
                    Entity.cpp Entity.h
                    Board.cpp Board.h
                    Block.cpp Block.h
                    Clock.cpp Clock.h
                    Controller.cpp Controller.h
                    BoardController.cpp BoardController.h
                )

target_include_directories(sources PUBLIC ${CMAKE_CURRENT_LIST_DIR})