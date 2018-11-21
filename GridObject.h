#pragma once

// project includes
#include "Framework/SpriteObject.h"

// forward declaration
// (only works with pointers/references)
class Level;

class GridObject : public SpriteObject
{


public:

	GridObject();

	void setGridPosition(sf::Vector2i _newPosition);
	void setGridPosition(int _x, int _y);
	
	void SetLevel(Level* _newLevel);


private:

	sf::Vector2i m_gridPosition;
	Level* m_level;

};