/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:31:30 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/12 22:00:13 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ans = ft_strnew(len);
	if (!ans)
		return (NULL);
	ans = ft_strcat(ans, s1);
	ans = ft_strcat(ans, s2);
	ans[len] = '\0';
	return (ans);
}
