// project includes
#include "Box.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Box::Box()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
	m_blocksMovement = true;
}

bool Box::AttemptPush(sf::Vector2i _direction)
{
	// attempt to move the box in the given direction

	// Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	// check if the space is empty
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);

	// Check if any of those objects block movement
	bool blocked = false;
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->GetBlocksMovement() == true)
		{
			blocked = true;
			
		}

	}
	if (blocked == false)
		return m_level->MoveObjectTo(this, targetPos);
}