/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/12/16 16:50:11 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "iterator_traits.hpp"

namespace ft {
	
//######################################################################
//######################## VECTOR ITERATOR #############################
//######################################################################

	template<typename T, typename Container>
	class vector_iterator {
	
//---------------VECTOR ITERATOR TYPEDEFS (iterator traits)---------------------------------
	
	
		public:
			typedef T														iterator_type;
			typedef typename ft::iterator_traits<T>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<T>::value_type				value_type;
			typedef typename ft::iterator_traits<T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<T>::pointer				pointer;
			typedef typename ft::iterator_traits<T>::reference				reference;


//---------------VECTOR ITERATOR CONSTRUCTORS-----------------------------------------------


		public:
			vector_iterator(void) : _ptr(NULL) {}
			vector_iterator(pointer ptr) : _ptr(ptr) {}
			//below added for const/non-const
			template<typename _T>
			vector_iterator(const vector_iterator<_T, typename ft::enable_if<ft::are_same<_T, typename Container::pointer>::value, Container>::type>& copy) : _ptr(copy.base()) {}		
			//end addition
			vector_iterator(const vector_iterator &copy) : _ptr(copy.base()) {}
			~vector_iterator() {}


//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------

			
			pointer base() const { return (_ptr); }


//---------------VECTOR ITERATOR OPERATOR OVERLOADS----------------------------------------


			vector_iterator& operator=(vector_iterator const &rhs) {
				_ptr = rhs._ptr;
				return (*this);
			}
			
			reference operator*(void) const { return (*_ptr); }

			pointer operator->(void) const { return (_ptr); }

			reference operator[](const difference_type &offset) const { return(*(_ptr + offset)); }
			
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

			vector_iterator  operator-(difference_type offset) const {

				return (vector_iterator(_ptr - offset));
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


//---------------VECTOR ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename T1, typename T2, typename Container>
	bool operator==(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() == rhs.base());	
	}

	template<typename T1, typename T2, typename Container>
	bool operator!=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
		return (!(lhs.base() == rhs.base()));
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

	template<typename T2, typename Container>
	vector_iterator<T2, Container> operator+(typename vector_iterator<T2, Container>::difference_type offset, const vector_iterator<T2, Container> &rhs) {

		return (vector_iterator<T2, Container>(rhs.base() + offset));
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator+(const vector_iterator<T1, Container> &lhs, typename vector_iterator<T1, Container>::difference_type offset) {

		return (vector_iterator<T1, Container>(lhs.base() + offset));
	}

	template<typename T2, typename Container>
	vector_iterator<T2, Container> operator-(typename vector_iterator<T2, Container>::difference_type offset, const vector_iterator<T2, Container> &rhs) {

		return (vector_iterator<T2, Container>(rhs.base() - offset));
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator-(const vector_iterator<T1, Container> &lhs, typename vector_iterator<T1, Container>::difference_type offset) {

		return (vector_iterator<T1, Container>(lhs.base() - offset));
	}


//---------------VECTOR ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> FOR SIZE_TYPE CALCULATIONS----------------------------------------


	template<typename TPtr1, typename TPtr2, typename Container>
	typename ft::iterator_traits<TPtr1>::difference_type operator-(const vector_iterator<TPtr1, Container>& lhs, const vector_iterator<TPtr2, Container>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename TPtr, typename Container>
	typename ft::iterator_traits<TPtr>::difference_type operator-(const vector_iterator<TPtr, Container>& lhs, const vector_iterator<TPtr, Container>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename TPtr1, typename TPtr2, typename Container>
	typename ft::iterator_traits<TPtr1>::difference_type operator+(const vector_iterator<TPtr1, Container>& lhs, const vector_iterator<TPtr2, Container>& rhs) {
		return lhs.base() + rhs.base();
	}

	template<typename TPtr, typename Container>
	typename ft::iterator_traits<TPtr>::difference_type operator+(const vector_iterator<TPtr, Container>& lhs, const vector_iterator<TPtr, Container>& rhs) {
		return lhs.base() + rhs.base();
	}


//######################################################################
//#################### REVERSE ITERATOR ################################
//######################################################################


	template <typename vector_iterator>
	class reverse_vector_iterator {
		
//---------------VECTOR REVERSE_ITERATOR TYPEDEFS (iterator traits)------------------------------------

		public:
			typedef vector_iterator									iterator_type;
			typedef typename vector_iterator::iterator_category		iterator_category;
			typedef typename vector_iterator::value_type			value_type;
			typedef typename vector_iterator::difference_type		difference_type;
			typedef typename vector_iterator::pointer				pointer;
			typedef typename vector_iterator::reference				reference;


//---------------VECTOR REVERSE_ITERATOR CONSTRUCTORS--------------------------------------------------


		public:
			reverse_vector_iterator(void) : _base() {} // changed from iterator_type() to _base()
			
			reverse_vector_iterator(iterator_type x) : _base(x) {}
			
			reverse_vector_iterator(const reverse_vector_iterator& other) : _base(other.base()) {}

			template< class U >
			reverse_vector_iterator(const reverse_vector_iterator<U>& other) : _base(other.base()) {}

			reverse_vector_iterator& operator=(const reverse_vector_iterator& rhs) {
				_base = rhs.base();
				return (*this);
			}


//---------------BASE FUNCTION--------------------------------------------------------------

			
			iterator_type base() const { return (_base); }


//---------------VECTOR (MEMBER) REVERSE_ITERATOR OPERATOR OVERLOAD--------------------------------------------------

			
			reference operator*(void) const { 
				
				// iterator_type tmp(_base - 1);
				// return (*(tmp));
				return *iterator_type(this->_base - 1);
			}

			pointer operator->(void) const { return ( &(operator*()) ); }

			reference operator[](const difference_type &offset) const { 
				
				// return(base()[offset - 1]); 
				return (*(*this + offset)); // removed '-1' here
			}

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

			reverse_vector_iterator  operator-(difference_type offset) const {

				return (reverse_vector_iterator(_base + offset)); // added +1
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


//---------------VECTOR REVERSE ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------


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
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<=(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>=(const reverse_vector_iterator<T1> &lhs, const reverse_vector_iterator<T2> &rhs) {
		return (lhs.base() <= rhs.base());
	}

//---------------VECTOR REVERSE ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> FOR SIZE_TYPE CALCULATIONS----------------------------------------


	template<typename T1>
	reverse_vector_iterator<T1> operator+(const reverse_vector_iterator<T1> &lhs, typename reverse_vector_iterator<T1>::difference_type offset) {

		return (reverse_vector_iterator<T1>(lhs.base() - offset));
	}

	template<typename T2>
	reverse_vector_iterator<T2> operator+(typename reverse_vector_iterator<T2>::difference_type offset, const reverse_vector_iterator<T2> &rhs) {

		return (reverse_vector_iterator<T2>(rhs.base() - offset));
	}
	
	template<typename T2>
	reverse_vector_iterator<T2> operator-(typename reverse_vector_iterator<T2>::difference_type offset, const reverse_vector_iterator<T2> &rhs) {

		return (reverse_vector_iterator<T2>(rhs.base() + offset));
	}

	template<typename T1>
	reverse_vector_iterator<T1> operator-(const reverse_vector_iterator<T1> &lhs, typename reverse_vector_iterator<T1>::difference_type offset) {

		return (reverse_vector_iterator<T1>(lhs.base() + offset));
	}

	template<typename Iterator1, typename Iterator2>
	typename reverse_vector_iterator<Iterator1>::difference_type operator-(const reverse_vector_iterator<Iterator1>& lhs, const reverse_vector_iterator<Iterator2>& rhs) {
		return (rhs.base() - lhs.base());
	}

} //namespace end
