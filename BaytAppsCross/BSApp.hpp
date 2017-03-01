//
//  BSApp.hpp
//  BaytAppsCross
//
//  Created by iMokhles on 28/02/2017.
//  Copyright © 2017 imokhles. All rights reserved.
//

#ifndef BSApp_hpp
#define BSApp_hpp

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class BSApp: public wxApp
{
public:
    virtual bool OnInit() override;
};


#endif /* BSApp_hpp */
