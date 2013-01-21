/*
 * GamePassScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GamePassScene.h"
#include "../SpriteMath.h"
#include "../SceneManager.h"

USING_NS_CC;

GamePassScene::GamePassScene() {
}
GamePassScene::~GamePassScene() {
}

bool GamePassScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemSprite* btnBack = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			CCSprite::createWithSpriteFrameName("btnBack.png"),
			this,
			menu_selector(GamePassScene::buttonBackCallback));

	CCMenuItemSprite* btnPlayAgain = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnResume.png"),
			CCSprite::createWithSpriteFrameName("btnResume.png"),
			this,
			menu_selector(GamePassScene::buttonPlayAgainCallback));

	CCMenuItemSprite* btnPlayNext = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("btnNext.png"),
			CCSprite::createWithSpriteFrameName("btnNext.png"),
			this,
			menu_selector(GamePassScene::buttonPlayNextCallback));

	addMenuItem(btnBack, btnPlayAgain, btnPlayNext);
	return true;

}

void GamePassScene::setTitle() {
	CCLog("GamePassScene::setTitle...");
}

void GamePassScene::drawView() {
	CCLog("GamePassScene::drawView...");
	if (!m_pDialogBg) {
		return;
	}

	SpriteMath spriteMath;

	CCSize bgSize = m_pDialogBg->getContentSize();
	float bgLeft = m_pDialogBg->getPositionX() - bgSize.width/2;
	float bgRighr = m_pDialogBg->getPositionX() + bgSize.width/2;
	float padding = 20;

	CCLabelTTF* pLabel = CCLabelTTF::create("Game Pass", "Arial", 28);
	pLabel->setPosition(ccp(m_pDialogBg->getPositionX(),
			m_pDialogBg->getPositionY() + m_pDialogBg->getContentSize().height/2 - pLabel->getContentSize().height));
	this->addChild(pLabel, 1);

	std::string strMessage;
	std::ostringstream ss;
	ss << "Total Score : " << spriteMath.getUserTotalScore();
	strMessage = ss.str();
	ss.clear();


//	strMessage = "Total Score : ";
//	spriteGameUtil.ConvertTo<string>(spriteMath.getUserTotalScore());

	CCLabelTTF* pLabelTotalScore = CCLabelTTF::create(strMessage.c_str(), "Arial", 24);
	pLabelTotalScore->setAnchorPoint(CCPointMake(0,0));
	pLabelTotalScore->setPosition(ccp(bgLeft+padding,
			pLabel->getPositionY()- pLabelTotalScore->getContentSize().height*1.5));
	this->addChild(pLabelTotalScore, 1);

	std::ostringstream ss2;
	ss2 << "Score : " << spriteMath.getCurLevelUserScore();
	strMessage = ss2.str();
	ss2.clear();

	CCLabelTTF* pLabelScore = CCLabelTTF::create(strMessage.c_str(), "Arial", 24);
	pLabelScore->setAnchorPoint(CCPointMake(0,0));
	pLabelScore->setPosition(ccp(bgLeft+padding,
			pLabelTotalScore->getPositionY()- pLabelScore->getContentSize().height*1.5));
	this->addChild(pLabelScore, 1);




	//show star


	int starSum = spriteMath.getLevelStars(spriteMath.getLevel(), spriteMath.getLevelPassTime());
	std::string stars[3] = {"icon_star_off.png","icon_star_off.png","icon_star_off.png"};
	switch(starSum){
	case 1:
		stars[0] = "icon_star_on.png";
		break;

	case 2:
		stars[0] = "icon_star_on.png";
		stars[1] = "icon_star_on.png";
		break;

	case 3:
		stars[0] = "icon_star_on.png";
		stars[1] = "icon_star_on.png";
		stars[2] = "icon_star_on.png";
		break;
	}


	CCSprite* pStart1 = CCSprite::createWithSpriteFrameName(stars[0].c_str());
	pStart1->setPosition(ccp(m_pDialogBg->getPositionX() - m_pDialogBg->getContentSize().width/4, pLabelScore->getPositionY() - pStart1->getContentSize().height));
	this->addChild(pStart1, 1);

	CCSprite* pStart2 = CCSprite::createWithSpriteFrameName(stars[1].c_str());
	pStart2->setPosition(ccp(m_pDialogBg->getPositionX(), pLabelScore->getPositionY() - pStart1->getContentSize().height));
	this->addChild(pStart2, 1);

	CCSprite* pStart3 = CCSprite::createWithSpriteFrameName(stars[2].c_str());
	pStart3->setPosition(ccp(m_pDialogBg->getPositionX() + m_pDialogBg->getContentSize().width/4, pLabelScore->getPositionY() - pStart1->getContentSize().height));
	this->addChild(pStart3, 1);

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

