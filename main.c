/*
 * File:   main.c
 * Author: AKYakout
 *
 * Created on April 15, 2020, 6:15 PM
 */


#include <avr/io.h>
#include "DIO.h"
#include "config.h"



int main(void) {
    portAs(ddrB, BUTTON0, IN);
    portAs(ddrB, BUTTON1, IN);
    portAs(ddrD, BUTTON2, IN);
    
    portAs(ddrC, LED0, OUT);
    portAs(ddrD, LED1, OUT);
    portAs(ddrD, LED2, OUT);
    
    while (1) {
       
        if(isPressed(portB, BUTTON0))
        {
            setPortX(portC, LED0);            
        } else
        {
            reSetPortX(portC, LED0);
        }
        
        if(isPressed(portB, BUTTON1))
        {
            setPortX(portC, LED1);            
        } else
        {
            reSetPortX(portC, LED1);
        }
        
        if(isPressed(portD, BUTTON2))
        {
            setPortX(portD, LED2);            
        } else
        {
            reSetPortX(portD, LED2);
        }
    }
}

