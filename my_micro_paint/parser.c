/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:54:39 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/04 17:21:47 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mp.h"

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *s)
{
	int	i;
	int	len;
	int	sign;
	int	n;
	int	ten_pow;

	i = 0;
	n = 0;
	ten_pow = 1;
	sign = 1;
	len = ft_strlen(s);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (--len >= i)
	{
		n += s[len] - '0' * ten_pow;
		ten_pow *= 10;
	}
	n *= sign;
	return (n);
}

int	check_integer(char *s, int min, int max)
{
	int	n;
	int	i;
	int	maxlen;

	if (s[0] == '+' || s[0] == '-')
		maxlen = 11;
	else
		maxlen = 10;
	if (ft_strlen(s) > maxlen)
		return (1);
	i = 0;
	while (s[i])
	{
		if (!ft_isnum(s[i]))
			return (1);
		i++;
	}
	n = ft_atoi(s);
	printf("n = %d\n", n);
	if (n > max || n < min)
		return (1);
	return (0);
}

int	check_char(char *s)
{
	if (ft_strlen(s) != 1)
		return (1);
	if (s[0] < 32 || s[0] > 126)
		return (1);
	return (0);
}

int	check_canvas(char **split)
{
	if (check_integer(split[0], 1, 300)
			|| check_integer(split[1], 1, 300)
			|| check_char(split[2]))
		return (1);
	return (0);
}

t_canvas	set_canvas(char **split)
{
	t_canvas	canvas;

	canvas.width = ft_atoi(split[0]);
	canvas.height = ft_atoi(split[1]);
	canvas.character = split[2][0];
	return (canvas);
}

int	get_canvas(FILE *f, t_canvas *canvas)
{
	int		rd;
	char	*line;
	char	**split;

	rd = get_next_line(f, &line);
	if (rd < 0)
		return (1);
	split = ft_split(line, " \t\v\r\f");
	if (check_canvas(split))
		return (1);
	else
		printf("ok\n");
	*canvas = set_canvas(split);
	free_split(split);
	return (0);
}

int	parse(char *path, t_canvas *canvas)
{
	FILE		*f;
	
	f = fopen(path, "r");
	if (!f)
	{
		ft_putendl_fd(FILE_ERR, 1);
		return (1);
	}
	if (!get_canvas(f, canvas))
	{
		ft_putendl_fd(FILE_ERR, 1);
		return (1);
	}
	fclose(f);
	return (0);
}
