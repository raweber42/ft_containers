/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:24:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/11 13:53:06 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

template<typename Category, typename T, typename Distance = std::ptrdiff_t>
class Iterator {
	public:
		typedef Category			iterator_category;
		typedef T					value_type;
		typedef Distance			difference_type;
		typedef value_type*			pointer;
		typedef value_type&			reference;
};

// iterator traits -> pointer in iterators sauber umwandeln
#endif