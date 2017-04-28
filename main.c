
#define F_CPU 8000000UL
#include <avr/io.h>
#include "motor.h"
#include "qtr_driver.h"
#include <util/delay.h>

int main()
{
	//DDRF = 0x00;
	DDRB = 0x00; 			//We'll output QTR values continuously to PORTB. set port d as an output port.
	init_motors();
	init_QTR_driver();  //iMust call the driver initialization
	unsigned char QTR_Val;
	
	while(1){
		QTR_Val = get_QTR_value() & 0x03; // setting value to the right 4 sensors if both black

		// if(QTR_Val == 0x03){
		// 	rightmotor_forward();
		// 	leftmotor_reverse();
		// 	_delay_ms(2);
		// 	rightmotor_brake();
		// 	leftmotor_brake();
		// 	_delay_ms(1);
		// }
		if(QTR_Val == 0x00){		// if all white
			//while(QTR_Val == 0x00){
				//QTR_Val = get_QTR_value() & 0x03;
				
					rightmotor_reverse();
					leftmotor_forward();
					_delay_ms(2);
					rightmotor_brake();
					leftmotor_brake();
					_delay_ms(2);
			//}
			//	rightmotor_reverse();
			//	leftmotor_forward();
			//	_delay_ms(2);
			//	rightmotor_brake();
			//	leftmotor_brake();
			//	_delay_ms(1);			
		}
		else if(QTR_Val == 0x01){
				rightmotor_forward();
				leftmotor_forward();
				_delay_ms(2);
				rightmotor_brake();
				leftmotor_brake();
				_delay_ms(2);
			
			
		}
		else if(QTR_Val == 0x02){
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);
		}
		else{
			rightmotor_forward();
			leftmotor_reverse();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);
		}

	}
}

/*		if(QTR_Val == 0x33) {
			leftmotor_forward();
			rightmotor_forward();
			_delay_ms(2);
			leftmotor_brake();
			rightmotor_brake();
			_delay_ms(2);
		} 
		
		else if(QTR_Val == 0x00) {
			leftmotor_reverse();
			rightmotor_reverse();
			_delay_ms(2);
			leftmotor_brake();
			rightmotor_brake();
			_delay_ms(2);
		}
*/	

	

	


	