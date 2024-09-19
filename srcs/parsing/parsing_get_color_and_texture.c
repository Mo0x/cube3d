/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_color_and_texture.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:07:03 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/26 19:22:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	id_check(char *ids)
{
	/* check si palette_patrol est empty car si c est le cas on a toutes les infos*/
	while (*ids)
	{
		if (*ids != ' ')
			return (1);
		ids++;
	}
	return (0);
}

void	trim_stuff(t_map *map)
{
	char		*save;
	char const	*nl;

	save = map->n_path;
	nl = ft_strdup("\n");
	map->n_path = ft_strtrim(map->n_path, nl);
	wfree(save);
	save = map->s_path;
	map->s_path = ft_strtrim(map->s_path, nl);
	wfree(save);
	save = map->w_path;
	map->w_path = ft_strtrim(map->w_path, nl);
	wfree(save);
	save = map->e_path;
	map->e_path = ft_strtrim(map->e_path, nl);
	wfree(save);
	save = map->ccolor;
	map->ccolor = ft_strtrim(map->ccolor, nl);
//	wfree(save);
	save = map->fcolor;
	map->fcolor = ft_strtrim(map->fcolor, nl);
	wfree(save);
	wfree((void *)nl);
}

int	add_info(char erase_me, t_data *c3d, char *palette_patrol, char *line)
{
	/* 
	Recherche la lettre dans palette patrol et l erase de palette patroll 
	verifie qu apres l identifiant NSWECF il y a qqchose sinon error
	copie le reste de la ligne dans map->n_path ou les autres var
	si absent : a deja ete erase et renvoit error 
	*/
	while (*palette_patrol != erase_me && *palette_patrol)
		palette_patrol++;
	if (!*palette_patrol)
		exit_exclaim("Same id twice in file my friend\n", c3d);
	*palette_patrol = ' '; //efface l identifiant trouve
	skip_spaces(&line);
	if (*line == '\0' || *line == '\n')
		exit_exclaim("Have you missed something ? Nothing comes \
after identifier\n", c3d);
	if (erase_me == 'N')
		c3d->map->n_path = ft_strdup(line);
	else if (erase_me == 'S')
		c3d->map->s_path = ft_strdup(line);
	else if (erase_me == 'W')
		c3d->map->w_path = ft_strdup(line);
	else if (erase_me == 'E')
		c3d->map->e_path = ft_strdup(line);
	else if (erase_me == 'C')
		c3d->map->ccolor = ft_strdup(line);
	else if (erase_me == 'F')
		c3d->map->fcolor = ft_strdup(line);
	return (1);
}

int	get_info(char *line, char *ids, t_data *c3d)
{
	if (*line == '\n')
		return (1);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (add_info('N', c3d, ids, line + 2));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (add_info('S', c3d, ids, line + 2));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (add_info('W', c3d, ids, line + 2));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (add_info('E', c3d, ids, line + 2));
	else if (line[0] == 'F' && line[1] == ' ')
		return (add_info('F', c3d, ids, line + 1));
	else if (line[0] == 'C' && line[1] == ' ')
		return (add_info('C', c3d, ids, line + 1));
	else
		exit_exclaim("invalid identifier my friend\n", c3d);
	return (0);
}

void	colors_harvester(t_data *c3d)
{
	/* Fonction qui parse la map avec gnl et verifie que les donnees NSWEFC sont la*/
	char	*palette_patrol;

	palette_patrol = ft_strdup("NSWEFC");
	c3d->map->line = get_next_line(c3d->map->fd);
	if (!c3d->map->line)
		exit_exclaim("Empty file\n", c3d);
	while (get_info(c3d->map->line, palette_patrol, c3d) == 1 \
			&& id_check(palette_patrol) == 1)
	{
		wfree(c3d->map->line);
		c3d->map->line = get_next_line(c3d->map->fd);
		if (!c3d->map->line)
			exit_exclaim("Empty file", c3d);
	}
	trim_stuff(c3d->map);
	wfree(palette_patrol);
}
