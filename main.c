/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC18F26K83
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "laserCommands.h"
#include "laserDescriptor.h"
#include <stdio.h>

/*
                         Main application
 */

// 1ms interrupt
void tmr0Handler(void);
uint8_t feedback = 0;
char buffer[1024];
uint16_t bufferCount = 0;

extern LaserModule module_1, module_2, module_3, module_4, module_5; //laserInstances

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:
    
    __delay_ms(500); //wait for debugger USB connection
    
    printf("\n\nMain controller starting...\n");
    
    TMR0_SetInterruptHandler(tmr0Handler);
    

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    printf("Start laser controller...\n");

    while (1)
    {
        taskModule(&module_1); //handle module 1
        if(!IO_S1_GetValue()){
            IO_D3_SetHigh();
        }
        else IO_D3_SetLow();
        
    }
}

void tmr0Handler(void){
    static int counter;
    static bool S2_Value,S2_Value_latch; 
    static uint8_t DebounceCnt;
    if(500 <= counter++){ // create 2Hz blinking hearth beat
        counter = 0;
        IO_D2_Toggle();
    }
    
    S2_Value = !IO_S2_GetValue(); //Invert the logic -? pressed-> low
    if (S2_Value) //If button already triggered
    {
        if (!S2_Value_latch)// not processed the press yet
        {
        DebounceCnt++;
        
        if (DebounceCnt >= 100 ) { //10ms
            if (module_1.state == INITIALISED_OFF) { //If laser off
                activateLaser(&module_1); //then start
                IO_D4_SetHigh();
            }
            else if(module_1.state == MEASURE) //Start motor
            {
                deactivateLaser(&module_1);
                IO_D4_SetLow();
            }
            S2_Value_latch = true; //Save the state
            DebounceCnt = 0;
            
        }
        }
    } 
    else { // if button released
        if(S2_Value_latch){
            DebounceCnt++;
            if (DebounceCnt >= 100 ){
                DebounceCnt = 0;
                S2_Value_latch = false;
            }
        }
    }
    
    
}

/**
 End of File
*/