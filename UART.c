#include "uart.h" //Fetch and include my header file.

void USART2_Init(void){ //Declare a function and init from uart.h
 RCC->APB1ENR  |=  0x20000; //Enable the clock for USART2 by setting bit 17 of RCC->APB1ENR to 1
 RCC->AHB1ENR   |=0x01; //Enable clock access PortA
 
GPIOA->MODER &=~0x00F0; //Rensar bitarna 4-7 för att föbereda pins PA2 och PA3
GPIOA->MODER |= 0x00A0; //Enable pins to port, alternative function. Declare bits 5-7 to 1, to activate alternative function on PA2 & PA3

GPIOA->AFR[0] &= ~0xFF00; // Rensar bitarna 8-15 för att förbereda pins PA2 and PA3
GPIOA->AFR[0] |= 0x7700; //Choose type of alternative for pins. Sätter bitarna 8-11 samt 12-15 format 0111

//Configuaration of UART
USART2->BRR  =  0x0683; //Sätter vi standard baud-rate med hjälp av hexadecimalen 
USART2->CR1  =  0x000C; //Sätter vi tx och rx till att arbeta i 8-bitars data.(8-bitars data, 1stop bt,ingen paritet
USART2->CR2  =  0x000; //Leave USART2->CR2 at its default value.
USART2->CR3  =  0x000; //Leave USART2->CR3 at its default value.
USART2->CR1  |=  0x2000; //Omställer bit 13 (UART-aktiveringen) till 1
	
	

}

int USART2_write(int ch){ //

	while(!(USART2->SR & 0x0080)){} //
	USART2->DR = (ch & 0xFF); //
	
  return ch; //Return character that was written
}

int USART2_read(void){ //Create void with new variable 
  while(!(USART2->SR & 0x0020)){} //While function 
	return USART2->DR; //Return UART2 to Data register
}

struct __FILE { int handle; }; //
FILE __stdin  = {0}; //
FILE __stdout = {1}; //
FILE __stderr = {2}; //


int fgetc(FILE *f) { //
    int c; //Create variable

    c = USART2_read(); //     

    if (c == '\r') {        //
        USART2_write(c);    //
        c = '\n'; //
    }

    USART2_write(c); //      

    return c; //Return c
}

int fputc(int c, FILE *f) { //
    return USART2_write(c); //
}


int n; //Declare variable
char str[80]; //Declare char array
		
void test_setup(void){ //Init function from uart.h
	
	printf("please enter a number: "); //print function, ask user to enter a number.
	scanf("%d", &n); //Scan function and retrieve number.
	printf("the number entered is: %d\r\n", n); //Print function, show input from user(number)
	printf("please type a character string: "); //Print function, ask user for a string.
	gets(str); //Gets function(string)
	printf("the character string entered is: "); //Print function, shows input from user(string)
	puts(str); //Print the string from user.
	printf("\r\n"); //Prints new line
	
}
