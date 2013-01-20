#include "SpriteMath.h"
#include "cocos2d.h"
#include <memory>

USING_NS_CC;
using namespace std;

//��ʼ����
const int ADDED_DIRECTION_INIT = 0x0000;
//��
const int ADDED_DIRECTION_UP = 0x0001;
//��
const int ADDED_DIRECTION_DOWN = 0x0002;
//��
const int ADDED_DIRECTION_LEFT = 0x0003;
//��
const int ADDED_DIRECTION_RIGHT = 0x0004;
//ͬɫ��������
vector<int> vInts;
//��������
int spriteTotalNum = MAX_GAME_ROW * MAX_GAME_COL;
//����˵ľ�����
bool  addedSprites[MAX_GAME_ROW * MAX_GAME_COL];



static void addSprites(char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL], int index, int Direction)
{
	//int i = 0;
	if (index < 0 || index >= spriteTotalNum)  //������鳬Խ�˷�Χ��ֱ���˳���
		return;

	if ( Direction != ADDED_DIRECTION_DOWN && 
		(index + MAX_GAME_COL) < spriteTotalNum  && m_BlocksType[index + MAX_GAME_COL] == m_BlocksType[index] 
		&& addedSprites[index + MAX_GAME_COL] == false)
	{
	//	i++;
		vInts.push_back(index + MAX_GAME_COL);
		addedSprites[index + MAX_GAME_COL] = true;
		addSprites(m_BlocksType, index + MAX_GAME_COL, ADDED_DIRECTION_UP);
	}

	if ( Direction != ADDED_DIRECTION_UP && 
		index - MAX_GAME_COL > 0  && m_BlocksType[index - MAX_GAME_COL] == m_BlocksType[index]
		&& addedSprites[index - MAX_GAME_COL] == false)
	{
	//	i++;
		vInts.push_back(index - MAX_GAME_COL);
		addedSprites[index - MAX_GAME_COL] = true; 
		addSprites(m_BlocksType, index - MAX_GAME_COL, ADDED_DIRECTION_DOWN);
	}
	if ( Direction != ADDED_DIRECTION_RIGHT && 
		(index % MAX_GAME_COL)  != 0  && m_BlocksType[index - 1] == m_BlocksType[index]
		&& addedSprites[index - 1] == false)
	{
	//	i++;
		vInts.push_back(index -1);
		addedSprites[index - 1] = true;
		addSprites(m_BlocksType, index -1, ADDED_DIRECTION_LEFT);
	}
	if ( Direction != ADDED_DIRECTION_LEFT && 
		((index + 1) % MAX_GAME_COL)  != 0 &&  m_BlocksType[index + 1] == m_BlocksType[index]
		&& addedSprites[index + 1] == false)
	{
	//	i++;
		vInts.push_back(index + 1);
		addedSprites[index + 1] = true;
		addSprites(m_BlocksType, index + 1, ADDED_DIRECTION_RIGHT);
	}

}
vector<int> SpriteMath::findCrossSprites(char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL], int index)
{
	memset(addedSprites, 0, sizeof(addedSprites)); 
	vInts.clear();
	vInts.push_back(index);
	addedSprites[index] = true;
	addSprites(m_BlocksType, index, ADDED_DIRECTION_INIT);
    return vInts;
}


//��ȡ����ɫ��Ĳ�ͬ�ɫ��

const int LEVEL_COLOR_BASE = 3;
const int LEVEL_COLOR_BASE_LEVEL = 3;

int SpriteMath::getLevelColors(int intLevel)
{
	if ( intLevel <= 0)
		return 0;

	if (intLevel <= LEVEL_COLOR_BASE_LEVEL)
		return LEVEL_COLOR_BASE;
	else if (intLevel <= LEVEL_COLOR_BASE_LEVEL * 2)
		return LEVEL_COLOR_BASE + 1;
	else// if (intLevel <= LEVEL_COLOR_BASE_LEVEL * 3)
		return LEVEL_COLOR_BASE + 2;
}

//��ȡ���ص����Ϸʱ��
const int LEVEL_TIME_BASE = 60; //һ���ؿ��Ļ�����Ϸʱ��������Ϊ��λ��
const int LEVEL_TIME_INCREASED_LEVEL = 3;

int SpriteMath::getLevelTime(int intLevel)
{
	if (intLevel <= 0)
		return 0;
	if ( intLevel % LEVEL_TIME_INCREASED_LEVEL == 0)
		return LEVEL_TIME_BASE * (intLevel / LEVEL_TIME_INCREASED_LEVEL);
	else
		return LEVEL_TIME_BASE * (intLevel / LEVEL_TIME_INCREASED_LEVEL + 1);
}

//��ȡ����ͨ�ر���ﵽ�ķ���
const int LEVEL_SCORE_BASE = 2000;
const int LEVEL_SCORE_INCREASE = 1000;

int SpriteMath::getLevelPassScore(int intLevel)
{
	if (intLevel <= 0)
		return 0;
	return LEVEL_SCORE_BASE + (intLevel - 1) * LEVEL_SCORE_INCREASE;
}

//�ж��Ƿ�ͨ��
bool SpriteMath::isPassLevel(int intLevel, int intScore)
{
	if (intLevel <= 0 || intScore <= 0)
		return 0;

	int passScore = getLevelPassScore(intLevel);
	return intScore >= passScore ? true : false;
}

//��ȡ�û�ͨ��ʱ��ȡ�������Ǹ���
const float LEVEL_STAR_TWO = 0.7f;
const float LEVEL_STAR_THREE = 0.5f;

int SpriteMath::getLevelStars(int intLevel, int intSuccessTime)
{
	if (intLevel <= 0 || intSuccessTime <= 0)
		return 0;
	int levelTime = getLevelTime(intLevel);
	if ( intSuccessTime <= (int)(LEVEL_STAR_THREE * levelTime))
		return 3;
	else if (intSuccessTime <= (int)(LEVEL_STAR_TWO * levelTime))
		return 2;
	else
		return 1;
}

//��ȡ�û���ǰ�ؿ���ʱ������
int userLevelScore = 0;
int SpriteMath::getCurLevelUserScore()
{
	return userLevelScore;
}

//�����û���ǰ�ؿ���ʱ������
int SpriteMath::setCurLevelUserScore(int oneTimeScore)
{
	userLevelScore = userLevelScore + oneTimeScore;
	return userLevelScore;
}

//��ȡ�û���ǰ�ؿ���ʱ������
int SpriteMath::getUserTotalScore()
{
	return CCUserDefault::sharedUserDefault()->getIntegerForKey("USER_TOTAL_SCORE", 0);
}

//�����û���ǰ�ؿ���ʱ������
int SpriteMath::setUserTotalScore(int curLevelScore)
{
	int userTotalScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("USER_TOTAL_SCORE", 0);
	if (curLevelScore > 0)
	{
		userTotalScore = userTotalScore + curLevelScore;
		CCUserDefault::sharedUserDefault()->setIntegerForKey("USER_TOTAL_SCORE", userTotalScore);
	}
	return userTotalScore;
}

