#pragma once

#include <glm/glm.hpp>
#include "Vector.h"

namespace gray
{
	class Camera
	{
	public:
		Camera();

		glm::mat4 getViewMatrix() const;
		glm::mat4 getProjectionMatrix() const;

		Vector2f getCenter();
		void setCenter(Vector2f center);
		void move(Vector2f offset);

		Vector2f getSize();
		void setSize(Vector2f size);

		float getRotation();
		void setRotation(float rotation);
		void rotate(float rotation);

	private:
		Vector2f m_Center;
		Vector2f m_Size; //size of the viewing rectangle
		float m_Rotation; //rotation around the z axis, in degrees
	};
}