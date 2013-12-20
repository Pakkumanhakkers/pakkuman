/*
 * Settings.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/**
 * Inställningar som bestämmer fysik, poäng och allt möjligt
 */
struct Settings
{
  Settings();

  int soundLevel;
  bool soundMute;

  int initLives;
  int scoreDot;
  int scoreFruit;
  int scoreGhost;

  int fps;
  int frameTime;

  int sickTime;
  int blinkTime;

  int ghostCount;
  int ghostSleep;
  double ghostSpeed;
  double ghostSickSpeed;

  double pacmanSpeed;
};


#endif /* SETTINGS_H_ */
