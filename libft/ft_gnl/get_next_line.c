#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char *tmp;
	if (!s1)
		s1 = ft_strnew(0);
	tmp = ft_strjoin(s1, s2);
	if (s1 && flag == 1)
		free(s1);
	else if (s2 && flag == 2)
		free(s2);
	else if (s1 && s2 && flag == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}

static int	get_from_buffer(char **buffers, char **line)
{
	char	*tmp;
	char	*tmp_buf;

	if ((tmp = ft_strchr(*buffers, '\n')))
	{
		*tmp = '\0';
		tmp++;
		tmp_buf = *buffers;
		*line = ft_strjoin_free(*line, *buffers, 1);
		*buffers = ft_strdup(tmp);
		free(tmp_buf);
		return (1);
	}
	else
	{
		*line = ft_strjoin_free(*line, *buffers, 2);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffers[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (!line || fd < 0 || (read(fd, buffers[0], 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(0);
	if (buffers[fd])
		if (get_from_buffer(&buffers[fd], line))
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*tmp = '\0';
			tmp++;
			buffers[fd] = ft_strdup(tmp);
			*line = ft_strjoin_free(*line, buf, 1);
			return (1);
		}
		*line = ft_strjoin_free(*line, buf, 1);
	}
	return (*line[0] ? 1 : 0);
}