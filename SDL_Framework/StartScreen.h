#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "SDLTexture.h"

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
	SDLTexture* mPlayerOne;
	SDLTexture* mPlayerTwo;
	SDLTexture* mHiScore;
	Scoreboard* mPlayerOneScore;
	Scoreboard* mPlayerTwoScore;
	Scoreboard* mTopScore;

	//Logo Entities
	GameEntity* mLogoHolder;
	SDLTexture* mLogo;
	AnimatedTexture* mAnimatedLogo;

	//Play Mode
	GameEntity* mPlayModes;
	SDLTexture* mOnePlayerMode;
	SDLTexture* mTwoPlayerMode;
	SDLTexture* mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffsetPos;
	int mSelectedMode;

	//Bottom Bar
	GameEntity* mBottomBar;
	SDLTexture* mNamco;
	SDLTexture* mDates;
	SDLTexture* mRights;
};