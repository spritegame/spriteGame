#include "HelloWorldScene.h"
#include "SoundManager.h"
#include "SlidingMenu.h"
#include "GameOverScene.h"

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

		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(HelloWorld::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		// Place the menu item bottom-right conner.
		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
				origin.y + pCloseItem->getContentSize().height/2));




		CCMenuItemImage *pSoundItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(HelloWorld::menuSoundCallback));
		CC_BREAK_IF(! pSoundItem);

		// Place the menu item bottom-right conner.
		pSoundItem->setPosition(ccp(origin.x + pSoundItem->getContentSize().width/2 ,
				origin.y + pSoundItem->getContentSize().height/2));



		CCMenuItemImage *pSoundSwitchItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(HelloWorld::menuSoundSwitchCallback));
		CC_BREAK_IF(! pSoundSwitchItem);

		// Place the menu item bottom-right conner.
		pSoundSwitchItem->setPosition(ccp(origin.x + pSoundSwitchItem->getContentSize().width/2 ,
				origin.y + pSoundSwitchItem->getContentSize().height + 100+ pSoundSwitchItem->getContentSize().height/2));



		CCMenuItemImage *pGameOverItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
				menu_selector(HelloWorld::menuGameOverCallback));
		CC_BREAK_IF(! pGameOverItem);

		// Place the menu item bottom-right conner.
		pGameOverItem->setPosition(ccp(origin.x + pGameOverItem->getContentSize().width/2 +200,
				origin.y + pGameOverItem->getContentSize().height + 100+ pGameOverItem->getContentSize().height/2));





		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, pSoundItem, pSoundSwitchItem,pGameOverItem, NULL);
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
		this->addChild(pLabel, 1);

		// 3. Add add a splash screen, show the cocos2d splash image.
		CCSprite* pSprite = CCSprite::create("HelloWorld.png");
		CC_BREAK_IF(! pSprite);

		// Place the sprite on the center of the screen
		pSprite->setPosition(ccp(size.width/2, size.height/2));

		// Add the sprite to HelloWorld layer as a child layer.
		this->addChild(pSprite, 0);

		SoundManager::sharedSoundManager()->playMusic();





		CCArray* ccArray = CCArray::createWithCapacity(2);

		CCMenuItemImage* pItem1 = CCMenuItemImage::create("menu1.jpg", "menu1.jpg");
		CCMenuItemImage* pItem2 = CCMenuItemImage::create("menu2.jpg", "menu2.jpg");
		CCMenuItemImage* pItem3 = CCMenuItemImage::create("menu3.jpg", "menu3.jpg");
		CCMenuItemImage* pItem4 = CCMenuItemImage::create("menu4.jpg", "menu4.jpg");

		ccArray->addObject(pItem1);
		ccArray->addObject(pItem2);
		ccArray->addObject(pItem3);
		ccArray->addObject(pItem4);
		SlidingMenuGrid* slidingMenuGrid = SlidingMenuGrid::create(ccArray, 1, 1, CCPointMake(size.width / 2,size.height / 2), CCPointMake(0,0));
		slidingMenuGrid->setPosition(0,0);
		this->addChild(slidingMenuGrid, 2);



		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender) {
	// "close" menu item clicked
	CCDirector::sharedDirector()->end();
}
void HelloWorld::menuSoundCallback(CCObject* pSender) {
	SoundManager::sharedSoundManager()->playEffect();
}
void HelloWorld::menuSoundSwitchCallback(CCObject* pSender) {
	SoundManager::sharedSoundManager()->setMusic(!SoundManager::sharedSoundManager()->isMusicPlaying());
}
void HelloWorld::menuGameOverCallback(CCObject* pSender) {

	GameOverScene* pGameOverScene = GameOverScene::create();
	this->addChild(pGameOverScene, 3);

}

