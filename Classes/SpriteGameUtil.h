/*
 * SpriteGameUtil.h
 *
 *  Created on: 2013-1-20
 *      Author: allin.dev
 */

#ifndef SPRITEGAMEUTIL_H_
#define SPRITEGAMEUTIL_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class SpriteGameUtil {
public:
	template<class T>
	string ToString(T t);

	template<class T1,class T2>
	T1 ConvertTo(T2 t);
};


#endif /* SPRITEGAMEUTIL_H_ */
