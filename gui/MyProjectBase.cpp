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

newtask_base::newtask_base( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	calendar = new wxCalendarCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SHOW_HOLIDAYS );
	bSizer4->Add( calendar, 0, wxALL, 5 );

	timepicker = new wxTimePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT );
	bSizer4->Add( timepicker, 0, wxALL, 5 );

	deadline_check = new wxCheckBox( this, wxID_ANY, _("Enable deadline"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( deadline_check, 0, wxALL, 5 );

	confirm = new wxButton( this, wxID_ANY, _("Done"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( confirm, 0, wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );
}

newtask_base::~newtask_base()
{
}
