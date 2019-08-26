#ifndef GAMECLEAR_H_
#define GAMECLEAR_H_

#include "SceneSwitch.h"

class GameClear
{
public:
	Scene scene;
	SceneId UpdateGameClear();
	void DrawGameClear();
};

#endif