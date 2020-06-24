/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_vm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/06/24 12:18:25 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VM_H
# define DEFINE_VM_H

# define NO_SPECIFIC_POSITION	0

# define BITWISE_OPT_SHIFT		3

# define OPT_DUMP				0b00000001
# define OPT_DUMP32				0b00000010
# define OPT_DUMP64				0b00000100
# define OPT_VISU				0b00001000

# define WRONG_OPT_VALUE 		"Option value should be a positive int"
# define INVALID_OPT			"This is not a valid option"
# define POSITION_OUT_OF_RANGE	"Champions' index need to be between 1 and 4"
# define TO_MANY_CHAMP			"To many champions"
# define INDEX_ALREADY_USED		"Several champions on the same index"

#endif
