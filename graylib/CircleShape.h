#pragma once

#include "Window.h"
#include "Shape.h"

namespace gray
{
	class CircleShape : public Shape
	{
	public:
		CircleShape();

		void draw(Window& window) const override;

		float getRadius() const;
		void setRadius(float radius);

		std::size_t getPointCount() const;
		void setPointCount(std::size_t pointCount);

	private:
		float m_Radius;
		std::size_t m_PointCount;

		void calculatePoints();
	};
}