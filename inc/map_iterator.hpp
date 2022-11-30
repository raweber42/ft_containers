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

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

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

	template<typename node_pointer, typename value_type>
	class map_iterator {

//---------------MAP ITERATOR TYPEDEFS (iterator traits)---------------------------------
		
		public:
			typedef bidirectional_iterator_tag			iterator_category;
			//maggi change // typedef pair<const Key, T>					value_type;
			//maggi change // typedef typename node_pointer						node_pointer;

//---------------PROTECTED MEBER FUNCTION------------------------------------------------

		protected:
			node_pointer	m_current_ptr;
			node_pointer	m_root_ptr;

//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------

		public:

			map_iterator(void) : m_current_ptr(NULL), m_root_ptr(NULL) {}
			
			map_iterator(node_pointer ptr, node_pointer root_ptr) : m_current_ptr(ptr), m_root_ptr(root_ptr) {}
			
			// //below added for const/non-const
			template<typename n_ptr, typename v_type>
			map_iterator(const map_iterator<n_ptr, v_type> &copy) : m_current_ptr(copy.base()) , m_root_ptr(copy.getRootPtr()) {}
			// //end addition
			
			map_iterator(const map_iterator &src) : m_current_ptr(src.m_current_ptr), m_root_ptr(src.m_root_ptr) {}
			
			~map_iterator() {}
	
//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			node_pointer base() const { return (m_current_ptr); }

			node_pointer getRootPtr() const { return (m_root_ptr); }

//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			map_iterator& operator=(map_iterator const &rhs) {
				m_current_ptr = rhs.m_current_ptr;
				m_root_ptr = rhs.m_root_ptr;
				return (*this);
			}
			
			value_type &operator*(void) const { return (m_current_ptr->content); }

			value_type *operator->(void) const { return (m_current_ptr); }
			
			map_iterator &operator++(void) {
				
				m_current_ptr = plusPlus(m_current_ptr);
				return (*this);
			}
			
			map_iterator operator++(int) {
				
				map_iterator ret(*this);
				++(*this);
				return (ret);
			}

			map_iterator &operator--(void) {
				
				m_current_ptr = minusMinus(m_current_ptr);
				return (*this);
			}
			
			map_iterator operator--(int) {
				
				map_iterator ret(*this);
				--(*this);
				return (ret);
			}
		
		private:
			
			node_pointer plusPlus(node_pointer current) {

				node_pointer tmp;
				if (current == NULL)
				{
					tmp = m_root_ptr;
					while (tmp->left)
						tmp = tmp->left;
				}
				else if (current->right) // if right exists, go right once and left as long as possible
				{
					tmp = current->right;
					while (tmp->left)
						tmp = tmp->left;
				}
				else // go to parent: while parent is bigger -> go further up
				{
					tmp = current->parent;
					while (tmp != NULL && current == tmp->right)
					{
						current = tmp;
						tmp = tmp->parent;
					}
				}
				return (tmp);
			}

			node_pointer minusMinus(node_pointer current) {

				node_pointer tmp;
				if (current == NULL)
				{
					tmp = m_root_ptr;
					while (tmp->right)
						tmp = tmp->right;
				}
				else if (current->left) // if left exists, go left once and right as long as possible
				{
					tmp = current->left;
					while (tmp->right)
						tmp = tmp->right;
				}
				else // go to parent: while parent is smaller -> go further up
				{
					tmp = current->parent;
					while (tmp != NULL && current == tmp->left)
					{
						current = tmp;
						tmp = tmp->parent;
					}
				}
				return (tmp);
			}
	};

// //---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename n_ptr, typename v_type>
	bool operator==(const map_iterator<n_ptr, v_type> &lhs, const map_iterator<n_ptr, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr, typename v_type>
	bool operator!=(const map_iterator<n_ptr, v_type> &lhs, const map_iterator<n_ptr, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator==(const map_iterator<n_ptr1, v_type> &lhs, const map_iterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator!=(const map_iterator<n_ptr1, v_type> &lhs, const map_iterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator==(const map_iterator<n_ptr1, v_type1> &lhs, const map_iterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator!=(const map_iterator<n_ptr1, v_type1> &lhs, const map_iterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() != rhs.base());
	}



//######################################################################
//######################## REVERSE MAP ITERATOR ########################
//######################################################################

	template<typename map_iterator>
	class reverse_map_iterator {

//---------------MAP ITERATOR TYPEDEFS (iterator traits)---------------------------------
		
		public:

			typedef typename map_iterator::iterator_category			iterator_category;
			typedef typename map_iterator::node_pointer					node_pointer;
			typedef typename map_iterator::value_type					value_type;
			//maggi change // typedef pair<const Key, T>					value_type;
			//maggi change // typedef typename node_pointer						node_pointer;

// //---------------PROTECTED MEBER FUNCTION------------------------------------------------

		protected:
			iterator_type	_base; // HEEEEEEEEERREEE
// 			node_pointer	m_current_ptr;
// 			node_pointer	m_root_ptr;

//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------

		public:
			reverse_map_iterator(void) : iterator_type() {}
			
			reverse_map_iterator(node_pointer ptr, node_pointer root_ptr) : m_current_ptr(ptr), m_root_ptr(root_ptr) {}
			
			// //below added for const/non-const
			template<typename n_ptr, typename v_type>
			reverse_map_iterator(const reverse_map_iterator<n_ptr, v_type> &copy) : m_current_ptr(copy.base()) , m_root_ptr(copy.getRootPtr()) {}
			// //end addition
			
			reverse_map_iterator(const reverse_map_iterator &src) : m_current_ptr(src.m_current_ptr), m_root_ptr(src.m_root_ptr) {}
			
			~reverse_map_iterator() {}
	
//---------------BASE FUNCTION (HELPER)--------------------------------------------------------------
			
			node_pointer base() const { return (m_current_ptr); }

			node_pointer getRootPtr() const { return (m_root_ptr); }

//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			reverse_map_iterator& operator=(reverse_map_iterator const &rhs) {
				m_current_ptr = rhs.m_current_ptr;
				m_root_ptr = rhs.m_root_ptr;
				return (*this);
			}
			
			value_type &operator*(void) const { return (m_current_ptr->content); }

			value_type *operator->(void) const { return (m_current_ptr); }
			
			reverse_map_iterator &operator++(void) {
				
				m_current_ptr = plusPlus(m_current_ptr);
				return (*this);
			}
			
			reverse_map_iterator operator++(int) {
				
				reverse_map_iterator ret(*this);
				++(*this);
				return (ret);
			}

			reverse_map_iterator &operator--(void) {
				
				m_current_ptr = minusMinus(m_current_ptr);
				return (*this);
			}
			
			reverse_map_iterator operator--(int) {
				
				reverse_map_iterator ret(*this);
				--(*this);
				return (ret);
			}
		
		private:
			
			node_pointer plusPlus(node_pointer current) {

				node_pointer tmp;
				if (current == NULL)
				{
					tmp = m_root_ptr;
					while (tmp->left)
						tmp = tmp->left;
				}
				else if (current->right) // if right exists, go right once and left as long as possible
				{
					tmp = current->right;
					while (tmp->left)
						tmp = tmp->left;
				}
				else // go to parent: while parent is bigger -> go further up
				{
					tmp = current->parent;
					while (tmp != NULL && current == tmp->right)
					{
						current = tmp;
						tmp = tmp->parent;
					}
				}
				return (tmp);
			}

			node_pointer minusMinus(node_pointer current) {

				node_pointer tmp;
				if (current == NULL)
				{
					tmp = m_root_ptr;
					while (tmp->right)
						tmp = tmp->right;
				}
				else if (current->left) // if left exists, go left once and right as long as possible
				{
					tmp = current->left;
					while (tmp->right)
						tmp = tmp->right;
				}
				else // go to parent: while parent is smaller -> go further up
				{
					tmp = current->parent;
					while (tmp != NULL && current == tmp->left)
					{
						current = tmp;
						tmp = tmp->parent;
					}
				}
				return (tmp);
			}
	};

// //---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------

	template<typename n_ptr, typename v_type>
	bool operator==(const reverse_map_iterator<n_ptr, v_type> &lhs, const reverse_map_iterator<n_ptr, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr, typename v_type>
	bool operator!=(const reverse_map_iterator<n_ptr, v_type> &lhs, const reverse_map_iterator<n_ptr, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator==(const reverse_map_iterator<n_ptr1, v_type> &lhs, const reverse_map_iterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator!=(const reverse_map_iterator<n_ptr1, v_type> &lhs, const reverse_map_iterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator==(const reverse_map_iterator<n_ptr1, v_type1> &lhs, const reverse_map_iterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator!=(const reverse_map_iterator<n_ptr1, v_type1> &lhs, const reverse_map_iterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() != rhs.base());
	}



}

#endif