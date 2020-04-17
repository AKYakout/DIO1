/*
 * File:   DIO.c
 * Author: AKYakout
 *
 * Created on April 15, 2020, 9:57 PM
 */


#include <xc.h>

#include "config.h"

int isPressed(int port, int PIN_number) {
    switch (port) {
        case 1:
            if (PINA & (1 << PIN_number)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 2:
            if (PINB & (1 << PIN_number)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 3:
            if (PINC & (1 << PIN_number)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 4:
            if (PIND & (1 << PIN_number)) {
                return 1;
            } else {
                return 0;
            }
            break;
       
    }
    return -1;
}

void reSetPortX(int port, int pin) {
    switch (port) {
        case 1:
            PORTA &= ~(1 << pin);
            break;
        case 2:
            PORTB &= ~(1 << pin);
            break;
        case 3:
            PORTC &= ~(1 << pin);
            break;
        case 4:
            PORTD &= ~(1 << pin);
            break;
    }
}

void setPortX(int port, int pin) {
    switch (port) {
        case 1:
            PORTA |= (1 << pin);
            break;
        case 2:
            PORTB |= (1 << pin);
            break;
        case 3:
            PORTC |= (1 << pin);
            break;
        case 4:
            PORTD |= (1 << pin);
            break;
    }
}


void portAs(int port, int pin, int dir) {
    switch (dir) {
        case 1:
            switch (port) {
                case 1:
                    DDRA |= (1 << pin);
                    break;
                case 2:
                    DDRB |= (1 << pin);
                    break;
                case 3:
                    DDRC |= (1 << pin);
                    break;
                case 4:
                    DDRD |= (1 << pin);
                    break;
    }
            break;
        case 0:
            switch (port) {
                case 1:
                    DDRA &= ~(1 << pin);
                    break;
                case 2:
                    DDRB &= ~(1 << pin);
                    break;
                case 3:
                    DDRC &= ~(1 << pin);
                    break;
                case 4:
                    DDRD &= ~(1 << pin);
                    break;
        }
            break;
        default :
# warning "warning";
            break;
    }
    
}