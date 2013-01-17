/*
 * GameBaseDialog.h
 *
 *  Created on: 2013-1-16
 *      Author: Administrator
 */

#ifndef GAMEBASEDIALOG_H_
#define GAMEBASEDIALOG_H_

#include "cocos2d.h"

USING_NS_CC;

class GameBaseDialog: public CCLayerColor {
public:
	GameBaseDialog();
	~GameBaseDialog();
	virtual bool init();
	virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
	virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
	virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
	virtual void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent);

	void onEnter();
	void onExit();

	void addMenuItem(CCMenuItemImage*);
	void addMenuItem(CCMenuItemImage*, CCMenuItemImage*);

	void cancel();
	void setOnCancel(CCObject* target, SEL_CallFuncO selector);

	CREATE_FUNC(GameBaseDialog);

	virtual void drawView();

protected:
	CCSprite* m_pDialogBg;
	CCMenu* m_pMenu;

private:
	bool m_bTouchMenu;
	CCTouch* m_pTouch;
	SEL_CallFuncO m_selector;
	CCObject* m_pCancelCallbackTarget;
};

#endif /* GAMEBASEDIALOG_H_ */
