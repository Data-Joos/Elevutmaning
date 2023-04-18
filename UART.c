#include "uart.h" //Fetch and include my header file.

void USART2_Init(void){ //Init function from uart.h
 RCC->APB1ENR  |=  0x20000; 
 RCC->AHB1ENR   |=0x01;
 
GPIOA->MODER &=~0x00F0;
GPIOA->MODER |= 0x00A0; 

GPIOA->AFR[0] &= ~0xFF00;
GPIOA->AFR[0] |= 0x7700;


USART2->BRR  =  0x0683;
USART2->CR1  =  0x000C; 
USART2->CR2  =  0x000;
USART2->CR3  =  0x000;
USART2->CR1  |=  0x2000; 
	
	

}

int USART2_write(int ch){

	while(!(USART2->SR & 0x0080)){}
	USART2->DR = (ch & 0xFF);
	
  return ch;
}

int USART2_read(void){
  while(!(USART2->SR & 0x0020)){}
	return USART2->DR;
}

struct __FILE { int handle; }; 
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};


int fgetc(FILE *f) {
    int c;

    c = USART2_read();     

    if (c == '\r') {        
        USART2_write(c);    
        c = '\n';
    }

    USART2_write(c);       

    return c; //Return c
}

int fputc(int c, FILE *f) {
    return USART2_write(c);
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
