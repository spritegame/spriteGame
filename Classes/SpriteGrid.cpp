#include "SpriteGrid.h"
#include "SpriteGameResource.h"
#include "SpriteMath.h"
#include <vector>
#include <algorithm>


//定义一个枚举以表示添加到层的标签TAG

enum CrossTag 
{
	kTagStart,
	kTagProgress,
	kTagBatchNode,
	kTagScore,
	kTagBgProgress,
	kTagRestart,
	kTagBatchDot,
	kTagBaoJi,
};


USING_NS_CC;

const int EMPTY_BLOCK = 10;
static const char g_gamescore[] = "\xe6\xb8\xb8\xe6\x88\x8f\xe5\xbe\x97\xe5\x88\x86";//游戏得分
static const char g_restart[]	= "\xe5\x86\x8d\xe7\x8e\xa9\xe4\xb8\x80\xe6\xac\xa1";//再玩一次

CCScene* SpriteGrid::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        SpriteGrid *layer = SpriteGrid::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}
bool SpriteGrid::init()
{
    bool bRet = false;
    do 
    {

        CC_BREAK_IF(! CCLayer::init());
		//设置可角摸
		setTouchEnabled(true);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(s_soundCorrect);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(s_soundError);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(s_soundOver);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(s_soundStart);

		initGame();

        bRet = true;
    } while (0);

    return bRet;
}

void SpriteGrid::readyGame()
{
	//打开游戏开始音效
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(s_soundStart);

	//加载表格背景
	CCSprite* pSpriteGrid = CCSprite::create(s_bg_grid);
	pSpriteGrid->setPosition(ccp(20, 40));
	pSpriteGrid->setAnchorPoint(ccp(0, 0));
	this->addChild(pSpriteGrid, 0);

	//加载进度条背景
	CCSprite* pSpriteProgressBackGroup = CCSprite::create(s_bg_time);
	pSpriteProgressBackGroup->setPosition(ccp(37, 443));
	pSpriteProgressBackGroup->setAnchorPoint(ccp(0, 0));
	this->addChild(pSpriteProgressBackGroup, 2, kTagBgProgress);

	//加载进度条
	CCProgressTimer* pSpriteProgressTimer = CCProgressTimer::create(CCSprite::create(s_fg_time));
	pSpriteProgressTimer->setType(kCCProgressTimerTypeBar);
	pSpriteProgressTimer->setMidpoint(ccp(1, 0));
	pSpriteProgressTimer->setBarChangeRate(ccp(1, 0));
	pSpriteProgressTimer->setPercentage(0);
	pSpriteProgressTimer->setPosition(ccp(38, 444));
	pSpriteProgressTimer->setAnchorPoint(ccp(0, 0));
	this->addChild(pSpriteProgressTimer, 3, kTagProgress);

	//加载表格,这里使用到CCSpriteBatchNode 纹理贴图创建CCSprite
	//从一个贴图产生不同的精灵
	CCSpriteBatchNode* pSpriteBatchNode = CCSpriteBatchNode::create(s_a_cell);
	//每张精灵的背景图
	CCSpriteBatchNode* pSpriteDotBatchNode = CCSpriteBatchNode::create(s_dot);

	//随即数的产生
	srand(time(0));

	//循环产生
	for(int row = 0; row < MAX_GAME_ROW; ++ row)
	{
		for(int col = 0; col < MAX_GAME_COL; ++ col)
		{
			int nRandType = row;
			int nIndex = row * MAX_GAME_COL + col;
			CCSprite* pSprite = CCSprite::createWithTexture(pSpriteBatchNode->getTexture(), CCRectMake(nRandType * 23, 0, 23, 23));
			pSprite->setPosition(ccp(col * SPRITE_SIZE + SPRITE_MOVE_START_X, (row + MAX_GAME_ROW) * SPRITE_SIZE + SPRITE_MOVE_START_Y));
			pSprite->setAnchorPoint(ccp(0, 0));
			pSpriteBatchNode->addChild(pSprite, pSprite->getZOrder(), nIndex);
			//添加移动画
			pSprite->runAction(CCMoveBy::create(SPRITE_MOVE_TIME * MAX_GAME_ROW, ccp(0,-SPRITE_SIZE*MAX_GAME_ROW)));
			m_BlocksType[nIndex] = nRandType;

			CCSprite* pDotSprite = CCSprite::create(s_dot);
			pDotSprite->setPosition(ccp(col * 25 + 51, row * 25 + 58));
			pDotSprite->setAnchorPoint(ccp(0, 0));
			pDotSprite->setVisible(false);
			pSpriteDotBatchNode->addChild(pDotSprite, pDotSprite->getZOrder(), nIndex);

		}
	}

	this->addChild(pSpriteDotBatchNode, 4, kTagBatchDot);
	this->addChild(pSpriteBatchNode, 4, kTagBatchNode);

	//创建进度条字体
	CCLabelTTF* pProgressScore = CCLabelTTF::create("0", "Arial", 18);
	pProgressScore->setPosition(ccp(623, 448));
	pProgressScore->setColor(ccc3(255, 102, 102));
	this->addChild(pProgressScore, 5, kTagScore);

	this->schedule(schedule_selector(SpriteGrid::updateProgress), 1.0);

	m_RunGame = true;
}
//随机生成精灵
void SpriteGrid::randCreateSprite()
{

}
//
void SpriteGrid::removeSprite(CCNode *pSender)
{
	CCSpriteBatchNode* pBatchNode = (CCSpriteBatchNode*) pSender->getParent();
	pBatchNode->removeChild((CCSprite*)pSender, true);
}
void SpriteGrid::updateProgress(float dt) 
{
	updateProgressPercent(1);
}
void SpriteGrid::initGame()
{
	m_RunGame = false;
	//加载游戏背景
	CCSprite* pSpriteGameBackGroup = CCSprite::create(s_bg_frame);
	pSpriteGameBackGroup->setPosition(ccp(0, 0));
	pSpriteGameBackGroup->setAnchorPoint(ccp(0, 0));
	this->addChild(pSpriteGameBackGroup, 1);

	//开始按键
	CCSprite* pSpriteStart = CCSprite::create(s_start);
	pSpriteStart->setPosition(ccp(20, 40));
	pSpriteStart->setAnchorPoint(ccp(0, 0));
	this->addChild(pSpriteStart, 0, kTagStart);

}

void SpriteGrid::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	if(!touch)
	{
		return;
	}

	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	//如果点击开始按钮则准备游戏
	CCNode* pStart = this->getChildByTag(kTagStart);
	if(pStart && pStart->isVisible())
	{
		if(CCRect::CCRectContainsPoint(CCRectMake(261, 206, 105, 41), location))
		{
			pStart->setVisible(false);
			readyGame();
		}
	}
	else
	{
		//是否重新开始完
		CCNode* pRestart = this->getChildByTag(kTagRestart);
		if(pRestart && pRestart->isVisible() && !m_RunGame &&
			CCRect::CCRectContainsPoint(CCRectMake(
			pRestart->getPositionX() - pRestart->getContentSize().width / 2,
			pRestart->getPositionY() - pRestart->getContentSize().height / 2,
			pRestart->getContentSize().width,
			pRestart->getContentSize().height), location))
		{
			this->removeAllChildrenWithCleanup(true);
			initGame();
			return;
		}

		//判断是否在大格子里
		if(m_RunGame && CCRect::CCRectContainsPoint(CCRectMake(44, 51, 575, 375), location))
		{
			int nPosX = (int)((location.x - 44) / 25);
			int nPosY = (int)((location.y - 51) / 25);
			goCross(nPosY, nPosX);
		}
	}
}
//排序函数，以从大到小
bool pr(int s1, int s2)
{
	return s1>s2;
}

//消灭
void SpriteGrid::goCross(int x, int y)
{
	if (0 > x || MAX_GAME_ROW < x || 0 > y || MAX_GAME_COL < y)
	{
		return;
	}

	int nBlockType = (int)m_BlocksType[x * MAX_GAME_COL + y];
	std::clog<< "hxh" << nBlockType <<std::endl;
	std::cout<< "hxh" << nBlockType <<std::endl;
	/*if (EMPTY_BLOCK != nBlockType)
	{
		return;
	}*/
	
	CCNode *pBatchNode = this->getChildByTag(kTagBatchNode);
	CCNode *pBatchDot = this->getChildByTag(kTagBatchDot);

	int nIndex = x * MAX_GAME_COL + y;
	SpriteMath spriteMath; 
	std::vector<int> spriteVector = spriteMath.findCrossSprites(m_BlocksType, nIndex);
	int crossSize = spriteVector.size();
	std::vector<CCSprite*> pBlocksSprite;
	std::vector<CCNode*> arrSpriteDot;
	if(crossSize < 3)
	{
		return;
	}

	for(int i = 0; i< crossSize; ++i)
	{
		pBlocksSprite.push_back((CCSprite*)pBatchNode->getChildByTag(spriteVector.at(i)));
		arrSpriteDot.push_back(pBatchDot->getChildByTag(spriteVector.at(i)));
	}

	srand(time(0));
	int nDir = 1;
	int nScore = 0;
	for (int i = 0; i < crossSize; ++i)
	{
		m_BlocksType[spriteVector.at(i)] = EMPTY_BLOCK;
		if (!pBlocksSprite[i])
		{
			continue;
		}

		CCPoint ptStart = pBlocksSprite[i]->getPosition();
		ccBezierConfig bezier;
		int nPosX = ptStart.x + (10 + rand() % 200) * nDir;
		bezier.controlPoint_1 = ccp(nPosX, ptStart.y + 250);
		nPosX = nPosX + 50 * nDir;
		bezier.controlPoint_2 = ccp(nPosX, 0);
		bezier.endPosition = ccp(nPosX, -30);
		pBlocksSprite[i]->setRotation(nDir * 25);
		pBlocksSprite[i]->setTag(-1);
		pBlocksSprite[i]->getParent()->reorderChild(pBlocksSprite[i], 6);
		pBlocksSprite[i]->runAction(CCSequence::create(
			CCBezierTo::create(0.8f, bezier),
			CCCallFuncN::create(this, callfuncN_selector(SpriteGrid::removeSprite)),
				NULL));
		nDir = nDir * -1;
		++nScore;
	}
	if (0 == nScore)
	{
		updateProgressPercent(10);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(s_soundError);
		return;
	}
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(s_soundCorrect);
	for (std::string::size_type i = 0; i < arrSpriteDot.size(); ++i)
	{
		arrSpriteDot[i]->setVisible(true);
	}
	for (std::string::size_type i = 0; i < arrSpriteDot.size(); ++i)
	{
		arrSpriteDot[i]->runAction(CCFadeOut::create(1.0f));
	}
	std::sort(spriteVector.begin(), spriteVector.end(), pr);
	for (int i = 0; i < crossSize; ++i) 
	{
		int nIndex = spriteVector.at(i);
		////找出相邻的几个值
		//int nextNumbers = 1;
		//for(int k =0; k < crossSize; ++k)
		//{
		//	if(k != i)
		//	{
		//		if(nIndex + k * MAX_GAME_COL == spriteVector.at(k) ||
		//			nIndex - k * MAX_GAME_COL == spriteVector.at(k))
		//		{
		//			nextNumbers ++;
		//		}
		//	}
		//}
		int row = nIndex / MAX_GAME_COL;
		int col = nIndex % MAX_GAME_COL;
		for(int j = row ; j < MAX_GAME_ROW; j++)
		{
			int headSpriteIndex = (j+1) * MAX_GAME_COL + col;
			int crossSpriteIndex = j * MAX_GAME_COL + col;
			CCSprite* pSprite = (CCSprite*)pBatchNode->getChildByTag(headSpriteIndex);
			if(!pSprite)
			{
				continue;
			}
			//添加移动画
			//CCPoint point = pSprite->getPosition();
			pSprite->runAction(CCMoveBy::create(SPRITE_MOVE_TIME * 1, ccp(0,-SPRITE_SIZE*1)));
			pSprite->setTag(crossSpriteIndex);
			//pSprite->setPosition(ccp(pSprite->getPosition().x, pSprite->getPosition().y + SPRITE_SIZE));
			m_BlocksType[crossSpriteIndex] = m_BlocksType[headSpriteIndex];
			//m_BlocksType[headSpriteIndex] = EMPTY_BLOCK;

			if((j+1) == MAX_GAME_ROW -1)
			{
				//生成新的精灵
				int nRandType = rand() % 6;
				int nIndex = (j+1) * MAX_GAME_COL + col;
				CCSprite* pSprite = CCSprite::createWithTexture(((CCSpriteBatchNode*)pBatchNode)->getTexture(), CCRectMake(nRandType * 23, 0, 23, 23));
				pSprite->setPosition(ccp(col * SPRITE_SIZE + SPRITE_MOVE_START_X, (j + 1) * SPRITE_SIZE + SPRITE_MOVE_START_Y));
				pSprite->setAnchorPoint(ccp(0, 0));
				((CCSpriteBatchNode*)pBatchNode)->addChild(pSprite, pSprite->getZOrder(), nIndex);
				pSprite->runAction(CCMoveBy::create(SPRITE_MOVE_TIME, ccp(0,-SPRITE_SIZE)));
				m_BlocksType[nIndex] = nRandType;
				std::clog<< "HXH LOG: index--" << nIndex << " Rand Type---" << nRandType <<std::endl;
				cocos2d::CCLog("HXH LOG: index-- %d,Rand Type---%d/r/n", nIndex, nRandType);
				printf("HXH LOG: index-- %d,Rand Type---%d/r/n", nIndex, nRandType);
			}
		}
	}
	
	CCLabelTTF* pLabelScore = (CCLabelTTF*)this->getChildByTag(kTagScore);
	nScore = nScore + atoi(pLabelScore->getString());
	char strScore[10] = {0};
	sprintf(strScore, "%d", nScore);
	pLabelScore->setString(strScore);

	//清除
	arrSpriteDot.clear();
	pBlocksSprite.clear();
	return;

}
//游戏结束
void SpriteGrid::overGame()
{
	m_RunGame = false;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(s_soundOver);
	CCLabelTTF* pLabelScore = (CCLabelTTF*)this->getChildByTag(kTagScore);
	pLabelScore->setVisible(false);
	CCNode* pProgressTimer = this->getChildByTag(kTagProgress);
	pProgressTimer->setVisible(false);
	CCNode* pSpriteProgressBg = this->getChildByTag(kTagBgProgress);
	pSpriteProgressBg->setVisible(false);

	CCLabelTTF* pLabelTitle = CCLabelTTF::create(g_gamescore, "宋体", 40);
	pLabelTitle->setPosition(ccp(330, 650));
	pLabelTitle->setColor(ccc3(255, 102, 102));
	CCRenderTexture* pStrokeTitle = createStroke(pLabelTitle, 3, ccWHITE);
	this->addChild(pStrokeTitle, 5);
	this->addChild(pLabelTitle, 5);

	CCLabelTTF* pLabelResult = CCLabelTTF::create(pLabelScore->getString(), "Arial", 42);
	pLabelResult->setPosition(ccp(330, 600));
	pLabelResult->setColor(ccc3(255, 102, 102));
	CCRenderTexture* pStrokeResult = createStroke(pLabelResult, 3, ccWHITE);
	this->addChild(pStrokeResult, 5);
	this->addChild(pLabelResult, 5);
	CCSprite* pSpriteButton = CCSprite::create(s_restart);
	pSpriteButton->setPosition(ccp(330, 520));
	this->addChild(pSpriteButton, 5, kTagRestart);
	CCLabelTTF* pLabelButton = CCLabelTTF::create(g_restart, "宋体", 23);
	pLabelButton->setPosition(ccp(330, 520));
	pLabelButton->setColor(ccc3(0, 0, 0));
	this->addChild(pLabelButton, 5);

	int nMove = 300;
	pStrokeTitle->runAction(CCMoveTo::create(1.2f, ccp(pStrokeTitle->getPositionX(), pStrokeTitle->getPositionY() - nMove)));
	pLabelTitle->runAction(CCMoveTo::create(1.2f, ccp(pLabelTitle->getPositionX(), pLabelTitle->getPositionY() - nMove)));
	pStrokeResult->runAction(CCMoveTo::create(1.2f, ccp(pStrokeResult->getPositionX(), pStrokeResult->getPositionY() - nMove)));
	pLabelResult->runAction(CCMoveTo::create(1.2f, ccp(pLabelResult->getPositionX(), pLabelResult->getPositionY() - nMove)));
	pSpriteButton->runAction(CCMoveTo::create(1.2f, ccp(pSpriteButton->getPositionX(), pSpriteButton->getPositionY() - nMove)));
	pLabelButton->runAction(CCMoveTo::create(1.2f, ccp(pLabelButton->getPositionX(), pLabelButton->getPositionY() - nMove)));
}
//更新时间进度条
void SpriteGrid::updateProgressPercent( float fPercentage )
{
	CCProgressTimer* pProgressTimer = (CCProgressTimer*)this->getChildByTag(kTagProgress);
	pProgressTimer->setPercentage(fPercentage + pProgressTimer->getPercentage());
	if (100 <= pProgressTimer->getPercentage())
	{
		pProgressTimer->setPercentage(0);
		unschedule(schedule_selector(SpriteGrid::updateProgress));
		overGame();
	}
}
CCRenderTexture* SpriteGrid::createStroke( CCLabelTTF* pLabel, float size, ccColor3B color )
{
	CCRenderTexture* rt = CCRenderTexture::create(pLabel->getTexture()->getContentSize().width + size * 2,
		pLabel->getTexture()->getContentSize().height + size * 2);
	CCPoint originalPos = pLabel->getPosition();
	ccColor3B originalColor = pLabel->getColor();
	bool originalVisibility = pLabel->isVisible();
	pLabel->setColor(color);
	pLabel->setVisible(true);
	ccBlendFunc originalBlend = pLabel->getBlendFunc();
	ccBlendFunc newBlend = {GL_SRC_ALPHA, GL_ONE};
	pLabel->setBlendFunc(newBlend);

	CCPoint bottomLeft = ccp(pLabel->getTexture()->getContentSize().width * pLabel->getAnchorPoint().x + size, 
		pLabel->getTexture()->getContentSize().height * pLabel->getAnchorPoint().y + size);
	CCPoint positionOffset = ccp(pLabel->getTexture()->getContentSize().width * pLabel->getAnchorPoint().x - pLabel->getTexture()->getContentSize().width / 2, 
		pLabel->getTexture()->getContentSize().height * pLabel->getAnchorPoint().y - pLabel->getTexture()->getContentSize().height / 2);
	CCPoint position = ccpSub(originalPos, positionOffset);

	rt->begin();
	for (int i = 0; i < 360; i += 30)
	{
		pLabel->setPosition(ccp(bottomLeft.x + sin(CC_DEGREES_TO_RADIANS(i)) * size, bottomLeft.y + cos(CC_DEGREES_TO_RADIANS(i)) * size));
		pLabel->visit();
	}
	rt->end();
	pLabel->setPosition(originalPos);
	pLabel->setColor(originalColor);
	pLabel->setBlendFunc(originalBlend);
	pLabel->setVisible(originalVisibility);
	rt->setPosition(position);
	return rt;
}
//初始背影
void initBackGroup() 
{

}
//初始网格背景
void initCellBackGroup() 
{

}
//初始精灵
void initSprite() 
{

}
//初始精灵边框
void initBorderSprite()
{

}
//初始关卡进度条
void initLevelProgress()
{

}
//初始得分面板
void initScore()
{

}
//初始声音
void initSound()
{

}


