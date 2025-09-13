#pragma once

namespace gray
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		void sendData(const void* data, unsigned int size);

		void bind() const;
		void unbind() const;

	private:
		unsigned int m_ID;
	};
}