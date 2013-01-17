/*
 * GameOverScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameOverScene.h"
#include "SceneManager.h"

USING_NS_CC;

GameOverScene::GameOverScene() {
}
GameOverScene::~GameOverScene() {
}

bool GameOverScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnBack = CCMenuItemImage::create("btnBack.png", "btnBack.png",
			this, menu_selector(GameOverScene::buttonBackCallback));

	CCMenuItemImage* btnPlayAgain = CCMenuItemImage::create("btnResume.png", "btnResume.png",
			this, menu_selector(GameOverScene::buttonPlayAgainCallback));

	addMenuItem(btnBack, btnPlayAgain);
	return true;

}

void GameOverScene::drawView() {
	CCLog("GameOverScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

	CCSprite* sprite = CCSprite::create("menu4.jpg");
	sprite->setPosition(
			ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
	this->addChild(sprite, 1);

}

void GameOverScene::back() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_MENU);
}


void GameOverScene::playAgain() {
	SceneManager::sharedGameManager()->runScene(SceneManager::SCENE_PLAY);
}



void GameOverScene::buttonBackCallback(CCObject* pSender) {
	playAgain();
}
void GameOverScene::buttonPlayAgainCallback(CCObject* pSender) {
	back();
}

