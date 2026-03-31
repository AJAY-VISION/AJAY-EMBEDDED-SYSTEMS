      
#include <stdio.h>

typedef enum{
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
    STATE_FAULT
} TrafficState;

// main function
int main(){

   TrafficState state = STATE_RED;

   int cycles = 0;   // count full cycles
   int counter = 0;  // total timer steps
   int fault_threshold = 15;

   while(cycles < 3){

       switch (state) {

           case STATE_RED:
               printf("STATE: RED\n");
               for (int i = 0; i < 5; i++){
                   printf("RED TIMER: %d\n", i);
                   counter++;
               }
               state = STATE_YELLOW;
               break;

           case STATE_YELLOW:
               printf("STATE: YELLOW\n");
               for (int i = 0; i < 5; i++){
                   printf("YELLOW TIMER: %d\n", i);
                   counter++;
               }
               state = STATE_GREEN;
               break;

           case STATE_GREEN:
               printf("STATE: GREEN\n");
               for (int i = 0; i < 5; i++){
                   printf("GREEN TIMER: %d\n", i);
                   counter++;
               }
               state = STATE_RED;
               cycles++;
               break;

           case STATE_FAULT:
               printf("STATE: FAULT\n");
               return 0;
       }

       // Fault detection
       if (counter > fault_threshold) {
           state = STATE_FAULT;
       }
   }

   printf("Completed 3 cycles successfully.\n");
   return 0;
}
