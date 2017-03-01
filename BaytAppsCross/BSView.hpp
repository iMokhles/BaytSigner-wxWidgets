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
protected:
    
    wxBoxSizer* topSizer;
    wxTextCtrl* appleIdField;
    wxTextCtrl* passIdField;
    
    wxRadioButton* signButton;
    wxStaticText* statusText;
    
    wxComboBox* appsBox;
    wxComboBox* appsBox2;
    
    void setupLoginFields();
};

#endif /* BSFrame_hpp */
