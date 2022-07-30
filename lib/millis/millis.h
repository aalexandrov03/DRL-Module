#ifndef _MILLIS_H_
#define _MILLIS_H_

volatile unsigned long _millis;

ISR(TIMER1_COMPA_vect);
void init_millis(void);
unsigned long millis(void);

#endif
