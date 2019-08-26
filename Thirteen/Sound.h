#include <SoundsManager.h>
#include <tchar.h>

SoundLib::SoundsManager soundsManager;


// ������
// SoundsManager�C���X�^���X�������1�x�̂ݍs���B


bool isSuccess = soundsManager.Initialize();


// �����t�@�C���I�[�v��
// ��2�����͉����t�@�C�������ʂ��邽�߂̔C�ӂ̕�������L�[�Ƃ��Ďw�肷��B
// ���̌�̑���֐��̌Ăяo�����ɂ́A�����Őݒ肵���L�[���w�肵�ĉ��������ʂ���B

const TCHAR* filePath = _T("���y�t�@�C��");
isSuccess = soundsManager.AddFile(filePath, _T("bgm"));



// ������Đ�
// �ꎞ��~���̉����ɑ΂��ē��֐������s�����ꍇ��������̍Đ��ƂȂ�B
// ��2������true��n���ƃ��[�v�Đ��ɂȂ�B
isSuccess = soundsManager.Start(_T("bgm"), true);

// �ꎞ��~
isSuccess = soundsManager.Pause(_T("bgm"));

// �ꎞ��~���̉����𑱂�����Đ�
isSuccess = soundsManager.Resume(_T("bgm"));

// �Đ���~
isSuccess = soundsManager.Stop(_T("bgm"));

// �Đ���Ԃ��擾
SoundLib::PlayingStatus status = soundsManager.GetStatus(_T("bgm"));


/// <summary>
/// �Đ��󋵂������X�e�[�^�X
/// </summary>
enum PlayingStatus {
	/// <summary>��~��</summary>
	Stopped,
	/// <summary>�Đ���</summary>
	Playing,
	/// <summary>�ꎞ��~��</summary>
	Pausing
};



//�@�{�����[���ύX
// 0(����)�`100(������)�̊ԂŐݒ�\
soundsManager.SetVolume(_T("bgm"), 50);

// �{�����[���擾
uint8_t volume = soundsManager.GetVolume(_T("bgm"));



// �Đ����x�E�s�b�`�ύX
isSuccess = soundsManager.SetFrequencyRatio(_T("bgm"), 1.0f);

// �Đ����x�E�s�b�`�擾
float ratio = soundsManager.GetFrequencyRatio(_T("bgm"));



class Foo {
public:
	void Play() {
		bool isSuccess = soundsManager.Start(_T("bgm"), this);
	}

	void OnPlayedToEnd(std::basic_string<TCHAR> key) {
		// �Đ��I����ɍs������
	}
};