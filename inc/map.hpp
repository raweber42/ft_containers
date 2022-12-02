/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:32 by raweber           #+#    #+#             */
/*   Updated: 2022/12/02 17:56:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iterator>
#include <memory>
#include <iostream>
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

			typedef map_iterator<node_pointer, value_type>				iterator;
			typedef map_iterator<const_node_pointer, const_value_type>	const_iterator;
			typedef reverse_map_iterator<iterator>						reverse_iterator;
			typedef reverse_map_iterator<const_iterator>				const_reverse_iterator;
			
			// class value_compare {
				
			// 	typedef bool			result_type;
			// 	typedef value_type		first_argument_type;
			// 	typedef value_type		second_argument_type;
			// }


//---------------------------CONSTRUCTORS---------------------------------------//
			
			
			explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc())
				:  m_comp(comp), m_alloc(alloc) {}
			
			template< class InputIt >
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) 
				: m_comp(comp), m_alloc(alloc) {
				
				InputIt tmp = first;
				while(tmp != last)
					insert(*tmp++);
			}

			map( const map& other ) : m_comp(other.m_comp), m_alloc(other.m_alloc) {

				m_tree.deleteAll(m_tree.getRoot());
				m_tree.copyTree(other.m_tree.getRoot());
			}


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~map(void) { clear(); }


//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


			map& operator=( const map& rhs ) {
				
				
				m_alloc = rhs.m_alloc;
				m_comp = rhs.m_comp;
				m_tree.clear();
				m_tree.copyTree(rhs.m_tree.getRoot());

				return (*this);
			}


//-------------------------------GET ALLOC-----------------------------------------------//


			alloc_type get_allocator(void) const { return m_alloc; }


//---------------------------ELEMENT ACCESS----------------------------------------//
			

			mapped_type& at( const key_type& key ) {
				
				iterator tmp = find(key);
				if (tmp.base())
					return ((*tmp).second);
				else
					throw std::out_of_range("Invalid key for 'at()'");
			}

			const mapped_type& at( const key_type& key ) const {

				iterator tmp = find(key);
				if (tmp.base())
					return ((*tmp).second);
				else
					throw std::out_of_range("Invalid key for 'at()'");
			}

			mapped_type& operator[](const key_type& key) {
				
				iterator tmp = find(key);
				if (!tmp.base())
				{
					insert(value_type(key, mapped_type()));
				}
				tmp = find(key);
				return ((*tmp).second);
			}


//---------------------------ITERATOR FUNCTIONS----------------------------------------//


			iterator begin() {
				
				return iterator(m_tree.begin(), m_tree.m_tree_root);
			}

			const_iterator begin() const {
				
				return const_iterator(m_tree.begin(), m_tree.m_tree_root);
			}

			iterator end() {
				
				return iterator(NULL, m_tree.m_tree_root);
				// return iterator(m_tree.end(), m_tree.m_tree_root);
			}

			const_iterator end() const {
				
				return const_iterator(NULL, m_tree.m_tree_root);
				// return const_iterator(m_tree.end(), m_tree.m_tree_root, 0);
			}

			reverse_iterator rbegin() {
				
				return reverse_iterator(m_tree.end(), m_tree.m_tree_root);
			}

			const_reverse_iterator rbegin() const {
				
				return const_reverse_iterator(m_tree.end(), m_tree.m_tree_root);
			}

			reverse_iterator rend() {
				
				return reverse_iterator(m_tree.begin(), m_tree.m_tree_root);
			}

			const_reverse_iterator rend() const {
				
				return const_reverse_iterator(m_tree.begin(), m_tree.m_tree_root);
			}


//---------------------------CAPACITY----------------------------------------//
			

			bool empty() const { return (m_tree.empty()); }

			size_type size() const { return (m_tree.size()); }

			size_type max_size() const {
				
				return m_tree.max_size();
			}


//---------------------------MODIFIERS----------------------------------------//


			void clear() { m_tree.deleteAll(); }
			
			ft::pair<iterator, bool> insert( const value_type& value ) {
			
				ft::pair<iterator,bool> tmp;
				
				if (m_tree.sameKeyExists(value.first, m_tree.m_tree_root))
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

			iterator insert( iterator hint, const value_type& value ) {
				
				(void) hint; // does not make much sense to use in map
				iterator it = find(value.first);
				if (it != end())
					return (it);
				return (iterator(m_tree.insertNode(&(m_tree.m_tree_root), value), m_tree.m_tree_root));
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ) {
				
				while(first != last)
					insert(*first++);
			}

			void erase( iterator pos ) {
				
				m_tree.erase((*pos).first, m_tree.getRoot());
				m_tree.m_tree_size--;
			}

			void erase( iterator first, iterator last ) {
				
				while (first != last) {

					key_type tmp = (*first).first;
					first++;
					erase(tmp);
				}
			}

			size_type erase( const Key& key ) {
				
				node_pointer tmp = m_tree.findKey(key, m_tree.m_tree_root);
				if (tmp)
				{
					erase(iterator(tmp, m_tree.getRoot()));
					return (1);	
				}
				return (0);
			}

			void swap( map& other ) {

				key_compare	tmp_comp = m_comp;
				alloc_type	tmp_alloc =	m_alloc;
				binary_tree	tmp_tree = m_tree;

				m_comp = other.m_comp;
				m_alloc = other.m_alloc;
				m_tree = other.m_tree;

				other.m_comp = tmp_comp;
				other.m_alloc = tmp_alloc;
				other.m_tree = tmp_tree;
			}

		
//---------------------------LOOKUP----------------------------------------//


			size_type count(const key_type& key) const {
				
				if (m_tree.sameKeyExists(key, m_tree.getRoot()))
					return (1);
				else
					return (0);
			}

			iterator find(const key_type& key) {

				node_pointer tmp = m_tree.findKey(key, m_tree.m_tree_root);
				if (tmp)
					return iterator(tmp, m_tree.m_tree_root);
				else
					return iterator(NULL, m_tree.m_tree_root);
			}

			const_iterator find( const key_type& key ) const {
				
				node_pointer tmp = m_tree.findKey(key, m_tree.m_tree_root);
				if (tmp)
					return const_iterator(tmp, m_tree.m_tree_root);
				else
					return const_iterator(NULL, m_tree.m_tree_root);
			}

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