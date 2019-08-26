#ifndef MAINTGAME_H_
#define GameScene_H_

#include "SceneSwitch.h"

class GameScene
{
public:
	Scene scene;
	SceneId UpdateGameScene();
	void DrawGameScene();
};

#endif