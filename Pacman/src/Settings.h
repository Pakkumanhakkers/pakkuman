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
  int soundLevel{0};
  bool soundMute{true};

  int scoreDot{10};
  int scoreFruit{50};
  int scoreGhost{100};

  int frameTime{200};

  int sickTime{10 * 1000};
  int blinkTime{2 * 1000};

  int ghostCount{4};
  int ghostSleep{200};
};


#endif /* SETTINGS_H_ */
