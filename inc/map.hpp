/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:32 by raweber           #+#    #+#             */
/*   Updated: 2022/11/30 18:07:51 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <functional>
#include "utils.hpp"
#include "map_iterator.hpp"


namespace ft {
	
	template< typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key, T> > >
	class map {

		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef pair<const Key, T>									value_type;
			typedef const pair<const Key, T>							const_value_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef Compare												key_compare;
			typedef Alloc												alloc_type;
			typedef typename Alloc::reference							reference;
			typedef typename Alloc::const_reference						const_reference;
			typedef typename Alloc::pointer								pointer;
			typedef typename Alloc::const_pointer						const_pointer;
			typedef BST<Key, T, Compare, Alloc>							binary_tree;
			typedef typename binary_tree::node_pointer					node_pointer;
			typedef typename binary_tree::const_node_pointer			const_node_pointer;

			// typedef map_iterator<Key, T>								iterator;
			typedef map_iterator<node_pointer, value_type>				iterator;
			typedef map_iterator<const_node_pointer, const_value_type>	const_iterator;
			typedef reverse_vector_iterator<iterator>					reverse_iterator;
			typedef reverse_vector_iterator<const_iterator>				const_reverse_iterator;
			
			
			
			// typedef map_iterator<const_pointer, map<T, Alloc> >			const_iterator;
			// typedef reverse_map_iterator<???>		reverse_iterator;
			// typedef const_reverse_map_iterator<???>	const_reverse_iterator;

			// class value_compare {
				
			// 	typedef bool			result_type;
			// 	typedef value_type		first_argument_type;
			// 	typedef value_type		second_argument_type;
			// }


//---------------------------CONSTRUCTORS---------------------------------------//
			
			explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc())
				:  m_comp(comp), m_alloc(alloc) {}
			
			// template< class InputIt >
			// map(InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) 
				// : m_comp(comp), m_alloc(alloc) { // set m_tree_root & _size!
				
			// }

			// map( const map& other ) : m_comp(other.m_comp), m_alloc(other.m_alloc) {
			// 	// make proper tree copy here with m_alloc !
			//	// set m_tree_root & _size!
			// }


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~map(void) {} // destroy tree!


//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


			// map& operator=( const map& rhs ) {
				
			// 	if (m_tree != rhs.m_tree)
			// 	{
			// 		m_alloc = rhs.m_alloc;
			// 		m_comp = rhs.m_comp;
			// 		// something like assign here
			// 	}
			// 	return (*this);
			// }


//-------------------------------GET ALLOC-----------------------------------------------//


			// alloc_type get_alloc() const;


//---------------------------ELEMENT ACCESS----------------------------------------//
			

			// T& at( const Key& key ); //use find

			// const T& at( const Key& key ) const; //use find

			// T& operator[]( const Key& key ); //use find


//---------------------------ITERATOR FUNCTIONS----------------------------------------//


			iterator begin() {
				
				return iterator(m_tree.begin(), m_tree.m_tree_root);
			}

			const_iterator begin() const {
				
				return const_iterator(m_tree.begin(), m_tree.m_tree_root);
			}

			iterator end() {
				
				return iterator(m_tree.end(), m_tree.m_tree_root);
			}

			const_iterator end() const {
				
				return const_iterator(m_tree.end(), m_tree.m_tree_root);
			}

			reverse_iterator rbegin() {
				
				return reverse_iterator(m_tree.end(), m_tree_root);
			}

			const_reverse_iterator rbegin() const {
				
				return const_reverse_iterator(m_tree.end(), m_tree_root);
			}

			reverse_iterator rend() {
				
				return reverse_iterator(m_tree.begin(), m_tree_root);
			}

			const_reverse_iterator rend() const {
				
				return const_reverse_iterator(m_tree.begin(), m_tree_root);
			}


//---------------------------CAPACITY----------------------------------------//
			

			bool empty() const { return (m_tree.empty()); }

			size_type size() const { return (m_tree.empty()); }

			// size_type max_size() const {
				
			// 	std::allocator<Node<Key, T> > tmp;
			// 	return tmp.max_size();
			// } // CHECK THIS THOROUGHLY!


//---------------------------MODIFIERS----------------------------------------//


			// void clear();
			ft::pair<iterator, bool> insert( const value_type& value ) {
			
				ft::pair<iterator,bool> tmp;
				
				if (m_tree.sameKeyExists(m_tree.m_tree_root, value.first))
				{
					tmp.second = false;
				}
				else
				{
					tmp.second = true;
				}
				tmp.first = iterator(m_tree.insertNode(&(m_tree.m_tree_root), value), m_tree.m_tree_root);
				
				return (tmp);
			}

			// iterator insert( iterator pos, const value_type& value );

			// template< class InputIt >
			// void insert( InputIt first, InputIt last );

			// iterator erase( iterator pos );

			// iterator erase( iterator first, iterator last );

			// size_type erase( const Key& key );

			// void swap( map& other ) {

			// 	BinarySearchTree<Key, T> tmp_tree = m_tree;
			// 	key_compare tmp_comp = m_comp;
			// 	alloc_type tmp_alloc = m_alloc;
				
			// 	m_tree = other.m_tree;
			// 	m_comp = other.m_comp;
			// 	m_alloc = other.m_alloc;

			// 	other.m_tree = tmp_tree;
			// 	other.m_comp = tmp_comp;
			// 	other.m_alloc = tmp_alloc;
			// }

		
//---------------------------LOOKUP----------------------------------------//


			// size_type count( const Key& key ) const;
				// if find -> return 1, else -> return 0;

			// iterator find( const Key& key );

			// const_iterator find( const Key& key ) const;

			// std::pair<iterator,iterator> equal_range( const Key& key );

			// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

			// iterator lower_bound( const Key& key );

			// const_iterator lower_bound( const Key& key ) const;

			// iterator upper_bound( const Key& key );

			// const_iterator upper_bound( const Key& key ) const;


//---------------------------OBSERVERS----------------------------------------//


			// key_compare key_comp() const;

			// ft::map::value_compare value_comp() const;


//---------------------------PRIVATE MEMBERS----------------------------------------//

			
		public:
			
			key_compare						m_comp;
			alloc_type						m_alloc;
			binary_tree						m_tree;
			// Node							*m_tree_root;
			// size_type						m_tree_size;
			// std::allocator<Node>			m_node_alloc;
	};

//---------------------------RELATIONAL OPERATORS (non-member)--------------------------------//

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
}


#endif


// src/../inc/map.hpp:239:65: error: declaration of ‘ft::BST<Key, T, Compare, Alloc> ft::map<Key, T, Compare, Alloc>::BST’ changes meaning of ‘BST’ [-fpermissive]
// src/../inc/map.hpp:239:49: error: declaration of ‘ft::BST<Key, T> ft::map<Key, T, Compare, Alloc>::BST’ changes meaning of ‘BST’ [-fpermissive]