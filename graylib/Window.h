#pragma once

#include <string>

#include <memory>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.h"
#include "VertexArray.h"
#include "Color.h"
#include "Drawable.h"
#include "Camera.h"
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

		void draw(const Drawable& drawable); //draw(shape)
		void drawShape(const VertexArray& vertexArray, const glm::mat4& transform, const Color& fillColor);
		void drawCircle(const VertexArray& vertexArray, const unsigned int numVertices, const glm::mat4& transform, const Color& fillColor);

		void display();

		Camera& getCamera();
		void setCamera(const Camera& camera);

		bool isKeyPressed(Key key);
	private:
		GLFWwindow* m_Window;
		Camera m_Camera;
		std::unique_ptr<Shader> m_Shader;
	};
}