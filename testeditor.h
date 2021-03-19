/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeditor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:30:57 by mrosario          #+#    #+#             */
/*   Updated: 2021/03/19 12:35:11 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <termios.h>

typedef struct	s_testeditor
{
	struct termios	term;
	struct termios	orig_term;
}				t_testeditor;

void	enable_raw_mode(t_testeditor *testeditor);
void	exit_failure(const char *s, t_testeditor *testeditor);
int		disable_raw_mode(t_testeditor *testeditor);