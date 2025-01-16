#include "GLGraphics.h"

namespace SDLFramework {
	GLGraphics* GLGraphics::Instance() {
		if (sInstance == nullptr) {
			Graphics::Instance();
		}

		return static_cast<GLGraphics*>(sInstance);
	}

	GLGraphics::GLGraphics() {
		sInitialized = Init();
	}

	GLGraphics::~GLGraphics() {
		SDL_GL_DeleteContext(mWindow);
	}

	void GLGraphics::ClearBackBuffer() {
		glClearDepth(1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GLGraphics::Render() {
		glBegin(GL_TRIANGLES);
		//If we want color, color NEEDS to be applied first
		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 500.0);
		glVertex2f(500.0f, 500.0f);

		glEnd();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		SDL_GL_SwapWindow(mWindow);
	}

	bool GLGraphics::Init() {
		glContext = SDL_GL_CreateContext(mWindow);
		if (glContext == nullptr) {
			std::cerr << "SDL_GL_Context could not be created!" << SDL_GetError() << std::endl;
			return false;
		}

		GLenum error = glewInit();
		if (error != GLEW_OK) {
			std::cerr << "Could not initialize glew!" << glewGetErrorString(error) << std::endl;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		return true;
	}
}