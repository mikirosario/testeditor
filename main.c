/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:01:17 by mrosario          #+#    #+#             */
/*   Updated: 2021/03/19 12:37:28 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeditor.h"

int	main(void)
{
	t_testeditor	testeditor;
	char	c;

	enable_raw_mode(&testeditor);
	while (1)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == -1)
			exit_failure("read", &testeditor);
		if (iscntrl(c))
			printf("%d\r\n", c);
		else
			printf("%d ('%c')\r\n", c, c);
		if (c == 'q')
			break ;
	}
	exit(disable_raw_mode(&testeditor));
}
