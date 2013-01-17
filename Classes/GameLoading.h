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

	/*
	 * 加载图片资源完成后的回调函数
	 */
	void loadingCallBack(cocos2d::CCObject* obj);
	/*
	 * 预加载游戏资源
	 * 使用addImageAsync加载图片资源
	 */
	void preLoadResource(char const* resource);

private:
	int m_iResource_count;
};


#endif /* GAMELOADING_H_ */
