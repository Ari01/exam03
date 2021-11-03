/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:52:05 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/03 15:12:48 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mp.h"

int	main(int ac, char **av)
{
	int		rd;
	FILE	*f;
	char	*line;

	if (ac != 2)
	{
		ft_putstr_fd("Error: argument\n", 1);
		return (1);
	}
	f = fopen(av[1], "r");
	rd = get_next_line(f, &line);
	while (rd > 0)
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = NULL;
		rd = get_next_line(f, &line);
	}
	return (0);
}
