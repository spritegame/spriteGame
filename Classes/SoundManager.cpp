#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SoundManager.h"
#include "string.h"

// android effect only support ogg
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE        "effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE        "effect1.raw"
#else
#define EFFECT_FILE        "effect1.wav"
#endif // CC_PLATFORM_ANDROID
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE        "music.mid"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE        "background.ogg"
#else
#define MUSIC_FILE        "background.mp3"
#endif // CC_PLATFORM_WIN32
USING_NS_CC;
using namespace CocosDenshion;

SoundManager *SoundManager::_sharedSoundManager = NULL;

SoundManager::SoundManager() :
		_isMusic(true), _isSoundEffect(true) {

	_isMusic = CCUserDefault::sharedUserDefault()->getBoolForKey("isMusic",true);
	_isSoundEffect = CCUserDefault::sharedUserDefault()->getBoolForKey("isSoundEffect",true);
}

SoundManager::~SoundManager() {
}

SoundManager *SoundManager::sharedSoundManager() {
	if (_sharedSoundManager == NULL) {
		CCLog("create SoundManager...");
		_sharedSoundManager = new SoundManager();
		if (!_sharedSoundManager || !_sharedSoundManager->init()) {
			CC_SAFE_DELETE(_sharedSoundManager);
		}

	}

	return _sharedSoundManager;

}

void SoundManager::purgeSharedSoundManager() {
	CC_SAFE_DELETE(_sharedSoundManager);

}

bool SoundManager::init() {
	bool bRet = false;
	do {
		CCLog("pre-load sound start....");
		// preload background music and effect
		SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(
				CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(MUSIC_FILE));
		SimpleAudioEngine::sharedEngine()->preloadEffect(
				CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE));
		CCLog("pre-load sound end....");

		// set default volume
//		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
//		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);

		bRet = true;

	} while (0);

	return bRet;
}

void SoundManager::playMusic() {
	playMusic(true);
}

void SoundManager::playMusic(bool loop) {
	if (_isMusic) {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
				std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(MUSIC_FILE)).c_str(), loop);
	}
}

void SoundManager::stopMusic() {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void SoundManager::pauseMusic() {
	if (_isMusic) {
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}
}
void SoundManager::resumeMusic() {
	if (_isMusic) {
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
}
void SoundManager::rewindMusic() {
	// rewind background music
	if (_isMusic) {
		SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
	}
}

int SoundManager::playEffect() {
	return playEffect(false);
}
int SoundManager::playEffect(bool loop) {
	if (_isSoundEffect) {
		return SimpleAudioEngine::sharedEngine()->playEffect(
				std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE)).c_str(), loop);
	}

	return 0;
}

void SoundManager::stopEffect(int soundId) {
	SimpleAudioEngine::sharedEngine()->stopEffect(soundId);
}
void SoundManager::stopAllEffects() {
	SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

void SoundManager::setMusic(bool isMusic) {
	_isMusic = isMusic;

	CCUserDefault::sharedUserDefault()->setBoolForKey("isMusic",_isMusic);
	if (!_isMusic) {
		stopMusic();
	} else {
		playMusic();
	}
}
void SoundManager::setSoundEffect(bool isSoundEffect) {
	_isSoundEffect = isSoundEffect;

	CCUserDefault::sharedUserDefault()->setBoolForKey("isSoundEffect",_isSoundEffect);

}

bool SoundManager::isMusicPlaying() {
	return _isMusic;

}
bool SoundManager::isSoundEffectPlaying() {
	return _isSoundEffect;
}

