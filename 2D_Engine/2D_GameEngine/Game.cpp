#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

#undef main

GameObject* player;
GameObject* tileTex;
Map* map;

SDL_Texture* playerTex;


SDL_Rect tileR;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() 
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else isRunning = false;

	player = new GameObject("assets/char.png", 0, 0);
	map = new Map();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

bool walkRight = true;

Uint32 lastMoveTime;
int timePassed;

int counterNum = 0;

void Game::update()
{
	player->Update();

	counterNum++;

	/*
	lastMoveTime = SDL_GetTicks();
	timePassed = SDL_GetTicks() - lastMoveTime;

	std::cout << "Last Move: " << lastMoveTime << ": timePassed:" << timePassed << std::endl;

	if (lastMoveTime > timePassed)
	{
		SDL_Delay(500 - timePassed);
	}

	if (walkRight)
	{
		destR.x = destR.x + 64;
		destR.y = 100;
		
		if (destR.x > 600)
		{
			walkRight = false;
		}
	}
	else
	{
		destR.x = destR.x - 64;
		destR.y = 100;

		if (destR.x < 100)
		{
			walkRight = true;
		}
	}


	destR.h = 64;
	destR.w = 64;

	tileR.h = 64;
	tileR.w = 64;


	//std::cout << counterNum << std::endl;
	*/

	std::cout << counterNum << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->DrawMap();

	player->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned up game";
}