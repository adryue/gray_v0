#include "Color.h"

namespace gray
{
	Color::Color() :
		r(255), g(255), b(255), a(255)
	{ }

	Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
		: r(red), b(blue), g(green), a(alpha)
	{ }

	float Color::rFloat() const
	{
		return (float)r / 255.0f;
	}

	float Color::gFloat() const
	{
		return (float)g / 255.0f;
	}

	float Color::bFloat() const
	{
		return (float)b / 255.0f;
	}

	float Color::aFloat() const
	{
		return (float)a / 255.0f;
	}

	const Color Color::Black(0, 0, 0);
	const Color Color::White(255, 255, 255);
	const Color Color::Red(255, 0, 0);
	const Color Color::Green(0, 255, 0);
	const Color Color::Blue(0, 0, 255);
	const Color Color::Yellow(255, 255, 0);
	const Color Color::Magenta(255, 0, 255);
	const Color Color::Cyan(0, 255, 255);
}