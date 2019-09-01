#include "Sound.h"

using namespace SoundLib;

const TCHAR* filePath = _T("Sound/MenuPick.wav");


bool SoundPlay::SoundState()
{
	m_soundsManager.AddFile("Sound/MenuPick.wav", _T("SE")); // Or BGM

	m_soundsManager.Start(_T("SE"), true); // Or BGM

	m_soundsManager.Stop(_T("bgm")); // Or BGM

	return 0;

}

// �Đ���Ԃ�擾
SoundLib::PlayingStatus status = m_soundsManager.GetStatus(_T("bgm"));

/// �Đ��󋵂���X�e�[�^�X
enum SoundStatus 
{

	/// <summary>��~��</summary>
	Stopped,
	/// <summary>�Đ���</summary>
	Playing,
	/// <summary>�ꎞ��~��</summary>
	Pausing

};


bool SoundVolume::VolumeSet()
{

	//Volume Setting ( 0(����) ~ 100(������) )
	m_soundsManager.SetVolume(_T("bgm"), 50);

	//Volume ����
	m_soundsManager.GetVolume(_T("bgm"));

	return 0;

}

float SoundPitch::SoundRatio()
{

	//Sound Speed ����
	m_soundsManager.SetFrequencyRatio(_T("bgm"), 1.0f);

	//Sound Speed ��
	m_soundsManager.GetFrequencyRatio(_T("bgm"));

	return 0;

}

