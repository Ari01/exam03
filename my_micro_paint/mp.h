/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:48:25 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/04 17:13:08 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define BUFFER_SIZE 100000
# define FILE_ERR "Error: Operation file corrupted"

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_rectangle
{
	int		fill;
	int		width;
	int		height;
	int		character;
	t_point	tl;
	t_point	br;
}	t_rectangle;

typedef struct	s_list
{
	t_rectangle		rectangle;
	struct s_list	*next;
}	t_list;

typedef struct	s_canvas
{
	int		width;
	int		height;
	char	character;
	t_list	*list;
}	t_canvas;

/*	UTILS */
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char *charset);
void	free_split(char **split);

/*	GNL	*/
int		get_next_line(FILE *file, char **line);

/*	MP	*/
int		parse(char *path, t_canvas *canvas);
