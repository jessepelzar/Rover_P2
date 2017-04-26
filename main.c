
#define F_CPU 8000000UL
#include "motor.h"
#include <avr/io.h>
#include "qtr_driver.h"
#include <util/delay.h>

int main()
{
	DDRB=0xFF; 			//We'll output QTR values continuously to PORTB. set port d as an output port.
	init_QTR_driver();  //iMust call the driver initialization
	unsigned char QTR_Val;
	//Forever output QTR value on PORTB
	while(1){
		QTR_Val=get_QTR_value() & 0x0C;
		if(QTR_Val == 0x0C){
			leftmotor_forward;
			_delay_ms(2);
			rightmotor_forward;
			_delay_ms(2);
		}
		
	}
	return 0;
}
	
