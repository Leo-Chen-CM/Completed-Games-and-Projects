#include "Enemy.h"

Enemy::Enemy()
{

	enemy_object = new GameObject;
	srand((unsigned int)time(NULL));
	int randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (50)));
	float randomZ = rand() % 150 + 101;

	enemy_object->setPosition(vec3(randomX, 0.8f, -randomZ));
}

void Enemy::draw(GLint x_offsetID, GLint y_offsetID, GLint z_offsetID)
{
	glUniform1f(x_offsetID, enemy_object->getPosition().x);
	glUniform1f(y_offsetID, enemy_object->getPosition().y);
	glUniform1f(z_offsetID, enemy_object->getPosition().z);
	glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, NULL);
}

void Enemy::updateNPC(float t_playerXPosition)
{
	enemy_object->setPosition(enemy_object->getPosition() + movementSpeed);

	if (enemy_object->getPosition().z >= 60)
	{
		int randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (50)));
		float randomZ = rand() % 150 + 101;

		if (changePositivity == false)
		{
			enemy_object->setPosition(vec3(randomX + t_playerXPosition, 0.8f, -randomZ));
			changePositivity = true;
		}
		else
		{
			enemy_object->setPosition(vec3(-randomX + t_playerXPosition, 0.8f, -randomZ));
			changePositivity = false;
		}

	}
}

GameObject Enemy::getEnemyObject()
{
	return *enemy_object;
}

