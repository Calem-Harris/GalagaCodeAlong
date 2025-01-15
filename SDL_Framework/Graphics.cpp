#include "SDLGraphics.h"

namespace SDLFramework {
	//This is how we initialize static members in a class
	//Specifically ones that we do NOT want to be constants!!
	Graphics* Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	//This is where we make this class a singleton
	Graphics* Graphics::Instance() {
		//We are checking to see if sInstance already has an instance of Graphics stored in it
		if (sInstance == nullptr) {
			//If not, create a new instance of Graphics
			sInstance = new SDLGraphics();
		}

		//Returns our Graphics instance AFTER making sure there is one.
		return sInstance;
	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}

	SDL_Texture* Graphics::LoadTexture(std::string path) {
		SDL_Texture* tex = nullptr;

		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			//This means we have failed to find the image
			std::cerr << "Unable to load " << path << ". IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		//We can assume that we were able to create a surface of our image
		//We want to convert from a SDL_Surface to a SDL_Texture

		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		SDL_FreeSurface(surface);

		if (tex == nullptr) {
			std::cerr << "Unable to create a texture from surface! IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		return tex;
	}

	void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dst_Rect,
		float angle, SDL_RendererFlip flip) {
		//SDL_RenderCopyEx(mRenderer, texture, srcRect, dst_Rect, angle, nullptr, flip);
	}

	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

		if (surface == nullptr) {
			std::cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);

		if (tex == nullptr) {
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}

	void Graphics::DrawLine(float startX, float startY, float endX, float endY) {
		SDL_Color color;
		SDL_GetRenderDrawColor(mRenderer, &color.r, &color.g, &color.b, &color.a);
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(mRenderer, (int)startX, (int)startY, (int)endX, (int)endY);
		SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
	}

	//void Graphics::ClearBackBuffer() {
	//	SDL_RenderClear(mRenderer);
	//}

	//void Graphics::Render() {
	//	SDL_RenderPresent(mRenderer);

	//	//glClearDepth(1.0f);
	//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	//glEnableClientState(GL_COLOR_ARRAY);

	//	////This is where we can draw shapes/primitives to the window
	//	//glBegin(GL_TRIANGLES);
	//	////If we want color, color NEEDS to be applied first
	//	//glColor3f(1.0f, 0.0f, 0.0f);

	//	//glVertex2f(0.0f, 0.0f);
	//	//glVertex2f(0.0f, 500.0);
	//	//glVertex2f(500.0f, 500.0f);

	//	//glEnd();

	//	//SDL_GL_SwapWindow(mWindow);
	//}

	Graphics::Graphics() : mRenderer(nullptr) {
		sInitialized = Init();
	}

	Graphics::~Graphics() {
		//Destroy the renderer
		SDL_DestroyRenderer(mRenderer);
		//Destroy the window
		SDL_DestroyWindow(mWindow);
	}

	bool Graphics::Init() {

		//Initialize SDL subsytems
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			//We have failed to initialize
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}

		mWindow = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
		);

		if (mWindow == nullptr) {
			//We have failed to create a window
			std::cerr << "Unable to create Window! SDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}

		//Anything after this can assume that our Window was able to successfully create itself
		// TODO: Maybe uncomment this if we run into problems
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mRenderer == nullptr) {
			//We have failed to create a renderer
			std::cerr << "Unable to get renderer. SDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}

		//glContext = SDL_GL_CreateContext(mWindow);
		//if (glContext == nullptr) {
		//	std::cerr << "SDL_GL_Context could not be created!" << SDL_GetError() << std::endl;
		//	return false;
		//}

		//GLenum error = glewInit();
		//if (error != GLEW_OK) {
		//	std::cerr << "Could not initialize glew!" << glewGetErrorString(error) << std::endl;
		//}

		//Uncomment the below line to change the background to white for position testing
		//SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialize SDL_ttf! TTF Error " << TTF_GetError() << std::endl;
			return false;
		}

		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		//glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		//We can assume EVERYTHING has been built properly
		return true;
	}
}