#include "GameClear.h"
#include "Texture.h"
#include "Input.h"

// タイトルシーンの初期化
void InitGameClear();
// タイトルシーンのメイン処理
void MainGameClear();
// タイトルシーンの終了
SceneId FinishGameClear();

static class GameClear gameClear;

SceneId GameClear::UpdateGameClear()
{
	switch (scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameClear();
		break;
	case SceneStep::MainStep:
		MainGameClear();
		break;
	case SceneStep::EndStep:
		return FinishGameClear();
		break;
	}

	return SceneId::Title;
}

void GameClear::DrawGameClear()
{
	// 描画処理

}

void InitGameClear()
{
	// 描画準備


	gameClear.scene.ChangeSceneStep(SceneStep::MainStep);
}

void MainGameClear()
{
	// ゲーム処理


	gameClear.scene.ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishGameClear()
{
	// リリース開放


	return SceneId::Result;
}