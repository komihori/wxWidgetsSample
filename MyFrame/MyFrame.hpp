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
    wxStaticText* st1;
    wxTextCtrl* tc;
    wxButton* button;

    void OnClick(wxCommandEvent&);

};