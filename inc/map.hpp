/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:32 by raweber           #+#    #+#             */
/*   Updated: 2022/11/24 16:23:36 by raweber          ###   ########.fr       */
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
			//HERE

	}


}
#endif