/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC18F26K83
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_D2 aliases
#define IO_D2_TRIS                 TRISAbits.TRISA4
#define IO_D2_LAT                  LATAbits.LATA4
#define IO_D2_PORT                 PORTAbits.RA4
#define IO_D2_WPU                  WPUAbits.WPUA4
#define IO_D2_OD                   ODCONAbits.ODCA4
#define IO_D2_ANS                  ANSELAbits.ANSELA4
#define IO_D2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_D2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_D2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_D2_GetValue()           PORTAbits.RA4
#define IO_D2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_D2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_D2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_D2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_D2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_D2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_D2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define IO_D2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set IO_D3 aliases
#define IO_D3_TRIS                 TRISAbits.TRISA5
#define IO_D3_LAT                  LATAbits.LATA5
#define IO_D3_PORT                 PORTAbits.RA5
#define IO_D3_WPU                  WPUAbits.WPUA5
#define IO_D3_OD                   ODCONAbits.ODCA5
#define IO_D3_ANS                  ANSELAbits.ANSELA5
#define IO_D3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_D3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_D3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_D3_GetValue()           PORTAbits.RA5
#define IO_D3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_D3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_D3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_D3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_D3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_D3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_D3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define IO_D3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set IO_D4 aliases
#define IO_D4_TRIS                 TRISAbits.TRISA6
#define IO_D4_LAT                  LATAbits.LATA6
#define IO_D4_PORT                 PORTAbits.RA6
#define IO_D4_WPU                  WPUAbits.WPUA6
#define IO_D4_OD                   ODCONAbits.ODCA6
#define IO_D4_ANS                  ANSELAbits.ANSELA6
#define IO_D4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_D4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_D4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_D4_GetValue()           PORTAbits.RA6
#define IO_D4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_D4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_D4_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_D4_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_D4_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_D4_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_D4_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define IO_D4_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set IO_D5 aliases
#define IO_D5_TRIS                 TRISAbits.TRISA7
#define IO_D5_LAT                  LATAbits.LATA7
#define IO_D5_PORT                 PORTAbits.RA7
#define IO_D5_WPU                  WPUAbits.WPUA7
#define IO_D5_OD                   ODCONAbits.ODCA7
#define IO_D5_ANS                  ANSELAbits.ANSELA7
#define IO_D5_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_D5_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_D5_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_D5_GetValue()           PORTAbits.RA7
#define IO_D5_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_D5_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_D5_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_D5_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_D5_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_D5_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_D5_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define IO_D5_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set IO_S1 aliases
#define IO_S1_TRIS                 TRISBbits.TRISB4
#define IO_S1_LAT                  LATBbits.LATB4
#define IO_S1_PORT                 PORTBbits.RB4
#define IO_S1_WPU                  WPUBbits.WPUB4
#define IO_S1_OD                   ODCONBbits.ODCB4
#define IO_S1_ANS                  ANSELBbits.ANSELB4
#define IO_S1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_S1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_S1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_S1_GetValue()           PORTBbits.RB4
#define IO_S1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_S1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_S1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_S1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_S1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_S1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_S1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_S1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set IO_S2 aliases
#define IO_S2_TRIS                 TRISCbits.TRISC5
#define IO_S2_LAT                  LATCbits.LATC5
#define IO_S2_PORT                 PORTCbits.RC5
#define IO_S2_WPU                  WPUCbits.WPUC5
#define IO_S2_OD                   ODCONCbits.ODCC5
#define IO_S2_ANS                  ANSELCbits.ANSELC5
#define IO_S2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_S2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_S2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_S2_GetValue()           PORTCbits.RC5
#define IO_S2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_S2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_S2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_S2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_S2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_S2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_S2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_S2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/