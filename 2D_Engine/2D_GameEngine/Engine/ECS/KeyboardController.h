#pragma once

#include "../../Game.h"
#include "ECS.h"
#include "Components.h"

class keyboardController : public Component
{
public:
	TransformComponent *transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	Uint32 startTime;
	int currentTime;

	void update() override
	{
		/*
		// This section is crazy broken but works for now
		startTime = SDL_GetTicks();
		currentTime = SDL_GetTicks() - currentTime;
		if (100 > currentTime) return;
		*/

		int x = transform->position.x;
		int y = transform->position.y;
		if (y % 64 != 0 && x % 64 != 0) return;
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_KP_9:
				transform->velocity.y = -1;
				transform->velocity.x = +1;
				break;
			case SDLK_KP_8:
				transform->velocity.y = -1;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_7:
				transform->velocity.y = -1;
				transform->velocity.x = -1;
				break;
			case SDLK_KP_6:
				transform->velocity.y = 0;
				transform->velocity.x = +1;
				break;
			case SDLK_KP_5:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_4:
				transform->velocity.y = 0;
				transform->velocity.x = -1;
				break;
			case SDLK_KP_3:
				transform->velocity.y = +1;
				transform->velocity.x = +1;
				break;
			case SDLK_KP_2:
				transform->velocity.y = +1;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_1:
				transform->velocity.y = +1;
				transform->velocity.x = -1;
				break;
			}
		}
		/*
		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_KP_9:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_8:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_7:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_6:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_5:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_4:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_3:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_2:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			case SDLK_KP_1:
				transform->velocity.y = 0;
				transform->velocity.x = 0;
				break;
			}
		}*/
	}
};