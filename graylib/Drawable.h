#pragma once

namespace gray
{
	class Window;

	class Drawable
	{
	protected:
		friend class Window;
		virtual void draw(Window& window) const = 0;
	};
}