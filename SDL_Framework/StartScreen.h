#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "GLTexture.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {
public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	void ResetAnimation();

	int SelectedMode();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	InputManager* mInputManager;

	//Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;


	//Top Bar Entities
	//Empty GameEntity/GameObject
	GameEntity* mTopBar;
	GLTexture* mPlayerOne;
	GLTexture* mPlayerTwo;
	GLTexture* mHiScore;
	Scoreboard* mPlayerOneScore;
	Scoreboard* mPlayerTwoScore;
	Scoreboard* mTopScore;

	//Logo Entities
	GameEntity* mLogoHolder;
	GLTexture* mLogo;
	AnimatedTexture* mAnimatedLogo;

	//Play Mode
	GameEntity* mPlayModes;
	GLTexture* mOnePlayerMode;
	GLTexture* mTwoPlayerMode;
	GLTexture* mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffsetPos;
	int mSelectedMode;

	//Bottom Bar
	GameEntity* mBottomBar;
	GLTexture* mNamco;
	GLTexture* mDates;
	GLTexture* mRights;
};