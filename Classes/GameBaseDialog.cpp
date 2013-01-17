/*
 * GameBaseDialog.cpp
 *
 *  Created on: 2013-1-16
 *      Author: Administrator
 */

#include "GameBaseDialog.h"

USING_NS_CC;
GameBaseDialog::GameBaseDialog() :
		m_pTouch(NULL) {

}
GameBaseDialog::~GameBaseDialog() {
}

bool GameBaseDialog::init() {

	if (!CCLayer::init()) {
		return false;
	}

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	m_pDialogBg = CCSprite::create("popDialogBg.png");
	m_pDialogBg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(m_pDialogBg, 0);

//	draw();

	return true;
}

//void GameBaseDialog::draw() {
//
//}

void GameBaseDialog::onEnter() {
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority - 1, true);
}

void GameBaseDialog::onExit() {
	CCLog("onExit removeDelegate....");
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

void GameBaseDialog::cancel() {
	onExit();
	this->removeFromParentAndCleanup(true);
}
void GameBaseDialog::addMenuItem(CCMenuItemImage* menuItem) {

	menuItem->setPosition(ccp(m_pDialogBg->getPositionX(), m_pDialogBg->getPositionY()));
	m_pMenu = CCMenu::create(menuItem, NULL);
	m_pMenu->setPosition(CCPointZero);

	addChild(m_pMenu, 1);
}

void GameBaseDialog::addMenuItem(CCMenuItemImage* menuItem1, CCMenuItemImage* menuItem2) {

	CCSize bgZize = m_pDialogBg->getContentSize();

	menuItem1->setPosition(ccp(m_pDialogBg->getPositionX() - bgZize.width/4,
			m_pDialogBg->getPositionY() - bgZize.height/2 + menuItem1->getContentSize().height ));

	menuItem2->setPosition(ccp(m_pDialogBg->getPositionX() + bgZize.width/4,
			m_pDialogBg->getPositionY() - bgZize.height/2 + menuItem1->getContentSize().height));

	m_pMenu = CCMenu::create(menuItem1, menuItem2, NULL);

	m_pMenu->setPosition(CCPointZero);

	addChild(m_pMenu, 1);
}

bool GameBaseDialog::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) {

	if (m_pTouch == NULL) {
		m_pTouch = pTouch;
		m_bTouchMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);
	}

	return true;
}

void GameBaseDialog::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu) {
			m_pMenu->ccTouchMoved(pTouch, pEvent);
		}
	}
}

void GameBaseDialog::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu) {
			m_pMenu->ccTouchEnded(pTouch, pEvent);
			m_bTouchMenu = false;
		}
		m_pTouch = NULL;
	}
}
void GameBaseDialog::ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu) {
			m_pMenu->ccTouchEnded(pTouch, pEvent);
			m_bTouchMenu = false;
		}
		m_pTouch = NULL;
	}
}
