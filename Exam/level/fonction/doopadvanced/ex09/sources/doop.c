/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabousfi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 00:34:31 by wabousfi          #+#    #+#             */
/*   Updated: 2018/02/28 00:34:32 by wabousfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "do_opp.h"
#include "ft_opp.h"

void	print(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

void	ft_usage(int nbr1, int nbr2)
{
	unsigned long	i;
	unsigned long	length;

	(void)nbr1;
	(void)nbr2;
	i = 0;
	length = sizeof(g_opptab) / sizeof(*g_opptab);
	print("error : only [ ");
	while (i < length)
	{
		print(g_opptab[i].op);
		if (g_opptab[i].op[0] != '\0')
			print(" ");
		i++;
	}
	print("] are accepted.\n");
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&\
		s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int				nbr[2];
	unsigned long	i;
	unsigned long	length;

	if (argc != 4)
		return (0);
	nbr[0] = ft_atoi(argv[1]);
	nbr[1] = ft_atoi(argv[3]);
	i = 0;
	length = sizeof(g_opptab) / sizeof(*g_opptab);
	while (i < length)
	{
		if (ft_strcmp(g_opptab[i].op, argv[2]) == 0)
		{
			g_opptab[i].f(nbr[0], nbr[1]);
			print("\n");
			return (0);
		}
		i++;
	}
	ft_usage(0, 0);
	return (0);
}
