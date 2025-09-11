#pragma once

#include <cstdint>

namespace gray
{
	class Color
	{
	public:
		Color();
		Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);

		//functions to convert rgba values from uint8_t to floats (0 -> 0.0f, 255 -> 1.0f)
		float rFloat() const;
		float gFloat() const;
		float bFloat() const;
		float aFloat() const;

		std::uint8_t r, g, b, a;

		static const Color Black;
		static const Color White;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Magenta;
		static const Color Cyan;
	};
}