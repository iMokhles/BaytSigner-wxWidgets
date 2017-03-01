//
//  BSView.cpp
//  BaytAppsCross
//
//  Created by iMokhles on 28/02/2017.
//  Copyright © 2017 imokhles. All rights reserved.
//

#include "BSView.hpp"

#include <wx/clipbrd.h>
#include <wx/url.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

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
    // add sign button
    
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
    
    wxFont fontTmp = wxFont(20,wxFONTFAMILY_TELETYPE ,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    
    wxStaticBox* appleIdBox = new wxStaticBox(this, wxID_ANY, _("Apple ID"));
    appleIdBox->SetFont(fontTmp);
    
    wxStaticBoxSizer* appleIdSizer = new wxStaticBoxSizer( appleIdBox, wxHORIZONTAL);
    
    
    topSizer->Add(appleIdSizer, 0, wxALL|wxEXPAND, 1);
    
    appleIdField = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1));
    
    wxStaticBox* passwdBox = new wxStaticBox(this, wxID_ANY, _("Password"));
    appleIdBox->SetFont(fontTmp);
    
    wxStaticBoxSizer* passwordSizer = new wxStaticBoxSizer( passwdBox, wxHORIZONTAL);
    
    
    topSizer->Add(passwordSizer, 0, wxALL|wxEXPAND, 1);
    
    passIdField = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PASSWORD);
    
#if wxVERSION_NUMBER >= 3000
    appleIdField->SetHint(wxT("example@email.com"));
    passIdField->SetHint(wxT("*********"));
#endif
    appleIdSizer->Add(appleIdField, 1, wxALL, 1);
    passwordSizer->Add(passIdField, 1, wxALL, 1);
}
