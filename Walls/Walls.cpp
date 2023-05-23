//
// Created by xProsek on 23.05.2023.
//

#include "../includes/imports.h"
#include "Walls.h"


Walls::Walls(sf::RenderWindow* windowPtr)
{
    this->windowPtr = windowPtr;

}
Walls::~Walls()
{

}

void Walls::defaultVars()
{
    this->red = 124 + 24;
    this->green = 124 + 24;
    this->blue = 150 + 24;
    this->colofOfWalls = sf::Color(red, green, blue);
    this->Size = sf::Vector2f(this->windowPtr->getSize().x/12, this->windowPtr->getSize().y);
    this->lPos = sf::Vector2f(0, 0);
    this->rectLeft = sf::RectangleShape(Size);
    this->rectLeft.setPosition(lPos);
    this->rectLeft.setFillColor(colofOfWalls);
    int rPosX = this->windowPtr->getSize().x - (Size.x);
    this->rPos = sf::Vector2f(rPosX, 0);
    this->rectRight = sf::RectangleShape(Size);
    this->rectRight.setPosition(rPos);
    this->rectRight.setFillColor(colofOfWalls);
}

void Walls::update()
{
    defaultVars();
    //std::cout << Size.x<<" - " << Size.y<< std::endl;
}

void Walls::render()
{
    this->windowPtr->draw(rectLeft);
    this->windowPtr->draw(rectRight);
}

bool Walls::checkCollision(sf::RectangleShape player)
{
    bool collides = false;
    if (rectLeft.getGlobalBounds().intersects(player.getGlobalBounds()))
    {
        collides = true;
    }
    if (rectRight.getGlobalBounds().intersects(player.getGlobalBounds()))
    {
        collides = true;
    }
    return collides;
}

Walls* Walls::getPtr() {
    return this;
}
