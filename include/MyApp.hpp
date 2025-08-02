#pragma once
#include <wx/wx.h>

// アプリケーションについての挙動を管理するシングルトンクラス。
// 具体的には、初期化処理、メインループの管理など。
class MyApp : public wxApp {
    virtual bool OnInit() override;
};

// wxGetApp 関数を宣言する（後述）
wxDECLARE_APP(MyApp);