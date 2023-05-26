#include "../includes/imports.h"

void Player::InitializeVariables()
{
	this->pPosition.x = 640.f - 16;
	this->pPosition.y = 720.f - 32;
    this->pSize.x = 32.f;
    this->pSize.y = 32.f;

	this->movementSpeed = 10.2f;
}

void Player::InitializeComponents()
{
}

Player::Player(Walls* wallPtr, sf::RenderWindow* windowPtr)
{
	this->InitializeVariables();
	this->InitializeComponents();
	this->pRectShape.setPosition(this->pPosition);
    this->windowPtr = windowPtr;
    createPlater();
}

Player::~Player()
{
}

void Player::update()
{
	this->move();


    //GRAWITACJA

    if (this->pRectShape.getPosition().y < 720 - 32 && !colision)
    {
        this->pRectShape.move(0, 5.f);
    }
    if (this->pRectShape.getPosition().y < 720 - 32 && colision)
    {
        this->pRectShape.move(0, 0.f);
    }
}

void Player::render()
{
    windowPtr->draw(this->pRectShape);
	//this->drawPlayer(this->pTexture);
}

void Player::drawPlayer(sf::Texture texture)
{
	this->pTexture = sf::Texture();
	this->pSprite = sf::Sprite(this->pTexture);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->pRectShape.move(- this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->pRectShape.move(+ this->movementSpeed, 0.f);
	}
    this->pPosition = this->pRectShape.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->pRectShape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->pRectShape.move(0.f, + this->movementSpeed);
	}
    this->pPosition = this->pRectShape.getPosition();
}

Player* Player::getPtr()
{
	return this;
}

void Player::createPlater()
{
    this->pRectShape = sf::RectangleShape(this->pSize);
    this->pRectShape.setPosition(this->pPosition);
    this->pRectShape.setFillColor(sf::Color::Blue);
}

sf::RectangleShape *Player::playerPtr() {
    return &pRectShape;
}
