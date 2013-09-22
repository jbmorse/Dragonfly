/*
 * GameManager.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

//Game engine header files
#include "Manager.h"

//Misc required headers
#include "time.h"

#define DEFAULT_FRAME_TIME 33 //Measured in milliseconds

class GameManager : public Manager {

private:
	GameManager();							//Private (singleton)
	GameManager(GameManager const&);		//No copying
	void operator=(GameManager const&);		//No assignment
	bool game_over;							//If true, game should stop
	int frame_time;							//Target time for game loop (ms)

public:
	~GameManager();							//Destructor
	static GameManager &getInstance();		//Get singleton
	int startUp();							//Start all game manager services
	int startUp(bool flush);				//If true, call fflush after each write
	void shutDown();						//Shut down game manager services
	void run(int fr_time=DEFAULT_FRAME_TIME);//Run the game loop
	void setGameOver();						//Set game_over to true
	void setGameOver(bool new_game_over);	//Set game over status
	int getFrameTime();						//Return frame time
	bool isValid(string event_name);		//Accepts game manager events

};

#endif /* GAMEMANAGER_H_ */
