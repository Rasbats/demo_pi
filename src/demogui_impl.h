/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  demo Plugin
 * Author:   Mike Rossiter
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Mike Rossiter                                   *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#ifndef _CALCULATORGUI_IMPL_H_
#define _CALCULATORGUI_IMPL_H_

#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "demogui.h"
#include "demo_pi.h"

#include "NavFunc.h"
#include "tinyxml.h"

#include <list>
#include <vector>

using namespace std;

class demo_pi;
class Position;

class Dlg : public m_Dialog
{
public:
	Dlg(wxWindow *parent, demo_pi *ppi);
	~Dlg();
        
	wxWindow *pParent;
	demo_pi *pPlugIn;

	
	
	    void OnPSGPX( wxCommandEvent& event );		
		bool OpenXML();
		
		vector<Position> my_positions;
		vector<Position> my_points;

        void Calculate( wxCommandEvent& event, bool Export, int Pattern );
        void Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype);
       				
		

		wxString rte_start;
	    wxString rte_end;

private:
	    void OnClose( wxCloseEvent& event );
        double lat1, lon1, lat2, lon2;
        bool error_found;
        bool dbg;

		wxString     m_gpx_path;		
};


class Position
{
public:

    wxString lat, lon, wpt_num;
    Position *prev, *next; /* doubly linked circular list of positions */
    int routepoint;

};

#endif
