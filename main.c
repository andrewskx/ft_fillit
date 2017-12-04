/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:56:37 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/04 16:00:55 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int ft_valid_file(char *str);
int		main(int arg, char **argv)
{
	if (arg != 2)
	{
		write(1, "Usage :\n./fillit [file]\n", 25);
		return (0);
	}
	if (ft_valid_file(argv[1]))
			write(1, "\nSuccess\n", 9);
	return (0);
}
