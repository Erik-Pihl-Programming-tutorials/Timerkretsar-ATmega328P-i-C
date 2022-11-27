/********************************************************************************
* main.c: Demonstration av timerkretsar Timer 0 - Timer2 på ATmega328P.
*         Tre lysdioder anslutna till pin 8 - 10 (PORTB0 - PORTB2) togglas
*         med olika blinkhastigheter via var sin timerkrets enligt nedan:
*
*         Timer 0 togglar lysdiod 1 på pin 8 (PORTB0) var 100:e millisekund.
*         Timer 1 togglar lysdiod 2 på pin 9 (PORTB1) var 200:e millisekund.
*         Timer 2 togglar lysdiod 3 på pin 10 (PORTB2) var 500:e millisekund.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar det inbyggda systemet vid start. Programmet hålls igång så
*       länge matningsspänning tillförs. Togglingen av lysdioderna är genererat
*       via timeravbrott, så ingen kod för toggling implementeras här.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {

   }

   return 0;
}

