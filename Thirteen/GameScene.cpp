<<<<<<< HEAD
ï»¿
=======
#include "GameScene.h"
#include "Texture.h"
#include "Input.h"

// ƒ^ƒCƒgƒ‹ƒV[ƒ“‚Ì‰Šú‰»
void InitGameScene();
// ƒ^ƒCƒgƒ‹ƒV[ƒ“‚ÌƒƒCƒ“ˆ—
void MainGameScene();
// ƒ^ƒCƒgƒ‹ƒV[ƒ“‚ÌI—¹
SceneId FinishGameScene();

SceneId GameScene::UpdateGameScene()
{
	switch (scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}

void GameScene::DrawGameScene()
{
	// •`‰æˆ—

}

void InitGameScene()
{
	// •`‰æ€”õ

}

void MainGameScene()
{
	// ƒQ[ƒ€ˆ—

}

SceneId FinishGameScene()
{
	// ƒŠƒŠ[ƒXŠJ•ú

}
>>>>>>> ddecbd2f9c32077f741ac9dbcb1816dd0e10d61d
