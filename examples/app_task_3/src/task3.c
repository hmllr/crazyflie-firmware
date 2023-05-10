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
#include "param.h"

#define DEBUG_MODULE "TASK3"
#include "debug.h"

static uint8_t test = 0;

void appMain() {
  DEBUG_PRINT("I am the solution of programming task 3 ...\n");

  while(1) {
    vTaskDelay(M2T(2000));
    DEBUG_PRINT("Hello World! %d \n", test);
  }
}
PARAM_GROUP_START(app)
  PARAM_ADD(PARAM_UINT8, test, &test)
PARAM_GROUP_STOP(app)