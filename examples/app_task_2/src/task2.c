/**
 * ,---------,       ____  _ __
 * |  ,-^-,  |      / __ )(_) /_______________ _____  ___
 * | (  O  ) |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * | / ,--´  |    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *    +------`   /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2019 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * task2.c - App layer application for task 2 
 * 
 * 9.5.2023 modified by: Hanna Müller, hanmuell@ethz.ch, ETH Zürich
 */


#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"

#include "FreeRTOS.h"
#include "task.h"

#include "motors.h"

#define DEBUG_MODULE "TASK2"
#include "debug.h"

uint16_t testmelody[] = {D4, 0}; // PLACEHOLDER FOR YOUR MELODY

// Play a tone with a given frequency and a specific duration in milliseconds (ms)
void motorsPlayTone(uint16_t frequency, uint16_t duration_msec)
{
  // PLACEHOLDER FOR YOUR CODE
}

// Plays a melody from a note array - end with a 0 duration note to terminate
void motorsPlayMelody(uint16_t *notes)
{
  // PLACEHOLDER FOR YOUR CODE
}

void appMain() {
  DEBUG_PRINT("I am programming task 2 ...\n");

  while(1) {
    vTaskDelay(M2T(2000));
    // PLACEHOLDER FOR YOUR CODE
  }
}
