
#define F_CPU 1000000UL
#include "motor.c"
#include "qtr_driver.c"

int main()
{
	init_motors();
	init_QTR_driver();  //iMust call the driver initialization
	unsigned char QTR_Val;
	//uint8_t encoderVal = leftquad_value() ^ rightquad_value();

	while(1){
		QTR_Val = get_QTR_value() & 0x03; // setting value to the right 4 sensors if both black
		
		if(QTR_Val == 0x03){			// if all black
			rightmotor_forward();
			leftmotor_reverse();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);
		}
		else if(QTR_Val == 0x00){		// if all white
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);		
		}
		else if(QTR_Val == 0x01){ //black on right, white on left
			rightmotor_forward();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);	
		}
		else if(QTR_Val == 0x02){ //black on left, white on right
			rightmotor_reverse();
			leftmotor_forward();
			_delay_ms(2);
			rightmotor_brake();
			leftmotor_brake();
			_delay_ms(1);
		
		}
	}
}

	


	