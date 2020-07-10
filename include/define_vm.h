/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_vm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/07/10 16:41:28 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VM_H
# define DEFINE_VM_H

# define NO_SPECIFIC_POSITION	0
# define MINIMUM_LEN			4

# define BITWISE_OPT_SHIFT		3

# define OPT_DUMP				0b00000001
# define OPT_DUMP32				0b00000010
# define OPT_DUMP64				0b00000100
# define OPT_VISU				0b00001000

# define MALLOC_ERR				"memory allocation failed"	
# define WRONG_OPT_VALUE 		"option value should be a positive int"
# define INVALID_OPT			"this is not a valid option"
# define POSITION_OUT_OF_RANGE	"champions' index need to be between 1 and 4"
# define TO_MANY_CHAMP			"to many champions"
# define INDEX_ALREADY_USED		"several champions on the same index"
# define INCORRECT_FILE_NAME	"incorrect file name"
# define NOT_VALID_FILE			"this is not a valid file"
# define WRONG_EXTENSION		"only '.cor' file are accepted"
# define CANT_OPEN				"cant open, NEED DEFINE[?]"

#endif
