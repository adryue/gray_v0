#pragma once

#include "Drawable.h"
#include "Transformable.h"
#include "Color.h"
#include "Vector.h"

namespace gray
{
	class Shape : public Drawable, public Transformable
	{
	public:
		Color getFillColor();
		void setFillColor(const Color& color);

	private:
		Color m_Color;
	};
}