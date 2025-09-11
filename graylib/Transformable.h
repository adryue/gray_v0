#pragma once

#include <glm/glm.hpp>
#include "Vector.h"

// In a model-view-projection system of matrices, the Transformable class acts as the model matrix,
// i.e. where the model exists in the world.

namespace gray
{
	class Transformable
	{
	public:
		Transformable();

		Vector2f getPosition();
		void setPosition(const Vector2f& position);

		float getRotation();
		void setRotation(float rotation);

		Vector2f getScale();
		void setScale(const Vector2f& scale);

		Vector2f getOrigin();
		void setOrigin(const Vector2f& origin);

		glm::mat4 getMatrix();

	private:
		Vector2f m_Position;
		float m_Rotation; //rotation in degrees
		Vector2f m_Scale;
		Vector2f m_Origin;
	};
}