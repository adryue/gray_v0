#pragma once

#include <iostream>

namespace gray
{
	template<typename T>
	class Vector2
	{
	public:
		T x;
		T y;

		Vector2() : x{}, y{}
		{ }
		Vector2(T x, T y) : x{ x }, y{ y }
		{ }

		Vector2& operator=(const Vector2& other)
		{
			if (this == &other)
				return *this;

			this->x = other.x;
			this->y = other.y;

			return *this;
		}

		Vector2& operator+=(const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		Vector2& operator-=(const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}
		friend Vector2 operator+(Vector2 lhs, const Vector2& rhs)
		{
			lhs += rhs;
			return lhs;
		}
		friend Vector2 operator-(Vector2 lhs, const Vector2& rhs)
		{
			lhs -= rhs;
			return lhs;
		}
		Vector2 operator-()
		{
			return { -x, -y };
		}
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vec)
		{
			os << "(" << vec.x << ", " << vec.y << ")";
			return os;
		}
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
}