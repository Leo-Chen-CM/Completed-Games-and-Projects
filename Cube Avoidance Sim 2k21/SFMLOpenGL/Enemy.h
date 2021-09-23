#pragma once
#include <GameObject.h>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Enemy
{
public:
	Enemy();
	void draw(GLint x_offsetID, GLint y_offsetID, GLint z_offsetID);
	void updateNPC(float t_playerXPosition);
	GameObject getEnemyObject();
private:
	GameObject* enemy_object;
	vec3 movementSpeed = vec3(0.0f, 0.0f, 0.9f);
	bool changePositivity = false;
};

