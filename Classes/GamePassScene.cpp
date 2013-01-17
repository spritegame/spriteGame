/*
 * GamePassScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePassScene.h"

USING_NS_CC;

GamePassScene::GamePassScene() {
}
GamePassScene::~GamePassScene() {
}

bool GamePassScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnOk = CCMenuItemImage::create("btnOk.png", "btnOk.png",
			this, menu_selector(GamePassScene::menuOkCallback));
	CCMenuItemImage* btnCancel = CCMenuItemImage::create("btnCancel.png",
			"btnCancel.png", this,
			menu_selector(GamePassScene::menuCancelCallback));

	addMenuItem(btnOk, btnCancel);
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
}
void GamePassScene::playNext() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}

void GamePassScene::menuOkCallback(CCObject* pSender) {

}
void GamePassScene::menuCancelCallback(CCObject* pSender) {
	cancel();
}



