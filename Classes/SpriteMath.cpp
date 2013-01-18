#include "SpriteMath.h"
#include <memory>

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