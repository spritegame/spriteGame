/*
 * GameOverScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameOverScene.h"

USING_NS_CC;

GameOverScene::GameOverScene() {
}
GameOverScene::~GameOverScene() {
}

//CCScene* GameOverScene::scene(){
//
//	CCScene* scene = NULL;
//
//	do {
//
//		scene = CCScene::create();
//		CC_BREAK_IF(!scene);
//
//		CCLayer* layer = GameOverScene::create();
//
//		scene->addChild(layer);
//
//	}while(0);
//
//	return scene;
//}

bool GameOverScene::init() {

	if (!GameBaseDialog::init()) {
		return false;
	}
	CCMenuItemImage* btnOk = CCMenuItemImage::create("btnOk.png", "btnOk.png", this,
			menu_selector(GameOverScene::menuOkCallback));
	CCMenuItemImage* btnCancel = CCMenuItemImage::create("btnCancel.png", "btnCancel.png", this,
			menu_selector(GameOverScene::menuCancelCallback));

	addMenuItem(btnOk, btnCancel);
	return true;

}

//void GameOverScene::draw() {
//
//}

void GameOverScene::menuOkCallback(CCObject* pSender) {

}
void GameOverScene::menuCancelCallback(CCObject* pSender) {
	cancel();
}

