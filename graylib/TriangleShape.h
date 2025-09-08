#pragma once

#include <cstddef>
#include "Shape.h"
#include "Vector.h"

namespace gray
{
	class TriangleShape : public Shape
	{
	public:
		TriangleShape();
		void draw() const override;

		Vector2f getPoint(std::size_t index);
		void setPoint(std::size_t index, Vector2f point);
	private:
		Vector2f m_Points[3];
	};
}