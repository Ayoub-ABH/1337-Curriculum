/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:59:27 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/20 12:10:50 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char d[10]="Ezs";
// 	char s[5] = "ayoub";
// 	int i = 0;
// 	char *c = ft_strncat(d,s,0);
// 	while(c[i])
// 	{
// 		printf("%c",c[i]);
// 		i++;
// 	}
// 	//printf("%s",c);
// }
