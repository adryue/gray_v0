#pragma once

#include <cstddef>
#include <vector>
#include "Shape.h"

#include "Vector.h"

namespace gray
{
	class TriangleShape : public Shape
	{
	public:
		TriangleShape();

		Vector2f getPoint(std::size_t index);
		void setPoint(std::size_t index, Vector2f point);

	private:
		Vector2f m_Points[3];

		std::vector<float> pointsToArray(); //formats m_Points into a vector of floats
		void updateVertexBuffer(); //send data from m_Points to Shape::m_VertexBuffer
	};
}