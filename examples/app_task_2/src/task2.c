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
#include "led.h"

#define DEBUG_MODULE "HELLOWORLD"
#include "debug.h"

#define d 200
uint16_t testmelody[52] = {D4, d, D4, d, E4, 2*d, D4, 2*d, G4, 2*d, GES4, 4*d,D4, d, D4, d, E4, 2*d, D4, 2*d, A4, 2*d, G4, 4*d, D4, d, D4, d, D5, 2*d, H4, 2*d, G4, 2*d, GES4, 2*d, E4, 2*d, C5, d, C5, d, H4, 2*d, G4, 2*d, A4, 2*d, G4, 4*d, D4, 0};

// Play a tone with a given frequency and a specific duration in milliseconds (ms)
void motorsPlayTone(uint16_t frequency, uint16_t duration_msec)
{
  motorsBeep(MOTOR_M1, true, frequency, (uint16_t)(MOTORS_TIM_BEEP_CLK_FREQ / frequency)/ 20);
  motorsBeep(MOTOR_M2, true, frequency, (uint16_t)(MOTORS_TIM_BEEP_CLK_FREQ / frequency)/ 20);
  motorsBeep(MOTOR_M3, true, frequency, (uint16_t)(MOTORS_TIM_BEEP_CLK_FREQ / frequency)/ 20);
  motorsBeep(MOTOR_M4, true, frequency, (uint16_t)(MOTORS_TIM_BEEP_CLK_FREQ / frequency)/ 20);
  vTaskDelay(M2T(duration_msec));
  motorsBeep(MOTOR_M1, false, frequency, 0);
  motorsBeep(MOTOR_M2, false, frequency, 0);
  motorsBeep(MOTOR_M3, false, frequency, 0);
  motorsBeep(MOTOR_M4, false, frequency, 0);
}

// Plays a melody from a note array
void motorsPlayMelody(uint16_t *notes)
{
  int i = 0;
  uint16_t note;      // Note in hz
  uint16_t duration;  // Duration in ms

  do
  {
    note = notes[i++];
    duration = notes[i++];
    motorsPlayTone(note, duration);
    // DEBUG_PRINT("%d %d\n", note, duration);
  } while (duration != 0);
}

void appMain() {
  DEBUG_PRINT("I am the solution of programming task 2 ...\n");

  while(1) {
    vTaskDelay(M2T(2000));
    motorsPlayMelody(testmelody);
  }
}
