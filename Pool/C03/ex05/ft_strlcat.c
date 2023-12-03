/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:22:54 by aait-bab          #+#    #+#             */
/*   Updated: 2023/09/21 09:52:19 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
unsigned int	strlen_helper(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	sd;
	unsigned int	ss;

	i = 0;
	sd = strlen_helper(dest);
	j = sd;
	ss = strlen_helper(src);
	if (size == 0 || size <= j)
		return (size + ss); 
	while (src[i] && i < size - sd - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (sd + ss);
}

// int main()
// {
// 	char src[] = "Born to code";
//     char dest [] = "1337 42";
// 	printf("%d\n",ft_strlcat(dest,src,20));
// 	printf("%s",dest);
// }