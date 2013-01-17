#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

class SoundManager {
public:
	static SoundManager *sharedSoundManager();
	static void purgeSharedSoundManager();

	void playMusic();
	void playMusic(bool loop);
	void stopMusic();
	void pauseMusic();
	void resumeMusic();
	void rewindMusic();


	int playEffect();
	int playEffect(bool loop);
	void stopEffect(int soundId);
	void stopAllEffects();

	void setMusic(bool isMusic);
	void setSoundEffect(bool isSoundEffect);
	bool isMusicPlaying();
	bool isSoundEffectPlaying();

protected:
	SoundManager();
	~SoundManager();

	bool init();

private:
	static SoundManager* m_pSharedSoundManager;
	/*
	 * 是否打开背景音乐
	 */
	bool m_bIsMusic;
	/*
	 * 是否打开音效
	 */
	bool m_bIsSoundEffect;

};

#endif

