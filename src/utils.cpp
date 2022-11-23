/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:13:41 by raweber           #+#    #+#             */
/*   Updated: 2022/11/23 10:47:22 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ) {
		
		while ((first1 != last1) && (first2 != last2))
		{
			if (!(*first1 < *first2))
				return (false);
			first1++;
			first2++;
		}
		if (first1 != last1 && (first2 == last2))
			return (false);
		return (true);
	}

	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}
}