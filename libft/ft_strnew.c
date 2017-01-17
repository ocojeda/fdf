/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:22:24 by tfaure            #+#    #+#             */
/*   Updated: 2016/11/14 21:13:57 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}
