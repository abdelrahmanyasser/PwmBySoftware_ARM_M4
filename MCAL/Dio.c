/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Implementation of Digital Input output (DIO) driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Mcu_Hw.h"


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static volatile uint32* Dio_GetBaseAddress(Dio_ChannelType ChannelId);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : volatile uint32* Dio_GetBaseAddress(Dio_ChannelType ChannelId)
* \Description     : Private Function that gets the GPIOx base address                           
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName                         
* \Parameters (out): None                                                      
* \Return value:   : volatile uint32*  
*                                                                      
*******************************************************************************/
static volatile uint32* Dio_GetBaseAddress(Dio_ChannelType ChannelId)
{
    if (ChannelId >= PA0 && ChannelId <= PA7)
    {
        return (volatile uint32*)GPIOA_BASE_ADDRESS;
    }
    else if (ChannelId >= PB0 && ChannelId <= PB7)
    {
        return (volatile uint32*)GPIOB_BASE_ADDRESS;
    }
    else if (ChannelId >= PC0 && ChannelId <= PC7)
    {
        return (volatile uint32*)GPIOC_BASE_ADDRESS;
    }
    else if (ChannelId >= PD0 && ChannelId <= PD7)
    {
        return (volatile uint32*)GPIOD_BASE_ADDRESS;
    }
    else if (ChannelId >= PE0 && ChannelId <= PE5)
    {
        return (volatile uint32*)GPIOE_BASE_ADDRESS;
    }
    else if (ChannelId >= PF0 && ChannelId <= PF4)
    {
        return (volatile uint32*)GPIOF_BASE_ADDRESS;
    }
    else
    {
        return NULL;
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId) 
* \Description     : Function that reads from a pin                           
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName                         
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType  
*                                                                      
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    volatile uint32* regPtr = Dio_GetBaseAddress(ChannelId);
    if (ChannelId >= PA0 && ChannelId <= PA7)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PA0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
    else if (ChannelId >= PB0 && ChannelId <= PB7)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PB0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
    else if (ChannelId >= PC0 && ChannelId <= PC7)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PC0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
    else if (ChannelId >= PD0 && ChannelId <= PD7)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PC0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
    else if (ChannelId >= PE0 && ChannelId <= PE5)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PC0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
    else if (ChannelId >= PF0 && ChannelId <= PF4)
    {
        if (BIT_IS_SET((*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId - PC0)))
        {
            return PIN_HIGH;
        }
        else
        {
            return PIN_LOW;
        }
    }
		/* ERR */
		return PIN_LOW;
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)   
* \Description     : Function that writes to a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                          
* \Parameters (out): None                                                      
* \Return value:   : None                                                      
*******************************************************************************/
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{

    volatile uint32* regPtr = Dio_GetBaseAddress(ChannelId);
    
    if (ChannelId >= PA0 && ChannelId <= PA7)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PA0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PA0));
        }
    }
    else if (ChannelId >= PB0 && ChannelId <= PB7)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PB0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PB0));
        }    }
    else if (ChannelId >= PC0 && ChannelId <= PC7)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PC0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PC0));
        }    }
    else if (ChannelId >= PD0 && ChannelId <= PD7)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PD0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PD0));
        }    }
    else if (ChannelId >= PE0 && ChannelId <= PE5)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PE0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PE0));
        }    }
    else if (ChannelId >= PF0 && ChannelId <= PF4)
    {
        if (Level)
        {
            SET_BIT((*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PF0));
        }
        else
        {
            CLEAR_BIT((*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PF0));
        }    
    }
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
* \Description     : Function that toggles a pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                          
* \Parameters (out): None                                                      
* \Return value:   : None                                                      
*******************************************************************************/
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
{

    volatile uint32* regPtr = Dio_GetBaseAddress(ChannelId);
    
    if (ChannelId >= PA0 && ChannelId <= PA7)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PA0));
    }
    else if (ChannelId >= PB0 && ChannelId <= PB7)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PB0));
    }
    else if (ChannelId >= PC0 && ChannelId <= PC7)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PC0));
    }
    else if (ChannelId >= PD0 && ChannelId <= PD7)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PD0));
    }
    else if (ChannelId >= PE0 && ChannelId <= PE5)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PE0));
    }
    else if (ChannelId >= PF0 && ChannelId <= PF4)
    {
        TOGGLE_BIT((*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)), (ChannelId-PF0));        
    }
    return Dio_ReadChannel(ChannelId);
}

/******************************************************************************
* \Syntax          :Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
* \Description     : Function that reads whole port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                          
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType                                                      
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    switch (PortId)
    {
        case PORTA:
        return (*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        case PORTB:
        return (*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        case PORTC:
        return (*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        case PORTD:
        return (*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        case PORTE:
        return (*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        case PORTF:
        return (*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC));
        
        default: /* Err unknown port */ return 0;
    }
}

/******************************************************************************
* \Syntax          : void Port_setPinAnalog ( const Port_ConfigType* ConfigPtr )     
* \Description     : Function that writes whole port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                          
* \Parameters (out): None                                                      
* \Return value:   : None                                                      
*******************************************************************************/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    
     switch (PortId)
    {
        case PORTA:
        (*(volatile uint32*)((volatile uint8*)GPIOA_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        case PORTB:
        (*(volatile uint32*)((volatile uint8*)GPIOB_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        case PORTC:
        (*(volatile uint32*)((volatile uint8*)GPIOC_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        case PORTD:
        (*(volatile uint32*)((volatile uint8*)GPIOD_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        case PORTE:
        (*(volatile uint32*)((volatile uint8*)GPIOE_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        case PORTF:
        (*(volatile uint32*)((volatile uint8*)GPIOF_BASE_ADDRESS + GPIODATA_OFFSET + 0x3FC)) = Level;
        break;
        
        default: /* Err unknown port */ ;
    }   
}


/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
