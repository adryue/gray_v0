#pragma once

#include "Drawable.h"
#include "Transformable.h"
#include "Color.h"
#include "Vector.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace gray
{
	class Shape : public Drawable, public Transformable
	{
	public:
		Shape();

		void draw(Window& window) const override;

		const VertexBuffer& getVertexBuffer() const;
		const VertexArray& getVertexArray() const;

		Color getFillColor() const;
		void setFillColor(const Color& color);

	protected:
		VertexBuffer m_VertexBuffer;
		VertexArray m_VertexArray;
		Color m_FillColor;
		Color m_OutlineColor;
	};
}