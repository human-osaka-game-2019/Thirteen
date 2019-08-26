#include "SceneSwitch.h"
#include "Title.h"
#include "GameScene.h"
#include "GameClear.h"
#include "Result.h"

static SceneId g_CurrentSceneId = SceneId::Title;						// 動作中シーンID
static SceneStep g_CurrentSceneStep = SceneStep::InitStep;		// 動作中シーンステップ

SceneId Scene::GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep Scene::GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void Scene::ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}

void Scene::UpdateScene()
{
	SceneId scene_id = g_CurrentSceneId;
	switch (g_CurrentSceneId)
	{
	case SceneId::Title:
		class Title title;
		scene_id = title.UpdateTitle();
		break;
	case SceneId::GameScene:
		class GameScene gameScene;
		scene_id = gameScene.UpdateGameScene();
		break;
	case SceneId::GameClear:
		class GameClear gameClear;
		scene_id = gameClear.UpdateGameClear();
	case SceneId::Result:
		class Result result;
		scene_id = result.UpdateResult();
	}

	DrawScene();

	if (scene_id != g_CurrentSceneId)
	{
		g_CurrentSceneId = scene_id;
		ChangeSceneStep(SceneStep::InitStep);
	}
}

void Scene::DrawScene()
{


}