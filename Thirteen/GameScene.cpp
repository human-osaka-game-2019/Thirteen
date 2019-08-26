#include "GameScene.h"
#include "Texture.h"
#include "Input.h"

// タイトルシーンの初期化
void InitGameScene();
// タイトルシーンのメイン処理
void MainGameScene();
// タイトルシーンの終了
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
	// 描画処理

}

void InitGameScene()
{
	// 描画準備

}

void MainGameScene()
{
	// ゲーム処理

}

SceneId FinishGameScene()
{
	// リリース開放

}