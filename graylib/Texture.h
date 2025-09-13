#pragma once

#include <string>

namespace gray
{
	class Texture
	{
	private:
		unsigned int m_ID;
		int m_Width, m_Height, m_nrChannels; //number of color channels (number of bytes per pixel)
		std::string m_Filename;
	public:
		Texture(const std::string& filename);
		~Texture();

		void bind(unsigned int slot = 0);
		void unbind();
	};
}