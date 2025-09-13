#pragma once

namespace gray
{
	class IndexBuffer
	{
	private:
		unsigned int m_ID;
		unsigned int m_Count;
	public:
		IndexBuffer();
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void sendData(const unsigned int* data, unsigned int count);

		void bind() const;
		void unbind() const;

		inline unsigned int getCount() const { return m_Count; }
	};
}