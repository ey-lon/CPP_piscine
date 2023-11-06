/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:39:52 by abettini          #+#    #+#             */
/*   Updated: 2023/10/31 09:48:56 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	easyfind(T container, int intToFind)
{
	int i = 0;
	int j = -1;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == intToFind)
		{
			j = i;
			break ;
		}
		i++;
	}
	return (j);
}