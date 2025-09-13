#include "Transformable.h"

#include <glm/gtc/matrix_transform.hpp>

namespace gray
{
	Transformable::Transformable()
		: m_Position(), m_Rotation(0), m_Scale(1.0f, 1.0f), m_Origin()
	{
	}
	Vector2f Transformable::getPosition()
	{
		return m_Position;
	}
	void Transformable::setPosition(const Vector2f& position)
	{
		m_Position = position;
	}
	float Transformable::getRotation()
	{
		return m_Rotation;
	}
	void Transformable::setRotation(float rotation)
	{
		m_Rotation = rotation;
	}
	Vector2f Transformable::getScale()
	{
		return m_Scale;
	}
	void Transformable::setScale(const Vector2f& scale)
	{
		m_Scale = scale;
	}
	Vector2f Transformable::getOrigin()
	{
		return m_Origin;
	}
	void Transformable::setOrigin(const Vector2f& origin)
	{
		m_Origin = origin;
	}

	glm::mat4 Transformable::getTransformMatrix() const
	{
		glm::mat4 transform(1.0f);
		transform = glm::translate(transform, glm::vec3(m_Position.x, m_Position.y, 0.0f));
		transform = glm::rotate(transform, glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		transform = glm::scale(transform, glm::vec3(m_Scale.x, m_Scale.y, 0.0f));
		return transform;
	}
}