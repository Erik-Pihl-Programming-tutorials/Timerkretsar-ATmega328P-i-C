/********************************************************************************
* setup.c: Innehåller initieringsrutiner.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_timers(void);

/********************************************************************************
* setup: Initierar det inbyggda systemet (I/O-portar samt timerkretsar).
********************************************************************************/
void setup(void)
{
   init_ports();
   init_timers();
   return;
}

/********************************************************************************
* init_ports: Sätter lysdioderna till utportar genom ettställning av motsvarande
*             bitar i datariktningsregister DDRB.
********************************************************************************/
static inline void init_ports(void)
{
   DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
   return;
}

/********************************************************************************
* init_timers: Aktiverar timerkretsar Timer 0 - 2 till att generera avbrott
*              var 0.128 ms.
*
*              1. Vi aktiverar avbrott globalt via ettställning av I-flaggan
*                 i statusregister SREG.
*
*              2. Vi ställer in Timer 0 i Normal Mode med avbrott var 0.128:e ms
*                 genom ettställning av biten CS01 (Clock Select 0 bit 1) i
*                 kontrollregistret TCCR0B (Timer/Counter Control Register 0 B).
*
*                 Vi aktiverar sedan overflow-avbrott på Timer 0 genom att
*                 ettställa biten TOIE0 (Timer/Counter Overflow Interrupt Enable 0)
*                 i maskregistret TIMSK0 (Timer/Counter Interrupt Mask Register 0).
*                 Vid uppräkning till 256, då registret är överfullt, får vi
*                 overflow, varav avbrott sker och kvarvarande innehåll blir 0,
*                 eftersom 256 = 1 0000 0000, där ettan trunkeras så att 0
*                 återstår i räknarregistret TCNT0 (Timer/Counter Register 0).
*
*              3. Vi ställer in Timer 1 i CTC Mode (Clear Timer On Compare Match)
*                 så att denna räknar upp till ett specificerat värde lagrat i
*                 register OCR1A (Output Compare Register 1 A). Detta åstadkommes
*                 genom att ettställa biten WGM12 (Waveform Generator Mode 12)
*                 i kontrollregistret TCCR1B (Timer/Counter Control Register 1 B).
*
*                 Vi ställer in avbrott var 0.128:e ms vid uppräkning till 256
*                 genom att ettställa biten CS11 (Clock Select 1 bit 1) i
*                 samma register. Vi specificerar sedan att uppräkning ska ske
*                 till 256 innan avbrott och timern nollställs genom att tilldela
*                 256 till registret OCR1A. 
*
*                 Slutligen aktiveras avbrott när innehållet i räknarregistret 
*                 TCNT1 (Timer/Counter 1) är lika med innehållet i OCR1A (256)
*                 genom att ettställa biten OCIE1A (Output Compare A Match 
*                 Interrupt Enable 1 A) i maskregistret TIMSK1 (Timer/Counter 
*                 Mask Register 1).
*
*              4. Vi ställer in Timer 2 i Normal Mode med avbrott var 0.128:e ms
*                 genom ettställning av biten CS21 (Clock Select 2 bit 1) i
*                 kontrollregistret TCCR2B (Timer/Counter Control Register 2 B).
*
*                 Vi aktiverar sedan overflow-avbrott på Timer 2 genom att
*                 ettställa biten TOIE2 (Timer/Counter Overflow Interrupt Enable 2)
*                 i maskregistret TIMSK2 (Timer/Counter Interrupt Mask Register 2).
*                 Vid uppräkning till 256, då registret är överfullt, får vi
*                 overflow, varav avbrott sker och kvarvarande innehåll blir 0,
*                 eftersom 256 = 1 0000 0000, där ettan trunkeras så att 0
*                 återstår i räknarregistret TCNT2 (Timer/Counter Register 2).            
********************************************************************************/
static inline void init_timers(void)
{
   asm("SEI");
   TCCR0B = (1 << CS01);
   TIMSK0 = (1 << TOIE0);

   TCCR1B = (1 << WGM12) | (1 << CS11);
   OCR1A = 256;
   TIMSK1 = (1 << OCIE1A);

   TCCR2B = (1 << CS21);
   TIMSK2 = (1 << TOIE2);
   return;
}