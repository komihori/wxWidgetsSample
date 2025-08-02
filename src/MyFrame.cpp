#include "../include/MyFrame.hpp"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Sample App")/*, timer(this)*/ {
    // メインメニューの作成
    menuBar = new wxMenuBar;
    menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT, "Quit"); // wxID_EXIT のような定義済みIDはプラットフォームによって扱いが変わる。例えば、 Mac ではアプリケーションメニューの Quit と統合される。
    menuBar->Append(menuFile, "File");
    SetMenuBar(menuBar);

//	Bind(wxEVT_TIMER, &MyFrame::OnTimer, this, timer.GetId());
//	timer.Start(10);
    panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vBoxSizer = new wxBoxSizer(wxVERTICAL);

    staticText1 = new wxStaticText(panel, wxID_ANY, "HexText");
    tc = new wxTextCtrl(panel, wxID_ANY);

    button = new wxButton(panel, wxID_ANY, "Button");
    button->Bind(wxEVT_BUTTON, &MyFrame::OnClick, this);

    vBoxSizer->Add(staticText1);
    vBoxSizer->Add(tc);
    vBoxSizer->Add(button);
    
    panel->SetSizer(vBoxSizer);

	Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame::OnPaintLine));

    // イベントハンドラーの登録.
    // 自身のメンバー関数を登録する場合.
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);
    // 無名関数で直接記述する場合.
    Bind(wxEVT_MENU, [this](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

MyFrame::~MyFrame() {

}

//void MyFrame::OnTimer(wxTimerEvent &e){
	
//}

void MyFrame::OnClick(wxCommandEvent &e){
    std::string tcText = tc->GetValue().ToStdString();
	deltaY = std::stoi(tcText);
    //staticText1->SetLabel(tcText);
    tc->SetValue("");
	Refresh();
//	lineDC->DrawLine(20, 100, 380, 40);
}

void MyFrame::OnPaintLine(wxPaintEvent &e){
	lineDC = new wxPaintDC(this);
    lineDC->SetPen(wxPen(wxColour("yellow"),   1, wxSOLID));
    lineDC->DrawLine(xPos, yPos, xPos + deltaX, yPos + deltaY);
	//lineDC = dc;
}

// wxEVT_CLOSE_WINDOW はウィンドウが閉じられようとしていた場合に呼ばれる.
// 実装しなかった場合は単に Destroy() が呼ばれる.
void MyFrame::OnClose(wxCloseEvent& event) {
    Destroy();
}
