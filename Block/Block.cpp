//
// Created by xProsek on 24.05.2023.
//

#include "../includes/imports.h"
#include "Block.h"


Block::Block(sf::RenderWindow* windowPtr, sf::RectangleShape* playerPtr, sf::Vector2f position, float sizeX)
{
    this->windowPtr = windowPtr;
    this->sizeX = sizeX;
    this->position = position;
    this->playerPtr = playerPtr;
    //std::cout << std::endl << this->sizeX << " " << this->position.x;
    if (this->sizeX < minSizeX)
    {
        this->sizeX = minSizeX;
    }
    if (this->maxSizeX < this->sizeX + this->position.x)
    {
        this->sizeX = this->maxSizeX - this->position.x;
    }

    //std::cout << std::endl << this->sizeX << " " << this->position.x;
//    this->maxSizeX = this->maxPosX - this->position.x;
//    if (this->sizeX > maxSizeX)
//    {
//        this->sizeX = maxSizeX;
//        this->maxSizeX = this->maxPosX - this->position.x;
//
//    }
//
//
//    if (this->position.x < minPosX)
//    {
//        this->position.x = minPosX;
//        this->maxSizeX = this->maxPosX - this->position.x;
//
//    }

//    if (this->position.x > maxPosX)
//    {
//        this->position.x = maxPosX;
//        this->maxSizeX = this->maxPosX - this->position.x;
//
//    }
//    if (this->sizeX > maxSizeX)
//    {
//        this->sizeX = maxSizeX;
//    }
//
//    //std::cout <<std::endl << position.x + sizeX;
//    if (this->position.x + this->sizeX > maxPosX)
//    {
//        if (this->position.x >= maxPosX - this->sizeX && this->position.x > minPosX)
//        {
//            this->position.x = this->position.x - this->sizeX;
//            this->maxSizeX = this->maxPosX - this->position.x;
//
//        }
//        this->sizeX = maxPosX - this->position.x;
//        this->maxSizeX = this->maxPosX - this->position.x;
//
//    }
//    this->maxSizeX = this->maxPosX - this->position.x;
//
//    //std::cout <<std::endl << position.x + sizeX;
//    std::cout <<std::endl << this->maxSizeX;


    createBlock();
}

Block::~Block()
{

}

void Block::update()
{
//    worldMoving();
//    if (checkCollision(playerPtr))
//    {
//        if (playerPtr->getPosition().y > (position.y + sizeY))
//        {
//            playerWentThrough = true;
//
//        }
//    }
//
//    if (playerWentThrough)
//    {
//        if (checkCollision(playerPtr))
//        {
//            //if (playerSpeedY < 0)
//            // {
//            //      playerSpeedY = 0;
//            // }
//        }
//    }



    //Implementacja ruchu góra dół gdy gracz skacze
}

void Block::render()
{
    //Rysowanie bloczku jednego
    windowPtr->draw(this->left);
    windowPtr->draw(this->middle);
    windowPtr->draw(this->right);
//    this->left.setPosition(this->left.getPosition().x, this->left.getPosition().y +5);
//    this->middle.setPosition(this->middle.getPosition().x, this->middle.getPosition().y +5);
//    this->right.setPosition(this->right.getPosition().x, this->right.getPosition().y +5);

}

bool Block::checkCollision(sf::RectangleShape *player)
{
    bool colided = false;
    if (left.getGlobalBounds().intersects(player->getGlobalBounds()))
    {
        colided = true;
    }
    if (middle.getGlobalBounds().intersects(player->getGlobalBounds()))
    {
        colided = true;
    }
    if (right.getGlobalBounds().intersects(player->getGlobalBounds()))
    {
        colided = true;
    }
    return colided;
}

void Block::createBlock()
{
    this->left = sf::RectangleShape(sf::Vector2f(this->sizeY, this->sizeY));
    this->left.setPosition(this->position.x - 10, this->position.y);

    this->middle = sf::RectangleShape(sf::Vector2f(this->sizeX-2*this->sizeY, this->sizeY));
    this->middle.setPosition(this->position.x + this->sizeY, this->position.y);

    this->right = sf::RectangleShape(sf::Vector2f(this->sizeY, this->sizeY));
    this->right.setPosition(this->position.x +10+ (this->sizeX-this->sizeY), this->position.y);

    //std::cout << std::endl << this->sizeX << " " << this->position.x;
}

void Block::worldMoving()
{
    if (playerPtr->getPosition().y > lastPlayerY)
    {
        this->position.y -= playerPtr->getPosition().y - lastPlayerY;
        this->lastPlayerY = playerPtr->getPosition().y;
    }

    if (playerPtr->getPosition().y < lastPlayerY)
    {
        this->position.y += playerPtr->getPosition().y - lastPlayerY;
        this->lastPlayerY = playerPtr->getPosition().y;
    }


}
