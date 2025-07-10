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

    wxStaticText* staticText1;
    wxTextCtrl* tc;
    wxButton* button;

    void OnClick(wxCommandEvent&);

};