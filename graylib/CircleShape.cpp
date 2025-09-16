#include "CircleShape.h"

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

static const float DEFAULT_RADIUS = 100.0f;
static const int DEFAULT_POINT_COUNT = 50;

namespace gray
{
	CircleShape::CircleShape()
		: m_Radius(DEFAULT_RADIUS), m_PointCount(DEFAULT_POINT_COUNT)
	{
		calculatePoints();
	}

	void CircleShape::draw(Window& window) const
	{
		//number of points includes center point and duplicated first circle point
		window.drawCircle(m_VertexArray, (unsigned int)m_PointCount + 2, getTransformMatrix(), m_FillColor);
	}

	float CircleShape::getRadius() const
	{
		return m_Radius;
	}
	void CircleShape::setRadius(float radius)
	{
		m_Radius = radius;
		calculatePoints();
	}
	std::size_t CircleShape::getPointCount() const
	{
		return m_PointCount;
	}
	void CircleShape::setPointCount(std::size_t pointCount)
	{
		if (pointCount < 3) return;

		m_PointCount = pointCount;
		calculatePoints();
	}
	void CircleShape::calculatePoints()
	{
		//Calculate an array of points around a circle to send to m_VertexBuffer
		//The circle will be drawn using a triangle fan.

		std::vector<float> points;

		//first point is the center point
		points.push_back(0.0f);
		points.push_back(0.0f);

		//rest of the points are calculated along the circle
		float angle = 0.0f;
		float increment = 2 * (float)M_PI / (float)m_PointCount;
		for (int i = 0; i < m_PointCount * 2; i+=2)
		{
			points.push_back(std::cos(angle) * m_Radius); //x
			points.push_back(std::sin(angle) * m_Radius); //y
			angle += increment;
		}

		//last point is a duplicate of the first point
		points.push_back(points[2]);
		points.push_back(points[3]);

		m_VertexBuffer.sendData(points.data(), (unsigned int)points.size() * sizeof(float));
	}
}