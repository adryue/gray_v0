#include "TriangleShape.h"

namespace gray
{
	TriangleShape::TriangleShape() :
		m_Points {
			{ 0.0f, 0.0f},
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f }
		}
	{
	}
	void TriangleShape::draw() const
	{

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
	}
}