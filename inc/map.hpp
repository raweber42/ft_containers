/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:32 by raweber           #+#    #+#             */
/*   Updated: 2022/11/24 17:13:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include "utils.hpp"

namespace ft {
	

	template< typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<std::pair<const Key, T> > >
	class map {

		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef T*								pointer;
			typedef const T*						const_pointer;
			// typedef map_iterator<???>				iterator;
			// typedef const_map_iterator<???>			const_iterator;
			// typedef reverse_map_iterator<???>		reverse_iterator;
			// typedef const_reverse_map_iterator<???>	const_reverse_iterator;

			// class value_compare {
				
			// 	typedef bool			result_type;
			// 	typedef value_type		first_argument_type;
			// 	typedef value_type		second_argument_type;
			// }


//---------------------------CONSTRUCTORS---------------------------------------//


			map();
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			map( const map& other );


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~map(void);


//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


			map& operator=( const map& other );


//-------------------------------GET ALLOCATOR-----------------------------------------------//


			allocator_type get_allocator() const;


//---------------------------ELEMENT ACCESS----------------------------------------//
			

			T& at( const Key& key );

			const T& at( const Key& key ) const;

			T& operator[]( const Key& key );


//---------------------------ITERATOR FUNCTIONS----------------------------------------//


			iterator begin();

			const_iterator begin() const;

			iterator end();

			const_iterator end() const;

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

			const_reverse_iterator rend() const;


//---------------------------CAPACITY----------------------------------------//
			

			bool empty() const;

			size_type size() const;

			size_type max_size() const;


//---------------------------MODIFIERS----------------------------------------//


			void clear();
			
			std::pair<iterator, bool> insert( const value_type& value );

			iterator insert( iterator pos, const value_type& value );

			template< class InputIt >
			void insert( InputIt first, InputIt last );

			iterator erase( iterator pos );

			iterator erase( iterator first, iterator last );

			size_type erase( const Key& key );

			void swap( map& other );

		
//---------------------------LOOKUP----------------------------------------//

			size_type count( const Key& key ) const;

			iterator find( const Key& key );

			const_iterator find( const Key& key ) const;

			std::pair<iterator,iterator> equal_range( const Key& key );

			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

			iterator lower_bound( const Key& key );

			const_iterator lower_bound( const Key& key ) const;

			iterator upper_bound( const Key& key );

			const_iterator upper_bound( const Key& key ) const;


//---------------------------OBSERVERS----------------------------------------//

			key_compare key_comp() const;

			ft::map::value_compare value_comp() const;

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