#pragma once

class IndexBuffer
{
private:
	unsigned int m_ID;
	unsigned int m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void bind();
	void unbind();

	inline unsigned int getCount() const { return m_Count; }
};