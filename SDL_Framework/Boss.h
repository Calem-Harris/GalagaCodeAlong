#pragma once
#include "Enemy.h"
#include "CaptureBeam.h"
#include "Random.h"

using namespace SDLFramework;

class Boss : public Enemy {
public:
	static void CreateDivePaths();

	void Dive(int type = 0) override;

	Boss(int path, int index, bool challenge);
	~Boss();

private:
	static std::vector<std::vector<Vector2>> sDivePaths;

	bool mCaptureDive;
	int mCurrentPath;
	bool mCapturing;

	CaptureBeam* mCaptureBeam;

	void HandleCaptureBeam();

	Vector2 LocalFormationPosition() override;

	void HandleDiveState() override;
	void HandleDeadState() override;

	void RenderDiveState() override;
	void RenderDeadState() override;
};