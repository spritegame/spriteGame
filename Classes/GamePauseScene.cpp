/*
 * GamePauseScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePauseScene.h"
#include "SceneManager.h"

USING_NS_CC;

GamePauseScene::GamePauseScene() {
}
GamePauseScene::~GamePauseScene() {
}

bool GamePauseScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnBack = CCMenuItemImage::create("btnBack.png", "btnBack.png",
			this, menu_selector(GamePauseScene::buttonBackCallback));

	CCMenuItemImage* btnPlayAgain = CCMenuItemImage::create("btnCancel.png",
			"btnCancel.png", this,
			menu_selector(GamePauseScene::buttonPlayAgainCallback));

	CCMenuItemImage* btnPlayContinue = CCMenuItemImage::create("btnResume.png",
			"btnResume.png", this,
			menu_selector(GamePauseScene::buttonPlayContinueCallback));

	addMenuItem(btnBack, btnPlayAgain, btnPlayContinue);

	return true;

}

void GamePauseScene::drawView() {
	CCLog("GamePauseScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

	CCSprite* sprite = CCSprite::create("menu4.jpg");
	sprite->setPosition(ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
	this->addChild(sprite, 1);

}

void GamePauseScene::back() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
}


void GamePauseScene::playAgain() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}
void GamePauseScene::playContinue() {
	cancel();
}

void GamePauseScene::buttonBackCallback(CCObject* pSender) {
	back();
}
void GamePauseScene::buttonPlayAgainCallback(CCObject* pSender) {
	playAgain();
}
void GamePauseScene::buttonPlayContinueCallback(CCObject* pSender) {
	playContinue();
}


