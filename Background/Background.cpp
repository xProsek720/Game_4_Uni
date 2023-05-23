//
// Created by xProsek on 23.05.2023.
//

#include "Background.h"

Background::Background(sf::RenderWindow* windowPtr)
{
    this->windowPtr = windowPtr;
    this->red = 124;
    this->green = 124;
    this->blue = 150;
    this->backgroundColor = sf::Color(red, green, blue);
    this->up = true;

}
Background::~Background()
{}

void Background::update()
{
    this->backgroundColor = sf::Color(red, green, blue);
//
//    if (green < 255 && up)
//    {
//        this->green +=1;
//    }
//    else
//    {
//        up = false;
//        this->green -=1;
//    }
//    if(green > 0 && !up)
//    {
//        this->green -=1;
//    }
//    else
//    {
//        this->green +=1;
//        up= true;
//    }
//    std::cout << green << std::endl;
}

void Background::render()
{
    windowPtr->clear(backgroundColor);
}
