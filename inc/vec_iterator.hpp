/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/25 18:41:23 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <cstddef>
#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"
#include <iterator>

namespace ft {
	
//######################################################################
//######################## ITERATOR TRAITS #############################
//######################################################################

	struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag : public input_iterator_tag {};
	struct random_access_iterator_tag : public forward_iterator_tag {};
	struct output_iterator_tag : public bidirectional_iterator_tag {};

	// generic
	template <typename T>
	struct iterator_traits {
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;	
	};

	// spezialization pointer
	template <typename T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t					difference_type;
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;	
	};

	// spezialization const pointer
	template <typename T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t					difference_type;
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;	
	};

	
//######################################################################
//######################## ITERATOR ####################################
//######################################################################

	template<typename T, typename Container>
	class vector_iterator {
		
//---------------ITERATOR TYPEDEFS (iterator traits)---------------------------------
		public:
			typedef typename ft::iterator_traits<T>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<T>::value_type				value_type;
			typedef typename ft::iterator_traits<T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<T>::pointer				pointer;
			typedef typename ft::iterator_traits<T>::reference				reference;

//---------------ITERATOR CONSTRUCTORS-----------------------------------------------

		public:
			vector_iterator(void) : _ptr(NULL) {}
			vector_iterator(pointer ptr) : _ptr(ptr) {}
			//below added for const/non-const
			template<typename _T>
			vector_iterator(const vector_iterator<_T, typename ft::enable_if<ft::are_same<_T, typename Container::pointer>::value, Container>::type>& copy) : _ptr(copy.base()) {}
			//end addition
			vector_iterator(const vector_iterator &src) : _ptr(src._ptr) {}
			~vector_iterator() {};

//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			pointer base() const { return (_ptr); }

//---------------ITERATOR OPERATOR OVERLOADS----------------------------------------

			vector_iterator& operator=(vector_iterator const &rhs) {
				_ptr = rhs._ptr;
				return (*this);
			}
			
			reference operator*(void) const { return (*_ptr); }

			pointer operator->(void) const { return (_ptr); }

			reference operator[](difference_type offset) const { return(*((*this) + offset)); }
			
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

		protected:
			pointer _ptr;


	};


//---------------ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename T1, typename T2, typename Container>
	bool operator==(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() == rhs.base());	
	}

	template<typename T1, typename T2, typename Container>
	bool operator!=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator<(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator<=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator>(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator>=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (lhs.base() >= rhs.base());
	}

//---------------ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

	template<typename T, typename Container>
	bool operator==(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename T, typename Container>
	bool operator!=(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename Container>
	bool operator<(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename Container>
	bool operator<=(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename Container>
	bool operator>(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T, typename Container>
	bool operator>=(const vector_iterator<T, Container> &lhs, const vector_iterator<T, Container> &rhs) {
		return (lhs.base() >= rhs.base());
	}

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
			reverse_vector_iterator(const reverse_vector_iterator<U>& other) : _base(other.base()) {}

			template< class U >
			reverse_vector_iterator& operator=(const reverse_vector_iterator& rhs) {
				_base = rhs.base();
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

// //---------------(NON-MEMBER) REVERSE_ITERATOR OPERATOR OVERLOADS--------------------------------------------------

// 	template< class Iterator1, class Iterator2 >
// 	bool operator==( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() == rhs.base());
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator!=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() != rhs.base());
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator<( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() > rhs.base());
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator<=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() >= rhs.base());
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator>( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() < rhs.base());
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator>=( const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs ) {
// 		return (lhs.base() <= rhs.base());
// 	}

//---------------REVERSE ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename T1, typename T2>
	bool operator==(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
				return (lhs.base() == rhs.base());	
	}

	template<typename T1, typename T2>
	bool operator!=(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<=(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>=(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() >= rhs.base());
	}

//---------------REVERSE ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

	template<typename T>
	bool operator==(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename T>
	bool operator!=(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	bool operator<(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	bool operator<=(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T>
	bool operator>(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	bool operator>=(const reverse_vector_iterator<T> &lhs, const reverse_vector_iterator<T> &rhs) {
		return (lhs.base() >= rhs.base());
	}

} //namespace end

#endif