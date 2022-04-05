/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:17:13 by fdaumas           #+#    #+#             */
/*   Updated: 2022/03/29 13:40:18 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0 ;
	while (str[index] != '\0')
		index++;
	return (index);
}
