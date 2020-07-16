/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_vm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/06/24 16:18:07 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VM_H
# define DEFINE_VM_H

# define NO_SPECIFIC_POSITION	0
# define MINIMUM_LEN			4
# define MIN_LEN_FILE			2192
# define EXEC_CODE_SIZE			4
# define FILE_PADDING			4
# define BITWISE_OPT_SHIFT		3
# define NB_OF_OPE				16
# define FIRST_PARAM			6
# define SECOND_PARAM			4
# define THIRD_PARAM			2

# define OPT_DUMP				0b00000001
# define OPT_DUMP32				0b00000010
# define OPT_DUMP64				0b00000100
# define OPT_RESET_DUMP			0b00000111
# define OPT_VISU				0b00001000

/*
** error basic
*/
# define MALLOC_ERR				"memory allocation failed"	
# define TOO_MANY_CHAMPS		"too many champions"
/*
** error option 
*/
# define INVALID_OPT			"this is not a valid option"
# define WRONG_OPT_VALUE 		"option value should be a positive int"
# define NO_ARG_FOR_DUMP		"the dump option take an argument"
# define POSITION_OUT_OF_RANGE	"index need to be between 1 and MAX_PLAYERS"
# define NO_ARG_FOR_N			"the n option take 2 arguments"
# define INDEX_ALREADY_USED		"several champions on the same index"
# define WRONG_POSITION			"players' position must follow each other"

/*
** error player file
*/
# define CANT_OPEN				"can't open a file"
# define INCORRECT_FILE_NAME	"incorrect file name"
# define NOT_VALID_FILE			"this is not a valid file"
# define WRONG_EXTENSION		"only '.cor' file are accepted"
# define WRONG_MAGIC_NB			"magic number is not valid"
# define CODE_TOO_LONG			"executable code size exceed CHAMP_MAX_SIZE"
# define FILE_TOO_SHORT			"file is too short to be valid"


/*
** ope code 
*/
# define OPE_LIVE				0x01
# define OPE_LD					0x02
# define OPE_ST					0x03
# define OPE_ADD				0x04
# define OPE_SUB				0x05
# define OPE_AND				0x06
# define OPE_OR					0x07
# define OPE_XOR				0x08
# define OPE_ZJMP				0x09
# define OPE_LDI				0x0a
# define OPE_STI				0x0b
# define OPE_FORK				0x0c
# define OPE_LLD				0x0d
# define OPE_LLDI				0x0e
# define OPE_LFORK				0x0f
# define OPE_AFF				0x10

# define W_LIVE					10
# define W_LD					5
# define W_ST					5
# define W_ADD					10
# define W_SUB					10
# define W_AND					6
# define W_OR					6
# define W_XOR					6
# define W_ZJMP					20
# define W_LDI					25
# define W_STI					25
# define W_FORK					800
# define W_LLD					10
# define W_LLDI					50
# define W_LFORK				1000
# define W_AFF					2

#endif
