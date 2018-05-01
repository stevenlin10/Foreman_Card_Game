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
	build_Character();
	build_table();
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

// Create the table
void MyViewer::build_table()
{

	SnModel *s;

		s = new SnModel;
		s->model()->load_obj("../Table/table.obj");
		s->model()->scale(0.05f);
		add_model(s, GsVec(0.0f, 0.5f, 1.5f));

}

// Create the the player
void MyViewer::build_Character()
{

	SnModel *s;

		s = new SnModel;
		s->model()->load_obj("../Character/body.obj");
		add_model(s, GsVec(0.0, 0.0, 0.0));


		s = new SnModel;
		s->model()->load_obj("../Character/leftarms.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/lefthand.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/leftshoulder.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/leftupperarm.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));


		s = new SnModel;
		s->model()->load_obj("../Character/rightarm.obj");
		add_model(s, GsVec(0.0f, 0.01f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/righthand.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/rightshoulder.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));
		s = new SnModel;
		s->model()->load_obj("../Character/rightupperarm.obj");
		add_model(s, GsVec(0.0f, 0.0f, 0.0f));


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

			//move camera
		case GsEvent::KeySpace:
		{

			double lt, t0 = gs_time();
			do
			{

				lt = gs_time() - t0;
				if (lt < 3.0f)
				{
					//move Z 
					camera().eye.z -= 0.005f;
					camera().center.z -= 0.005f;
					camera().up.z -= 0.005f;

					//move Y
					camera().eye.y += 0.01f;
					camera().center.y += 0.01f;
					camera().up.y += 0.01f;

				}
				else if(lt >3.0f && lt < 3.8f)
				{
					//move x
					camera().eye.x -= 0.07f;
					camera().center.x -= 0.03f;
					camera().eye.z -= 0.07f;
					//camera().eye.y -= 0.03f;


				}
				else if (lt >3.8f && lt < 6.3f)
				{
					camera().eye.z -= 0.02f;

				}
				else if (lt >6.3f && lt < 9)
				{
					camera().eye.x += 0.02f;
					camera().center.x += 0.003f;

				}
				else if (lt > 9 && lt < 9.1f)
				{
					camera().center.x = 0.0f;
				}
				else if (lt > 9.1f && lt < 10.5f)
				{
					camera().eye.z += 0.009f;
					camera().eye.y -= 0.008f;
				}


				render();
				ws_check();
				message().setf("local time = %f", lt);
			} while (lt < 13);


			return 1;
		}
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
