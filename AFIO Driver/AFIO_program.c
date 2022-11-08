/*
 * AFIO_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Moe
 */

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

#include "STD_TYPES.h"

void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap){


	if(Copy_u8Line >= 0 && Copy_u8Line < 4){
		AFIO_EXTICR1 &= ~((0b1111)<<(Copy_u8Line * 4));
		AFIO_EXTICR1 |= ((Copy_u8PortMap)<<(Copy_u8Line * 4));
	}
	else if(Copy_u8Line >= 4 && Copy_u8Line < 8){
		Copy_u8Line -= 4;
		AFIO_EXTICR2 &= ~((0b1111)<<(Copy_u8Line * 4));
		AFIO_EXTICR2 |= ((Copy_u8PortMap)<<(Copy_u8Line * 4));
	}
	else if(Copy_u8Line >= 8 && Copy_u8Line < 12){
		Copy_u8Line -= 8;
		AFIO_EXTICR3 &= ~((0b1111)<<(Copy_u8Line * 4));
		AFIO_EXTICR3 |= ((Copy_u8PortMap)<<(Copy_u8Line * 4));
	}
	else if(Copy_u8Line >= 12 && Copy_u8Line < 16){
		Copy_u8Line -= 12;
		AFIO_EXTICR4 &= ~((0b1111)<<(Copy_u8Line * 4));
		AFIO_EXTICR4 |= ((Copy_u8PortMap)<<(Copy_u8Line * 4));
	}
}
