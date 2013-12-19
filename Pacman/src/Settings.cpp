/*
 * Settings.cpp
 *
 *  Created on: Dec 19, 2013
 *      Author: ivar
 */

#include "Settings.h"


Settings::Settings() :
  soundLevel{0},
  soundMute{true},

  scoreDot{10},
  scoreFruit{50},
  scoreGhost{100},

  fps{16},
  frameTime{1000 / fps},

  sickTime{10 * 1000},
  blinkTime{2 * 1000},

  ghostCount{4},
  ghostSleep{200}
{
}
