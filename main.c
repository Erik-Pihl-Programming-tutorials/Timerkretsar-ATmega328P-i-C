/********************************************************************************
* main.c: Demonstration av timerkretsar Timer 0 - Timer2 p� ATmega328P.
*         Tre lysdioder anslutna till pin 8 - 10 (PORTB0 - PORTB2) togglas
*         med olika blinkhastigheter via var sin timerkrets enligt nedan:
*
*         Timer 0 togglar lysdiod 1 p� pin 8 (PORTB0) var 100:e millisekund.
*         Timer 1 togglar lysdiod 2 p� pin 9 (PORTB1) var 200:e millisekund.
*         Timer 2 togglar lysdiod 3 p� pin 10 (PORTB2) var 500:e millisekund.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar det inbyggda systemet vid start. Programmet h�lls ig�ng s�
*       l�nge matningssp�nning tillf�rs. Togglingen av lysdioderna �r genererat
*       via timeravbrott, s� ingen kod f�r toggling implementeras h�r.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {

   }

   return 0;
}

