/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:25 by raweber           #+#    #+#             */
/*   Updated: 2022/11/12 17:12:30 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft
{
	template< typename T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef T&											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			// typedef iterator;				// ADD
			// typedef const_iterator;			// ADD
			// typedef std::reverse_iterator<iterator>			reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			
			//---------------------------CONSTRUCTORS---------------------------------------//
			
			
			explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0) {
				
				_vec_ptr = _alloc.allocate(0);			
			}
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n) {
				
				_vec_ptr = _alloc.allocate(n);	
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&(_vec_ptr[i]), val);
			}
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(last - first), _capacity(last - first) {
				
				_vec_ptr = _alloc.allocate(last - first);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vec_ptr[i], *first++);
			}

			vector(const vector& rhs)
			: _alloc(rhs._alloc), _size(rhs._size), _capacity(rhs._capacity) {
				
				_vec_ptr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_vec_ptr[i], *(rhs[i]));
			}

			//---------------------------DESTRUCTOR----------------------------------------//
			
			~vector(void) {
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				_alloc.deallocate(_vec_ptr, _capacity);
			}
			
			//---------------------------OPERATOR=----------------------------------------//

			reference operator=(const vector& rhs);
				// do this later! (assign)
			

			//---------------------------ITERATORS----------------------------------------//
			
			// iterator begin();const_iterator begin() const;
			// iterator end();const_iterator end() const;
			// reverse_iterator rbegin();const_reverse_iterator rbegin() const;
			// reverse_iterator rend();const_reverse_iterator rend() const;
			
			//---------------------------CAPACITY----------------------------------------//
			bool empty() const;
			size_type size() const { return(_size); };
			size_type max_size() const;
			void reserve( size_type new_cap );
			size_type capacity() const;
			//---------------------------ELEMENT ACCESS----------------------------------------//
			reference at( size_type pos );

			reference operator[](unsigned int index) {
			
				return (_vec_ptr[index]);
			}

			const_reference operator[](unsigned int index) const {
			
				return (_vec_ptr[index]);
			}

			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			T* data();
			const T* data() const;

			
			//---------------------------MODIFIERS----------------------------------------//
			
			void assign( size_type count, const T& value );
			
			template< class InputIt >
			void assign( InputIt first, InputIt last );
			
			void push_back (const value_type& val);
			void pop_back();
			
			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);iterator erase (iterator first, iterator last);

			void swap (vector& x);			
			void clear();

			void resize (size_type n, value_type val = value_type());
			
		//--------------------------PRIVATE VARIABLES----------------------------------------//
		private:
			pointer			_vec_ptr;
			allocator_type	_alloc;
			size_t			_size;
			size_t			_capacity;
	};
	//---------------------------RELATIONAL OPERATORS (non-member)--------------------------------//
	template< class T, class Alloc >
	bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	template< class T, class Alloc >
	bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	template< class T, class Alloc >
	bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
				
	template< class T, class Alloc >
	bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	template< class T, class Alloc >
	bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	template< class T, class Alloc >
	bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	//---------------------------SWAP (non-member)--------------------------------//
	template< class T, class Alloc >
	void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );

} // namespace ft

// see bookmark page 484

// constructors: capacity = size?
#endif