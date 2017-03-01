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

#define frameWidth 400
#define frameHeight 400




BSView::BSView()
: wxFrame(NULL, wxID_ANY, "BaytSigner")
{
    this->SetSize(frameWidth, frameHeight);
    SetMinSize(GetSize());
    SetMaxSize(GetSize());
    
    // add device connection field
    
    // add login fields
    
    // add sign button
    
    // add bottom status bar
    CreateStatusBar();
    SetStatusText( "Status...!!!" );
    
    // center application frame after opening it
    this->Center();
}

