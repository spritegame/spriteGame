#ifndef __SPRITE_MATH_H__
#define __SPRITE_MATH_H__

#include "CCStdC.h"
#include <math.h>
#include <vector>
#include "SpriteConstant.h"

//绿色
static const int COLOR_GREEN = 0x0001;
//红色
static const int COLOR_RED = 0x0002;
//蓝色
static const int COLOR_BLUE = 0x0003;
//褐色
static const int COLOR_BROWN = 0x0003;
//金色
static const int COLOR_GOLDEN = 0x0004;
//金色
static const int COLOR_PURPLE = 0x0005;

class SpriteMath
{
public:
#define GAME_TOTAL_LEVEL 10

//获取各关色块的不同顔色数
int getLevelColors(int intLevel);
//获取各关的最长游戏时间
int getLevelTime(int intLevel);
//获取各关通关必须达到的分数
int getLevelPassScore(int intLevel);
//判断是否通关
bool isPassLevel(int intLevel, int intScore);
//获取用户通关时获取到的星星个数
int getLevelStars(int intLevel, int intSuccessTime);

//获取用户当前关卡即时分数；
int getCurLevelUserScore();

//保存用户当前关卡即时分数；
int setCurLevelUserScore(int oneTimeScore);

//获取用户当前关卡即时分数；
int getUserTotalScore();

//保存用户当前关卡即时分数；
int setUserTotalScore(int curLevelScore);


static std::vector<int> findCrossSprites(char m_BlocksType[MAX_GAME_ROW * MAX_GAME_COL], int index);//获取与被点击的色块同色邻近色块

};


#endif


