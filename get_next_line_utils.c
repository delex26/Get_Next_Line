/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:00:07 by hben-mes          #+#    #+#             */
/*   Updated: 2023/02/27 14:42:56 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	new_line(char *c)
{
	int	i;

	i = 0;
	while (c && c[i])
	{
		if (c[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_cut(char *y8)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (!y8)
		return (0);
	while (y8[i])
		i++;
	while (y8[j] && y8[j] != '\n')
		j++;
	if (y8[j] == '\n')
		j++;
	if ((i - j) <= 0)
		return (0);
	ptr = malloc((i - j) + 2);
	if (!ptr)
		return (0);
	while (y8[j])
		ptr[k++] = y8[j++];
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1len;
	int		s2len;
	int		i;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len <= 0 && s2len <= 0)
		return (0);
	str = malloc(sizeof(char) * ((s1len + s2len) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
		str[s1len++] = s2[i++];
	str[s1len] = '\0';
	free(s1);
	return (str);
}

char	*get_new_line(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	free(str);
	return (ptr);
}
