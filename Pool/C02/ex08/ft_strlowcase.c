/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:00:13 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/18 12:05:48 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) = *(str + i) + 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[] = "545454djskgfhjgzdhfgEHSFGHDHJK";

// 	printf("%s", ft_strlowcase(str));
// }
