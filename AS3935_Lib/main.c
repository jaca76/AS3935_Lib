/*
 * main.c
 *
 *  Created on: 7 lip 2016
 *      Author: Jacek
 */


#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "AS3935/AS3935.h"
#include <avr/pgmspace.h>
#include "UART/uart.h"
uint8_t Distance;
uint8_t Thunder_dane;
uint8_t interrupt=0;
uint8_t min_distance=99;


int main(void)
{
    SPI_Init();
    Thunder_Init();
   // Perip_Init();
    USART_Init(__UBRR);
    sei();
    uart_puts("******* Start ***********\r\n");
    tuneAntena();
   // check_timer();
    uart_puts("******* koniec ***********\r\n");
	while (1)
	{
		Thunder_dane=lightningDistanceKm();
		if (Thunder_dane < min_distance) {
			min_distance=Thunder_dane;
			Thunder_dane=interruptSource();
			if (Thunder_dane ==0) {
				uart_puts("No interrupt\r\n");
									};
			if (Thunder_dane ==1) {
				uart_puts("Noise\r\n");
									};
			if (Thunder_dane ==4) {
				uart_puts("Distru\r\n");;
									};
			if (Thunder_dane ==4) {
				uart_puts("Light\r\n");
									};
			}
	}
}
