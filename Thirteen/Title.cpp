#include "Title.h"
#include "Texture.h"
#include "Input.h"

// �^�C�g���V�[���̏�����
void InitTitle();
// �^�C�g���V�[���̃��C������
void MainTitle();
// �^�C�g���V�[���̏I��
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
	// �`�揈��

}

void InitTitle()
{
	// �`�揀��


	title.scene.ChangeSceneStep(SceneStep::MainStep);
}

void MainTitle()
{
	// �Q�[������


	title.scene.ChangeSceneStep(SceneStep::EndStep);
}

SceneId FinishTitle()
{
	// �����[�X�J��


	return SceneId::GameScene;
}