#ifndef __SPRITEGRID_SCENE_H__
#define __SPRITEGRID_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SpriteConstant.h"

class SpriteGrid : public cocos2d::CCLayer
{
public:
	//初始方法
    virtual bool init();  

	//创建屏幕
    static cocos2d::CCScene* scene();

    // implement the "static node()" method manually
    CREATE_FUNC(SpriteGrid);

	void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);

	//初始化游戏
	void initGame();

	//准备游戏,进行游戏布局
	void readyGame();

	//随机生成精灵
	void randCreateSprite();

	//移除精灵
	void removeSprite(cocos2d::CCNode *pSender);

	//进度更新定时回调函数
	//dt:时间间隔
	void updateProgress(float dt);

	//消除，传入x,y坐标
	void goCross(int x, int y);

	// 进度条进度的设置
	void updateProgressPercent(float fPercentage);

	// 游戏结束
	void overGame();

	cocos2d::CCRenderTexture* createStroke(cocos2d::CCLabelTTF* pLabel, float size, cocos2d::ccColor3B color);

private:
	char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL];
	bool m_RunGame;
};

#endif  // __SPRITEGRID_SCENE_H__
