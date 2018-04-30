/*
	Function definitions of the viewer. Please reference my_viewer.h for more abstract details.

	This is written using SIG libraries, which are the property of Professor Kallmann of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/

# include "my_viewer.h"
# include "Card.h"
# include "Deck.h"

# include <sigogl/ui_button.h>
# include <sigogl/ui_radio_button.h>
# include <sig/sn_primitive.h>
# include <sig/sn_transform.h>
# include <sig/sn_manipulator.h>

# include <sigogl/ws_run.h>

// Viewer constructor.
MyViewer::MyViewer(int x, int y, int w, int h, const char* l) : WsViewer(x,y,w,h,l)
{
	// Initialize global variables.
	_nbut = 0;

	// Create scene and UI.
	build_ui();
	build_scene();
}

// Build the viewer UI.
void MyViewer::build_ui()
{
	// Panel pointers.
	UiPanel *p;

	// Create a UI manager.
	UiManager* uim = WsWindow::uim();

	// Add the panel to the left side of the screen.
	p = uim->add_panel("", UiPanel::HorizLeft);

	// Add exit button.
	p->add (new UiButton("Exit", EvExit));
}

// Adds model part to the scene.
void MyViewer::add_model(SnShape* s, GsVec p)
{
	// Create a manipulator.
	SnManipulator* manip = new SnManipulator;

	// Create the model matrix.
	GsMat m;

	// Place the model matrix at the specified point.
	m.translation (p);

	// Set as the model matrix.
	manip->initial_mat (m);

	// Create a new group.
	SnGroup* g = new SnGroup;

	// Add model to the group.
	g->add(s);

	// Add model to the scene.
	manip->child(g);
	rootg()->add(manip);
}

// Create the Viewer scene.
void MyViewer::build_scene()
{
	Deck main(Deck::DeckType::Main);
	Deck hand(Deck::DeckType::Hand);

	SnModel *s;
	double offset = 0.0;
	for (int i = 0; i < 52; i++)
	{
		s = new SnModel;
		s->model()->load_obj("../CardFiles/TestCard.obj");
		add_model(s, GsVec(0.0, 0.0, offset));
		offset += 0.1;
	}
}

// Handle keyboard events.
int MyViewer::handle_keyboard(const GsEvent &event)
{
	// First let system check events.
	int ret = WsViewer::handle_keyboard (event);
	if (ret) return ret;

	// Handle the appropriate key event.
	switch (event.key)
	{	
		case GsEvent::KeyEsc : gs_exit(); return 1;
		default: gsout<<"Key pressed: "<<event.key<<gsnl;
	}

	return 0;
}

// Handle UI events.
int MyViewer::uievent(int event)
{
	// Handle the appropriate UI event.
	switch (event)
	{	
		case EvExit: gs_exit();
	}

	return WsViewer::uievent(event);
}
