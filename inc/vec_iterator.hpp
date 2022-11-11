/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/11 10:50:39 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

template<typename Iterator>
class VectorIterator {
	public:
		VectorIterator();
		~VectorIterator();
		VectorIterator(const VectorIterator &src);
		VectorIterator& operator=(Cat const &rhs);

		// VectorIterator& operator==(VectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator++(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		
		
	protected:
		Iterator iterator;
};

#endif