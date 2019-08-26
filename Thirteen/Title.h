#ifndef TITLE_H_
#define TITLE_H_

#include "SceneSwitch.h"

class Title
{
public:
	Scene scene;
	SceneId UpdateTitle();
	void DrawTitle();
};

#endif