//
// Created by xProsek on 23.05.2023.
//

#include "../includes/imports.h"
#ifndef GANE_4_UNI_IML_BACKGROUND_H
#define GANE_4_UNI_IML_BACKGROUND_H


class Background {
private:
    int red;
    int blue;
    int green;
    bool up;

    sf::Color backgroundColor;
    sf::RenderWindow* windowPtr;


public:
    Background(sf::RenderWindow* windowPtr);
    ~Background();


    void update();
    void render();

    Background* getPtr();

};

#endif //GANE_4_UNI_IML_BACKGROUND_H
