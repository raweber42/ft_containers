/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:57 by raweber           #+#    #+#             */
/*   Updated: 2022/11/29 08:32:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "BST.hpp"
// #include "map.hpp"
// #include <iterator>

namespace ft {

//######################################################################
//######################## MAP ITERATOR ################################
//######################################################################

	template<typename Key, typename T>
	class map_iter {

//---------------MAP ITERATOR TYPEDEFS (iterator traits)---------------------------------
		public:
			typedef bidirectional_iterator_tag								iterator_category;
			typedef pair<const Key, T>										value_type;
			//###### HEEEREEEEE // typedef typename map<Key, T>::Node*								node_pointer;
			typedef typename BST<Key, T>::Node*		node_pointer;

//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------

		public:
		
			map_iter(void) : m_current_ptr(NULL) {}
			
			map_iter(node_pointer ptr) : m_current_ptr(ptr) {}
			
			// //below added for const/non-const
			// template<typename _T>
			// map_iter(const map_iter<_T, typename ft::enable_if<ft::are_same<_T, typename Node::pointer>::value, Node>::type>& copy) : m_ptr(copy.base()) , m_current(m_ptr.getRoot()) {}
			// //end addition
			
			map_iter(const map_iter &src) : m_current_ptr(src.m_current_ptr) {}
			
			~map_iter() {}
	
//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			// pointer base() const { return (m_ptr); }

//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			map_iter& operator=(map_iter const &rhs) {
				m_current_ptr = rhs.m_current_ptr;
				return (*this);
			}
			
			value_type &operator*(void) const { return (*m_current_ptr); }

			value_type *operator->(void) const { return (m_current_ptr); }
			
			// map_iter &operator++(void) {
			// 	m_ptr++;
			// 	return (*this);
			// }
			
			// map_iter operator++(int) {
			// 	map_iter ret(*this);
			// 	m_ptr++;
			// 	return (ret);
			// }

			// map_iter &operator--(void) {
			// 	m_ptr--;
			// 	return (*this);
			// }
			
			// map_iter operator--(int) {
			// 	map_iter ret(*this);
			// 	m_ptr--;
			// 	return (ret);
			// }

		protected:
			node_pointer	m_current_ptr;
	};

	//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename T1, typename T2, typename Node>
	bool operator==(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
				return (lhs.base() == rhs.base());	
	}

	template<typename T1, typename T2, typename Node>
	bool operator!=(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator<(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator<=(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator>(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2, typename Node>
	bool operator>=(const map_iter<T1, Node> &lhs, const map_iter<T2, Node> &rhs) {
		return (lhs.base() >= rhs.base());
	}

//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> SAME ITERATOR TYPE----------------------------------------

	template<typename T, typename Node>
	bool operator==(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename T, typename Node>
	bool operator!=(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename Node>
	bool operator<(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename Node>
	bool operator<=(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename Node>
	bool operator>(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T, typename Node>
	bool operator>=(const map_iter<T, Node> &lhs, const map_iter<T, Node> &rhs) {
		return (lhs.base() >= rhs.base());
	}
}