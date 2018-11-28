#pragma once

// project includes
#include "GridObject.h"

class Player : public GridObject
{

public:
	Player();

	
	// overriding Methods
	virtual void Input(sf::Event _gameEvent);

private:

	bool AttemptMove(sf::Vector2i _direction);

};