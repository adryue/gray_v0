#include "TriangleShape.h"

#include <iostream>
#include "VertexBufferLayout.h"
#include "Window.h"

static const std::size_t SIZE_OF_DATA = 6 * sizeof(float);

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