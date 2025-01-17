#pragma once
#include "Graphics.h"
#include "glew.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "ShaderUtil.h"
#include "GLTexture.h"


namespace SDLFramework {

	class GLGraphics : public Graphics {
	public:
		static GLGraphics* Instance();

		GLGraphics();
		~GLGraphics();

		void ClearBackBuffer() override;
		void Render() override;

		void DrawTexture(GLTexture* glTex, SDL_Rect* srcRect = nullptr,
			SDL_Rect* dstRect = nullptr, float angle = 0.0f,
			SDL_RendererFlip flip = SDL_FLIP_NONE);

	private:
		bool Init() override;

		SDL_GLContext glContext;
	};
}