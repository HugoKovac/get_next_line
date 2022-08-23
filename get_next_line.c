/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:49:52 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/07 11:03:28 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_b(char *str)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (freenquit(str, NULL, NULL));
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	else
		i++;
	rtn = malloc (sizeof (char) * (ft_strlen(&str[i]) + 1));
	if (!rtn)
		return (NULL);
	j = 0;
	while (str[i])
	{
		rtn[j] = str[i];
		i++;
		j++;
	}
	rtn[j] = 0;
	return (rtn);
}

char	*del_a(char *str)
{
	char	*rtn;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (freenquit(str, NULL, ft_strdup(str)));
	else
		i++;
	rtn = malloc(sizeof (char) * (i + 1));
	if (!rtn)
		return (freenquit(str, NULL, NULL));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i++] = '\n';
	rtn[i] = 0;
	return (freenquit(str, NULL, rtn));
}

char	*ft_read(char *before, int fd)
{
	char	*buffer;
	int		r_rtn;
	char	*rtn;

	r_rtn = 1;
	rtn = NULL;
	if (before)
	{
		rtn = ft_strdup(before);
		free(before);
	}
	while (!ft_check(rtn) && r_rtn != 0)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		r_rtn = read(fd, buffer, BUFFER_SIZE);
		if (r_rtn <= 0)
			return (freenquit(buffer, NULL, rtn));
		buffer[r_rtn] = 0;
		rtn = strmcat (rtn, buffer);
	}
	if (!rtn)
		return (NULL);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*save = NULL;

	rtn = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rtn = ft_read(save, fd);
	if (!rtn)
		return (freenquit(rtn, save, NULL));
	if (!*rtn)
	{
		free(rtn);
		rtn = NULL;
	}
	save = del_b(rtn);
	rtn = del_a(rtn);
	if (!rtn)
		free(save);
	return (rtn);
}
/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *str;
	int fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	for (size_t i = 0; i < 10; i++)
	{
		str = get_next_line(fd);;
		printf("\n=> %s\n-----------------------------\n", str);
		free(str);
	}
	
}
*/
