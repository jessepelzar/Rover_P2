// ©Jesse Pelzar
// 4/20/17
#define F_CPU 1000000UL
#include "motor.c"
#include "qtr_driver.c"

int main () {
	init_motors();
	init_QTR_driver();
	unsigned char QTR_Val;

	while (1) {
		QTR_Val = get_QTR_value() & 0x0F;
		
		if (QTR_Val == 0x0F) {
			rightmotor_forward();
			leftmotor_reverse();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);
		}
		else if (QTR_Val == 0x00) {
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);		
		}
		else if (QTR_Val == 0x03) {
			rightmotor_forward();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);	
		}
		else if (QTR_Val == 0x01) {
			rightmotor_forward();
			leftmotor_forward();
			_delay_ms(2);
			leftmotor_brake();
			_delay_ms(1);
		}
		else if (QTR_Val == 0x0E) {
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(1);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(2);
		}
		else if (QTR_Val == 0x0C) {
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(1);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(2);
		} 
		else {						
			rightmotor_forward();
			leftmotor_forward();
			_delay_ms(1);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(2);
		}
	}
	return 0;
}


// <------not used-----><------in use------>
// [ n ][ n ][	n ][ n ][ y ][ y ][ y ][ y ]
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB
// BBBBBBBBWWWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBB

// 1 = black detected
// 0 = white detected

// 0x00 -- 0000
// 0x01 -- 0001
// 0x02 -- 0010
// 0x03 -- 0011
// 0x04 -- 0100
// 0x05 -- 0101
// 0x06 -- 0110
// 0x07 -- 0111
// 0x08 -- 1000
// 0x09 -- 1001
// 0x0A -- 1010
// 0x0B -- 1011
// 0x0C -- 1100
// 0x0D -- 1101
// 0x0E -- 1110
// 0x0F -- 1111




