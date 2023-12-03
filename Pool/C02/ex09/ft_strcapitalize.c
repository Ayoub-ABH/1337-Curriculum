/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:06:05 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/19 15:21:04 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

int	con_helper(int cara)
{
	return (!(cara >= 'a' && cara <= 'z')
		&& !(cara >= 'A' && cara <= 'Z')
		&& !(cara >= '0' && cara <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	to_lowercase(str);
	if ((str[0] >= 'a' && str[0] <= 'z'))
		str[0] = str[0] - 32;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (con_helper(str[i - 1]))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

// int	main()
// {
// 	char str[] = "cd4a,salut, comment tu vas ? ;
// 	char str1[] = "HGRSJHJKFSHGUFHSJVFHS;
// 	// printf("%s", ft_strcapitalize(str));
// 	printf("%s", ft_strcapitalize(str));
// }
