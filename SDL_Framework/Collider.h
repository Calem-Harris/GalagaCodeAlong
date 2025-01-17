#pragma once
#include "GLTexture.h"

namespace SDLFramework {

	//Abstract class
	class Collider : public GameEntity {
	public:
		enum class ColliderType {Box, Circle};

		Collider(ColliderType type);
		virtual ~Collider();

		virtual void Render();

		virtual Vector2 GetFurthestPoint() = 0;

		ColliderType GetType();

	protected:
		ColliderType mType;

		static const bool DEBUG_COLLIDERS = true;
		GLTexture* mDebugTexture;

		void SetDebugTexture(GLTexture* texture);
	};
}