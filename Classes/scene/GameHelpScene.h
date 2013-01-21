/*
 * GameHelpScene.h
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#ifndef GAMEHELPSCENE_H_
#define GAMEHELPSCENE_H_

#include "cocos2d.h"

class GameHelpScene: public cocos2d::CCLayer {
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(GameHelpScene);

};

#endif /* GAMEHELPSCENE_H_ */
