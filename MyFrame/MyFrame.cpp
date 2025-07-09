#include "MyFrame.hpp"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Sample App") {
    // メインメニューの作成
    menuBar = new wxMenuBar;
    menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT, "Quit"); // wxID_EXIT のような定義済みIDはプラットフォームによって扱いが変わる。例えば、 Mac ではアプリケーションメニューの Quit と統合される。
    menuBar->Append(menuFile, "File");
    SetMenuBar(menuBar);

    panel = new wxPanel(this, wxID_ANY);

    vbox  = new wxBoxSizer(wxVERTICAL);
    hbox = new wxBoxSizer(wxHORIZONTAL);
    panel->SetSizer(vbox);

    st1 = new wxStaticText(panel, wxID_ANY, "StaticText");
    tc = new wxTextCtrl(panel, wxID_ANY);
    
    hbox->Add(st1, 0, wxLEFT);
    hbox->Add(tc, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTER, 10);
    vbox->Add(-1, 10);

    // イベントハンドラーの登録
    // 自身のメンバー関数を登録する場合：
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
    // 無名関数で直接記述する場合：
    Bind(wxEVT_MENU, [this](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

MyFrame::~MyFrame() {

}

// wxEVT_CLOSE_WINDOW はウィンドウが閉じられようとしていた場合に呼ばれる。
// 実装しなかった場合は単に Destroy() が呼ばれる。
void MyFrame::OnClose(wxCloseEvent& event) {
    Destroy();
}