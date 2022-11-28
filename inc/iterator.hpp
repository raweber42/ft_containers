/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:38:06 by raweber           #+#    #+#             */
/*   Updated: 2022/11/28 11:32:48 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "BST.hpp"
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
//######################## VECTOR ITERATOR #############################
//######################################################################

	template<typename T, typename Container>
	class vector_iterator {
	
//---------------VECTOR ITERATOR TYPEDEFS (iterator traits)---------------------------------
		public:
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
			vector_iterator(const vector_iterator &src) : _ptr(src._ptr) {}
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


//---------------VECTOR ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

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

//---------------VECTOR ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

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

//---------------VECTOR (MEMBER) REVERSE_ITERATOR OPERATOR OVERLOAD--------------------------------------------------
			
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

//---------------VECTOR REVERSE ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

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



//######################################################################
//######################## MAP ITERATOR ################################
//######################################################################

	template<typename T, typename BST>
	class map_iterator {

//---------------MY HELPER TYPEDEFS ----------------------------------------------

		// public:
			typedef typename BST::node_pointer								node_pointer;

//---------------MAP ITERATOR TYPEDEFS (iterator traits)---------------------------------
		public:
			typedef bidirectional_iterator_tag								iterator_category;
			typedef typename ft::iterator_traits<T>::value_type				value_type;
			typedef typename ft::iterator_traits<T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<T>::pointer				pointer;
			typedef typename ft::iterator_traits<T>::reference				reference;

//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------

		public:
			map_iterator(void) : m_ptr(NULL), m_current(NULL) {}
			map_iterator(node_pointer ptr) : m_ptr(ptr), m_current(m_ptr->getRoot()) {}
			// //below added for const/non-const
			// template<typename _T>
			// map_iterator(const map_iterator<_T, typename ft::enable_if<ft::are_same<_T, typename Node::pointer>::value, Node>::type>& copy) : m_ptr(copy.base()) , m_current(m_ptr.getRoot()) {}
			// //end addition
			// map_iterator(const map_iterator &src) : m_ptr(src.m_ptr), m_current(m_ptr->getRoot()) {}
			~map_iterator() {}
	
//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			pointer base() const { return (m_ptr); }

//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			map_iterator& operator=(map_iterator const &rhs) {
				m_ptr = rhs.m_ptr;
				m_current = rhs.m_current;
				return (*this);
			}
			
			reference operator*(void) const { return (*m_ptr); }

			pointer operator->(void) const { return (m_ptr); }
			
			// map_iterator &operator++(void) {
			// 	m_ptr++;
			// 	return (*this);
			// }
			
			// map_iterator operator++(int) {
			// 	map_iterator ret(*this);
			// 	m_ptr++;
			// 	return (ret);
			// }

			// map_iterator &operator--(void) {
			// 	m_ptr--;
			// 	return (*this);
			// }
			
			// map_iterator operator--(int) {
			// 	map_iterator ret(*this);
			// 	m_ptr--;
			// 	return (ret);
			// }

		protected:
			node_pointer	m_ptr;
			node_pointer	m_current;
	};

	//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename T1, typename T2, typename Node>
	bool operator==(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
				return (lhs.base() == rhs.base());	
	}

	template<typename T1, typename T2, typename Node>
	bool operator!=(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator<(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator<=(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator>(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator>=(const map_iterator<T1, Node> &lhs, const map_iterator<T2, Node> &rhs) {
		return (lhs.base() >= rhs.base());
	}

//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

	template<typename T, typename Node>
	bool operator==(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename T, typename Node>
	bool operator!=(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename Node>
	bool operator<(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename Node>
	bool operator<=(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename Node>
	bool operator>(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T, typename Node>
	bool operator>=(const map_iterator<T, Node> &lhs, const map_iterator<T, Node> &rhs) {
		return (lhs.base() >= rhs.base());
	}

} //namespace end

#endif