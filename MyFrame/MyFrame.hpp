#pragma once
#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame();
    virtual ~MyFrame();

    void OnClose(wxCloseEvent& event);

private:
    wxMenuBar* menuBar;
    wxMenu* menuFile;
    wxPanel* panel;
    wxBoxSizer* vbox;
    wxBoxSizer* hbox;
    wxBoxSizer* hbox2;
    wxBoxSizer* hbox3;
    wxStaticText* staticText1;
    wxTextCtrl* tc;
    wxButton* button;

    void OnClick(wxCommandEvent&);

};