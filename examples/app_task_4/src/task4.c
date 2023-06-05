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
 * task2.c - App layer application for task 4
 * 
 * 9.5.2023 modified by: Hanna Müller, hanmuell@ethz.ch, ETH Zürich
 */


#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"
#include "deck.h"

#include "FreeRTOS.h"
#include "task.h"

#define DEBUG_MODULE "task4"
#include "debug.h"

#define DECK_GPIO_LED_RED       DECK_GPIO_RX1
#define DECK_GPIO_LED_GREEN     DECK_GPIO_TX1
#define DECK_GPIO_LED_YELLOW    DECK_GPIO_TX2
#define DECK_GPIO_LED_BLUE      DECK_GPIO_RX2

void appMain() {
  DEBUG_PRINT("I am the solution of programming task 4 ...\n");
  pinMode(DECK_GPIO_LED_RED, OUTPUT);     // Set my Led pin to output
  pinMode(DECK_GPIO_LED_BLUE, OUTPUT);     // Set my Led pin to output
  pinMode(DECK_GPIO_LED_GREEN, OUTPUT);     // Set my Led pin to output
  pinMode(DECK_GPIO_LED_YELLOW, OUTPUT);     // Set my Led pin to output
  digitalWrite(DECK_GPIO_LED_RED, LOW);  // Turn it off
  digitalWrite(DECK_GPIO_LED_GREEN, LOW);  // Turn it off
  digitalWrite(DECK_GPIO_LED_YELLOW, LOW);  // Turn it off
  digitalWrite(DECK_GPIO_LED_BLUE, LOW);  // Turn it off
  while(1) {
    digitalWrite(DECK_GPIO_LED_BLUE, LOW);  // Turn it off
    digitalWrite(DECK_GPIO_LED_RED, HIGH);  // Light it up
    vTaskDelay(M2T(1000));
    digitalWrite(DECK_GPIO_LED_RED, LOW);  // Turn it off
    digitalWrite(DECK_GPIO_LED_GREEN, HIGH);  // Light it up
    vTaskDelay(M2T(1000));
    digitalWrite(DECK_GPIO_LED_GREEN, LOW);  // Turn it off
    digitalWrite(DECK_GPIO_LED_YELLOW, HIGH);  // Light it up
    vTaskDelay(M2T(1000));
    digitalWrite(DECK_GPIO_LED_YELLOW, LOW);  // Turn it off
    digitalWrite(DECK_GPIO_LED_BLUE, HIGH);  // Light it up
    vTaskDelay(M2T(1000));
  }
}
