/*
 * GameOverScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GAMEOVERSCENE_H_
#define GAMEOVERSCENE_H_

#include "GameBaseDialog.h"

class GameOverScene: public GameBaseDialog {
public:
	GameOverScene();
	~GameOverScene();

	virtual bool init();
	virtual void drawView();
	void buttonBackCallback(CCObject* pSender);
	void buttonPlayAgainCallback(CCObject* pSender);

	/*
	 * 返回
	 */
	void back();
	/**
	 * 重新开始
	 */
	void playAgain();


	CREATE_FUNC(GameOverScene);

};

#endif /* GAMEOVERSCENE_H_ */
