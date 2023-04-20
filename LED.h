#ifndef LED_H
#define LED_H //Definerar att headern betecknas med LED.h och skall inkluderas vid benämning

#include <stdint.h> //Inkluderar ett av c:s standardbibliotek
#include "UART.h" //Inkluderar vårt UART-drivrutin

typedef enum { //Bygger en funktion som numrerar de olika färgerna som kan antas av LED
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

typedef enum {//Bygger en funktion som numrerar de olika statusarna som
  OFF = 0,
  ON = 1,
}LedState_Type;

typedef struct{
  LedColor_Type color;
  LedState_Type state;
}Led_Type;

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me, LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

#endif


ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include "stm32f4xx.h"  // Device header

//Definerar vilken GPIO som skall vara ansvarig för LED-funktionen
#define	LED_PORT GPIOB
//Definerar klocksignalen för porten
#define	LED_PORT_CLOCK (1U<<1)
//Definerar de olika pinsen för de olika LED-färgerna
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define	LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Definerar mode bits för varje LED-färg
#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)


//Definerar de olika LED-färgerna som finns
typedef  enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE

}LedColor_Type;

//Definerar ju/numrerar de olika lägena som LED kan befinna sig i
typedef enum{
 OFF =0,
 ON = 1
}LedState_Type;


/*Led's attributes*/
//Definerar de attribut som LED består utav
typedef struct{
	
 LedColor_Type color; 
 LedState_Type state;  
	
}Led_Type;

//Definerar funktionsprototyperna för led-konstruktorn samt statuskontrollen
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);
#endif
