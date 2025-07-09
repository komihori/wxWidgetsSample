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
    wxStaticText* st1;
    wxTextCtrl* tc;

};