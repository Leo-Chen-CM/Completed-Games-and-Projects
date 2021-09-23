#pragma once
#include <GameObject.h>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <string>
class Player
{
public:
	Player();
	void draw(GLint x_offsetID, GLint y_offsetID, GLint z_offsetID);
	void move();
	GameObject getPlayerObject();
	vec3 getPlayerPosition();

private:
	GameObject* player_object;
	vec3 movementSpeed = vec3(0.3f, 0.0f, 0.0f);
};

