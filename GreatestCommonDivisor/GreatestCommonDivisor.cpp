// GreatestCommonDivisor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void mainMenu();
void info();
void calc();
int gcd(int a, int b);

int main()
{
	system("COLOR 81");
	std::ios::sync_with_stdio(false);
	try
	{
		mainMenu();
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR, Program Failed.  Code: " << &e;
	}
	util::ClearScreen();
	std::cout << "\n\n\t" << "\nGoodbye!";
	util::AnyKeyToContinue();
}

void mainMenu()
{
	int userInput = NULL;
	bool exit = false;
	while (!exit)
	{
		util::ClearScreen();
		std::cout << "\n\n" << std::setfill('-') << std::setw(41) << "Main Menu" << std::setw(42);
		std::cout
			<< "\n\n\t" << "[1] : GCD Calc"
			<< "\n\n\t" << "[2] : Help / Info"
			<< "\n\n\t" << "[3] : Exit"
			<< "\n\n" << std::setfill('=') << std::setw(84)
			<< "\n\n\n\t" << "Enter your choice [1-3]: ";
		userInput = util::IntChecker();
		switch (userInput)
		{
		case 1:		//Main thing 
			calc();
			break;
		case 2:		//Help-Info
			info();
			break;
		case 3:		//Exit program
			exit = util::Exit();
			break;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 132);
			std::cout << "\n[That is not a valid selection.]";
			util::Pause(2);
			break;
		}
	}
}

void info()		
{
	util::ClearScreen();
	std::cout << std::setfill('-') << std::setw(41) << "Help / Info" << std::setw(41) << "\n\n"
		<< "\n\n\t" << "This program is intended to find the greatest common div-"
		<< "\n\n\t" << "isor.  The user will enter two integers seperately, then "
		<< "\n\n\t" << "the program will calculate which is the greatest common  "
		<< "\n\n\t" << "divisor.  " << "\n"
		<< "\n\n\t" << "This program was developed by Christian Brannon.\n\n";
	util::AnyKeyToContinue();
}

void calc()
{
	util::ClearScreen();
	int x, y, z;
	std::cout << "\n\n\t" << "Enter the first integer (X): ";
	x = util::IntChecker();
	std::cout << "\n\n\t" << "Enter the second integer (Y): ";
	y = util::IntChecker();
	z = gcd(x, y);
	std::cout << "\n\n\t" << "G.C.D. of " << x << " and " << y << " is: " << z;
	util::AnyKeyToContinue();
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}