/*
 * GameOverScene.cpp
 *
 *  Created on: 2013-1-14
 *      Author: allin.dev
 */

#include "GameOverScene.h"

USING_NS_CC;

CCScene* GameOverScene::scene(){

	CCScene* scene = NULL;

	do {

		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		CCLayer* layer = GameOverScene::create();

		scene->addChild(layer);

	}while(0);

	return scene;
}


bool GameOverScene::init(){

	if(!CCLayer::init()){
		return false;
	}


	return true;


}

