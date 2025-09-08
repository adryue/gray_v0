#include "VertexArray.h"

#include <glad/gl.h>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.bind();
	auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout.getStride(), (void*)offset);
		offset += elements[i].count * VertexBufferElement::getSizeOfType(elements[i].type);
	}
}

void VertexArray::bind()
{
	glBindVertexArray(m_ID);
}
void VertexArray::unbind()
{
	glBindVertexArray(0);
}