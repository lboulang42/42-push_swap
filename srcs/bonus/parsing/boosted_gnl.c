/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boosted_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:05:54 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/21 17:13:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_join_free(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_get_file(char *buffer, int fd)
{
	char	*tmp;
	int		readed;

	readed = 1;
	tmp = malloc(2 * sizeof(char));
	if (!tmp)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (free(tmp), NULL);
	}
	while (readed > 0 && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, tmp, 1);
		if (readed == -1)
			return (free(tmp), NULL);
		tmp[readed] = '\0';
		buffer = ft_join_free(buffer, tmp);
	}
	return (free(tmp), buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*boosted_gnl(char *buffer, int fd)
{
	char	*line;

	if (fd < 0)
		return (NULL);
	buffer = ft_get_file(buffer, fd);
	if (!buffer)
		return (free(buffer), NULL);
	line = ft_get_line(buffer);
	return (free(buffer), line);
}
