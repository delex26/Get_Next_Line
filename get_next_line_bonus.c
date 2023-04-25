/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:38:05 by hben-mes          #+#    #+#             */
/*   Updated: 2023/02/27 14:42:38 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*modu[10240];
	char		buff[BUFFER_SIZE + 1];
	int			res;
	char		*ptr;

	res = 1;
	ptr = NULL;
	if (modu[fd])
		ptr = ft_strjoin(modu[fd], ptr);
	while (res)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
			break ;
		buff[res] = '\0';
		ptr = ft_strjoin(ptr, buff);
		if (new_line(ptr))
			break ;
	}
	modu[fd] = get_cut(ptr);
	return (get_new_line(ptr));
}
// int main()
// {
// 	int fd;
// 	int fd1;

// 	fd = open("test.txt", O_RDWR);
// 	fd1 = open("test1.txt", O_RDWR);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));

// }
