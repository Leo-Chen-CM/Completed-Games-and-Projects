#include "Player.h"

Player::Player()
{
	player_object = new GameObject;
	player_object->setPosition(vec3(0.5f, 0.8f, 4.0f));
}

void Player::draw(GLint x_offsetID, GLint y_offsetID, GLint z_offsetID)
{
	glUniform1f(x_offsetID, player_object->getPosition().x);
	glUniform1f(y_offsetID, player_object->getPosition().y);
	glUniform1f(z_offsetID, player_object->getPosition().z);
	glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, NULL);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		player_object->setPosition(player_object->getPosition() + (-movementSpeed));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player_object->setPosition(player_object->getPosition() + (movementSpeed));
	}
}

GameObject Player::getPlayerObject()
{
	return *player_object;
}

vec3 Player::getPlayerPosition()
{
	return player_object->getPosition();
}
