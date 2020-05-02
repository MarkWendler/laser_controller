/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef enum {
    UNINITIALISED = 0, //laser module unitialised
    INITIALISED_OFF, //laser module communication OK and waiting to start measure
    MEASURE,    // Laser module
    CALIBRATE,  //Module is calibrating
    ALARM
            
} moduleState;

typedef struct laserModuleTag{
    moduleState state;
    uint16_t distance;
    void (*dataSend)(uint8_t); //UART send function
    uint8_t (*dataSend)(void); //UART receive function
    
    
} laserModule;

laserModule laserTask(laserModule);

#endif	/* XC_HEADER_TEMPLATE_H */

