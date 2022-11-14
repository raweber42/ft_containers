/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/14 12:36:29 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

template<typename T>
class vector_iterator {
	public:
		vector_iterator(T *ptr) : _ptr(ptr) {}
		// ~VectorIterator();
		// VectorIterator(const VectorIterator &src);
		// VectorIterator& operator=(Cat const &rhs);

		T& operator*(void) { return (*_ptr); }
		
		T& operator++(void) {
			_ptr++;
			return (*this);
		}
		
		T operator++(int) {
			T ret(*this);
			_ptr++;
			return (ret);
		}
		
		bool operator==(vector_iterator const &rhs) const {
			if (_ptr == rhs._ptr)
				return(true);
			else
				return(false);	
		}
		
		bool operator!=(vector_iterator const &rhs) const {
			if (_ptr != rhs.ptr)
				return(true);
			else
				return(false);
		}
		
		// VectorIterator& operator++(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		
		
	private: // protected??
		T	*_ptr;
};


//-------------------OLD (ask Maggie)----------------------
// template<typename Iterator>
// template<typename Category, typename T, typename Distance = std::ptrdiff_t>
// class vector_iterator : Iterator< std::random_access_iterator_tag, T, Distance> {
// 	public:
// 		vector_iterator(Iterator ptr) : _iterator(ptr) {}
// 		// ~VectorIterator();
// 		// VectorIterator(const VectorIterator &src);
// 		// VectorIterator& operator=(Cat const &rhs);

// 		// VectorIterator& operator==(VectorIterator const &rhs);
// 		// VectorIterator& operator!=(CVectorIterator const &rhs);
// 		// VectorIterator& operator++(CVectorIterator const &rhs);
// 		// VectorIterator& operator!=(CVectorIterator const &rhs);
// 		// VectorIterator& operator!=(CVectorIterator const &rhs);
// 		// VectorIterator& operator!=(CVectorIterator const &rhs);
		
		
// 	private: // protected??
// 		Iterator::pointer _iterator;
// };

#endif