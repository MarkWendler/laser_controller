#include "mcc_generated_files/uart1.h"
#include "laserDescriptor.h"
//************************************//
// Laser object instances //
volatile laserModule module_1 = { 
    .ID = 1,
    .state = UNINITIALISED,
    .distance = 0,
    
    .comm = {
        .state = COMM_UNINITIALISED,
        .receiveCount = 0,
        .dataSend = UART1_Write, //hook the corresponding communication function
        .dataReceive = UART1_Read
    }
};
// Laser module 2
volatile laserModule module_2 = { 
    .ID = 1,
    .state = UNINITIALISED,
    .distance = 0,
    
    .comm = {
        .state = COMM_UNINITIALISED,
        .receiveCount = 0,
        .dataSend = UART1_Write, //hook the corresponding communication function
        .dataReceive = UART1_Read
    }
};
// Laser module 3
volatile laserModule module_3 = { 
    .ID = 1,
    .state = UNINITIALISED,
    .distance = 0,
    
    .comm = {
        .state = COMM_UNINITIALISED,
        .receiveCount = 0,
        .dataSend = UART1_Write, //hook the corresponding communication function
        .dataReceive = UART1_Read
    }
};
// Laser module 4
volatile laserModule module_4 = { 
    .ID = 1,
    .state = UNINITIALISED,
    .distance = 0,
    
    .comm = {
        .state = COMM_UNINITIALISED,
        .receiveCount = 0,
        .dataSend = UART1_Write, //hook the corresponding communication function
        .dataReceive = UART1_Read
    }
};
// Laser module 5
volatile laserModule module_5 = { 
    .ID = 1,
    .state = UNINITIALISED,
    .distance = 0,
    
    .comm = {
        .state = COMM_UNINITIALISED,
        .receiveCount = 0,
        .dataSend = UART1_Write, //hook the corresponding communication function
        .dataReceive = UART1_Read
    }
};
