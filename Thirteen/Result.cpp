#include "Result.h"
#include "Texture.h"
#include "Input.h"

// �^�C�g���V�[���̏�����
void InitResult();
// �^�C�g���V�[���̃��C������
void MainResult();
// �^�C�g���V�[���̏I��
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
	// �`�揈��

}

void InitResult()
{
	// �`�揀��

	result.scene.ChangeSceneStep(SceneStep::MainStep);
}

void MainResult()
{
	// �Q�[������


	result.scene.ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishResult()
{
	// �����[�X�J��


	return SceneId::Title;
}