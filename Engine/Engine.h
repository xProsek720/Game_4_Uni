//
// Created by xProsek on 23.05.2023.
//

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../includes/imports.h"
#include "../Background/Background.h"
#include "../Walls/Walls.h"

#ifndef GANE_4_UNI_IML_ENGINE_H
#define GANE_4_UNI_IML_ENGINE_H


class Engine {

private:

    Background bg = Background(nullptr);
    Walls walls = Walls(nullptr);

    int windowWidth;
    int windowHeight;
    int bitsPerPixel;

    std::string title;

    sf::RenderWindow *windowPtr;
public:
    Engine(int windowWidth, int windowHeight, int bitsPerPixel, std::string title);
    ~Engine();

protected:
    void loadClasses();
    void gameStart();
    void gameLoop();
    void update();
    void render();

    sf::RenderWindow* getWindow();

    Engine* getPtr();





};


#endif //GANE_4_UNI_IML_ENGINE_H
