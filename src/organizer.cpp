#include <fstream>
#include <string>
#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/calctrl.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
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
        deadline_check->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED, &newtask::onDeadlineCheck, this);
        calendar->Enable(false);
        timepicker->Enable(false);
        CallAfter([this]() {
            taskName_input->SetFocus();
        });

    }

    void donemake(wxCommandEvent& event)
    {

        if (taskName_input->GetLineLength(0) == 0)
        {
            wxMessageBox("Task name must not be empty.", "Skill Issue", wxOK | wxICON_ERROR);
        }
        else
        {
            json task;
            task["name"] = taskName_input->GetLineText(0).ToStdString();
            task["completed"] = false;
            if (deadline_check->GetValue())
            {
                task["deadline"] = true;
                task["deadline_date"] = calendar->GetDate().FormatISODate().ToStdString();
                int hour, minute, second;
                timepicker->GetTime(&hour, &minute, &second);
                char timeStr[9];
                snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", hour, minute, second);
                task["deadline_time"] = std::string(timeStr);
            }
            else
            {
                task["deadline"] = false;
            }

            std::string filename = "tasks.json";
            json tasks_json;

            std::ifstream inFile(filename);
            inFile >> tasks_json;
            if (!tasks_json.is_array()) {
                wxMessageBox("tasks.json is fucked up", "Massive Skill Issue", wxOK | wxICON_ERROR);
                return;
            }
            tasks_json = json::array();
            inFile.close();

            int max_id = 0;
            for (const auto& t : tasks_json) {
                if (t.contains("id") && t["id"].is_number_integer()) {
                    max_id = std::max(max_id, t["id"].get<int>());
                }
            }
            task["id"] = max_id + 1;

            tasks_json.push_back(task);
            std::ofstream outFile(filename);
            outFile << tasks_json.dump(4);
            outFile.close();
        }
    }
    void onDeadlineCheck(wxCommandEvent& event)
    {
        if (deadline_check->GetValue())
        {
            calendar->Enable(true);
            timepicker->Enable(true);
        }
        else
        {
            calendar->Enable(false);
            timepicker->Enable(false);
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
