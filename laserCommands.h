/**
 * File:  laserCommands 
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>


const struct {
    uint8_t open[16];  
    uint8_t startMeasure[16]; 
} commandsSend = {
    {0xFA, 0xFA, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC6, 0x7E, 0xBD, 0xBA },
    {0xFA, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x01, 0xE8, 0xD8 }
};

void sendLaserCommand(const uint8_t*);

#endif	/* XC_HEADER_TEMPLATE_H */

