//
//  BSView.cpp
//  BaytAppsCross
//
//  Created by iMokhles on 28/02/2017.
//  Copyright © 2017 imokhles. All rights reserved.
//

#include "BSView.hpp"

#include <wx/grid.h>
#include <wx/clipbrd.h>
#include <wx/url.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/combo.h>
#include <wx/odcombo.h>
#include <wx/valgen.h>


#include "BSAPIHelper.hpp"
#include "json.hpp"



#define frameWidth 400
#define frameHeight 400

#define requestApiUrl "http://cloud.baytapps.net/jbyalu/api/access"
#define appsApiUrl "http://cloud.baytapps.net/jbyalu/api/customapps"

BSView::BSView()
: wxFrame(NULL, wxID_ANY, "BaytSigner")
{
    this->SetSize(frameWidth, frameHeight);
    SetMinSize(GetSize());
    SetMaxSize(GetSize());
    
    // Api Connection
    BSAPIHelper apiClinet;
    
    std::string out;
    apiClinet.Get(appsApiUrl, out);
    
    nlohmann::json js = nlohmann::json::parse(out.c_str());
    printf("%s", js.dump().c_str());
    
    // add device connection field
    
    // add apps dropdown
    
    // add login fields
    BSView::setupLoginFields();
    BSView::setupLoginButton();
    
    // add bottom status bar
    CreateStatusBar();
    SetStatusText( "Status...!!!" );
    
    // center application frame after opening it
    this->Center();
}

void BSView::setupLoginFields() {
    
    topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(frameWidth, -1);
    this->SetSizer(topSizer);
    
    fontTmp = wxFont(20,wxFONTFAMILY_TELETYPE ,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    
    wxStaticBox* appleIdBox = new wxStaticBox(this, wxID_ANY, _("Apple ID"));
    appleIdBox->SetFont(fontTmp);
    
    wxStaticBoxSizer* appleIdSizer = new wxStaticBoxSizer( appleIdBox, wxHORIZONTAL);
    
    
    topSizer->Add(appleIdSizer, 0, wxALL|wxEXPAND, 1);
    
    appleIdEntry = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1));
    
    wxStaticBox* passwdBox = new wxStaticBox(this, wxID_ANY, _("Password"));
    appleIdBox->SetFont(fontTmp);

    wxStaticBoxSizer* passwordSizer = new wxStaticBoxSizer( passwdBox, wxHORIZONTAL);
    
    
    
    
    
    topSizer->Add(passwordSizer, 0, wxALL|wxEXPAND, 1);
    
    passwordIdEntry = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PASSWORD);
    
#if wxVERSION_NUMBER >= 3000
    appleIdEntry->SetHint(wxT("example@email.com"));
    passwordIdEntry->SetHint(wxT("*********"));
#endif
    appleIdSizer->Add(appleIdEntry, 1, wxALL, 1);
    passwordSizer->Add(passwordIdEntry, 1, wxALL, 1);
    
}
void BSView::setupLoginButton() {
    
    listAppsBox = new wxStaticBox(this, wxID_ANY, _("Apps"));
    listAppsBox->SetFont(fontTmp);
    listAppsBoxSizer = new wxStaticBoxSizer( listAppsBox, wxHORIZONTAL);
    
    
    appsArray.Add(wxT("WhatsApp"));
    appsArray.Add(wxT("SnapChat"));
    appsArray.Add(wxT("Instagram"));
    
    int app_selection_setting;
    
    topSizer->Add(listAppsBoxSizer, 0, wxALL|wxEXPAND, 1);
    
    chooseAppsBox = new wxChoice (this, wxID_ANY, wxPoint(298,57), wxSize(115,21), appsArray, 0, wxGenericValidator(&app_selection_setting), wxT(""));
    
    listAppsBoxSizer->Add(chooseAppsBox, 1, wxALL, 1);
    
    buttonBox = new wxStaticBox(this, wxID_ANY, _("Process Button"));
    buttonBox->SetFont(fontTmp);
    buttonBoxSizer = new wxStaticBoxSizer( buttonBox, wxHORIZONTAL);
    
    buttonLogin = new wxButton(this, BUTTON_Login, wxT("Sign"));
    buttonBoxSizer->Add(buttonLogin);
    
    topSizer->Add(buttonBoxSizer, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);
}

void BSView::OnLogin(wxCommandEvent& event)
{
    wxString username = appleIdEntry->GetValue();
    wxString password = passwordIdEntry->GetValue();
    
    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Wrong we cannot process this without Developer account"), wxT("Warning!"), wxICON_WARNING);
    }
    else {
        wxMessageBox(wxT("Welcome"), wxT("Message!"), wxICON_INFORMATION);
    }
}

BSView::~BSView() {}

BEGIN_EVENT_TABLE(BSView, wxFrame)
EVT_BUTTON(BUTTON_Login, BSView::OnLogin)

wxEND_EVENT_TABLE()
