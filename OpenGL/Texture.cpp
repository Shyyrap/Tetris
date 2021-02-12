#include"Texture.h"
#include<cassert>
#include<iostream>
#define STB_IMAGE_IMPLEMENTATION
#include"STB/stb_image.h"

Texture::Texture(const std::string& fileName):
	mTexture(0)
{
	int width, height, numComponents;
	unsigned char* ImageData = (stbi_load(fileName.c_str(), &width, &height, &numComponents, 4));
	if (ImageData == NULL)
		std::cerr << "Texture loading failed" <<fileName<< std::endl;
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ImageData);
		stbi_image_free(ImageData);
}
Texture::~Texture()
{
	glDeleteTextures(1, &mTexture);
}
void Texture::Bind(unsigned int unit)
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE0+unit);
	glBindTexture(GL_TEXTURE_2D, mTexture);
}