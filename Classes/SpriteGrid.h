#ifndef __SPRITEGRID_SCENE_H__
#define __SPRITEGRID_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SpriteConstant.h"

class SpriteGrid : public cocos2d::CCLayer
{
public:
	//��ʼ����
    virtual bool init();  

	//������Ļ
    static cocos2d::CCScene* scene();

    // implement the "static node()" method manually
    CREATE_FUNC(SpriteGrid);

	void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);

	//��ʼ����Ϸ
	void initGame();

	//׼����Ϸ,������Ϸ����
	void readyGame();

	//������ɾ���
	void randCreateSprite();

	//�Ƴ�����
	void removeSprite(cocos2d::CCNode *pSender);

	//���ȸ��¶�ʱ�ص�����
	//dt:ʱ����
	void updateProgress(float dt);

	//����������x,y����
	void goCross(int x, int y);

	// ���������ȵ�����
	void updateProgressPercent(float fPercentage);

	// ��Ϸ����
	void overGame();

	cocos2d::CCRenderTexture* createStroke(cocos2d::CCLabelTTF* pLabel, float size, cocos2d::ccColor3B color);

private:
	char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL];
	bool m_RunGame;
};

#endif  // __SPRITEGRID_SCENE_H__
