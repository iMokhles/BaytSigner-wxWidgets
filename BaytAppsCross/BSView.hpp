//
//  BSView.hpp
//  BaytAppsCross
//
//  Created by iMokhles on 28/02/2017.
//  Copyright © 2017 imokhles. All rights reserved.
//

#ifndef BSView_hpp
#define BSView_hpp

#include <wx/wx.h>

class BSView : public wxFrame {
public:
    BSView();
    virtual ~BSView();
protected:
    
    // top box
    wxBoxSizer* topSizer;
    
    // custom font
    wxFont fontTmp;
    
    // account info labels
    wxStaticText* appleIdLabel;
    wxStaticText* passwordIdLabel;
    
    // input fields
    wxTextCtrl* appleIdEntry;
    wxTextCtrl* passwordIdEntry;
    
    // apps chooser box
    wxArrayString appsArray;
    wxStaticBox* listAppsBox;
    wxStaticBoxSizer* listAppsBoxSizer;
    wxChoice *chooseAppsBox;
    
    // login button
    wxStaticBoxSizer* buttonBoxSizer;
    wxStaticBox* buttonBox;
    wxButton* buttonLogin;
    
    // message alert
    wxMessageDialog *dialogMsg;
    
    void setupLoginFields();
    void setupLoginButton();
private:
    void OnLogin(wxCommandEvent& event);
private:
    DECLARE_EVENT_TABLE()
    
    enum
    {
        BUTTON_Login = wxID_HIGHEST + 1
    };
};

#endif /* BSFrame_hpp */
