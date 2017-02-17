/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:04:31 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/17 18:41:10 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_iscapital(char c)
{
	if(c >= 65 && c <= 90)
		return (1);
	else 
		return (0);
}
unsigned int	ft_getcolor(char *nbr)
{
	unsigned int i;
	char *str;
	char str2[3];
	int pow;
	int e;

	i = 0;
	if(!nbr)
		return 0;
	str = ft_strchr(nbr,'x')+1;
	while(*str)
	{
		ft_strncpy(str2, str, 2);
		e = 0;
		ft_putendl(str2);
		pow = 16;
		while(str2[e])
		{
			if (ft_isalpha(str2[e]))
			{
				if(ft_iscapital(str2[e]))
					i = i + (str2[e] - 'A' + 10)*pow;
				else 
					i = i + (str2[e] - 'a' + 10)*pow;
			}
			else
				i = i + (str2[e]-'0')*pow;
			e++;
			pow = 1;
		}
		str+=2;
//	ft_putnbr(i);
	ft_putnbr(i);
	}
	return 1;
}
int main()
{
	char *str = "0xff0000";
	ft_getcolor(str);
	return 0;

}
