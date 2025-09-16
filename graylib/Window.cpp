#include "Window.h"

#include <iostream>

#include <glad/gl.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam);

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

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true); //only use for debugging purposes

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

		//debug if debugging is enabled
		int flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			std::cout << "Using Debug mode." << std::endl;
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(glDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_Shader = std::make_unique<Shader>("shader.vert", "shader.frag");
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
	void Window::draw(const Drawable& drawable)
	{
		drawable.draw(*this);
	}
	void Window::drawShape(const VertexArray& vertexArray, const glm::mat4& transform, const Color& fillColor)
	{
		glfwMakeContextCurrent(m_Window);
		
		m_Shader->bind();
		m_Shader->setUniform4f("u_Color", fillColor.rFloat(), fillColor.gFloat(), fillColor.bFloat(), fillColor.aFloat());

		glm::mat4 mvp = m_Camera.getProjectionMatrix() * m_Camera.getViewMatrix() * transform;
		m_Shader->setUniformMat4f("u_Transform", mvp);

		vertexArray.bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	void Window::drawCircle(const VertexArray& vertexArray, const unsigned int numVertices, const glm::mat4& transform, const Color& fillColor)
	{
		glfwMakeContextCurrent(m_Window);

		m_Shader->bind();
		m_Shader->setUniform4f("u_Color", fillColor.rFloat(), fillColor.gFloat(), fillColor.bFloat(), fillColor.aFloat());

		glm::mat4 mvp = m_Camera.getProjectionMatrix() * m_Camera.getViewMatrix() * transform;
		m_Shader->setUniformMat4f("u_Transform", mvp);

		vertexArray.bind();
		glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);
	}

	void Window::display()
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(m_Window);
	}

	Camera& Window::getCamera()
	{
		return m_Camera;
	}

	void Window::setCamera(const Camera& camera)
	{
		m_Camera = camera;
	}

	bool Window::isKeyPressed(Key key)
	{
		return glfwGetKey(m_Window, (int)key) == GLFW_PRESS;
	}
}

void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam)
{
	// ignore non-significant error/warning codes
	if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

	std::cout << "DEBUG MESSAGE (" << id << "): " << message << std::endl;
	switch (source)
	{
	case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
	case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
	case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
	case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
	} std::cout << std::endl;

	switch (type)
	{
	case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
	case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
	case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
	case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
	case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
	case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
	case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
	} std::cout << std::endl;

	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
	case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
	case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
	case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
	} std::cout << std::endl;
	std::cout << std::endl;
}