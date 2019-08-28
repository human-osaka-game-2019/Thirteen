#pragma once
#ifndef SCENESWITCH_H_
#define SCENESWITCH_H_

enum SceneId
{
	Title,
	GameScene,
	GameClear,
	Result,
	SceneIdMax
};

enum SceneStep
{
	InitStep,
	MainStep,
	EndStep
};

class Scene
{
public:
	// シーンID取得関数
	SceneId GetCurrentSceneId();

	// シーンステップ取得関数
	SceneStep GetCurrentSceneStep();

	// 指定したステップに切り替える
	void ChangeSceneStep(SceneStep next_step);

	// シーン処理の実行
	void UpdateScene();

	// シーンオブジェクトの描画
	void DrawScene();
};

#endif