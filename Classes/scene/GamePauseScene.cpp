/*
 * GamePauseScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePauseScene.h"
#include "../SceneManager.h"

USING_NS_CC;

GamePauseScene::GamePauseScene() {
}
GamePauseScene::~GamePauseScene() {
}

bool GamePauseScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemSprite* btnBack = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			this, menu_selector(GamePauseScene::buttonBackCallback));

	CCMenuItemSprite* btnPlayAgain = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnCancel.png"),
			CCSprite::createWithSpriteFrameName("btnCancel.png"),
			this,
			menu_selector(GamePauseScene::buttonPlayAgainCallback));

	CCMenuItemSprite* btnPlayContinue = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnCancel.png"),
			CCSprite::createWithSpriteFrameName("btnCancel.png"),
			this,
			menu_selector(GamePauseScene::buttonPlayContinueCallback));

	addMenuItem(btnBack, btnPlayAgain, btnPlayContinue);

	return true;

}

void GamePauseScene::setTitle() {
	CCLog("GamePauseScene::setTitle...");
	if (!m_pDialogBg) {
		return;
	}

	CCLabelTTF* pLabel = CCLabelTTF::create("Game pause", "Arial", 24);
	pLabel->setPosition(ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY() + m_pDialogBg->getContentSize().height/2 - pLabel->getContentSize().height));
	this->addChild(pLabel, 1);
}

void GamePauseScene::drawView() {
	CCLog("GamePauseScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

//	CCSprite* sprite = CCSprite::create("menu4.jpg");
//	sprite->setPosition(ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
//	this->addChild(sprite, 1);

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


