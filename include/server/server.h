#ifndef SERVER_H
#define SERVER_H

#include <wx/wx.h>
#include <wx/socket.h>

enum
{
    wxID_SOCKET = wxID_HIGHEST,
    wxID_SERVER,
    wxID_BUTSTART,
    wxID_BUTDISP,
    wxID_DESC
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
protected:
    wxPanel *m_panel;
    wxButton *m_start_button;
    wxButton *m_displayscreen_button;
    wxTextCtrl *m_log_box;
    wxSocketServer *m_server;

public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size,
           long style = wxDEFAULT_FRAME_STYLE);
    void ServerStart(wxCommandEvent &evt);
    void OnServerEvent(wxSocketEvent &evt);
    void OnSocketEvent(wxSocketEvent &evt);
    void DisplayScreen(wxCommandEvent &evt);

private:
    wxImage receivedImage;

    DECLARE_EVENT_TABLE()
};

class MyDisplayScreenFrame : public wxFrame {
public:
    MyDisplayScreenFrame(const wxString& title, const wxPoint& pos, const wxSize& size, wxImage image);
    void OnTimer(wxTimerEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnClose(wxCloseEvent& event);

private:
    wxTimer* timer;
    wxImage capturedImage;

    wxDECLARE_EVENT_TABLE();
};

#endif