/*
 * Coding Project for IMGD 3000 completed by Joshua Morse
 */

#include "GameManager.h"
#include "Gamestart.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Star.h"
#include "stdlib.h"
#include "Utility.h"

void loadResources() {

	//Load sprites
	ResourceManager &resource_manager = ResourceManager::getInstance();
	resource_manager.loadSprite("sprites/saucer-spr.txt", "saucer");
	resource_manager.loadSprite("sprites/ship-spr.txt", "ship");
	resource_manager.loadSprite("sprites/bullet-spr.txt", "bullet");
	resource_manager.loadSprite("sprites/explosion-spr.txt", "explosion");
	resource_manager.loadSprite("sprites/gameover-spr.txt", "gameover");
	resource_manager.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	resource_manager.loadSprite("sprites/laser-spr.txt", "laser");

}

void populateWorld() {
	//Start the game
	new GameStart();
	LogManager &log_manager = LogManager::getInstance();
	log_manager.writeLog("Game Started!\n");
	//Create some stars
	for (int i=0; i<16; i++) {
		new Star;
	}

}

int main(int argc, char *argv[]) {
	LogManager &log_manager = LogManager::getInstance();

	//Start up Game Manager
    GameManager &game_manager = GameManager::getInstance();
    if (game_manager.startUp())  {
    	log_manager.writeLog("Error starting game manager!\n");
    	game_manager.shutDown();
    	exit(1);
    }


    //Set up the Game
    loadResources();
    log_manager.writeLog("Loaded Resources!\n");
    populateWorld();
    log_manager.writeLog("Populated world!\n");

    //Run the game!
    game_manager.run();

    //Shut everything down
    game_manager.shutDown();
}
