// project includes
#include "Box.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Storage.h"

Box::Box()
	: GridObject()
	, m_stored(false)
	, m_storeSound()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
	m_storeSound.setBuffer(AssetManager::GetSoundBuffer("audio/stored.wav"));
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
	{
		bool moveSucceeded = m_level->MoveObjectTo(this, targetPos);
		
		// if we DID move successfully..
		if (moveSucceeded == true)
		{
			// check if we are stored

			// assume we are not stored to start
			m_stored = false;

			// loop through the contents and see if a storage object was found
			for (int i = 0; i < targetCellContents.size(); ++i)
			{
				// check if this element in the vector is a Storage object
				// by doing a dynamic cast
				Storage* storageObject = dynamic_cast<Storage*>(targetCellContents[i]);

				// if dynamic cast succeeds, it will NOT be a nullptr
				// aka, the object IS a storage object
				if (storageObject != nullptr)
				{
					// the object IS a storage object!

					// we are stored!
					m_stored = true;
				}
			}

			// and change our sprite
			if (m_stored)
			{
				m_sprite.setTexture(AssetManager::GetTexture("graphics/boxStored.png"));
				m_storeSound.play();
			}
			else
			{
				m_sprite.setTexture(AssetManager::GetTexture("graphics/box.png"));
			}

		}

		return moveSucceeded;
	}
}