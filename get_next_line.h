/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:53:06 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/07 11:03:29 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_check(char *str);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*freenquit(char *free1, char *free2, char *rtn);
char	*ft_strdup(char *str);
char	*strmcat(char *s1, char *s2);

#endif
