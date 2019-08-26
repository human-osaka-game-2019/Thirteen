#include <SoundsManager.h>
#include <tchar.h>

SoundLib::SoundsManager soundsManager;


// 初期化
// SoundsManagerインスタンス生成後に1度のみ行う。


bool isSuccess = soundsManager.Initialize();


// 音声ファイルオープン
// 第2引数は音声ファイルを識別するための任意の文字列をキーとして指定する。
// この後の操作関数の呼び出し時には、ここで設定したキーを指定して音声を識別する。

const TCHAR* filePath = _T("音楽ファイル");
isSuccess = soundsManager.AddFile(filePath, _T("bgm"));



// 頭から再生
// 一時停止中の音声に対して当関数を実行した場合も頭からの再生となる。
// 第2引数にtrueを渡すとループ再生になる。
isSuccess = soundsManager.Start(_T("bgm"), true);

// 一時停止
isSuccess = soundsManager.Pause(_T("bgm"));

// 一時停止中の音声を続きから再生
isSuccess = soundsManager.Resume(_T("bgm"));

// 再生停止
isSuccess = soundsManager.Stop(_T("bgm"));

// 再生状態を取得
SoundLib::PlayingStatus status = soundsManager.GetStatus(_T("bgm"));


/// <summary>
/// 再生状況を示すステータス
/// </summary>
enum PlayingStatus {
	/// <summary>停止中</summary>
	Stopped,
	/// <summary>再生中</summary>
	Playing,
	/// <summary>一時停止中</summary>
	Pausing
};



//　ボリューム変更
// 0(無音)～100(原音量)の間で設定可能
soundsManager.SetVolume(_T("bgm"), 50);

// ボリューム取得
uint8_t volume = soundsManager.GetVolume(_T("bgm"));



// 再生速度・ピッチ変更
isSuccess = soundsManager.SetFrequencyRatio(_T("bgm"), 1.0f);

// 再生速度・ピッチ取得
float ratio = soundsManager.GetFrequencyRatio(_T("bgm"));



class Foo {
public:
	void Play() {
		bool isSuccess = soundsManager.Start(_T("bgm"), this);
	}

	void OnPlayedToEnd(std::basic_string<TCHAR> key) {
		// 再生終了後に行う処理
	}
};