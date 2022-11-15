/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:25 by raweber           #+#    #+#             */
/*   Updated: 2022/11/15 15:16:41 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include "vec_iterator.hpp"

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
			typedef vector_iterator<vector<T, Alloc> >			iterator;
			typedef const vector_iterator<vector<T, Alloc> >	const_iterator;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			//---------------------------CONSTRUCTORS---------------------------------------//
			
			
			explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _vec_ptr(NULL) {};
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n) {
				
				_vec_ptr = _alloc.allocate(n);	
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&(_vec_ptr[i]), val);
			}
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0) {
				
				InputIterator tmp = first;
				while (tmp++ != last)
					_size++;
				_vec_ptr = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&(_vec_ptr[i]), *first++);
			}

			vector(const vector& rhs)
			: _alloc(rhs._alloc), _size(rhs._size), _capacity(rhs._capacity) {
				
				_vec_ptr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&(_vec_ptr[i]), rhs[i]);
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
			
			iterator begin(void) { return( iterator(_vec_ptr) ); }
			// const_iterator begin(void) const { return(_vec_ptr); }
			iterator end(void) { return( iterator(_vec_ptr + _size)); }
			// const_iterator end(void) const { return(_vec_ptr + _size); }
			
			// reverse_iterator rbegin(void);
			// const_reverse_iterator rbegin(void) const;
			// reverse_iterator rend(void);
			// const_reverse_iterator rend(void) const;
			
			//---------------------------CAPACITY----------------------------------------//
			
	 		bool empty(void) const { return(_size == 0); }
			
			size_type size(void) const { return(_size); }
			
			size_type max_size(void) const { return(_alloc.max_size()); }
			
			void reserve(size_type new_cap) {

				pointer tmp = NULL;
				if (new_cap > _alloc.max_size())
					throw std::length_error("Reserve: too big new cap");
				else if (new_cap < _capacity)
					return;
				try{
					tmp = _alloc.allocate(new_cap);
				} catch (std::bad_alloc &e) {
					throw e;
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&(tmp[i]), _vec_ptr[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				_alloc.deallocate(_vec_ptr, _capacity);
				_vec_ptr = tmp;
				_capacity = new_cap;
			}
			
			size_type capacity(void) const { return(_capacity); }
			
			//---------------------------ELEMENT ACCESS----------------------------------------//
			
			reference at(size_type pos) { return(_vec_ptr[pos]); }

			reference operator[](unsigned int index) { return(_vec_ptr[index]); }

			const_reference operator[](unsigned int index) const { return(_vec_ptr[index]); }

			reference front(void) { return(*_vec_ptr); }
			
			const_reference front(void) const { return(*_vec_ptr); }
			
			reference back(void) { return(_vec_ptr[_size - 1]); }
			
			const_reference back(void) const { return(*(_vec_ptr[_size - 1])); }
			
			T* data(void) { return(_vec_ptr); }
			
			const T* data(void) const { return(_vec_ptr); }
			
			//---------------------------MODIFIERS----------------------------------------//
			
			template< class InputIt >
			void assign(InputIt first, InputIt last);
			
			void assign(size_type count, const T& value);
			
			void push_back (const value_type& val);
				// user insert() here
			
			void pop_back(void) {
				
				if (!_size)
					return;
				_alloc.destroy(&(_vec_ptr[_size - 1]));
				_size--;
			}
			
			// TO FILL
			
			iterator insert (iterator position, const value_type& val) {

				if (!_vec_ptr) {
					_vec_ptr = _alloc.allocate(1);
					_alloc.construct(&_vec_ptr[0], val);
					_size = 1;
					_capacity = 1;
					std::cout << "HERE" << std::endl;
					return iterator(&_vec_ptr[0]);
				}
				if (_size == _capacity) { // has to reallocate
					if (!_capacity)
						MEM_realloc(1);
					else
						MEM_realloc(_capacity * 2);
				}
				// make a temp and insert val at the position, pushing the others to the back
				*position = val;
				// for (iterator it = position + 1; it < this->end(); it++)
				// 	*it = *(it + 1);
				return (position);
			}
			
			void insert (iterator position, size_type n, const value_type& val);
			
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			
			iterator erase (iterator position);
			
			iterator erase (iterator first, iterator last);

			void swap (vector& x);
			
			// TO FILL END

			void clear(void) {
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				_size = 0;
			}

			void resize(size_type n, value_type val = value_type()) {
				
				if (n > _size) {
					MEM_realloc(n, val);
					// pointer tmp = _alloc.allocate(n);
					// for (size_type i = 0; i < _size; i++)
					// 	_alloc.construct(&(tmp[i]), _vec_ptr[i]);
					// for (size_type i = _size; i < n; i++)
					// 	_alloc.construct(&(tmp[i]), val);
					// for (size_type i = 0; i < _size; i++)
					// 	_alloc.destroy(&(_vec_ptr[i]));
					// _alloc.deallocate(_vec_ptr, _capacity);
					// _vec_ptr = tmp;
					// _capacity = n;
				}
				else if (n < _size) {
					for (size_type i = n - 1; i < _size; i++)
						_alloc.destroy(&(_vec_ptr[i]));
				}
				_size = n;
			}
			
		//--------------------------PRIVATE VARIABLES----------------------------------------//
		private:
			pointer			_vec_ptr;
			allocator_type	_alloc;
			size_t			_size;
			size_t			_capacity;

			void MEM_realloc(size_type new_cap, value_type val = value_type()) {
				
				pointer tmp = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&(tmp[i]), _vec_ptr[i]);
				for (size_type i = _size; i < new_cap; i++)
					_alloc.construct(&(tmp[i]), val);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				_alloc.deallocate(_vec_ptr, _capacity);
				_vec_ptr = tmp;
				_capacity = new_cap;
			}
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
// when use _alloc and when Alloc ?? zurzeit beide in Benutzung
// why is 'multi' in Mikes resize?

#endif