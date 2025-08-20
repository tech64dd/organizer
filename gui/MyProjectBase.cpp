///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyProjectBase.h"

///////////////////////////////////////////////////////////////////////////

mainwin_base::mainwin_base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	tasktree = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer1->Add( tasktree, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	filemenu = new wxMenu();
	mb_sync = new wxMenuItem( filemenu, wxID_ANY, wxString( _("Synchronize") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	filemenu->Append( mb_sync );

	m_separator2 = filemenu->AppendSeparator();

	wxMenuItem* exit;
	exit = new wxMenuItem( filemenu, wxID_EXIT, wxString( _("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	filemenu->Append( exit );

	m_menubar1->Append( filemenu, _("File") );

	helpmenu = new wxMenu();
	wxMenuItem* about;
	about = new wxMenuItem( helpmenu, wxID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpmenu->Append( about );

	m_menubar1->Append( helpmenu, _("Help") );

	this->SetMenuBar( m_menubar1 );

	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	tb_new = m_toolBar1->AddTool( wxID_ANY, _("New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Add a new task"), NULL );

	tb_complete = m_toolBar1->AddTool( wxID_ANY, _("Complete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Mark a task as completed"), NULL );

	tb_edit = m_toolBar1->AddTool( wxID_ANY, _("Edit"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Edit selected task"), NULL );

	m_toolBar1->AddSeparator();

	tb_sync = m_toolBar1->AddTool( wxID_ANY, _("Sync"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Synchronize with server now"), NULL );

	m_toolBar1->Realize();

	statusbar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );
}

mainwin_base::~mainwin_base()
{
}

newtask_base::newtask_base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Task name") ), wxVERTICAL );

	taskName_input = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( taskName_input, 0, wxALL|wxEXPAND, 5 );


	bSizer4->Add( sbSizer5, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Due date") ), wxVERTICAL );

	deadline_check = new wxCheckBox( sbSizer4->GetStaticBox(), wxID_ANY, _("Enable due date"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( deadline_check, 0, wxALL, 5 );

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );

	calendar = new wxCalendarCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SHOW_HOLIDAYS );
	gSizer3->Add( calendar, 0, wxALL, 5 );

	timepicker = new wxTimePickerCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT );
	gSizer3->Add( timepicker, 1, wxALL, 5 );


	sbSizer4->Add( gSizer3, 1, wxEXPAND, 5 );


	bSizer4->Add( sbSizer4, 1, wxEXPAND, 5 );


	bSizer4->Add( 0, 5, 0, 0, 5 );

	actionbuttons = new wxStdDialogButtonSizer();
	actionbuttonsSave = new wxButton( this, wxID_SAVE );
	actionbuttons->AddButton( actionbuttonsSave );
	actionbuttonsCancel = new wxButton( this, wxID_CANCEL );
	actionbuttons->AddButton( actionbuttonsCancel );
	actionbuttons->Realize();

	bSizer4->Add( actionbuttons, 0, wxEXPAND, 5 );


	bSizer4->Add( 0, 5, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );
}

newtask_base::~newtask_base()
{
}
