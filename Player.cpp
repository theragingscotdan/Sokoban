// project includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Player::Player()
	: GridObject()
	, m_pendingMove(0,0)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));
};

void Player::Input(sf::Event _gameEvent)
{
	// read the input from the keyboard and convert it
	// to a direction to move in (and then move)

	// was the event a key press?
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		// yes it was a key press!

		// what key was pressed?

		if (_gameEvent.key.code == sf::Keyboard::W)
		{
			// it was W!
			// Move up
			m_pendingMove = sf::Vector2i(0, -1);
			
		}
		else if (_gameEvent.key.code == sf::Keyboard::A)
		{
			// it was A!
			// Move left
			m_pendingMove = (sf::Vector2i(-1, 0));
		}
		else if (_gameEvent.key.code == sf::Keyboard::S)
		{
			// it was S!
			// Move right
			m_pendingMove = (sf::Vector2i(0, 1));
		}
		else if (_gameEvent.key.code == sf::Keyboard::D)
		{
			// it was D!
			// Move down
			m_pendingMove = (sf::Vector2i(1, 0));
		}
	}
}

void Player::Update(sf::Time _frameTime)
{
	// If we have movement waiting to be processed,
	
	if (m_pendingMove.x != 0 || m_pendingMove.y != 0)
	{
		// move in that direction
		AttemptMove(m_pendingMove);

		// and clear the pending movement
		m_pendingMove = sf::Vector2i(0, 0);


	}
}

bool Player::AttemptMove(sf::Vector2i _direction)
{
	// Attempting to move in the given direction

	// Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	// TODO: check if the space is empty

	// If empty, move there
	return m_level->MoveObjectTo(this, targetPos);
}