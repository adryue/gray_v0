#include "Shape.h"

namespace gray
{
	Color Shape::getFillColor()
	{
		return m_Color;
	}

	void Shape::setFillColor(const Color& color)
	{
		m_Color = color;
	}

}