#include "Title.h"
#include "Texture.h"
#include "Input.h"

// タイトルシーンの初期化
void InitTitle();
// タイトルシーンのメイン処理
void MainTitle();
// タイトルシーンの終了
SceneId FinishTitle();

static class Title title;

SceneId Title::UpdateTitle()
{
	switch (scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitTitle();
		break;
	case SceneStep::MainStep:
		MainTitle();
		break;
	case SceneStep::EndStep:
		return FinishTitle();
		break;
	}

	return SceneId::Title;
}

void Title::DrawTitle()
{
	// 描画処理

}

void InitTitle()
{
	// 描画準備


	title.scene.ChangeSceneStep(SceneStep::MainStep);
}

void MainTitle()
{
	// ゲーム処理


	title.scene.ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishTitle()
{
	// リリース開放


	return SceneId::GameScene;
}