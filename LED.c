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
