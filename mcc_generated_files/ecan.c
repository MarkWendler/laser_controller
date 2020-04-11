/**
  ECAN Generated Driver  File

  @Company
    Microchip Technology Inc.

  @File Name
    ecan.c

  @Summary
    This is the generated driver implementation for the CAN driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for CAN.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC18F26K83
        Driver Version    :  3.0.0
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "ecan.h"


/**
    Local Functions
*/
static uint32_t convertReg2ExtendedCANid(uint8_t tempRXBn_EIDH, uint8_t tempRXBn_EIDL, uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL);
static uint32_t convertReg2StandardCANid(uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL);
static void convertCANid2Reg(uint32_t tempPassedInID, uint8_t canIdType, uint8_t *passedInEIDH, uint8_t *passedInEIDL, uint8_t *passedInSIDH, uint8_t *passedInSIDL);


void ECAN_Initialize(void)
{
    CANCON = 0x80;
    while (0x80 != (CANSTAT & 0xE0)); // wait until ECAN is in config mode

    /**
    Mode 2
    */
    ECANCON = 0x90;

    /**
    Initialize CAN I/O
    */
    CIOCON = 0x00;
    
    /**
    Mask and Filter definitions
    ........................................................    
    CAN ID		ID Type		Mask				Filter		Buffer    
    ........................................................    
    0x100		SID		Acceptance Mask 0		Filter 0	FIFO
    0x1FF		SID		Acceptance Mask 0		Filter 0	FIFO
    0x101		SID		Acceptance Mask 0		Filter 0	FIFO
    ........................................................
    */
    
    /**
    Configure Generic Buffers to be Transmit or Receive
    */
    BSEL0 = 0x00;
    
    /**    
        Initialize Receive Masks
    */
    RXM0EIDH = 0xFF;
    RXM0EIDL = 0xFF;
    RXM0SIDH = 0xE0;
    RXM0SIDL = 0x03;
    RXM1EIDH = 0xFF;
    RXM1EIDL = 0xFF;
    RXM1SIDH = 0xFF;
    RXM1SIDL = 0xE3;
    
    /**
    Enable Filters
    */
    RXFCON0 = 0x01;
    RXFCON1 = 0x00;
    
    /**
    Assign Filters to Masks
    */
    MSEL0 = 0x00;
    MSEL1 = 0x00;
    MSEL2 = 0x00;
    MSEL3 = 0x00;
    
    /**
    Initialize Receive Filters
    */
    
    RXF0EIDH = 0x00;
    RXF0EIDL = 0x00;
    RXF0SIDH = 0x20;
    RXF0SIDL = 0x00;
    RXF1EIDH = 0x00;
    RXF1EIDL = 0x00;
    RXF1SIDH = 0x00;
    RXF1SIDL = 0x00;
    RXF2EIDH = 0x00;
    RXF2EIDL = 0x00;
    RXF2SIDH = 0x00;
    RXF2SIDL = 0x00;
    RXF3EIDH = 0x00;
    RXF3EIDL = 0x00;
    RXF3SIDH = 0x00;
    RXF3SIDL = 0x00;
    RXF4EIDH = 0x00;
    RXF4EIDL = 0x00;
    RXF4SIDH = 0x00;
    RXF4SIDL = 0x00;
    RXF5EIDH = 0x00;
    RXF5EIDL = 0x00;
    RXF5SIDH = 0x00;
    RXF5SIDL = 0x00;
    
    RXF6EIDH = 0x00;
    RXF6EIDL = 0x00;
    RXF6SIDH = 0x00;
    RXF6SIDL = 0x00;
    RXF7EIDH = 0x00;
    RXF7EIDL = 0x00;
    RXF7SIDH = 0x00;
    RXF7SIDL = 0x00;
    RXF8EIDH = 0x00;
    RXF8EIDL = 0x00;
    RXF8SIDH = 0x00;
    RXF8SIDL = 0x00;
    RXF9EIDH = 0x00;
    RXF9EIDL = 0x00;
    RXF9SIDH = 0x00;
    RXF9SIDL = 0x00;
    RXF10EIDH = 0x00;
    RXF10EIDL = 0x00;
    RXF10SIDH = 0x00;
    RXF10SIDL = 0x00;
    RXF11EIDH = 0x00;
    RXF11EIDL = 0x00;
    RXF11SIDH = 0x00;
    RXF11SIDL = 0x00;
    RXF12EIDH = 0x00;
    RXF12EIDL = 0x00;
    RXF12SIDH = 0x00;
    RXF12SIDL = 0x00;
    RXF13EIDH = 0x00;
    RXF13EIDL = 0x00;
    RXF13SIDH = 0x00;
    RXF13SIDL = 0x00;
    RXF14EIDH = 0x00;
    RXF14EIDL = 0x00;
    RXF14SIDH = 0x00;
    RXF14SIDL = 0x00;
    RXF15EIDH = 0xFF;
    RXF15EIDL = 0xFF;
    RXF15SIDH = 0xFF;
    RXF15SIDL = 0xE3;

    /**
    Initialize CAN Timings
    */
    
   /**
	Baud rate: 500kbps
	System frequency: 64000000
    ECAN clock frequency: 64000000
	Time quanta: 8
	Sample point: 1-1-4-2
	Sample point: 75%
	*/
    
    BRGCON1 = 0x07;
    BRGCON2 = 0x98;
    BRGCON3 = 0x81;

    
    CANCON = 0x00;
    while (0x00 != (CANSTAT & 0xE0)); // wait until ECAN is in Normal mode

}
 /**
  Section: ECAN APIs
*/
void CAN_sleep(void) 
{
    CANCON = 0x20; // request disable mode
    while ((CANSTAT & 0xE0) != 0x20); // wait until ECAN is in disable mode   
    //Wake up from sleep should set the CAN module straight into Normal mode
}

uint8_t CAN_transmit(uCAN_MSG *tempCanMsg) 
{
    uint8_t tempEIDH = 0;
    uint8_t tempEIDL = 0;
    uint8_t tempSIDH = 0;
    uint8_t tempSIDL = 0;
    uint8_t returnValue = 0;

    if (TXB0CONbits.TXREQ != 1) 
    {
        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &tempEIDH, &tempEIDL, &tempSIDH, &tempSIDL);

        TXB0EIDH = tempEIDH;
        TXB0EIDL = tempEIDL;
        TXB0SIDH = tempSIDH;
        TXB0SIDL = tempSIDL;
        TXB0DLC  = tempCanMsg->frame.dlc;
        TXB0D0   = tempCanMsg->frame.data0;
        TXB0D1   = tempCanMsg->frame.data1;
        TXB0D2   = tempCanMsg->frame.data2;
        TXB0D3   = tempCanMsg->frame.data3;
        TXB0D4   = tempCanMsg->frame.data4;
        TXB0D5   = tempCanMsg->frame.data5;
        TXB0D6   = tempCanMsg->frame.data6;
        TXB0D7   = tempCanMsg->frame.data7;

        TXB0CONbits.TXREQ = 1; //Set the buffer to transmit		
        returnValue = 1;
        
    } 
    else if (TXB1CONbits.TXREQ != 1) 
    {

        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &tempEIDH, &tempEIDL, &tempSIDH, &tempSIDL);

        TXB1EIDH = tempEIDH;
        TXB1EIDL = tempEIDL;
        TXB1SIDH = tempSIDH;
        TXB1SIDL = tempSIDL;
        TXB1DLC  = tempCanMsg->frame.dlc;
        TXB1D0   = tempCanMsg->frame.data0;
        TXB1D1   = tempCanMsg->frame.data1;
        TXB1D2   = tempCanMsg->frame.data2;
        TXB1D3   = tempCanMsg->frame.data3;
        TXB1D4   = tempCanMsg->frame.data4;
        TXB1D5   = tempCanMsg->frame.data5;
        TXB1D6   = tempCanMsg->frame.data6;
        TXB1D7   = tempCanMsg->frame.data7;

        TXB1CONbits.TXREQ = 1; //Set the buffer to transmit		
        returnValue = 1;
    } 
    else if (TXB2CONbits.TXREQ != 1) 
    {

        convertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &tempEIDH, &tempEIDL, &tempSIDH, &tempSIDL);

        TXB2EIDH = tempEIDH;
        TXB2EIDL = tempEIDL;
        TXB2SIDH = tempSIDH;
        TXB2SIDL = tempSIDL;
        TXB2DLC  = tempCanMsg->frame.dlc;
        TXB2D0   = tempCanMsg->frame.data0;
        TXB2D1   = tempCanMsg->frame.data1;
        TXB2D2   = tempCanMsg->frame.data2;
        TXB2D3   = tempCanMsg->frame.data3;
        TXB2D4   = tempCanMsg->frame.data4;
        TXB2D5   = tempCanMsg->frame.data5;
        TXB2D6   = tempCanMsg->frame.data6;
        TXB2D7   = tempCanMsg->frame.data7;

        TXB2CONbits.TXREQ = 1; //Set the buffer to transmit		
        returnValue = 1;
    }

    return (returnValue);
}


/**
Version A2 has a silicon errata
This code works for all revisions
*/
//Fix for Errata
#define dRXB0CON_FIFO_POINTER_VALUE 0
#define dRXB1CON_FIFO_POINTER_VALUE 1
#define dB0CON_FIFO_POINTER_VALUE 2
#define dB1CON_FIFO_POINTER_VALUE 3
#define dB2CON_FIFO_POINTER_VALUE 4
#define dB3CON_FIFO_POINTER_VALUE 5
#define dB4CON_FIFO_POINTER_VALUE 6
#define dB5CON_FIFO_POINTER_VALUE 7

uint8_t CAN_receive(uCAN_MSG *tempCanMsg) {
    uint8_t returnValue = 0;
    uint8_t tempECANCON;
    uint8_t tempReg;

    tempReg = (CANCON & 0x0F); //get the next RX buffer to read
    tempECANCON = ECANCON; //Backup
    ECANCON |= (tempReg + 0x10);

    //Per Errata need to use this method to read out BxCON register
    switch (tempReg)
    {
        case dRXB0CON_FIFO_POINTER_VALUE:
            if (RXB0CONbits.RXFUL != 0) // Check RXB0
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                RXB0CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dRXB1CON_FIFO_POINTER_VALUE:
            if (RXB1CONbits.RXFUL != 0) // Check RXB1
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                } else {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                RXB1CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB0CON_FIFO_POINTER_VALUE:
            if (B0CONbits.RXFUL != 0) //Check B0
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                } else {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B0CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB1CON_FIFO_POINTER_VALUE:
            if (B1CONbits.RXFUL != 0) //CheckB1
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B1CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB2CON_FIFO_POINTER_VALUE:
            if (B2CONbits.RXFUL != 0) //CheckB2
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B2CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB3CON_FIFO_POINTER_VALUE:
            if (B3CONbits.RXFUL != 0) //CheckB3
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B3CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB4CON_FIFO_POINTER_VALUE:
            if (B4CONbits.RXFUL != 0) //CheckB4
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B4CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
        case dB5CON_FIFO_POINTER_VALUE:
            if (B5CONbits.RXFUL != 0) //CheckB5
            {
                if ((RXB0SIDL & 0x08) == 0x08) //If Extended Message
                {
                    //message is extended
                    tempCanMsg->frame.idType = (uint8_t) dEXTENDED_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2ExtendedCANid(RXB0EIDH, RXB0EIDL, RXB0SIDH, RXB0SIDL);
                }
                else
                {
                    //message is standard
                    tempCanMsg->frame.idType = (uint8_t) dSTANDARD_CAN_MSG_ID_2_0B;
                    tempCanMsg->frame.id = convertReg2StandardCANid(RXB0SIDH, RXB0SIDL);
                }

                tempCanMsg->frame.dlc   = RXB0DLC;
                tempCanMsg->frame.data0 = RXB0D0;
                tempCanMsg->frame.data1 = RXB0D1;
                tempCanMsg->frame.data2 = RXB0D2;
                tempCanMsg->frame.data3 = RXB0D3;
                tempCanMsg->frame.data4 = RXB0D4;
                tempCanMsg->frame.data5 = RXB0D5;
                tempCanMsg->frame.data6 = RXB0D6;
                tempCanMsg->frame.data7 = RXB0D7;
                B5CONbits.RXFUL = 0;
                returnValue = 1;
            }
            break;
    }
		
    ECANCON = tempECANCON;
    return (returnValue);
}

uint8_t CAN_messagesInBuffer(void) {
    uint8_t messageCount = 0;
    if (RXB0CONbits.RXFUL != 0) //CheckRXB0
    {
        messageCount++;
    }
    if (RXB1CONbits.RXFUL != 0) //CheckRXB1
    {
        messageCount++;
    }
    if (B0CONbits.RXFUL_TXBIF != 0) //CheckB0
    {
        messageCount++;
    }
    if (B1CONbits.RXFUL_TXBIF != 0) //CheckB1
    {
        messageCount++;
    }
    if (B2CONbits.RXFUL_TXBIF != 0) //CheckB2
    {
        messageCount++;
    }
    if (B3CONbits.RXFUL_TXBIF != 0) //CheckB3
    {
        messageCount++;
    }
    if (B4CONbits.RXFUL_TXBIF != 0) //CheckB4
    {
        messageCount++;
    }
    if (B5CONbits.RXFUL_TXBIF != 0) //CheckB5
    {
        messageCount++;
    }
    return (messageCount);
}

uint8_t CAN_isBusOff(void)
{
    uint8_t returnValue = 0;

    //COMSTAT bit 5 TXBO: Transmitter Bus-Off bit
    //1 = Transmit error counter > 255
    //0 = Transmit error counter less then or equal to 255

    if (COMSTATbits.TXBO == 1) {
        returnValue = 1;
    }
    return (returnValue);
}

uint8_t CAN_isRXErrorPassive(void)
{
    uint8_t returnValue = 0;

    //COMSTAT bit 3 RXBP: Receiver Bus Passive bit
    //1 = Receive error counter > 127
    //0 = Receive error counter less then or equal to 127

    if (COMSTATbits.RXBP == 1) {
        returnValue = 1;
    }
    return (returnValue);
}

uint8_t CAN_isTXErrorPassive(void)
{
    uint8_t returnValue = 0;

    //COMSTAT bit 4 TXBP: Transmitter Bus Passive bit
    //1 = Transmit error counter > 127
    //0 = Transmit error counter less then or equal to 127

    if (COMSTATbits.TXBP == 1)
    {
        returnValue = 1;
    }
    return (returnValue);
}

/**
Internal functions
*/

static uint32_t convertReg2ExtendedCANid(uint8_t tempRXBn_EIDH, uint8_t tempRXBn_EIDL, uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL) {
    uint32_t returnValue = 0;
    uint32_t ConvertedID = 0;
    uint8_t CAN_standardLo_ID_lo2bits;
    uint8_t CAN_standardLo_ID_hi3bits;

    CAN_standardLo_ID_lo2bits = (uint8_t)(tempRXBn_SIDL & 0x03);
    CAN_standardLo_ID_hi3bits = (uint8_t)(tempRXBn_SIDL >> 5);
    ConvertedID = (uint32_t)(tempRXBn_SIDH << 3);
    ConvertedID = ConvertedID + CAN_standardLo_ID_hi3bits;
    ConvertedID = (ConvertedID << 2);
    ConvertedID = ConvertedID + CAN_standardLo_ID_lo2bits;
    ConvertedID = (ConvertedID << 8);
    ConvertedID = ConvertedID + tempRXBn_EIDH;
    ConvertedID = (ConvertedID << 8);
    ConvertedID = ConvertedID + tempRXBn_EIDL;
    returnValue = ConvertedID;
    return (returnValue);
}

static uint32_t convertReg2StandardCANid(uint8_t tempRXBn_SIDH, uint8_t tempRXBn_SIDL) {
    uint32_t returnValue = 0;
    uint32_t ConvertedID;
    //if standard message (11 bits)
    //EIDH = 0 + EIDL = 0 + SIDH + upper three bits SIDL (3rd bit needs to be clear)
    //1111 1111 111
    ConvertedID = (uint32_t)(tempRXBn_SIDH << 3);
    ConvertedID = ConvertedID + (uint32_t)(tempRXBn_SIDL >> 5);
    returnValue = ConvertedID;
    return (returnValue);
}

static void convertCANid2Reg(uint32_t tempPassedInID, uint8_t canIdType, uint8_t *passedInEIDH, uint8_t *passedInEIDL, uint8_t *passedInSIDH, uint8_t *passedInSIDL) {
    uint8_t wipSIDL = 0;

    if (canIdType == dEXTENDED_CAN_MSG_ID_2_0B)
    {
        //EIDL
        *passedInEIDL = 0xFF & tempPassedInID; //CAN_extendedLo_ID_TX1 = &HFF And CAN_UserEnter_ID_TX1
        tempPassedInID = tempPassedInID >> 8; //CAN_UserEnter_ID_TX1 = CAN_UserEnter_ID_TX1 >> 8

        //EIDH
        *passedInEIDH = 0xFF & tempPassedInID; //CAN_extendedHi_ID_TX1 = &HFF And CAN_UserEnter_ID_TX1
        tempPassedInID = tempPassedInID >> 8; //CAN_UserEnter_ID_TX1 = CAN_UserEnter_ID_TX1 >> 8

        //SIDL
        //push back 5 and or it
        wipSIDL = 0x03 & tempPassedInID;
        tempPassedInID = tempPassedInID << 3; //CAN_UserEnter_ID_TX1 = CAN_UserEnter_ID_TX1 << 3
        wipSIDL = (0xE0 & tempPassedInID) + wipSIDL;
        wipSIDL = (uint8_t)(wipSIDL + 0x08); // TEMP_CAN_standardLo_ID_TX1 = TEMP_CAN_standardLo_ID_TX1 + &H8
        *passedInSIDL = (uint8_t)(0xEB & wipSIDL); //CAN_standardLo_ID_TX1 = &HEB And TEMP_CAN_standardLo_ID_TX1

        //SIDH
        tempPassedInID = tempPassedInID >> 8;
        *passedInSIDH = 0xFF & tempPassedInID;
    }
    else //(canIdType == dSTANDARD_CAN_MSG_ID_2_0B)
    {
        *passedInEIDH = 0;
        *passedInEIDL = 0;
        tempPassedInID = tempPassedInID << 5;
        *passedInSIDL = 0xFF & tempPassedInID;
        tempPassedInID = tempPassedInID >> 8;
        *passedInSIDH = 0xFF & tempPassedInID;
    }
}


