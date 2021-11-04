/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:54:17 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/04 17:18:22 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mp.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(*dup) * (len + 1));
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(*join) * (len1 + len2 + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = malloc(sizeof(*sub) * (len + 1));
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

int		get_split_len(char *s, char *charset)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		if (s[i])
		{
			n++;
			while (s[i] && !ft_strchr(charset, s[i]))
				i++;
		}
	}
	return (n);
}

char	**ft_split(char *s, char *charset)
{
	char	**split;
	int		split_len;
	int		i;
	int		j;
	int		start;

	split_len = get_split_len(s, charset);
	split = malloc(sizeof(*split) * (split_len + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && !ft_strchr(charset, s[i]))
				i++;
			split[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	split[j] = 0;
	return (split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
