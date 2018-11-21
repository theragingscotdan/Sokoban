#pragma once

// library includes 
#include <SFML/Graphics.hpp>

// project includes
#include "GridObject.h"

class Level
{

public:

	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);

	void LoadLevel(int _levelToLoad);
	void ReloadLevel();
	void LoadNextLevel();

	float GetCellSize();

private:

	const float m_cellSize;
	int m_currentLevel;
	std::vector< std::vector< sf::Sprite > > m_background;
	std::vector< std::vector< std::vector< GridObject* > >  > m_contents;
	

};