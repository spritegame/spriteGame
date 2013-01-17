/*
 * LoadingScene.cpp
 *
 *  Created on: 2013-1-13
 *      Author: allin.dev
 */

#include "GameLoading.h"
#include "SceneManager.h"
#include "SoundManager.h"

USING_NS_CC;

GameLoading::GameLoading():m_iResource_count(0){
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


//	CCTextureCache::sharedTextureCache()->addImage("loading_bg.jpg");
	CCSprite* loadingBg = CCSprite::create("loading_bg.jpg");
	loadingBg->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	addChild(loadingBg, 0);

	SoundManager::sharedSoundManager();

	std::string res[] = {
	        "CloseNormal.png",
	        "CloseSelected.png",
	        "HelloWorld.png",
/*	       
			"menu1.jpg",
	        "menu2.jpg",
	        "menu3.jpg",
	        "menu4.jpg",

			"popDialogBg.png",
	        "btnOk.png",
	        "btnCancel.png",
			*/
	 };

	 int res_len = sizeof(res) / sizeof(res[0]);

	 for(int i = 0; i != res_len; ++i){
		 preLoadResource(res[i].c_str());
	 }


	return true;

}

void GameLoading::preLoadResource(char const* resource){
	if(resource){
		++m_iResource_count;
		CCTextureCache::sharedTextureCache()->addImageAsync(resource, this, callfuncO_selector(GameLoading::loadingCallBack));
		CCLog("add resource: %d",m_iResource_count);
	}
}


void GameLoading::loadingCallBack(CCObject* obj) {
	--m_iResource_count;
	CCLog("loadingCallBack _resource_count:%d",m_iResource_count);
	if(m_iResource_count == 0){
		CCLog("loading finish...");
		SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
	}
}

