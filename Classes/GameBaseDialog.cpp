/*
 * GameBaseDialog.cpp
 *
 *  Created on: 2013-1-16
 *      Author: allin.dev
 */

#include "GameBaseDialog.h"

USING_NS_CC;
GameBaseDialog::GameBaseDialog() :
		m_pTouch(NULL) {

}
GameBaseDialog::~GameBaseDialog() {
}

bool GameBaseDialog::init() {
	if (!CCLayerColor::initWithColor(ccc4(0,0,0,160))) {
		return false;
	}

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	m_pDialogBg = CCSprite::create("popDialogBg.png");
	m_pDialogBg->setPosition(ccp(size.width / 2, size.height / 2));
	this->addChild(m_pDialogBg, 0);

	this->drawView();

	return true;
}

void GameBaseDialog::show(CCLayer* pParentLayer) {

	pParentLayer->addChild(this, 999);
}

void GameBaseDialog::cancel() {
	onExit();
	this->removeFromParentAndCleanup(true);

	if (m_pCancelCallbackTarget && m_selector) {
		(m_pCancelCallbackTarget->*m_selector)(NULL);
	}
}


void GameBaseDialog::drawView() {
	CCLog("GameBaseDialog::drawView...");
}

void GameBaseDialog::onEnter() {
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority - 1, true);
}

void GameBaseDialog::onExit() {
	CCLog("onExit removeDelegate....");
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}




void GameBaseDialog::setOnCancel(CCObject* target, SEL_CallFuncO selector) {
	m_pCancelCallbackTarget = target;
	m_selector = selector;

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
		if(m_pMenu){
			m_bTouchMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);
		}
	}

	return true;
}

void GameBaseDialog::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu && m_pMenu) {
			m_pMenu->ccTouchMoved(pTouch, pEvent);
		}
	}
}

void GameBaseDialog::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu && m_pMenu) {
			m_pMenu->ccTouchEnded(pTouch, pEvent);
			m_bTouchMenu = false;
		}
		m_pTouch = NULL;
	}
}
void GameBaseDialog::ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent) {
	if (m_pTouch == pTouch) {
		if (m_bTouchMenu && m_pMenu) {
			m_pMenu->ccTouchEnded(pTouch, pEvent);
			m_bTouchMenu = false;
		}
		m_pTouch = NULL;
	}
}

