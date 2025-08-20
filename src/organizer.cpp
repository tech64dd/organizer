#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/calctrl.h>
#include <wx/log.h>
#include <nlohmann/json.hpp>
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
        actionbuttons->GetAffirmativeButton()->Bind(wxEVT_BUTTON, &newtask::donemake, this);
        actionbuttons->GetCancelButton()->Bind(wxEVT_BUTTON, &newtask::onCancel, this);
        this->Bind(wxEVT_CLOSE_WINDOW, &newtask::onClose, this);
        CallAfter([this]() {
            taskName_input->SetFocus();
        });

    }

    void donemake(wxCommandEvent& event)
    {
        if (deadline_check->GetValue() && !taskName_input->GetLineLength(0) == 0)
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
        event.Skip();
    }
    void onCancel(wxCommandEvent& event)
    {
        this->Show(false);
    }
};

class mainwin : public mainwin_base
{
public:
    mainwin(wxWindow* parent) : mainwin_base(parent) {
        Bind(wxEVT_MENU, &mainwin::exitapp, this, wxID_EXIT);
        Bind(wxEVT_TOOL, &mainwin::open_newtask, this, tb_new->GetId());
        statusbar1->SetStatusText("Welcome to Organizer!");
    }

    void open_newtask(wxCommandEvent& event)
    {
        newtask* win = new newtask(this);
        win->ShowModal();
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
