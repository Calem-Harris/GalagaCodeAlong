#pragma once
#include "BezierPath.h"
#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "Player.h"

using namespace SDLFramework;

class Enemy : public PhysEntity {
public:
	//If we add new states here, make sure to update HandleStates in the .cpp
	enum States { FlyIn, InFormation, Diving, Dead };
	static void CreatePaths();

	States CurrentState();

	Enemy(int path);
	virtual ~Enemy();

	void Update() override;
	void Render() override;

protected:
	static std::vector<std::vector<Vector2>> sPaths;
	static Player* sPlayer;

	Timer* mTimer;

	Texture* mTexture;

	States mCurrentState;

	unsigned mCurrentPath;

	unsigned mCurrentWaypoint;
	const float EPSILON = 50.0f;

	float mSpeed;

	virtual void HandleFlyInState();
	virtual void HandleInFormationState();
	virtual void HandleDiveState();
	virtual void HandleDeadState();

	void HandleStates();

	virtual void RenderFlyInState();
	virtual void RenderInFormationState();
	virtual void RenderDiveState();
	virtual void RenderDeadState();

	void RenderStates();
};