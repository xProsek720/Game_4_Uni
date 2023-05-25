//
// Created by Davesooon on 25.05.2023.
//

#ifndef GANE_4_UNI_IML_PLAYER_H
#define GANE_4_UNI_IML_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>

class Player {

private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	sf::Vector2f pPosition;
	sf::Vector2f pSize;
	sf::RectangleShape pRectShape;
	float movementSpeed;

	void InitializeVariables();
	void InitializeComponents();

public:
	Player(Walls* wallPtr);
	virtual ~Player();

	void update();
	void render();
	void drawPlayer(sf::Texture* texture);
	void move();
	Player* getPtr();
};

#endif // !GANE_4_UNI_IML_PLAYER_H

