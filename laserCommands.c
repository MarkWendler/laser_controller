/*
 * File:   laserCommands.c
 * Author: M18034
 *
 * Created on April 12, 2020, 1:14 PM
 */


#include <xc.h>
#include <stdio.h>
#include "laserCommands.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/uart2.h"

// Send 16 byte command to laser module
void sendLaserCommand(const uint8_t *command){
    printf("Command send:");
    for(uint8_t i = 0; i<=15; i++){
        UART1_Write(*command);
        command++;
    }
    //Debug
    for(uint8_t i = 0; i<=15; i++){
        printf("%X ",*command);
        command++;
    }            
    printf("\n");
}