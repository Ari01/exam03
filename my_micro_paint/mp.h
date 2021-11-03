/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:48:25 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/03 15:11:20 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define BUFFER_SIZE 100000

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_canvas
{
	int		width;
	int		height;
	char	character;
}	t_canvas;

typedef struct	s_rectangle
{
	int		fill;
	int		width;
	int		height;
	int		character;
	t_point	tl;
}	t_rectangle;

int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int		get_next_line(FILE *file, char **line);
