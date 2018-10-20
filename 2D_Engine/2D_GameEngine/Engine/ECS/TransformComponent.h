#pragma once

#include "Components.h"
#include "../Additions/Vector2.h"

class TransformComponent : public Component
{
public:

	Vector2 position;
	Vector2 velocity;

	int speed = 1;

	TransformComponent()
	{
		position.x = 64.0f;
		position.y = 64.0f;
	}

	TransformComponent(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;

		int x = position.x;
		int y = position.y;

		int temp = x % 64;

		std::cout << x % 64 << std::endl;
		if (y % 64 == 0 && x % 64 == 0)
		{
			velocity.x = 0;
			velocity.y = 0;
		}
	}

};