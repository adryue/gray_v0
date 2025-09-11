#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void addIndexBuffer(const IndexBuffer& ib);

	void bind() const;
	void unbind() const;

private:
	unsigned int m_ID;
};