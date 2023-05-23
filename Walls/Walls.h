//
// Created by xProsek on 23.05.2023.
//

#ifndef GANE_4_UNI_IML_WALLS_H
#define GANE_4_UNI_IML_WALLS_H


#include <SFML/Graphics/RectangleShape.hpp>

class Walls {

private:
    int red;
    int blue;
    int green;
    sf::Vector2f Size;
    sf::Vector2f lPos;
    sf::RectangleShape rectLeft;
    sf::Vector2f rPos;
    sf::RectangleShape rectRight;
    sf::Color colofOfWalls;
    sf::RenderWindow* windowPtr;


public:
    Walls(sf::RenderWindow* windowPtr);
    ~Walls();

    void defaultVars();
    void update();
    void render();


};


#endif //GANE_4_UNI_IML_WALLS_H
