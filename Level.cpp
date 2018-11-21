// project includes
#include "Level.h"
#include "Framework/AssetManager.h"

// library includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_cellSize(64.0f)
	, m_currentLevel(0)
	, m_background()
	
{
	LoadLevel(1);
}
void Level::Draw(sf::RenderTarget& _target)
{
	// Create and update camera
	sf::View camera = _target.getDefaultView();

	// Adjust camera as needed
	camera.setCenter(m_background[0].size() * m_cellSize / 2 ,m_background.size() * m_cellSize / 2 );
	
	// Draw game world to the window
	_target.setView(camera);
	// TODO: Draw game objects
	for (int y = 0; y < m_background.size(); ++y)
	{
		for (int x = 0; x < m_background[y].size(); ++x)
		{
			_target.draw(m_background[y][x]);
		}
	}
	
	// Reset view
	_target.setView(_target.getDefaultView());

}
void Level::Update(sf::Time _frameTime)
{
		
	// TODO
	
}

void Level::LoadLevel(int _levelToLoad)
{
	// clean up the old level

	// delete any data already in the level
	// TODO

	// clear out our lists
	m_background.clear();


	// set the current level
	m_currentLevel = _levelToLoad;

	// set up the new level

	// Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	// make sure the file was open
	if (!inFile)
	{
		std::cerr << "Unable to open file" + fileName;
		exit(1); // call system to stop program with error
	}

	// set the starting x and y coordinates used to position level objects
	int x = 0;
	int y = 0;

	// create the first row in our grid
	m_background.push_back(std::vector<sf::Sprite>());

	
	// read each character one by one from the file
	char ch;
	// each time, try to read the next character
	// if sucessful, execute body of loop
	// the "noskipws" means our input from file will include
	// the white space (space and new lines)

	while (inFile >> std::noskipws >> ch)
	{
		// perform actions based on what character was read in

		if (ch == ' ')
		{
			++x;
		}
		else if (ch == '\n')
		{
			++y;
			x = 0;

			// create a new row in our grid
			m_background.push_back(std::vector<sf::Sprite>());


		}
		else
		{
			// this is going to be some object or empty space
			// create background sprite
			m_background[y].push_back(sf::Sprite(AssetManager::GetTexture("graphics/ground.png")));
			m_background[y][x].setPosition(x*m_cellSize, y*m_cellSize);

			if (ch == '-')
			{
				// do no - empty space
			}
			else
			{
				std::cerr << "Unrecognised character in level file: " << ch;
			}
		}


	}

	// close the file now that we are done with it
	inFile.close();
			
	
	// score - position not dependant on level
	
}

void Level::ReloadLevel()
{
	LoadLevel(m_currentLevel);
}

void Level::LoadNextLevel()
{
	LoadLevel(m_currentLevel + 1);
}