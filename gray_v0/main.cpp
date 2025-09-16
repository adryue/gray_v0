#include <iostream>

#include <Window.h>
#include <TriangleShape.h>
#include <CircleShape.h>
#include <Vector.h>

static const int WINDOW_WIDTH = 1280;
static const int WINDOW_HEIGHT = 720;

int main()
{
	gray::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello!");

	gray::Camera camera;
	//camera.setCenter({ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
	camera.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
	window.setCamera(camera);

	gray::TriangleShape shape;
	shape.setPoint(0, { 500.0f, 100.0f });
	shape.setPoint(1, { 100.0f, -100.0f });
	shape.setPoint(2, { -100.0f, -100.0f });
    shape.setFillColor(gray::Color::Cyan);
	shape.setScale({ 1.5f, 1.0f });

	gray::TriangleShape shape2;
	shape2.setPoint(0, { -200.0f, -200.0f });
	shape2.setPoint(1, { -150.0f, -150.0f });
	shape2.setPoint(2, { -150.0f, -200.0f });

	gray::CircleShape circle1;
	circle1.setRadius(100.0f);
	circle1.setPointCount(3);
	circle1.setFillColor(gray::Color::Green);
	circle1.setPosition({200.0f, 200.0f});

    float rotation = -1.0f;

	while (window.isOpen())
	{
		window.clear();

		if (window.isKeyPressed(gray::Key::Escape))
		{
			window.close();
		}
		if (window.isKeyPressed(gray::Key::Up))
		{
			window.getCamera().move({ 0.0f, 0.1f });
		}
		if (window.isKeyPressed(gray::Key::Down))
		{
			window.getCamera().move({ 0.0f, -0.1f });
		}
		if (window.isKeyPressed(gray::Key::Left))
		{
			window.getCamera().move({ -0.1f, 0.0f });
		}
		if (window.isKeyPressed(gray::Key::Right))
		{
			window.getCamera().move({ 0.1f, 0.0f });
		}
		if (window.isKeyPressed(gray::Key::A))
		{
			window.getCamera().rotate(0.05f);
		}
		if (window.isKeyPressed(gray::Key::D))
		{
			window.getCamera().rotate(-0.05f);
		}

		shape.setRotation(rotation);
		rotation += 0.01f;
		window.draw(shape);
		window.draw(shape2);
		window.draw(circle1);

		window.display();

		window.pollEvents();
	}

	window.close();
	std::cout << "END OF PROGRAM" << std::endl;
	return 0;
}