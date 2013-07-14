#include "Clanlib_and_flags.h"
#include "othelloWindow.h"
#include "othello.h"

othelloWindow::othelloWindow()
{
	window = CL_DisplayWindow("Othello", 640,640);

	gc = window.get_gc();
    keyboard = window.get_ic().get_keyboard();
    mouse = window.get_ic().get_mouse();

	slot_quit = window.sig_window_close().connect(this, &othelloWindow::on_window_close);

	font_descr.set_typeface_name("tahoma");
	font_descr.set_height(30);
	font = CL_Font_System(gc, font_descr);
	
	resources = CL_ResourceManager("resources.xml");
	background = CL_Texture(gc, "board", &resources);
	
	CL_Rect windowShape = window.get_viewport();
	gc.set_texture(0, background);
	CL_Draw::texture(gc, windowShape);
	gc.reset_texture(0);
	
	window.flip();
	CL_KeepAlive::process();

	initializeBoard();
	playerIsWhite = chooseColor();

	#ifdef DEBUG_CONSOLE
	if(AllocConsole())
	{
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stderr);
	}
	#endif
}

void othelloWindow::initializeBoard()
{
	bool done = false;

	while(!done)
	{
		if(keyboard.get_keycode(CL_KEY_ESCAPE) == true)
		{
			done = true;
		}

		font.draw_text(gc, 146, 60, "PLAYER, CHOOSE YOUR COLOR:");

		window.flip();
		CL_KeepAlive::process();
		CL_System::sleep(10);
	}
}

bool othelloWindow::chooseColor()
{
	//Should open up a prompt using GUI-based choice of a white chip or a black chip.

	return true;
}

void othelloWindow::on_window_close()
{
	quit = true;
}