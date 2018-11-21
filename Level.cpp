// project includes
#include "Level.h"


// library includes
#include <iostream>
#include <fstream>

Level::Level()
	: m_currentLevel(0)

{
	LoadLevel(1);
}
void Level::Draw(sf::RenderTarget& _target)
{
	// Create and update camera
	sf::View camera = _target.getDefaultView();
	// TODO: Adjust camera as needed
	
	// Draw game world to the window
	_target.setView(camera);
	// TODO: Draw game objects

	
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
	// TODO

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
	float x = 0.0f;
	float y = 0.0f;

	// Define the spacng we will use for our grid
	const float X_SPACE = 100.0f;
	const float Y_SPACE = 100.0f;

	// create the player first as other objects will need to reference it
	

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
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		
		else if (ch == '-')
		{
			// do no - empty space
		}
		else
		{
			std::cerr << "Unrecognised character in level file: " << ch;
		}
	}

	// close the file now that we are done with it
	inFile.close();

			
	/*Baddy* baddy = new Baddy();
	m_updateList.push_back(baddy);
	m_drawListWorld.push_back(baddy); */

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