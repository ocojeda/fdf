/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_to_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:13:46 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/26 15:09:38 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fl_to_int(float fl)
{
	int new;
	int tmp;
	int tmp2;

	tmp = fl;
	tmp2 = fl - 0.5;
	if (tmp == tmp2)
		return ((new = fl) + 1);
	else
		return (new = fl);
}
