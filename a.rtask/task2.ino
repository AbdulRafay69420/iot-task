#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

int main()
{
	unsigned char i,x[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	DDRB=0xff;
	DDRD=0x00;
	int max_count = 0;
	int loop_count = 200;
	int curr_val = 0;
	int max_val = 0;

	while(loop_count)
	{
       	unsigned char port_val = PIND;
		loop_count--;
		_delay_ms(10);
		switch(port_val)
		{
		case 0b00111111:
      	  	curr_val = 0;
			break;
		case 0b00111110:
      	  	curr_val = 1;
			break;
		case 0b00111100:
			curr_val = 2;
			break;
		case 0b00111000:
			curr_val = 3;
			break;
		case 0b00110000:
			curr_val = 4;
			break;
		case 0b00100000:
			curr_val = 5;
			break;
		case 0b00000000:
			curr_val = 6;
			break;
		default:
			curr_val = 0;
			break;
		}

		if(curr_val == max_val){		// current value equal to max value then update max_value count by 1
			max_count++;
		}
		else if(curr_val > max_val){		// current value greater than max value then update max value with current value and update max_value count to 1  
			max_val = curr_val;
			max_count=1;
		}

		if((loop_count == 0)){		// completed 200 loops then display the max value to 7seg display
			PORTB=~x[max_val];
			loop_count = 200;
			max_val = 0;
			max_count= 0;
		}
	}
	return(0);
}