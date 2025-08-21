#pragma once

#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

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
		void draw(); //draw(shape)
		void display();
	private:
		GLFWwindow* m_Window;
	};
}