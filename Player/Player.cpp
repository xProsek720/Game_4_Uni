#include "../includes/imports.h"
#include "Player.h"

void Player::InitializeVariables()
{
	this->pPosition.x = 10.f;
	this->pPosition.y = 0.f;
	this->movementSpeed = 1.2f;
}

void Player::InitializeComponents()
{
}

Player::Player(Walls* wallPtr)
{
	this->InitializeVariables();
	this->InitializeComponents();
	this->pRectShape.setPosition(this->pPosition);
}

Player::~Player()
{
}

void Player::update()
{
	this->move();
}

void Player::render()
{
	this->drawPlayer(this->pTexture);
}

void Player::drawPlayer(sf::Texture* texture)
{
	this->pTexture = texture;
	this->pSprite = new sf::Sprite(*this->pTexture);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->pRectShape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->pRectShape.move(this->movementSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->pRectShape.move(0.f, this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->pRectShape.move(0.f, -this->movementSpeed);
	}
}

Player* Player::getPtr()
{
	return this;
}
