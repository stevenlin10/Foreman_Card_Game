/*
	This header file defines the structure and global variables of the program viewer.

	This is written using SIG libraries, which are the property of Professor Kallman of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/

# pragma once

# include <sig/sn_poly_editor.h>
# include <sig/sn_lines2.h>

# include <sigogl/ui_button.h>
# include <sigogl/ws_viewer.h>

class MyViewer : public WsViewer
{  
protected :
	enum MenuEv { EvNormals, EvAnimate, EvExit };
	UiCheckButton* _nbut;

public :
	MyViewer(int x, int y, int w, int h, const char* l);
	void build_ui();
	void add_model(SnShape* s, GsVec p);
	void build_scene();
	virtual int handle_keyboard(const GsEvent &e) override;
	virtual int uievent(int e) override;
};

