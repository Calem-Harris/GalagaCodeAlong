#pragma once
#include "Graphics.h"
#include "glew.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "ShaderUtil.h"
#include "Texture.h"


namespace SDLFramework {

	class GLGraphics : public Graphics {
	public:
		static GLGraphics* Instance();

		GLGraphics();
		~GLGraphics();

		void ClearBackBuffer() override;
		void Render() override;

	private:
		bool Init() override;

		SDL_GLContext glContext;
	};
}