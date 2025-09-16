#include "Shape.h"

#include "Window.h"

namespace gray
{
	Shape::Shape()
	{
		//data will be formated like this:
		//[X1, Y1, X2, Y2, X3, Y3...]
		VertexBufferLayout layout;
		layout.push<float>(2);

		m_VertexArray.addVertexBuffer(m_VertexBuffer, layout);
	}
	void Shape::draw(Window& window) const
	{
		window.drawShape(m_VertexArray, getTransformMatrix(), m_FillColor);
	}

	const VertexBuffer& Shape::getVertexBuffer() const
	{
		return m_VertexBuffer;
	}
	const VertexArray& Shape::getVertexArray() const
	{
		return m_VertexArray;
	}

	Color Shape::getFillColor() const
	{
		return m_FillColor;
	}
	void Shape::setFillColor(const Color& color)
	{
		m_FillColor = color;
	}

}