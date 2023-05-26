//
// Created by Davesooon on 25.05.2023.
//

#ifndef GANE_4_UNI_IML_PLAYER_H
#define GANE_4_UNI_IML_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Player {

private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	sf::Vector2f pPosition;
	sf::Vector2f pSize;
	sf::RenderWindow* windowPtr;
	void InitializeVariables();
	void InitializeComponents();

public:
    bool colision = true;
    float movementSpeed;
    sf::RectangleShape pRectShape;
	Player(Walls* wallPtr, sf::RenderWindow* windowPtr);
	~Player();
    friend Block;
	void update();
	void render();
	void drawPlayer(sf::Texture texture);
	void move();
	Player* getPtr();
    void createPlater();
    sf::RectangleShape* playerPtr();

};

#endif // !GANE_4_UNI_IML_PLAYER_H

