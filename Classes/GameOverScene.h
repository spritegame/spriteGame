/*
 * GameOverScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GAMEOVERSCENE_H_
#define GAMEOVERSCENE_H_

#include "cocos2d.h"

class GameOverScene: public cocos2d::CCLayer {
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(GameOverScene);

};

#endif /* GAMEOVERSCENE_H_ */
