#include "HelloWorldScene.h"
#include "../SoundManager.h"
#include "../SlidingMenu.h"
#include "GameOverScene.h"
#include "GamePassScene.h"
#include "GamePauseScene.h"
#include "../SpriteGameResource.h"

USING_NS_CC;

CCScene* HelloWorld::scene() {
	CCScene * scene = NULL;
	do {
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		HelloWorld *layer = HelloWorld::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
	bool bRet = false;
	do {
		//////////////////////////////////////////////////////////////////////////
		// super init first
		//////////////////////////////////////////////////////////////////////////

		CC_BREAK_IF(! CCLayer::init());

		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		//////////////////////////////////////////////////////////////////////////
		// add your codes below...
		//////////////////////////////////////////////////////////////////////////

		// 1. Add a menu item with "X" image, which is clicked to quit the program.


		//game pause
		CCMenuItemSprite *pGamePauseItem = CCMenuItemSprite::create(
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				this,
				menu_selector(HelloWorld::menuGamePauseCallback));
		CC_BREAK_IF(! pGamePauseItem);
		pGamePauseItem->setPosition(ccp(origin.x + visibleSize.width/4,
				origin.y + pGamePauseItem->getContentSize().height));


		//game pass
		CCMenuItemSprite *pGamePassItem = CCMenuItemSprite::create(
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				this,
				menu_selector(HelloWorld::menuGamePassCallback));
		CC_BREAK_IF(! pGamePassItem);
		pGamePassItem->setPosition(ccp(origin.x + visibleSize.width/2,
				origin.y + pGamePassItem->getContentSize().height));


		//game over
		CCMenuItemSprite *pGameOverItem = CCMenuItemSprite::create(
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				CCSprite::createWithSpriteFrameName("CloseNormal.png"),
				this,
				menu_selector(HelloWorld::menuGameOverCallback));
		CC_BREAK_IF(! pGameOverItem);
		pGameOverItem->setPosition(
				ccp(origin.x + visibleSize.width*3/4 ,
						origin.y + pGamePassItem->getContentSize().height));


		CCMenu* pMenu = CCMenu::create(pGamePauseItem, pGamePassItem, pGameOverItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);

		// 2. Add a label shows "Hello World".

		// Create a label and initialize with string "Hello World".
		CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		// Get window size and place the label upper.
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pLabel->setPosition(ccp(size.width / 2, size.height - 50));

		// Add the label to HelloWorld layer as a child layer.
		this->addChild(pLabel, 2);

		// 3. Add add a splash screen, show the cocos2d splash image.
		CCSprite* pSprite = CCSprite::create(s_test_image);
		CC_BREAK_IF(! pSprite);

		// Place the sprite on the center of the screen
		pSprite->setPosition(ccp(size.width/2, size.height/2));

		// Add the sprite to HelloWorld layer as a child layer.
		this->addChild(pSprite, 0);


		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::menuGamePassCallback(CCObject* pSender) {
	GamePassScene* pGamePassScene = GamePassScene::create();
	pGamePassScene->show(this);
	pGamePassScene->setOnCancel(this, callfuncO_selector(HelloWorld::gamePassCancelCallback));
}
void HelloWorld::gamePassCancelCallback(CCObject* pSender) {
	CCLog("gamePassCancelCallback................");
}

void HelloWorld::menuGamePauseCallback(CCObject* pSender) {

	GamePauseScene* pGamePauseScene = GamePauseScene::create();
	pGamePauseScene->show(this);
	pGamePauseScene->setOnCancel(this, callfuncO_selector(HelloWorld::gamePauseCancelCallback));

}
void HelloWorld::gamePauseCancelCallback(CCObject* pSender) {
	CCLog("gamePauseCancelCallback................");
}

void HelloWorld::menuGameOverCallback(CCObject* pSender) {
	GameOverScene* pGameOverScene = GameOverScene::create();
	pGameOverScene->show(this);
	pGameOverScene->setOnCancel(this, callfuncO_selector(HelloWorld::gameOverCancelCallback));
}

void HelloWorld::gameOverCancelCallback(CCObject* pSender) {
	CCLog("gameOverCancelCallback................");
}

