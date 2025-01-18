#pragma once
#include <glew.h>
#include "Texture.h"

namespace SDLFramework {

	class GLTexture : public Texture {
	public:
		GLuint ID;
		GLuint Width, Height;
		GLuint Internal_Format;
		GLuint Image_Format;
		GLuint Wrap_S;
		GLuint Wrap_T;
		GLuint Filter_Min;
		GLuint Filter_Max;
		int mode;
		bool rendered;
		unsigned char* data;
		SDL_RendererFlip Flip;
		SDL_Surface* mSurface;

		GLTexture(std::string filename, bool managed = true);
		GLTexture(std::string filename, int x, int y, int width, int height, bool managed = true);
		//The below constructor makes a TEXT object instead of using an image
		GLTexture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = true);

		void SetSurfaceTexture(std::string filename, bool managed = true);
		void SetSurfaceTextTexture(std::string text, std::string filename,
			int size, SDL_Color color, bool managed = true);

		void Generate();

		~GLTexture();

		void Render() override;
	};
}