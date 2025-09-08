#pragma once

#include "Vector.h"

namespace gray
{
	class Transformable
	{
	public:
		Vector2f getPosition();
		void setPosition(const Vector2f& position);

		float getRotation();
		void setRotation(float rotation);

		Vector2f getScale();
		void setScale(const Vector2f& scale);

		Vector2f getOrigin();
		void setOrigin(const Vector2f& origin);

	private:
		Vector2f m_Position;
		float m_Rotation;
		Vector2f m_Scale;
		Vector2f origin;
	};
}