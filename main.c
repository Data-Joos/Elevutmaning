#include "uart.h" //Fetch and include our header file, with functions and library.
#include "led.h" 

Led_Type led1;
Led_Type led2;

int main(){ //Create main function
  
	USART2_Init(); //Init function
	Led_ctor(&led1,RED,OFF);
	Led_ctor(&led2,BLUE,ON);
	
	Led_getState(&led1);
	Led_setState(&led2,OFF);
	
	//test_setup();
	printf("Hello there from main function"); //Print
	while(1){ //While-function
	
	}

}
