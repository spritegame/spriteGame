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

	/**
	 * 背景音乐开关回调
	 */
	void buttonMusicCallback(CCObject* pSender);
	/**
	 * 音效开光回调
	 */
	void buttonSoundCallback(CCObject* pSender);
	/**
	 * 开始游戏回调
	 */
	void buttonPlayCallback(CCObject* pSender);

	/**
	 * 退出游戏回调
	 */
	void buttonCloseCallback(CCObject* pSender);

	/*
	 * 创建游戏关卡滑动菜单
	 */
	void createGameLevelSlidingMenu();

	CREATE_FUNC(GameMenuScene);

};

#endif /* GAMEMENUSCENE_H_ */
