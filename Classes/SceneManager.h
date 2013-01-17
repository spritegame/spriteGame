/*
 * SceneManager.h
 *
 *  Created on: 2013-1-13
 *      Author: allin.dev
 */
#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

class SceneManager {
public:
	static SceneManager* sharedGameManager();
	static void purgeSharedGameManager();

	bool init();

	enum SceneId
	{
		SCENE_LOADING,
		SCENE_MENU,
		SCENE_PLAY,
		SCENE_GAMEOVER,
		SCENE_HELP

	};

	void runScene(SceneId id);


protected:
	SceneManager();
	~SceneManager();

private:
	static SceneManager* m_pSharedGameManager;


};



#endif /* SCENEMANAGER_H_ */
