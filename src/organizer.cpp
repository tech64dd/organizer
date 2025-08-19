#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/xrc/xmlres.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/calctrl.h>
#include <wx/log.h>
#include "../gui/MyProjectBase.h"

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class newtask : public newtask_base
{
public:
    newtask(wxWindow* parent) : newtask_base(parent) {
        confirm->Bind(wxEVT_BUTTON, &newtask::donemake, this);
        this->Bind(wxEVT_CLOSE_WINDOW, &newtask::onClose, this);
    }

    void donemake(wxCommandEvent& event)
    {
        if (deadline_check->GetValue())
        {
            wxDateTime date = calendar->GetDate();
            wxDateTime time = timepicker->GetValue();

            wxLogMessage("%s %s", date.FormatISODate(), time.FormatISOTime());
        }
        else
        {
            wxLogMessage("lol no");
        }
    }
    void onClose(wxCloseEvent& event)
    {
        GetParent()->Enable();
        event.Skip();
    }
};

class mainwin : public mainwin_base
{
public:
    mainwin(wxWindow* parent) : mainwin_base(parent) {
        Bind(wxEVT_MENU, &mainwin::exitapp, this, wxID_EXIT);
        Bind(wxEVT_TOOL, &mainwin::opendialog, this, tb_new->GetId());
    }

    void opendialog(wxCommandEvent& event)
    {
        newtask* win = new newtask(this);
        this->Disable();
        win->Show(true);
    }

    void exitapp(wxCommandEvent& event)
    {
        Close(true);
    }
};

bool MyApp::OnInit()
{
    mainwin* win = new mainwin(nullptr);
    win->Show(true);
    return true;
}
