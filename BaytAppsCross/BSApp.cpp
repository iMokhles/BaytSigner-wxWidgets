//
//  BSApp.cpp
//  BaytAppsCross
//
//  Created by iMokhles on 28/02/2017.
//  Copyright © 2017 imokhles. All rights reserved.
//

#include "BSApp.hpp"
#include "BSView.hpp"

bool BSApp::OnInit() {
    auto frame = new BSView;
    frame->Show(true);
    return true;
}
