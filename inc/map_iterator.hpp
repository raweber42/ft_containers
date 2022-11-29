/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iteratorator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:57 by raweber           #+#    #+#             */
/*   Updated: 2022/11/29 09:40:47 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "BST.hpp"
#include "iterator_traits.hpp"

// #include "map.hpp"
// #include <iterator>

namespace ft {

//######################################################################
//######################## MAP ITERATOR ################################
//######################################################################

	template<typename Key, typename T>
	class map_iterator {

//---------------MAP ITERATOR TYPEDEFS (iterator traits)---------------------------------
		public:
			typedef bidirectional_iterator_tag			iterator_category;
			typedef pair<const Key, T>					value_type;
			//###### HEEEREEEEE // typedef typename map<Key, T>::Node*				node_pointer;
			typedef typename BST<Key, T>::Node*			node_pointer;

//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------

		public:
		
			map_iterator(void) : m_current_ptr(NULL), m_root_ptr(NULL) {}
			
			map_iterator(node_pointer ptr) : m_current_ptr(ptr), m_root_ptr(ptr->getRoot()) {}
			
			// //below added for const/non-const
			// template<typename _T>
			// map_iterator(const map_iterator<_T, typename ft::enable_if<ft::are_same<_T, typename Node::pointer>::value, Node>::type>& copy) : m_ptr(copy.base()) , m_current(m_ptr.getRoot()) {}
			// //end addition
			
			map_iterator(const map_iterator &src) : m_current_ptr(src.m_current_ptr), m_root_ptr(src.m_root_ptr) {}
			
			~map_iterator() {}
	
//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			// pointer base() const { return (m_ptr); }

//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			map_iterator& operator=(map_iterator const &rhs) {
				m_current_ptr = rhs.m_current_ptr;
				m_root_ptr = rhs.m_root_ptr;
				return (*this);
			}
			
			value_type &operator*(void) const { return (m_current_ptr->content); }

			value_type *operator->(void) const { return (m_current_ptr); }
			
			map_iterator &operator++(void) {
				
				m_current_ptr = m_current_ptr->plusPlus();
				// m_ptr++;
				return (*this);
			}
			
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
			node_pointer	m_current_ptr;
			node_pointer	m_root_ptr;
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
}