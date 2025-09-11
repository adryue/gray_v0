#include <iostream>

#include <Window.h>
#include <TriangleShape.h>
#include <Vector.h>

int main()
{
	std::cout << "Hello World" << std::endl;

	gray::Window window(1280, 720, "Hello!");

	gray::TriangleShape shape;
	shape.setPoint(0, { 0.5f, 0.5f });
	shape.setPoint(1, { 0.5f, -0.8f });
    shape.setPoint(2, { -0.5f, -0.5f });
    shape.setFillColor(gray::Color::Cyan);

    float position = -1.0f;

	while (window.isOpen())
	{
		window.clear();

		if (window.isKeyPressed(gray::Key::Escape))
		{
			window.close();
		}

        shape.setPoint(2, { position, -0.5f });
		position += 0.001f;
		window.draw(shape);

		window.display();

		window.pollEvents();
	}

	window.close();
	std::cout << "END OF PROGRAM" << std::endl;
	return 0;
}