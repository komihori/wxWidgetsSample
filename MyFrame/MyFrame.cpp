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
    hbox2 = new wxBoxSizer(wxHORIZONTAL);
    hbox3 = new wxBoxSizer(wxHORIZONTAL);
    panel->SetSizer(vbox);

    staticText1 = new wxStaticText(panel, wxID_ANY, "HexText");
    tc = new wxTextCtrl(panel, wxID_ANY);

    button = new wxButton(panel, wxID_ANY, "Button");
    button->Bind(wxEVT_BUTTON, &MyFrame::OnClick, this);
    

    hbox->Add(staticText1, 0, wxLEFT);
    hbox->Add(tc, 1);
    vbox->Add(hbox, 0, wxALIGN_LEFT, 10);
    hbox2->Add(button, 1, wxALIGN_LEFT, 10);
    vbox->Add(hbox2, 1, wxALIGN_LEFT, 10);

    vbox->Add(-1, 10);

    // イベントハンドラーの登録.
    // 自身のメンバー関数を登録する場合.
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
    // 無名関数で直接記述する場合.
    Bind(wxEVT_MENU, [this](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

MyFrame::~MyFrame() {

}

void MyFrame::OnClick(wxCommandEvent &e){
    wxString tcText = tc->GetValue().ToStdString();
    staticText1->SetLabel(tcText);
}

// wxEVT_CLOSE_WINDOW はウィンドウが閉じられようとしていた場合に呼ばれる.
// 実装しなかった場合は単に Destroy() が呼ばれる.
void MyFrame::OnClose(wxCloseEvent& event) {
    Destroy();
}