/*
	Primary driver of viewer application.

	This is written using SIG libraries, which are the property of Professor Kallman of University of California, Merced.

	Written by Jeff Foreman, 5 April 2018
*/
# include "my_viewer.h"

# include <sigogl/ws_run.h>

int main ( int argc, char** argv )
{
	MyViewer* v = new MyViewer ( -1, -1, 640, 480, "Foreman Card Game: Proof of Concept" );

	v->view_all ();
	v->show ();

	ws_run ();
	return 1;
}
