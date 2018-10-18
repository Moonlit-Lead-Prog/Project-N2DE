#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Components.h"

#undef main

GameObject* player;
GameObject* tileTex;
Map* map;

SDL_Texture* playerTex;


SDL_Rect tileR;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

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

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);
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
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << 
		newPlayer.getComponent<PositionComponent>().y() << std::endl;
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