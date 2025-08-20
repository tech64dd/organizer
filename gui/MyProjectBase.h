///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/calctrl.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class mainwin_base
///////////////////////////////////////////////////////////////////////////////
class mainwin_base : public wxFrame
{
	private:

	protected:
		wxToolBarToolBase* tb_uncomplete;
		wxToolBarToolBase* tb_delete;

	public:
		wxTreeCtrl* tasktree;
		wxMenuBar* m_menubar1;
		wxMenu* filemenu;
		wxMenuItem* mb_sync;
		wxMenuItem* m_separator2;
		wxMenu* helpmenu;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* tb_complete;
		wxToolBarToolBase* tb_new;
		wxToolBarToolBase* tb_edit;
		wxToolBarToolBase* tb_sync;
		wxStatusBar* statusbar1;

		mainwin_base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Organizer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 506,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~mainwin_base();

};

///////////////////////////////////////////////////////////////////////////////
/// Class newtask_base
///////////////////////////////////////////////////////////////////////////////
class newtask_base : public wxDialog
{
	private:

	protected:

	public:
		wxTextCtrl* taskName_input;
		wxCheckBox* deadline_check;
		wxCalendarCtrl* calendar;
		wxTimePickerCtrl* timepicker;
		wxStdDialogButtonSizer* actionbuttons;
		wxButton* actionbuttonsSave;
		wxButton* actionbuttonsCancel;

		newtask_base( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Create a new task"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 396,411 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );

		~newtask_base();

};

