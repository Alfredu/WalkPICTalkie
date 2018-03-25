/*
 * File:   main.c
 * Author: alfredu
 *
 * Created on March 24, 2018, 5:52 PM
 */


#include <xc.h>
#include "config.h"

volatile unsigned char result;

void interrupt interrupt_routine(void){
    if(PIE1bits.ADIE && !ADCON0bits.DONE){
        result = (ADRES>>2) & 0xFF;
    }
}

void setup(void){
    init_pins();
    init_oscillator();
    init_adc(); 
    init_interrupts();
    init_timer();
}


void main(void) {
    setup();
    while(1);
    
    return;
}
