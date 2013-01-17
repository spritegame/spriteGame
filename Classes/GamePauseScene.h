/*
 * GamePauseScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GAMEPAUSESCENE_H_
#define GAMEPAUSESCENE_H_

#include "GameBaseDialog.h"

class GamePauseScene: public GameBaseDialog {
public:
	GamePauseScene();
	~GamePauseScene();

	virtual bool init();
	virtual void drawView();
	void buttonBackCallback(CCObject* pSender);
	void buttonPlayAgainCallback(CCObject* pSender);
	void buttonPlayContinueCallback(CCObject* pSender);

	/*
	 * 返回
	 */
	void back();
	/**
	 * 重新开始
	 */
	void playAgain();
	/**
	 * 继续游戏
	 */
	void playContinue();

	CREATE_FUNC(GamePauseScene)
	;

};

#endif /* GAMEPAUSESCENE_H_ */
