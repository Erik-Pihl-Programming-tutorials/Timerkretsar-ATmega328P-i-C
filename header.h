/********************************************************************************
* header.h: Inneh�ller diverse definitioner och deklarationer f�r 
*           implementering av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Inneh�ller information om I/O-register s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller information om avbrottsrutiner. */

/* Makrodefinitioner: */
#define LED1 PORTB0 /* Lysdiod 1 ansluten till pin 8 (PORTB0). */
#define LED2 PORTB1 /* Lysdiod 2 ansluten till pin 9 (PORTB1). */
#define LED3 PORTB2 /* Lysdiod 3 ansluten till pin 10 (PORTB2). */

#define LED1_TOGGLE PINB = (1 << LED1) /* Togglar lysdiod 1. */
#define LED2_TOGGLE PINB = (1 << LED2) /* Togglar lysdiod 2. */
#define LED3_TOGGLE PINB = (1 << LED3) /* Togglar lysdiod 3. */

#define TIMER0_ELAPSE_TIME_MS 100 /* Timer 0 l�per ut efter 100 ms. */
#define TIMER1_ELAPSE_TIME_MS 200 /* Timer 1 l�per ut efter 200 ms. */
#define TIMER2_ELAPSE_TIME_MS 500 /* Timer 2 l�per ut efter 500 ms. */

#define TIME_BETWEEN_INTERRUPTS_MS 0.128 /* Tid mellan varje timergenererat avbrott. */

/********************************************************************************
* TIMERx_COUNTER_MAX: Maxv�rde f�r antalet timergenerade avbrott som r�knare f�r
*                     respektive timer ska r�kna upp till, vilket sker direkt
*                     i avbrottsrutinerna via statiska flyktiga variabler.
********************************************************************************/
#define TIMER0_COUNTER_MAX (uint32_t)(TIMER0_ELAPSE_TIME_MS / TIME_BETWEEN_INTERRUPTS_MS + 0.5)
#define TIMER1_COUNTER_MAX (uint32_t)(TIMER1_ELAPSE_TIME_MS / TIME_BETWEEN_INTERRUPTS_MS + 0.5)
#define TIMER2_COUNTER_MAX (uint32_t)(TIMER2_ELAPSE_TIME_MS / TIME_BETWEEN_INTERRUPTS_MS + 0.5)

/********************************************************************************
* setup: Initierar det inbyggda systemet (I/O-portar samt timerkretsar).
********************************************************************************/
void setup(void);

#endif /* HEADER_H_ */