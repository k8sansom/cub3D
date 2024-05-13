void	check_map(t_game *game)
{
	int	vertical;
	int	horizontal;
	int	height;
	int	width;

	vertical = ft_vertical(game);
	horizontal = ft_horizontal(game);
	if (!vertical || !horizontal)
		full_exit ("Error: missing external walls!", game, game->exit_code++);
	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width < ft_strlen(game->map[height]) - 2)
		{
			ft_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->player_counter != 1 || game->collectable_counter < 1 \
		|| game->exit_counter != 1)
		ft_exit ("Error: Something is wrong with player, exit or collectable", \
			game, game->exit_code++);
}
