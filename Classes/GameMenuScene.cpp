/*
 * GameMenuScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameMenuScene.h"

USING_NS_CC;

CCScene* GameMenuScene::scene() {
	CCScene* scene = NULL;

	do {

		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		CCLayer* layer = GameMenuScene::create();

		scene->addChild(layer);

	} while (0);

	return scene;
}

bool GameMenuScene::init() {

	if (!CCLayer::init()) {
		return false;
	}

	return true;
}

