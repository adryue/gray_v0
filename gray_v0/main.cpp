#include <iostream>

#include <Window.h>
#include <TriangleShape.h>
#include <Vector.h>

int main()
{
	std::cout << "Hello World" << std::endl;

	gray::Window window(1280, 720, "Hello!");

	gray::TriangleShape shape;
	shape.setPoint(0, { 10.0f, 10.0f });
	shape.setPoint(1, { 300.0f, 300.0f });
	shape.setPoint(2, { 10.0f, 300.0f });


	while (window.isOpen())
	{
		window.clear();
		window.pollEvents();

		if (window.isKeyPressed(gray::Key::Escape))
		{
			window.close();
		}

		window.display();
	}

	window.close();
	std::cout << "END OF PROGRAM" << std::endl;
	return 0;
}