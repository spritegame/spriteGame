/*
 * GameOverScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameOverScene.h"
#include "../SceneManager.h"

USING_NS_CC;

GameOverScene::GameOverScene() {
}
GameOverScene::~GameOverScene() {
}

bool GameOverScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemSprite* btnBack = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			this, menu_selector(GameOverScene::buttonBackCallback));

	CCMenuItemSprite* btnPlayAgain = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnResume.png"),
			CCSprite::createWithSpriteFrameName("btnResume.png"),
			this, menu_selector(GameOverScene::buttonPlayAgainCallback));

	addMenuItem(btnBack, btnPlayAgain);
	return true;

}

void GameOverScene::setTitle() {
	CCLog("GamePassScene::setTitle...");
//	if (!m_pDialogBg) {
//		return;
//	}
//
//	CCLabelTTF* pLabel = CCLabelTTF::create("Game over", "Arial", 24);
//	pLabel->setPosition(ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY() + m_pDialogBg->getContentSize().height/2 - pLabel->getContentSize().height));
//	this->addChild(pLabel, 1);
}

void GameOverScene::drawView() {
	CCLog("GameOverScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

//	CCSprite* sprite = CCSprite::create("menu4.jpg");
//	sprite->setPosition(
//			ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
//	this->addChild(sprite, 1);

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

