//program to demonstrate use of QTR driver
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
		QTR_Val=get_QTR_value();
		if(QTR_Val == 0x3C){
			leftmotorport = 0x01;
			_delay_ms(2);
			rightmotorport = 0x01;
			_delay_ms(2);
		}
		
	}
	return 0;
}
	
