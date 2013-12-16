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
  int soundLevel;
  bool soundMute;

  int scoreDot;
  int scoreFruit;
  int scoreGhost;

  int frameTime;

  int sickTime;
  int blinkTime;

  int ghostCount;
  int ghostSleep;
};


#endif /* SETTINGS_H_ */
