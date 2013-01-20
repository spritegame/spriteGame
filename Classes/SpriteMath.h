#ifndef __SPRITE_MATH_H__
#define __SPRITE_MATH_H__

#include "CCStdC.h"
#include <math.h>
#include <vector>
#include "SpriteConstant.h"

//��ɫ
static const int COLOR_GREEN = 0x0001;
//��ɫ
static const int COLOR_RED = 0x0002;
//��ɫ
static const int COLOR_BLUE = 0x0003;
//��ɫ
static const int COLOR_BROWN = 0x0003;
//��ɫ
static const int COLOR_GOLDEN = 0x0004;
//��ɫ
static const int COLOR_PURPLE = 0x0005;

class SpriteMath
{
public:
#define GAME_TOTAL_LEVEL 10

//��ȡ����ɫ��Ĳ�ͬ�ɫ��
int getLevelColors(int intLevel);
//��ȡ���ص����Ϸʱ��
int getLevelTime(int intLevel);
//��ȡ����ͨ�ر���ﵽ�ķ���
int getLevelPassScore(int intLevel);
//�ж��Ƿ�ͨ��
bool isPassLevel(int intLevel, int intScore);
//��ȡ�û�ͨ��ʱ��ȡ�������Ǹ���
int getLevelStars(int intLevel, int intSuccessTime);

//��ȡ�û���ǰ�ؿ���ʱ������
int getCurLevelUserScore();

//�����û���ǰ�ؿ���ʱ������
int setCurLevelUserScore(int oneTimeScore);

//��ȡ�û���ǰ�ؿ���ʱ������
int getUserTotalScore();

//�����û���ǰ�ؿ���ʱ������
int setUserTotalScore(int curLevelScore);


static std::vector<int> findCrossSprites(char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL], int index);//��ȡ�뱻�����ɫ��ͬɫ�ڽ�ɫ��

};


#endif


