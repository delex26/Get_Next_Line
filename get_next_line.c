/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:43:10 by hben-mes          #+#    #+#             */
/*   Updated: 2023/02/27 14:43:02 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*modu;
	char		buff[BUFFER_SIZE + 1];
	int			res;
	char		*ptr;

	res = 1;
	ptr = NULL;
	if (modu)
		ptr = ft_strjoin(modu, ptr);
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
	modu = get_cut(ptr);
	return (get_new_line(ptr));
}
// int main()
// {
// 	int fd;

// 	fd = open("test.txt", O_RDWR);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }