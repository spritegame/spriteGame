/*
 * GameBaseDialog.cpp
 *
 *  Created on: 2013-1-16
 *      Author: Administrator
 */

#include "GameBaseDialog.h"

USING_NS_CC;

bool GameBaseDialog::init() {

	if (!CCLayer::init()) {
		return false;
	}

	draw();

	return true;
}

void GameBaseDialog::onEnter() {
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority -1, true);
}

void GameBaseDialog::onExit() {
	CCDirector::sharedDirector()->getTouchDispatcher()->removeAllDelegates();
	CCLayer::onExit();
}

void GameBaseDialog::cancel() {

}

bool GameBaseDialog::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) {

}

void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent) {
}
void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
}
void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent) {
}

