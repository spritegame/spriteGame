/*
 * SceneManager.cpp
 *
 *  Created on: 2013-1-13
 *      Author: allin.dev
 */
#include "cocos2d.h"
#include "SceneManager.h"
#include "GameLoading.h"
#include "GameMenuScene.h"
#include "GameOverScene.h"
#include "GameHelpScene.h"
#include "HelloWorldScene.h"
#include "SpriteGrid.h"

USING_NS_CC;

SceneManager* SceneManager::m_pSharedGameManager = NULL;

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
}

SceneManager* SceneManager::sharedGameManager() {
	if (m_pSharedGameManager == NULL) {
		m_pSharedGameManager = new SceneManager();
		if (!m_pSharedGameManager || !m_pSharedGameManager->init()) {
			CC_SAFE_DELETE(m_pSharedGameManager);
		}
	}

	return m_pSharedGameManager;

}

void SceneManager::purgeSharedGameManager() {
	CC_SAFE_DELETE(m_pSharedGameManager);
}

bool SceneManager::init() {
	bool bRet = false;
	do {
//		System::Init();

//		CCSpriteFrameCache* cache =CCSpriteFrameCache::sharedSpriteFrameCache();
//		cache->addSpriteFramesWithFile("images-hd.plist", "images-hd.png");
		/*
		 if (System::IsPad())
		 {
		 cache->addSpriteFramesWithFile("images-hd.plist", "images-hd.png");
		 }
		 else
		 {
		 CCDirector::sharedDirector()->setDisplayStats(true);
		 //			CCDirector::sharedDirector()->enableRetinaDisplay(true);
		 cache->addSpriteFramesWithFile("images.plist", "images.png");
		 }
		 */
		bRet = true;

	} while (0);

	return bRet;
}

void SceneManager::runScene(SceneId id) {

	CCScene* newScene = NULL;

	switch (id) {
	case SCENE_LOADING:
		newScene = GameLoading::scene();
		break;
	case SCENE_MENU:
//		SoundManager::sharedSoundManager()->StopMusic();
//		newScene = HelloWorld::scene();
		newScene = GameMenuScene::scene();
		break;

	case SCENE_PLAY:
//		SoundManager::sharedSoundManager()->PlayMusic();
//		newScene = GameScene::create();
		//newScene = HelloWorld::scene();

	    newScene = SpriteGrid::scene();
		break;

	case SCENE_GAMEOVER:
		//newScene = GameOverScene::scene();
		break;

	case SCENE_HELP:
		newScene = GameHelpScene::scene();
		break;

	}

	if (newScene) {
		if (CCDirector::sharedDirector()->getRunningScene() == NULL)
			CCDirector::sharedDirector()->runWithScene(newScene);
		else
			CCDirector::sharedDirector()->replaceScene(newScene);

	}

}

