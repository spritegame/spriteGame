/*
 * GamePassScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GamePassScene_H_
#define GamePassScene_H_

#include "GameBaseDialog.h"

class GamePassScene: public GameBaseDialog {
public:
	GamePassScene();
	~GamePassScene();

	virtual bool init();
	virtual void drawView();
	void buttonBackCallback(CCObject* pSender);
	void buttonPlayAgainCallback(CCObject* pSender);
	void buttonPlayNextCallback(CCObject* pSender);

	/*
	 * 返回
	 */
	void back();
	/**
	 * 重新开始
	 */
	void playAgain();
	/**
	 * 下一关卡
	 */
	void playNext();

	CREATE_FUNC(GamePassScene);

};

#endif /* GamePassScene_H_ */
