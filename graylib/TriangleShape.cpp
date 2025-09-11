#include "TriangleShape.h"

#include <iostream>
#include "VertexBufferLayout.h"

static const std::size_t SIZE_OF_DATA = 6 * sizeof(float);

namespace gray
{
	TriangleShape::TriangleShape() :
		m_Points {
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f }
		},
		m_Shader("shader.vert", "shader.frag")
	{
		updateVertexBuffer();
		VertexBufferLayout layout;
		layout.push<float>(2);
		m_VertexArray.addVertexBuffer(m_VertexBuffer, layout);
	}
	void TriangleShape::draw()
	{
		m_Shader.bind();
		m_VertexArray.bind();
		m_Shader.setUniform4f("u_Color", getFillColor().rFloat(), getFillColor().gFloat(), getFillColor().bFloat(), getFillColor().aFloat());
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	Vector2f TriangleShape::getPoint(std::size_t index)
	{
		if (index > 2)
			return Vector2f();

		return m_Points[index];
	}
	void TriangleShape::setPoint(std::size_t index, Vector2f point)
	{
		if (index > 2)
			return;

		m_Points[index] = point;
		updateVertexBuffer();
	}

	std::vector<float> TriangleShape::pointsToArray()
	{
		return {
			m_Points[0].x, m_Points[0].y,
			m_Points[1].x, m_Points[1].y,
			m_Points[2].x, m_Points[2].y,
		};
	}

	void TriangleShape::updateVertexBuffer()
	{
		m_VertexBuffer.sendData(pointsToArray().data(), SIZE_OF_DATA);
	}
}