#pragma once

#include "Clanlib_and_flags.h"

class othelloWindow
{
private:
	bool quit;
	bool playerIsWhite;
	CL_GraphicContext gc;
    CL_InputDevice keyboard;
    CL_InputDevice mouse;
	CL_FontDescription font_descr;
	CL_Texture background;
	CL_Slot slot_quit;
	CL_ResourceManager resources;
	CL_Font_System font;
	CL_DisplayWindow window;
	CL_Sprite blackChip;
	CL_Sprite whiteChip;

public:
	othelloWindow();
	void on_window_close();
	bool chooseColor();
	void initializeBoard();
};