/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:32 by raweber           #+#    #+#             */
/*   Updated: 2022/12/08 15:05:22 by raweber          ###   ########.fr       */
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
			
			class value_compare {
				
				friend class map;
				
				protected:
					key_compare m_comp;
					value_compare(Compare c) : m_comp(c) {}
				
				public:
					typedef bool			result_type;
					typedef value_type		first_argument_type;
					typedef value_type		second_argument_type;
					
					bool operator()( const value_type& lhs, const value_type& rhs ) const {
						return (m_comp(lhs.first, rhs.first));
					}
			};


//---------------------------CONSTRUCTORS---------------------------------------//
			
			
			explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc())
				: m_comp(comp), m_alloc(alloc) {}
			
			template< class InputIt >
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) 
				: m_comp(comp), m_alloc(alloc) {
				
				InputIt tmp = first;
				while (tmp != last)
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
				m_tree.deleteAll();
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
				
				return iterator(m_tree.end(), m_tree.m_tree_root);
			}

			const_iterator end() const {
				
				return const_iterator(m_tree.end(), m_tree.m_tree_root);
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


			void clear() {
				
				m_tree.deleteAll();
				m_tree.m_tree_size = 0;
			}
			
			ft::pair<iterator, bool> insert( const value_type& value ) {
			
				ft::pair<iterator,bool> tmp;
				
				if (m_tree.sameKeyExists(value.first, m_tree.m_tree_root))
					tmp.second = false;
				else
					tmp.second = true;
				tmp.first = iterator(m_tree.insertNode(value), m_tree.m_tree_root);
				return (tmp);
			}

			iterator insert( iterator hint, const value_type& value ) {
				
				(void) hint; // does not make much sense to use in map
				iterator it = find(value.first);
				if (it != end())
					return (it);
				return (iterator(m_tree.insertNode(value), m_tree.m_tree_root));
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ) {
				
				while(first != last)
					insert(*first++);
			}

			void erase( iterator pos ) {
				
				m_tree.erase((*pos).first);
				m_tree.m_tree_size--;
			}

			void erase( iterator first, iterator last ) {
				
				int counter = 0;
				iterator tmp = first;
				while (tmp != last)
				{
					tmp++;
					counter++;
				}
				last--;
				for (int i = 0; i < counter; i++) {

					key_type tmp = (*last).first;
					erase(tmp);
				}
			}

			size_type erase( const Key& key ) {
				
				node_pointer tmp = m_tree.findKey(key);
				if (tmp)
				{
					m_tree.erase(key);
					m_tree.m_tree_size--;
					return (1);	
				}
				return (0);
			}

			void swap( map& x ) {
				
				if (this == &x) return;
				this->m_tree.swap(x.m_tree);
			}


			// void swap( map& other ) {

			// 	if (this == &other) return;
			// 	std::swap(this->m_tree.getRoot(), other.m_tree.getRoot());
			// 	std::swap(this->m_tree.m_tree_size, other.m_tree.m_tree_size);
				// key_compare	tmp_comp = m_comp;
				// alloc_type	tmp_alloc =	m_alloc;
				// binary_tree	tmp_tree = m_tree;

				// m_comp = other.m_comp;
				// m_alloc = other.m_alloc;
				// m_tree = other.m_tree;

				// other.m_comp = tmp_comp;
				// other.m_alloc = tmp_alloc;
				// other.m_tree = tmp_tree;
			// }

		
//---------------------------LOOKUP----------------------------------------//


			size_type count(const key_type& key) const {
				
				if (m_tree.sameKeyExists(key, m_tree.getRoot()))
					return (1);
				else
					return (0);
			}

			iterator find(const key_type& key) {

				node_pointer tmp = m_tree.findKey(key);
				if (tmp)
					return iterator(tmp, m_tree.m_tree_root);
				else
					return iterator(NULL, m_tree.m_tree_root);
			}

			const_iterator find( const key_type& key ) const {
				
				node_pointer tmp = m_tree.findKey(key);
				if (tmp)
					return const_iterator(tmp, m_tree.m_tree_root);
				else
					return const_iterator(NULL, m_tree.m_tree_root);
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				
				return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				
				return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}

			iterator lower_bound(const Key& key) {

				iterator it = begin();
				for (; it != end(); it++)
				{
					if (!m_comp(it.base()->content.first, key))
						break;
				}
				return (it);
			}

			const_iterator lower_bound( const Key& key ) const {

				const_iterator it = begin();
				for (; it != end(); it++)
				{
					if (!m_comp(it.base()->content.first, key))
						break;
				}
				return (it);
			}

			iterator upper_bound( const Key& key ) {
				
				iterator it = begin();
				for (; it != end(); it++)
				{
					if (m_comp(key, it.base()->content.first))
						return (it);
				}
				return (end());
			}

			const_iterator upper_bound( const Key& key ) const {
				
				const_iterator it = begin();
				for (; it != end(); it++)
				{
					if (m_comp(key, it.base()->content.first))
						return (it);
				}
				return (end());
			}


//---------------------------OBSERVERS----------------------------------------//


			key_compare key_comp() const { return (m_comp); }

			value_compare value_comp() const { return (value_compare(m_comp)); }


//---------------------------PRIVATE MEMBERS----------------------------------------//

			
		public:
			
			key_compare						m_comp;
			alloc_type						m_alloc;
			binary_tree						m_tree;
	};


//---------------------------SWAP (non-member)--------------------------------//


	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ) {
		
		lhs.swap(rhs);
	}
	

//---------------------------RELATIONAL OPERATORS (non-member)--------------------------------//

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		
		return (!(lhs == rhs));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {

		return (!(rhs < lhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {

		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		
		return (!(lhs < rhs));
	}
}


#endif
