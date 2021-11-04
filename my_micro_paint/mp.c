/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:52:05 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/04 17:14:27 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mp.h"

int	main(int ac, char **av)
{
	t_canvas	canvas;

	if (ac != 2)
	{
		ft_putstr_fd("Error: argument\n", 1);
		return (1);
	}
	parse(av[1], &canvas);
	printf("w = %d, h = %d, char = %c\n", canvas.width, canvas.height, canvas.character);
	return (0);
}
