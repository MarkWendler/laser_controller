/*
 * File:   laserCommands.c
 * Author: M18034
 *
 * Created on April 12, 2020, 1:14 PM
 */


#include <xc.h>
#include <stdio.h>
#include "laserCommands.h"
#include "laserDescriptor.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/uart2.h"


void communicationTask(laserModule module);

// Send 16 byte command to laser module
void sendLaserCommand(const uint8_t *command, void (*dataSend)(uint8_t)){
    printf("Command send:");
    for(uint8_t i = 0; i<=15; i++){
        dataSend(*command);
        command++;
    }
    //Debug
    for(uint8_t i = 0; i<=15; i++){
        printf("%X ",*command);
        command++;
    }            
    printf("\n");
}

void taskModule(laserModule module){
    
    communicationTask(module);
    
    
}

void communicationTask(laserModule module){
    
    switch (module.comm.state){
        case COMM_UNINITIALISED:  //laser module unitialised
            
            break;
        case SEND_INIT: //laser module communication OK and waiting to start measure
            
            
            break;
        case WAIT_INIT_ANSWER:    // Laser module
            
            break;
        case SEND_START_MEASURE:  //Module is calibrating
    
            break;
            
        case WAIT_START_FEEDBACK:
                    
            break;
        case WAIT_MEASURE_DATA:
            
            break;
            
        case READ_DISTANCE:
            
            break;
        case IDLE: //No communication ongoing
            
            break;
        default: 
            module.comm.state = COMM_UNINITIALISED;
    }
    
    
}

