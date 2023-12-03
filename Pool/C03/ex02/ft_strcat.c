/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:31:36 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/20 12:01:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
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
// 	char d[10]="Ehghm";
// 	char s[5] = "ayoub";
// 	int i = 0;
// 	char *c = ft_strcat(d,s);
// 	while(c[i])
// 	{
// 		printf("%c",c[i]);
// 		i++;
// 	}
// 	//printf("%s",c);
// }
