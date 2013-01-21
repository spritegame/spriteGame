/*
 * GameMenuScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameMenuScene.h"
#include "../SceneManager.h"
#include "../SlidingMenu.h"
#include "../SoundManager.h"
#include "../SpriteGameResource.h"
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
		CCMenuItemToggle* pMusicItem = CCMenuItemToggle::createWithTarget(this,
				menu_selector(GameMenuScene::buttonMusicCallback),
				CCMenuItemSprite::create(
						CCSprite::createWithSpriteFrameName("btnSoundOn.png"),
						CCSprite::createWithSpriteFrameName("btnSoundOn.png")),
				CCMenuItemSprite::create(
						CCSprite::createWithSpriteFrameName("btnSoundOff.png"),
						CCSprite::createWithSpriteFrameName("btnSoundOff.png")),
				NULL);
		CC_BREAK_IF(! pMusicItem);

		//check music
		if(SoundManager::sharedSoundManager()->isMusicEnable()){
			pMusicItem->setSelectedIndex(0);
			SoundManager::sharedSoundManager()->playMusic();
		}else{
			pMusicItem->setSelectedIndex(1);
		}

		pMusicItem->setPosition(ccp(origin.x + pMusicItem->getContentSize().width ,
				origin.y + pMusicItem->getContentSize().height));


		//sound button
		CCMenuItemSprite *pSoundItem = CCMenuItemSprite::create(
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				this,
				menu_selector(GameMenuScene::buttonSoundCallback));
		CC_BREAK_IF(! pSoundItem);
		pSoundItem->setPosition(ccp(origin.x + pSoundItem->getContentSize().width*2 ,
				origin.y + pSoundItem->getContentSize().height));



		//close button
		CCMenuItemSprite *pCloseItem = CCMenuItemSprite::create(
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				this,
				menu_selector(GameMenuScene::buttonCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
				origin.y + pCloseItem->getContentSize().height));

		CCMenu* pMenu = CCMenu::create(pCloseItem, pMusicItem, pSoundItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		this->addChild(pMenu, 1);



		//bg
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* pSprite = CCSprite::create(s_test_image);
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




//	CCMenuItemSprite* pItem1 = CCMenuItemSprite::create("menu1.jpg", "menu1.jpg", this,
//			menu_selector(GameMenuScene::buttonPlayCallback));
	CCMenuItemSprite * pItem1 = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("menu1.jpg"),
			CCSprite::createWithSpriteFrameName("menu1.jpg"), this,
			menu_selector(GameMenuScene::buttonPlayCallback));

	CCMenuItemSprite* pItem2 = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("menu2.jpg"),
			CCSprite::createWithSpriteFrameName("menu2.jpg"), this,
			menu_selector(GameMenuScene::buttonPlayCallback));

	CCMenuItemSprite* pItem3 = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("menu3.jpg"),
			CCSprite::createWithSpriteFrameName("menu4.jpg"), this,
			menu_selector(GameMenuScene::buttonPlayCallback));

	CCMenuItemSprite* pItem4 = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("menu4.jpg"),
			CCSprite::createWithSpriteFrameName("menu4.jpg"), this,
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
	SoundManager::sharedSoundManager()->setMusicEnable(!SoundManager::sharedSoundManager()->isMusicPlaying());
}

void GameMenuScene::buttonSoundCallback(CCObject* pSender) {
	SoundManager::sharedSoundManager()->setSoundEffectEnable(!SoundManager::sharedSoundManager()->isSoundEffectEnable());
}

void GameMenuScene::buttonPlayCallback(CCObject* pSender) {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}

void GameMenuScene::buttonCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();
}

