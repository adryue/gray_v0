#include "TriangleShape.h"

#include <iostream>
#include "VertexBufferLayout.h"
#include "Window.h"

static const std::size_t SIZE_OF_DATA = 6 * sizeof(float);

static const unsigned int ELEMENT_BUFFER_INDICES[] = {0, 1, 2};

namespace gray
{
	TriangleShape::TriangleShape() :
		m_Points {
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f }
		}
	{
		updateVertexBuffer();

		VertexBufferLayout layout;
		layout.push<float>(2);

		m_IndexBuffer.sendData(ELEMENT_BUFFER_INDICES, sizeof(ELEMENT_BUFFER_INDICES) / sizeof(ELEMENT_BUFFER_INDICES[0]));

		m_VertexArray.addVertexBuffer(m_VertexBuffer, layout);
		m_VertexArray.addIndexBuffer(m_IndexBuffer);
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