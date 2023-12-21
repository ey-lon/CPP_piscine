/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:39:52 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 11:48:32 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	easyfind(const T &container, int intToFind)
{
	int i = 0;
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++, i++) {
		if (*it == intToFind) {
			return (i);
		}
	}
	return (-1);
}
