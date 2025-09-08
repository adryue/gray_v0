#include "Window.h"

#include <iostream>

#include <glad/gl.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

namespace gray
{
	Window::Window(int width, int height, std::string title)
	{
		/* Initialize the library */
		if (!glfwInit())
		{
			std::cout << "Error initializing glfw" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		/* Create a windowed mode window and its OpenGL context */
		m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Error creating glfw window" << std::endl;
			glfwTerminate();
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);

		int version = gladLoadGL(glfwGetProcAddress);
		if (version == 0)
		{
			std::cout << "Failed to initialize OpenGL context" << std::endl;
			return;
		}
		std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

		glViewport(0, 0, width, height);
		glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
	}
	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::isOpen()
	{
		return !glfwWindowShouldClose(m_Window);
	}
	void Window::close()
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}
	void Window::clear()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::draw()
	{

	}
	void Window::display()
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);
	}

	bool Window::isKeyPressed(Key key)
	{
		return glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	}
}