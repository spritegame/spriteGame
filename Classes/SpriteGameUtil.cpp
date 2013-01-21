/*
 * SpriteGameUtil.cpp
 *
 *  Created on: 2013-1-20
 *      Author: allin.dev
 */

#include "SpriteGameUtil.h"

using namespace std;

template<class T>
string SpriteGameUtil::ToString(T t)
{
    stringstream sstm;
    string str;
    sstm<<t;
    sstm>>str;
    return str;
}

template<class T1,class T2>
T1 SpriteGameUtil::ConvertTo(T2 t)
{
    stringstream sstm;
    T1 res;
    sstm<<t;
    sstm>>res;
    return res;
}


