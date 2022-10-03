/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  NVIC
 *
 *  Description:  header file for NVIC driver
 *
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void IntCrtl_Init(void)
 * \Description     : initialize NVIC module to enable and prioritize the required interrupts
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void IntCrtl_Init(void);

#endif /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/