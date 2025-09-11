#pragma once

#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Drawable.h"
#include "Key.h"

namespace gray
{
	class Window
	{
	public:
		Window(int width, int height, std::string title);
		~Window();

		bool isOpen();
		void close();

		void pollEvents();
		void clear();
		void draw(Drawable& drawable); //draw(shape)
		void display();

		bool isKeyPressed(Key key);
	private:
		GLFWwindow* m_Window;
	};
}