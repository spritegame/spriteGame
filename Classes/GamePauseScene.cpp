/*
 * GamePauseScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePauseScene.h"

USING_NS_CC;

GamePauseScene::GamePauseScene() {
}
GamePauseScene::~GamePauseScene() {
}

bool GamePauseScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnOk = CCMenuItemImage::create("btnOk.png", "btnOk.png",
			this, menu_selector(GamePauseScene::menuOkCallback));
	CCMenuItemImage* btnCancel = CCMenuItemImage::create("btnCancel.png",
			"btnCancel.png", this,
			menu_selector(GamePauseScene::menuCancelCallback));

	addMenuItem(btnOk, btnCancel);
	return true;

}

void GamePauseScene::drawView() {
	CCLog("GamePauseScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

	CCSprite* sprite = CCSprite::create("menu4.jpg");
	sprite->setPosition(
			ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
	this->addChild(sprite, 1);

}

void GamePauseScene::back() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
}


void GamePauseScene::playAgain() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}

void GamePauseScene::menuOkCallback(CCObject* pSender) {

}
void GamePauseScene::menuCancelCallback(CCObject* pSender) {
	cancel();
}



