#include "Result.h"
#include "Texture.h"
#include "Input.h"

// タイトルシーンの初期化
void InitResult();
// タイトルシーンのメイン処理
void MainResult();
// タイトルシーンの終了
SceneId FinishResult();

static class Result result;

SceneId Result::UpdateResult()
{
	switch (scene.GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitResult();
		break;
	case SceneStep::MainStep:
		MainResult();
		break;
	case SceneStep::EndStep:
		return FinishResult();
		break;
	}

	return SceneId::Title;
}

void Result::DrawResult()
{
	// 描画処理

}

void InitResult()
{
	// 描画準備

	result.scene.ChangeSceneStep(SceneStep::MainStep);
}

void MainResult()
{
	// ゲーム処理


	result.scene.ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishResult()
{
	// リリース開放


	return SceneId::Title;
}