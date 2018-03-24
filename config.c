/*
 * File:   config.c
 * Author: alfredu
 *
 * Created on March 24, 2018, 6:00 PM
 */


#include <xc.h>
#include "config.h"

void init_pins(void){
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSA0 = 0;
}

void init_oscillator(void){
    OSCCONbits.IRCF = 0xF; //Clock running at 16MHz
    OSCCONbits.SCS  = 0x0; //Using Config Bits
}

void init_adc(void){
    ADCON0bits.ADRMD    = 0b1;      //10 bit format7
    ADCON0bits.CHS      = 0b00000;  //AN0 channel RA0 Pin
    ADCON0bits.ADON     = 0b1;      //Enable ADC
    
    ADCON1bits.ADFM     = 0b1;      //2's Complement
    ADCON1bits.ADCS     = 0b101;    //FOSC/16 ADC Frequency
    ADCON1bits.ADNREF   = 0b0;      //VREF- = VSS
    ADCON1bits.ADPREF   = 0b00;     //VREF+ = VDD
    
    ADCON2bits.TRIGSEL  = 0b0001;   //CCP1 Auto-conversion
    ADCON2bits.CHSN     = 0b1111;   //Negative Differential Input Channel
}

void init_timer(void){
    T1CONbits.TMR1CS    = 0b00;
    T1CONbits.T1CKPS    = 0b00;
    T1CONbits.T1OSCEN   = 0b0;
    T1CONbits.nT1SYNC   = 0b1;
    T1CONbits.TMR1ON    = 0b1;
    
}
