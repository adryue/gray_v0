#include <iostream>
         
#include "Window.h"

int main()
{
	std::cout << "Hello World" << std::endl;

	gray::Window window(800, 600, "Hello!");

	while (window.isOpen())
	{
		window.clear();
		window.pollEvents();
		window.display();
	}

	window.close();
	std::cout << "END OF PROGRAM" << std::endl;
	return 0;
}