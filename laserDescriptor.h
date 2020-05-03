/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LASERDESCRIPTOR_H
#define	LASERDESCRIPTOR_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef enum {
    UNINITIALISED = 0, //laser module unitialised
    INITIALISED_OFF, //laser module communication OK and waiting to start measure
    MEASURE,    // Laser module
    CALIBRATE,  //Module is calibrating
    ALARM
            
} moduleState;

typedef enum {
    COMM_UNINITIALISED = 0, //laser module unitialised
    SEND_INIT, //laser module communication OK and waiting to start measure
    WAIT_INIT_ANSWER,    // Laser module
    SEND_START_MEASURE,  //Module is calibrating
    WAIT_START_FEEDBACK,
    WAIT_MEASURE_DATA,
    READ_DISTANCE,
    IDLE                 //No communication ongoing
            
} communicationState;

typedef struct {
    uint8_t ID;
    moduleState state;
    uint16_t distance;

    struct {
        communicationState state;
        uint8_t receiveCount;
        void (*dataSend)(uint8_t); //UART send function
        uint8_t(*dataReceive)(void); //UART receive function        
    } comm;

} laserModule;

laserModule laserTask(laserModule);

#endif	/* LASERDESCRIPTOR_H */

