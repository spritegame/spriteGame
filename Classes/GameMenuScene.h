/*
 * GameHelpScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GAMEMENUSCENE_H_
#define GAMEMENUSCENE_H_

#include "cocos2d.h"

class GameMenuScene: public cocos2d::CCLayer {
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(GameMenuScene);

};

#endif /* GAMEMENUSCENE_H_ */
