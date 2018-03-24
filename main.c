/*
 * File:   main.c
 * Author: alfredu
 *
 * Created on March 24, 2018, 5:52 PM
 */


#include <xc.h>
#include "config.h"

volatile int x = 0;

void setup(void){
    init_pins();
    init_oscillator();
    init_adc();
    init_timer();
}


void main(void) {
    setup();
    while(1){
        ADCON0bits.GO = 1;
        while(!ADCON0bits.DONE);
        char res = (char) (ADRES>>2)&0x00FF;
    }
    
    return;
}
