/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:08:12 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 15:30:56 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_routine(t_data *data)
{
	close(data->fd_s);
	close(data->fd_cor);
	ft_lstdel(&data->token_lst, del_token_lst);
	ft_lstdel(&data->label_lst, del_label_lst);
	ft_strdel(&data->cor_name);
}

void	exit_error(t_data *data, char *err_message)
{
	char	*print_err;
	char	*line;

	print_err = ft_strdup("./asm: ");
	print_err = ft_join_free(print_err, data->file_name, 1);
	print_err = ft_join_free(print_err, ": ", 1);
	if (data->line != 0 || data->column != 0)
	{
		line = ft_itoa(data->line);
		print_err = ft_join_free(print_err, "l.", 1);
		print_err = ft_join_free(print_err, line, 1);
		print_err = ft_join_free(print_err, ": ", 1);
		ft_strdel(&line);
	}
	print_err = ft_join_free(print_err, err_message, 1);
	ft_putendl_fd(print_err, 2);
	ft_strdel(&print_err);
	exit_routine(data);
	exit(EXIT_FAILURE);
}
