/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:25 by raweber           #+#    #+#             */
/*   Updated: 2022/11/11 14:37:39 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
	template< class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			// typedef iterator;				// ADD
			// typedef const_iterator;			// ADD
			// typedef std::reverse_iterator<iterator>			reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			

			// CONSTRUCTORS
			explicit vector(const allocator_type &alloc = allocator_type())
					:;
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			
		private:
	};
} // namespace ft

// see bookmark page 484


#endif