#include "Shape.h"

#include "Window.h"

namespace gray
{
	void Shape::draw(Window& window) const
	{
		window.drawShape(m_VertexArray, getTransformMatrix(), m_FillColor);
	}

	const VertexBuffer& Shape::getVertexBuffer() const
	{
		return m_VertexBuffer;
	}
	const IndexBuffer& Shape::getIndexBuffer() const
	{
		return m_IndexBuffer;
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