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

	//static cocos2d::CCScene* scene();

//	virtual void draw();

	 void menuOkCallback(CCObject* pSender);
	 void menuCancelCallback(CCObject* pSender);

	CREATE_FUNC(GameOverScene);

};

#endif /* GAMEOVERSCENE_H_ */
