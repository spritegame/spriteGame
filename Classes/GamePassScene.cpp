/*
 * GamePassScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePassScene.h"
#include "SceneManager.h"

USING_NS_CC;

GamePassScene::GamePassScene() {
}
GamePassScene::~GamePassScene() {
}

bool GamePassScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnBack = CCMenuItemImage::create("btnBack.png", "btnBack.png",
			this, menu_selector(GamePassScene::buttonBackCallback));

	CCMenuItemImage* btnPlayAgain = CCMenuItemImage::create("btnResume.png",
			"btnResume.png", this,
			menu_selector(GamePassScene::buttonPlayAgainCallback));

	CCMenuItemImage* btnPlayNext = CCMenuItemImage::create("btnNext.png",
			"btnNext.png", this,
			menu_selector(GamePassScene::buttonPlayNextCallback));

	addMenuItem(btnBack, btnPlayAgain, btnPlayNext);
	return true;

}

void GamePassScene::drawView() {
	CCLog("GamePassScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

	CCSprite* sprite = CCSprite::create("menu4.jpg");
	sprite->setPosition(
			ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
	this->addChild(sprite, 1);

}

void GamePassScene::back() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
}


void GamePassScene::playAgain() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
	//do it
}
void GamePassScene::playNext() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
	//do it
}

void GamePassScene::buttonBackCallback(CCObject* pSender) {
	back();
}
void GamePassScene::buttonPlayAgainCallback(CCObject* pSender) {
	playAgain();
}
void GamePassScene::buttonPlayNextCallback(CCObject* pSender) {
	playNext();
}



