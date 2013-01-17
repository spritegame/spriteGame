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
	void menuOkCallback(CCObject* pSender);
	void menuCancelCallback(CCObject* pSender);

	void back();
	void playAgain();

	CREATE_FUNC(GamePauseScene);

};

#endif /* GAMEPAUSESCENE_H_ */
