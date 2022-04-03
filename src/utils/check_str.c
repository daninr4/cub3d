/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:48 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/18 13:53:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_str_isdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_str_val_len(char *str, int max)
{
	int		str_count;
	int		nbr_count;
	char	*newstr;
	int		value;

	value = TRUE;
	newstr = ft_strtrim_start(str, "0");
	str_count = ft_strlen(newstr);
	nbr_count = ft_digits_long(max);
	if (str_count > nbr_count)
		value = FALSE;
	else if ((str_count == nbr_count) && (ft_strcmp(newstr, "2147483647") < 0))
		value = FALSE;
	newstr = ft_memfree(newstr, NULL);
	return (value);
}
