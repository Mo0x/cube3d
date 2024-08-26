/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_color_and_texture.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:07:03 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/26 19:09:40 by mgovinda         ###   ########.fr       */
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
	wfree(save);
	save = map->fcolor;
	map->fcolor = ft_strtrim(map->fcolor, nl);
	wfree(save);
	wtfree((void *)nl);
}

int	add_info(char erase_me, t_map *map, char *palette_patrol, char *line)
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
		exit_exclaim("Same id twice in file my friend\n");
	*palette_patrol = ' '; //efface l identifiant trouve
	skip_spaces(&line);
	if (*line == '\0' || *line == '\n')
		exit_exclaim("Have you missed something ? Nothing comes \
after identifier\n");
	if (erase_me == 'N')
		map->n_path = ft_strdup(line);
	else if (erase_me == 'S')
		map->s_path = ft_strdup(line);
	else if (erase_me == 'W')
		map->w_path = ft_strdup(line);
	else if (erase_me == 'E')
		map->e_path = ft_strdup(line);
	else if (erase_me == 'C')
		map->ccolor = ft_strdup(line);
	else if (erase_me == 'F')
		map->fcolor = ft_strdup(line);
	return (1);
}

int	get_info(char *line, char *ids, t_map *map)
{
	if (*line == '\n')
		return (1);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (add_info('N', map, ids, line + 2));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (add_info('S', map, ids, line + 2));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (add_info('W', map, ids, line + 2));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (add_info('E', map, ids, line + 2));
	else if (line[0] == 'F' && line[1] == ' ')
		return (add_info('F', map, ids, line + 1));
	else if (line[0] == 'C' && line[1] == ' ')
		return (add_info('C', map, ids, line + 1));
	else
		exit_exclaim("invalid identifier my friend\n");
	return (0);
}

void	colors_harvester(t_map *map)
{
	/* Fonction qui parse la map avec gnl et verifie que les donnees NSWEFC sont la*/
	char	*palette_patrol;

	palette_patrol = ft_strdup("NSWEFC");
	map->line = get_next_line(map->fd);
	if (!map->line)
		exit_exclaim("Empty file\n");
	while (get_info(map->line, palette_patrol, map) == 1 \
			&& id_check(palette_patrol) == 1)
	{
		wfree(map->line);
		map->line = get_next_line(map->fd);
		if (!map->line)
			exit_exclaim("Empty file");
	}
	trim_stuff(map);
	wfree(palette_patrol);
}
