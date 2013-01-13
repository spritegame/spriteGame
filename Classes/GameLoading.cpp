/*
 * LoadingScene.cpp
 *
 *  Created on: 2013-1-13
 *      Author: allin
 */

#include "GameLoading.h"
#include "SceneManager.h"

USING_NS_CC;

#define TOTAL_RESOURCE 9

GameLoading::GameLoading():_resource_count(0){
}

GameLoading::~GameLoading(){
}


CCScene* GameLoading::scene() {
	CCScene* scene = NULL;

	do {

		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		GameLoading* layer = GameLoading::create();

		scene->addChild(layer);

	} while (0);

	return scene;
}

bool GameLoading::init() {

	// super init first
	if (!CCLayer::init()) {
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	CCLog("loading_bg 1");
	CCTextureCache::sharedTextureCache()->addImage("loading_bg.jpg");
	CCLog("loading_bg 2");
	CCSprite* loadingBg = CCSprite::create("loading_bg.jpg");
	CCLog("loading_bg 3");
	loadingBg->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	addChild(loadingBg, 0);
	CCLog("loading_bg 4");

	CCTextureCache::sharedTextureCache()->addImageAsync("CloseNormal.png", this,
			callfuncO_selector(GameLoading::loadingCallBack));

	CCLog("loading_bg 5");

	CCTextureCache::sharedTextureCache()->addImageAsync("CloseSelected.png",
			this, callfuncO_selector(GameLoading::loadingCallBack));
	CCLog("loading_bg 6");

//	CCTextureCache::sharedTextureCache()->addImageAsync("HelloWorld.png", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 7");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_1_1.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 8");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_1.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 9");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_2_1.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 10");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_2.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 11");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_3_1.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 12");
//
//	CCTextureCache::sharedTextureCache()->addImageAsync("game_bg_3.jpg", this,
//			callfuncO_selector(GameLoading::loadingCallBack));
//	CCLog("loading_bg 13");


	return true;

}

void GameLoading::loadingCallBack() {
	++_resource_count;
	CCLog("loadingCallBack _resource_count:%d",_resource_count);
	if(_resource_count >= TOTAL_RESOURCE){
		CCLog("loading finish...");
		SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
	}
}

