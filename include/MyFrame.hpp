#pragma once
#include <wx/wx.h>
#include <string>

class MyFrame : public wxFrame {
public:
    MyFrame();
    virtual ~MyFrame();

    void OnClose(wxCloseEvent& event);

private:
	//wxTimer timer;

    wxMenuBar* menuBar;
    wxMenu* menuFile;
    wxPanel* panel;

    wxStaticText* staticText1;
    wxTextCtrl* tc;
    wxButton* button;
	wxPaintDC* lineDC;

	int xPos = 20;
	int yPos = 100;
	int deltaX = 70;
	int deltaY = 0;

//	void OnTimer(wxTimerEvent &e);
    void OnClick(wxCommandEvent&);
	void OnPaintLine(wxPaintEvent &e);

};
