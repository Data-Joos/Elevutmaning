#include "uart.h" //Fetch and include our header file, with functions and library.
#include "led.h" 

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

int main(void){ //Create main function
  
	USART2_Init(); //Init function
	Led led2(BLUE,ON);
	
	Led *led3 = new Led(YELLOW,ON);
	
	led1_state = led1.getState();
	
	led1.setState(OFF);
	
	delete led3;

	while(1){ //While-function
	
	}

}
