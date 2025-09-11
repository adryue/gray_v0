#pragma once

#include <cstddef>
#include <vector>
#include "Shape.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

#include "Vector.h"

namespace gray
{
	class TriangleShape : public Shape
	{
	public:
		TriangleShape();
		void draw() override;

		Vector2f getPoint(std::size_t index);
		void setPoint(std::size_t index, Vector2f point);

	private:
		Vector2f m_Points[3];

		Shader m_Shader;
		VertexBuffer m_VertexBuffer;
		VertexArray m_VertexArray;

		std::vector<float> pointsToArray(); //formats m_Points into a vector of floats
		void updateVertexBuffer(); //send data from m_Points to m_VertexBuffer
	};
}