/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:59:53 by nmonzon           #+#    #+#             */
/*   Updated: 2024/10/28 11:29:45 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Checks if c is within the ascii range digits

int	ft_isdigit(int c)
{
	if (c == '\0')
		return (0);
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
