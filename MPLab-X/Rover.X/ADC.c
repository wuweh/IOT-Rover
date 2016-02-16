#include <xc.h>
static unsigned int DistanceLeft;
static unsigned int DistanceRight;
static unsigned int DistanceCentral;
static unsigned int Battery;


void ADCInit(void) {

    /* Configure the ADC - input to ADC is AN0 (PORTA.0)*/
    TRISA0 = 1; // configure PORTA.0 as an input
    TRISA1 = 1; // configure PORTA.1 as an input
    TRISA2 = 1; // configure PORTA.2 as an input
    TRISA3 = 1; // configure PORTA.3 as an input

    ANS0 = 1; // disable PORTA.0's digital input
    ANS1 = 1; // disable PORTA.1's digital input
    ANS2 = 1; // disable PORTA.2's digital input
    ANS3 = 1; // disable PORTA.3's digital input

    ADON = 1; // enable ADC
    ADCON1 = 0; // reference voltages are internal
    ADCON2 = 0x91; // right justified, 4 TAD, FOSC/8
    ADIF = 0; // clear the ADC conversion complete interrupt flag
    ADIE = 1; // enable ADC interrupt

    PEIE = 1; // set the global peripheral interrupt enable bit
    GIE = 1; // set the global interrupt enable bit

}

void ADCInitiateConversion(void) {
    GO = 1;
}

unsigned int ADCGetOutput(void) {
    int temp;
    temp = ADRESL;
    return temp + (ADRESH << 8);
}

unsigned char ADCGetOutputLowByte() {
    return ADRESL;
}

unsigned char ADCGetOutputHighByte() {
    return ADRESH;
}



void SetDistanceLeft (unsigned int lecture){
    DistanceLeft=5+(1023-lecture)*0.035;//Not exact, but it gives us an idea.
}

unsigned int ReadDistanceLeft (){
    return DistanceLeft;
}

void SetDistanceRight (unsigned int lecture){
    DistanceRight=5+(1023-lecture)*0.035;//Not exact, but it gives us an idea.
}

unsigned int ReadDistanceRight (){
    return DistanceRight;
}

void SetDistanceCentral (unsigned int lecture){
    DistanceCentral=5+(1023-lecture)*0.035;//Not exact, but it gives us an idea.
}

unsigned int ReadDistanceCentral (){
    return DistanceCentral;
}

void SetBattery (unsigned int lecture){
    Battery=lecture*3.548;//Hight accuracy.
}

unsigned int ReadBattery (){
    return Battery;
}
