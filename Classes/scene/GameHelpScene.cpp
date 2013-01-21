/*
 * GameHelpScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameHelpScene.h"

USING_NS_CC;

CCScene* GameHelpScene::scene() {
	CCScene* scene = NULL;

	do{

		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		CCLayer* layer = GameHelpScene::create();

		scene->addChild(layer);

	}while(0);

	return scene;
}

bool GameHelpScene::init() {

	if(!CCLayer::init()){
		return false;
	}


	return true;
}

