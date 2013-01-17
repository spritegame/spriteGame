/*
 * GameMenuScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameMenuScene.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "SlidingMenu.h"
#include "GameOverScene.h"
#include "GamePassScene.h"
#include "GamePauseScene.h"

USING_NS_CC;

CCScene* GameMenuScene::scene() {
	CCScene* scene = NULL;

	do {

		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		CCLayer* layer = GameMenuScene::create();

		scene->addChild(layer);

	} while (0);

	return scene;
}

bool GameMenuScene::init() {

	bool bRet = false;
	do {

		CC_BREAK_IF(! CCLayer::init());

		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		//music button
		CCMenuItemImage *pMusicItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(GameMenuScene::buttonMusicCallback));
		CC_BREAK_IF(! pMusicItem);

		pMusicItem->setPosition(ccp(origin.x + pMusicItem->getContentSize().width ,
				origin.y + pMusicItem->getContentSize().height));


		//sound button
		CCMenuItemImage *pSoundItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(GameMenuScene::buttonSoundCallback));
		CC_BREAK_IF(! pSoundItem);
		pSoundItem->setPosition(ccp(origin.x + pSoundItem->getContentSize().width*2 ,
				origin.y + pSoundItem->getContentSize().height));




		//close button
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(GameMenuScene::buttonCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
				origin.y + pCloseItem->getContentSize().height));

		CCMenu* pMenu = CCMenu::create(pCloseItem, pMusicItem, pSoundItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		this->addChild(pMenu, 1);


		//check music
		if(SoundManager::sharedSoundManager()->isMusicPlaying()){
			SoundManager::sharedSoundManager()->playMusic();
		}


		//bg
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* pSprite = CCSprite::create("HelloWorld.png");
		CC_BREAK_IF(! pSprite);
		pSprite->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pSprite, 0);

		//SlidingMenu
		createGameLevelSlidingMenu();

		bRet = true;
	} while (0);

	return bRet;
}

void GameMenuScene::createGameLevelSlidingMenu() {
	//read game level from somewhere...

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCArray* ccArray = CCArray::createWithCapacity(4);

	CCMenuItemImage* pItem1 = CCMenuItemImage::create("menu1.jpg", "menu1.jpg", this,
			menu_selector(GameMenuScene::buttonPlayCallback));
	CCMenuItemImage* pItem2 = CCMenuItemImage::create("menu2.jpg", "menu2.jpg", this,
			menu_selector(GameMenuScene::buttonPlayCallback));
	CCMenuItemImage* pItem3 = CCMenuItemImage::create("menu3.jpg", "menu3.jpg", this,
			menu_selector(GameMenuScene::buttonPlayCallback));
	CCMenuItemImage* pItem4 = CCMenuItemImage::create("menu4.jpg", "menu4.jpg", this,
			menu_selector(GameMenuScene::buttonPlayCallback));

	ccArray->addObject(pItem1);
	ccArray->addObject(pItem2);
	ccArray->addObject(pItem3);
	ccArray->addObject(pItem4);
	SlidingMenuGrid* slidingMenuGrid = SlidingMenuGrid::create(ccArray, 1, 1,
			CCPointMake(size.width / 2,size.height / 2), CCPointMake(0,0));
	slidingMenuGrid->setPosition(0, 0);
	this->addChild(slidingMenuGrid, 2);

}
void GameMenuScene::buttonMusicCallback(CCObject* pSender) {
	SoundManager::sharedSoundManager()->setMusic(!SoundManager::sharedSoundManager()->isMusicPlaying());
}

void GameMenuScene::buttonSoundCallback(CCObject* pSender) {
	SoundManager::sharedSoundManager()->setSoundEffect(!SoundManager::sharedSoundManager()->isSoundEffectPlaying());
}

void GameMenuScene::buttonPlayCallback(CCObject* pSender) {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}

void GameMenuScene::buttonCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();
}

