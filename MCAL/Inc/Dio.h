/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio module
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PORTA
#define PORTA (0u)
#endif

#ifndef PORTB
#define PORTB (1u)
#endif

#ifndef PORTC
#define PORTC (2u)
#endif

#ifndef PORTD
#define PORTD (3u)
#endif

#ifndef PORTE
#define PORTE (4u)
#endif

#ifndef PORTF
#define PORTF (5u)
#endif


#define PA0 (0u)
#define PA1 (1u)
#define PA2 (2u)
#define PA3 (3u)
#define PA4 (4u)
#define PA5 (5u)
#define PA6 (6u)
#define PA7 (7u)

#define PB0 (8u)
#define PB1 (9u)
#define PB2 (10u)
#define PB3 (11u)
#define PB4 (12u)
#define PB5 (13u)
#define PB6 (14u)
#define PB7 (15u)

#define PC0 (16u)
#define PC1 (17u)
#define PC2 (18u)
#define PC3 (19u)
#define PC4 (20u)
#define PC5 (21u)
#define PC6 (22u)
#define PC7 (23u)

#define PD0 (24u)
#define PD1 (25u)
#define PD2 (26u)
#define PD3 (27u)
#define PD4 (28u)
#define PD5 (29u)
#define PD6 (30u)
#define PD7 (31u)

#define PE0 (32u)
#define PE1 (33u)
#define PE2 (34u)
#define PE3 (35u)
#define PE4 (36u)
#define PE5 (37u)


#define PF0 (38u)
#define PF1 (39u)
#define PF2 (40u)
#define PF3 (41u)
#define PF4 (42u)


#define BIT_BANDING (0u)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef enum
{
    PIN_LOW,
    PIN_HIGH
} Dio_LevelType;

typedef uint8 Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
