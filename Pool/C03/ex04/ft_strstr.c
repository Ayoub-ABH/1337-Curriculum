/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:32:04 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/20 20:35:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	if (to_find[j] == '\0')
		return (str);
	while (to_find[k] != '\0')
		k++;
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j])
		{
			j++;
		}
		if (k == j)
		{
			return (str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

// int main(void)
// {
// 	char s[6]="ayoub";
// 	char f[2] = "r";

// 	int i = 0;
// 	char *c = ft_strstr(s,f);
// 	//while(c[i])
// 	//{
// 	//	printf("%c",c[i]);
// 	//	i++;
// 	//}
// 	printf("%s",c);
// }
