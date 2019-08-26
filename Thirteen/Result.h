#ifndef RESULT_H_
#define RESULT_H_

#include "SceneSwitch.h"

class Result
{
public:
	Scene scene;
	SceneId UpdateResult();
	void DrawResult();
};

#endif