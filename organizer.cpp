#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/xrc/xmlres.h>
#include "gui/MyProjectBase.h"
#include "wx/event.h"
#include "wx/frame.h"

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class mainwin : public mainwin_base
{
public:
    void exitapp(wxCommandEvent& event)
    {
        Close(true);
    }
private:
    wxDECLARE_EVENT_TABLE();
};

bool MyApp::OnInit()
{
    mainwin* win = new mainwin(nullptr);
    win->Show(true);
    return true;
}

wxBEGIN_EVENT_TABLE(mainwin, mainwin_base)
    EVT_MENU(wxID_EXIT, mainwin::exitapp)
wxEND_EVENT_TABLE()
