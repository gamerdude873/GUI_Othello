// Takes the place of main in essence by launching a  clanlib application. Implements program.


#include "Clanlib_and_flags.h"
#include <iostream>
#include "program.h"
#include "othello.h"
#include "board.h"

using namespace std;

class Program
{
public: 
	static int Program::main(const std::vector<CL_String> &args)
	{
		try
		{
			CL_SetupCore setup_core;
			CL_SetupDisplay setup_display;
			CL_SetupGL setup_gl;

			Othello othelloGame;
			othelloGame.playGame();
		}
		catch(CL_Exception &exception)
		{
				// Create a console window for text-output if not available
			   CL_ConsoleWindow console("Console", 80, 160);
			   CL_Console::write_line("Error: " + exception.get_message_and_stack_trace());

			   console.display_close_message();

			   return -1;
		}

		return 0;
	}
};

CL_ClanApplication app(&Program::main);