bool	ft_isdir(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (true);
	}
	return (false);
}
