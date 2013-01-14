/*
 * LoadingScene.h
 *
 *  Created on: 2013-1-13
 *      Author: allin.dev
 */

#ifndef GAMELOADING_H_
#define GAMELOADING_H_

#include "cocos2d.h"
class GameLoading : public cocos2d::CCLayer{
public:

	GameLoading();
	~GameLoading();

	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(GameLoading);

private:
	// scheduled Update
	void loadingCallBack();

private:
	int _resource_count;
};


#endif /* GAMELOADING_H_ */
