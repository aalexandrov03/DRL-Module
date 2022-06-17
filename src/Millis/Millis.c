#include <avr/io.h>
#include <util/atomic.h>
#include <avr/interrupt.h>

#include <Millis.h>

ISR(TIMER1_COMPA_vect) {
	_millis ++;
}

void init_millis() {
	unsigned long ctc_match_overflow;

	ctc_match_overflow = ((F_CPU / 1000) / 8);

	TCCR1B |= (1 << WGM12) | (1 << CS11);

	OCR1AH = (ctc_match_overflow >> 8);
	OCR1AL = ctc_match_overflow;

	TIMSK1 |= (1 << OCIE1A);

	//REMEMBER TO ENABLE GLOBAL INTERRUPTS AFTER THIS WITH sei(); !!!
}

unsigned long millis(void) {
	unsigned long millis_return;

	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		millis_return = _millis;
	}

	return millis_return;
}
