#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace gray
{
	Camera::Camera()
		: m_Rotation(0)
	{
	}
	glm::mat4 Camera::getViewMatrix() const
	{
		glm::mat4 view(1.0f);
		//Note: all transformations have to be the opposite (negative) of what they actually are.
		//e.g. if the camera moves up, the transformation matrix has to move all objects down for the effect to work.
		view = glm::translate(view, glm::vec3(-m_Center.x, -m_Center.y, 0.0f));
		view = glm::rotate(view, glm::radians(-m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		return view;
	}
	glm::mat4 Camera::getProjectionMatrix() const
	{
		return glm::ortho(-m_Size.x * 0.5f, m_Size.x * 0.5f,
						  -m_Size.y * 0.5f, m_Size.y * 0.5f,
						  -1.0f, 1.0f);
		//return glm::ortho(0.0f, m_Size.x, 0.0f, m_Size.y, -1.0f, 1.0f);
	}
	Vector2f Camera::getCenter()
	{
		return m_Center;
	}
	void Camera::setCenter(Vector2f center)
	{
		m_Center = center;
	}
	void Camera::move(Vector2f offset)
	{
		m_Center += offset;
	}
	Vector2f Camera::getSize()
	{
		return m_Size;
	}
	void Camera::setSize(Vector2f size)
	{
		m_Size = size;
	}
	float Camera::getRotation()
	{
		return m_Rotation;
	}
	void Camera::setRotation(float rotation)
	{
		m_Rotation = rotation;
	}
	void Camera::rotate(float rotation)
	{
		m_Rotation += rotation;
	}
}