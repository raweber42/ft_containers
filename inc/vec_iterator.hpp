/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/23 08:14:53 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"


//######################################################################
//######################## ITERATOR ####################################
//######################################################################

template<typename T>
class vector_iterator {
	
//---------------ITERATOR TYPEDEFS (iterator traits)---------------------------------
	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;

//---------------ITERATOR CONSTRUCTORS-----------------------------------------------

	public:
		vector_iterator(void) : _ptr(NULL) {}
		vector_iterator(pointer ptr) : _ptr(ptr) {}
		vector_iterator(const vector_iterator &src) : _ptr(src._ptr) {}
		~vector_iterator() {};

//---------------ITERATOR OPERATOR OVERLOADS----------------------------------------

		vector_iterator& operator=(vector_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}
		
		reference operator*(void) { return (*_ptr); }

		pointer operator->(void) { return (_ptr); }

		reference operator[](difference_type offset) { return(*((*this) + offset)); }
		
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

		// above: move out of member functions?
		
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


	private:
		pointer _ptr;
};


//######################################################################
//#################### REVERSE ITERATOR ################################
//######################################################################

template <typename vector_iterator>
class reverse_vector_iterator {
	
//---------------REVERSE_ITERATOR TYPEDEFS (iterator traits)------------------------------------
	public:
		typedef vector_iterator									iterator_type;
		typedef typename vector_iterator::iterator_category		iterator_category;
		typedef typename vector_iterator::value_type			value_type;
		typedef typename vector_iterator::difference_type		difference_type;
		typedef typename vector_iterator::pointer				pointer;
		typedef typename vector_iterator::reference				reference;

//---------------REVERSE_ITERATOR CONSTRUCTORS--------------------------------------------------
	public:
		reverse_vector_iterator(void) : iterator_type() {}
		
		explicit reverse_vector_iterator(iterator_type x) : _base(x) {}
		
		template< class U >
		reverse_vector_iterator(const reverse_vector_iterator<U>& other) : _base(other._base) {}

		template< class U >
		reverse_vector_iterator& operator=(const reverse_vector_iterator& rhs) {
			_base = rhs._base;
			return (*this);
		}

//---------------BASE FUNCTION--------------------------------------------------------------
		
		iterator_type base() const { return (_base); }

//---------------(MEMBER) REVERSE_ITERATOR OPERATOR OVERLOAD--------------------------------------------------
		reference operator*(void) { 
			
			iterator_type tmp = _base;
			return (*(--tmp));
		}

		pointer operator->(void) { return ( &(operator*()) ); }

		reference operator[](difference_type offset) { return(base()[offset - 1]); }

		reverse_vector_iterator &operator++(void) {
			_base--;
			return (*this);
		}
		
		reverse_vector_iterator operator++(int) {
			reverse_vector_iterator ret(*this);
			_base--;
			return (ret);
		}

		reverse_vector_iterator &operator--(void) {
			_base++;
			return (*this);
		}
		
		reverse_vector_iterator operator--(int) {
			reverse_vector_iterator ret(*this);
			_base++;
			return (ret);
		}

		reverse_vector_iterator operator+(difference_type offset) const {

			return (reverse_vector_iterator(_base - offset));
		}
		
		difference_type  operator+(reverse_vector_iterator rhs) const {

			return (_base - rhs._base);
		}

		reverse_vector_iterator  operator-(difference_type offset) const {

			return (reverse_vector_iterator(_base + offset));
		}

		difference_type  operator-(reverse_vector_iterator rhs) const {

			return (_base + rhs._base);
		}

		reverse_vector_iterator &operator+=(difference_type offset) {
			_base -= offset;
			return (*this);
		}
		
		reverse_vector_iterator &operator-=(difference_type offset) {
			_base += offset;
			return (*this);
		}

	protected:
		iterator_type _base;

};

//---------------(NON-MEMBER) REVERSE_ITERATOR OPERATOR OVERLOADS--------------------------------------------------

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() >= rhs.base());
}


template< class Iterator1, class Iterator2 >
bool operator>( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
	return (lhs.base() <= rhs.base());
}

#endif
