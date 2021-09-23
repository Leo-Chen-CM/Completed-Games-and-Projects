#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>
#include <time.h>
#include "Player.h"
#include "Enemy.h"

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:

	sf::Music m_gameMusic;
	Player* thePlayer;
	static const int MAXIMUMCUBES = 50;
	Enemy* theEnemies[MAXIMUMCUBES];
	RenderWindow window;
	Clock clock;
	Time time;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	vec3 move = vec3(0.3f, 0.0f, 0.0f);
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void processButtons();
	void printLocations();
	bool collisionDetection(GameObject& one, GameObject& two);
	void distanceTracker();
	int distance = 0;
	string distanceString;
	Text distanceText;
	float xAxis = 0.0f;

	bool gameActive = true;

	//Player image data
	unsigned char* playerImgData;
	const string playerFileName = ".//Assets//Textures//texture_2.tga";


};

#endif  // ! GAME_H