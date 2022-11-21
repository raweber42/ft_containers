/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/21 10:47:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

template<typename T>
class vector_iterator {
	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
		
	public:
		vector_iterator(void) : _ptr(NULL) {}
		vector_iterator(pointer ptr) : _ptr(ptr) {}
		vector_iterator(const vector_iterator &src) : _ptr(src._ptr) {}
		~vector_iterator() {};

		// --- VECTOR OPERATOR OVERLOADS ---

		vector_iterator& operator=(vector_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}
		
		reference operator*(void) { return (*_ptr); }

		pointer operator->(void) { return (_ptr); }
		
		bool operator==(vector_iterator const &rhs) const {
			return (_ptr == rhs._ptr);	
		}
		
		bool operator!=(vector_iterator const &rhs) const {
			return (_ptr != rhs._ptr);
		}

		bool operator<(vector_iterator const &rhs) const {
			return (_ptr < rhs._ptr);
		}

		bool operator<=(vector_iterator const &rhs) const {
			return (_ptr <= rhs._ptr);
		}

		bool operator>(vector_iterator const &rhs) const {
			return (_ptr > rhs._ptr);
		}

		bool operator>=(vector_iterator const &rhs) const {
			return (_ptr >= rhs._ptr);
		}
		
		
		vector_iterator &operator++(void) {
			_ptr++;
			return (*this);
		}
		
		vector_iterator operator++(int) {
			vector_iterator ret(*this);
			_ptr++;
			return (ret);
		}

		vector_iterator &operator--(void) {
			_ptr--;
			return (*this);
		}
		
		vector_iterator operator--(int) {
			vector_iterator ret(*this);
			_ptr--;
			return (ret);
		}

		vector_iterator operator+(difference_type offset) const {

			return (vector_iterator(_ptr + offset));
		}
		
		difference_type  operator+(vector_iterator rhs) const {

			return (_ptr + rhs._ptr);
		}

		vector_iterator  operator-(difference_type offset) const {

			return (vector_iterator(_ptr - offset));
		}

		difference_type  operator-(vector_iterator rhs) const {

			return (_ptr - rhs._ptr);
		}

		vector_iterator &operator+=(difference_type offset) {
			_ptr += offset;
			return (*this);
		}
		
		vector_iterator &operator-=(difference_type offset) {
			_ptr -= offset;
			return (*this);
		}

		reference operator[](difference_type offset) { return(*((*this) + offset)); }

		
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		// VectorIterator& operator!=(CVectorIterator const &rhs);
		
		
	private: // protected??
		pointer _ptr;
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