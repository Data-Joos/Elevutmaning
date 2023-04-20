#include "LED.h"

//Konstruktior: En funktion som etablerar parametrar för LED-applikation
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
  me->color =_color;
  me->state = _state;
}

//En funktion som sätter och kontrollerar status på LED
void Led_setState(Led_type * const me, LedState_Type _state){
  me->state = _state;
  
  switch(me->color){
    case RED:
      printf("Den röda LED-lampan är satt till %d \n\r",me->state);
      }
}


//En funktion som utger status på LED

//Konstruktorn för LED-lamportna
include "led.h"


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
  
	me->color  = _color;
	me->state  = _state; 

	 	
	 /*Hardware Init*///Enablea klockan för LED-porten(GPIOB)
	RCC->AHB1ENR |= LED_PORT_CLOCK;  
	//Konfigurera LED-pinsen baserad på deras färg och status
	switch(_color){
		 
		case RED: //Sätta portläget för LED_konfigurationen till output
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(me->state  == ON){
			  //Stänga på LED
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
		        //Stänga av LED
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


void Led_setState(Led_Type * const me,LedState_Type _state){
//Sätta statusen av LED:n
	 me->state =  _state;

	 
	//Kolla färgen på LED för att veta att korrekt LED manipuleras
	switch(me->color){
		 //Om LED Röd
		case RED:
			//Sätta pin till outputläge
			LED_PORT->MODER |=LED_RED_MODE_BIT;
			//Om önskad status är ON
		  if(me->state  == ON){
			  //Definerar pin output till Aktiv
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
				//Definerar pin output till iaktiv
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}

//Kontrollera färgen av den LED som efterfrågas,printa sedan statusen
LedState_Type Led_getState(Led_Type * const me){

	switch(me->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state);
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state;
}
