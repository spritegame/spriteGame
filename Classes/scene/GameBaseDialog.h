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

	void addMenuItem(CCMenuItemSprite*);
	void addMenuItem(CCMenuItemSprite*, CCMenuItemSprite*);
	void addMenuItem(CCMenuItemSprite*, CCMenuItemSprite*, CCMenuItemSprite*);

	/*
	 * 打开窗口
	 */
	void show(CCLayer* pParentLayer);
	/*
	 * 关闭窗口
	 */
	void cancel();
	/**
	 * 设置关闭窗口后的回调接口
	 */
	void setOnCancel(CCObject* target, SEL_CallFuncO selector);

	/*
	 * 绘制自定义UI
	 */
	virtual void drawView();
	virtual void setTitle();

	CREATE_FUNC(GameBaseDialog);

protected:
	/*
	 * 窗口背景图,帮助子类UI进行定位
	 */
	CCSprite* m_pDialogBg;
	/*
	 * 窗口菜单按钮,子类把按钮添加到该指针中
	 */
	CCMenu* m_pMenu;

private:
	/*
	 * 判断是否已触摸
	 */
	bool m_bTouchMenu;
	CCTouch* m_pTouch;
	/*
	 * 关闭窗口回调选择函数
	 */
	SEL_CallFuncO m_selector;
	/*
	 * 关闭窗口回调选择函数的目标对象
	 */
	CCObject* m_pCancelCallbackTarget;
};

#endif /* GAMEBASEDIALOG_H_ */
