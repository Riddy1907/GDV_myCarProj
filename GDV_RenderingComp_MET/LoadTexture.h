#define STB_IMAGE_IMPLEMENTATION
/* image reading library */
#include "stb_image.h"

// load a image from a file. Store the image data as texture and return the ID of the texture
GLuint LoadTexture(const char *filename)
{
	GLuint textureID = 0;
	int x, y;
	unsigned char *data = stbi_load(filename, &x, &y, 0, 4);
	if (data)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		stbi_image_free(data);
	}
	return textureID;
}
