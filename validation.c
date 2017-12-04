/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:38:14 by anboscan          #+#    #+#             */
/*   Updated: 2017/12/04 16:06:35 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define dot 0
#define block 1
#define new 2
#define line 3
#define block_line 4
#define block_num 5
#define file 6
#define len 7

void	ft_zero(int *ptr, size_t size)
{
	size_t i;

	i = 0;
	while (i++ != size)
		ptr[i] = 0;
}

int		ft_valid_file(char *str)
{
	int arr[8];
	char symbol;

	symbol = 0;
	ft_zero(arr, 8);
	if ((arr[file] = open(str, O_RDONLY)) > 0)
		while ((arr[len] = read(arr[file], &symbol, 1)) != 0)
		{
			arr[line]++;
			if (symbol == '.')
				arr[dot]++;
			if (symbol == '#')
				arr[block]++;
			if (symbol == '\n' && arr[line] != 5)
				return (0);
				
			else
			{
				arr[line] = 0;
				arr[block_line]++;
			}
			if (arr[block_line] == 4)
			{
				arr[block_num]++;
				if ((arr[len] = read(arr[file], &symbol, 1)) != 0 && symbol == '\n')
				   arr[block_line] = 0;
				if(arr[len] == 0)
					return (arr[block_line]);
				else
					return (0);
			}
		}
	return (0);
}	

