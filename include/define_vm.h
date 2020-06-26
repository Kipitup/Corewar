/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_vm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/06/26 15:01:54 by amartinod        ###   ########.fr       */
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


#endif
