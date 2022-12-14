/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:25 by raweber           #+#    #+#             */
/*   Updated: 2022/12/17 15:43:53 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include "colors.hpp"
#include "vector_iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template< typename T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef T&													reference;
			typedef const T&											const_reference;
			typedef T*													pointer;
			typedef const T*											const_pointer;
			typedef vector_iterator<pointer, vector<T, Alloc> >			iterator;
			typedef vector_iterator<const_pointer, vector<T, Alloc> >	const_iterator;
			typedef reverse_vector_iterator<iterator>					reverse_iterator;
			typedef reverse_vector_iterator<const_iterator>				const_reverse_iterator;
			

//---------------------------CONSTRUCTORS---------------------------------------//
			
			
			explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0) { _vec_ptr = NULL; };
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n) {
				
				_vec_ptr = _alloc.allocate(n);	
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&(_vec_ptr[i]), val);
			}
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _alloc(alloc), _size(0), _capacity(0) {
				
				InputIterator tmp = first;
				while (tmp != last)
				{
					_size++;
					tmp++;
				}	
				_vec_ptr = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&(_vec_ptr[i]), *first++);
				_capacity = _size;
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
			

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


			vector &operator=(const vector& rhs) {
				
				if (_vec_ptr != rhs._vec_ptr)
				{
					_alloc = rhs._alloc;
					assign(rhs.begin(), rhs.end());
				}
				return (*this);
			}


//-------------------------------GET ALLOC-----------------------------------------------//


			allocator_type get_allocator(void) const { return _alloc; }


//---------------------------ITERATOR FUNCTIONS----------------------------------------//

			
			iterator begin(void) { return( iterator(_vec_ptr) ); }

			const_iterator begin(void) const { return( const_iterator(_vec_ptr)); }

			iterator end(void) { return(iterator(_vec_ptr + _size)); }
			
			const_iterator end(void) const { return(const_iterator(_vec_ptr + _size)); }
			
			reverse_iterator rbegin(void) { return(reverse_iterator(_vec_ptr + _size )); }

			const_reverse_iterator rbegin(void) const { return(const_reverse_iterator(_vec_ptr + _size)); }

			reverse_iterator rend(void) { return(reverse_iterator(_vec_ptr)); }
			
			const_reverse_iterator rend(void) const { return(const_reverse_iterator(_vec_ptr)); }


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
				try {
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
	
			
			reference at(size_type pos) {
				
				if (pos >= _size)
					throw std::out_of_range("vector.at() call out of range");
				return(_vec_ptr[pos]);
			}

			const_reference at(size_type pos) const {
				
				if (pos >= _size)
					throw std::out_of_range("vector.at() call out of range");
				return(_vec_ptr[pos]);
			}

			reference operator[](unsigned int index) {
				
				if (index >= _size)
					throw std::out_of_range("vector[index] call out of range");
				return *(_vec_ptr + index);
			}

			const_reference operator[](unsigned int index) const {
				
				if (index >= _size)
					throw std::out_of_range("vector[index] call out of range");
				return *(_vec_ptr + index);
			}

			reference front(void) { return(*_vec_ptr); }
			
			const_reference front(void) const { return(*_vec_ptr); }
			
			reference back(void) { return(_vec_ptr[_size - 1]); }
			
			const_reference back(void) const { return(_vec_ptr[_size - 1]); }
			
			T* data(void) { return(_vec_ptr); }
			
			const T* data(void) const { return(_vec_ptr); }


//---------------------------MODIFIERS----------------------------------------//
			
			
			template< class InputIterator >
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				size_type new_size = 0;
				InputIterator tmp = first;
				while (tmp++ != last)
					new_size++;
				if (new_size > _capacity)
					MEM_realloc(new_size);
				for (size_type i = 0; i < new_size; i++)
					_alloc.construct(&(_vec_ptr[i]), *first++);
				if (new_size < _size)
				{
					for (size_type i = new_size; i < _size; i++)
						_alloc.destroy(&(_vec_ptr[i]));
				}
				_size = new_size;
			}
			
			void assign(size_type count, const T& value) {
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				if (_size < count)
					MEM_realloc(count);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&(_vec_ptr[i]), value);
				_size = count;
			}
				
			void push_back (const value_type& val) {
				if (!_capacity)
					MEM_realloc(1);
				if (_size == _capacity)
					MEM_realloc(_capacity * 2);
				_alloc.construct(_vec_ptr + _size, val);
				this->_size++;
			}
			
			void pop_back(void) {
				
				if (!_size)
					return;
				_alloc.destroy(&(_vec_ptr[_size - 1]));
				_size--;
			}
			
			iterator insert (iterator position, const value_type& val) {

				if (!_vec_ptr) {
					_vec_ptr = _alloc.allocate(1);
					_alloc.construct(&_vec_ptr[0], val);
					_size = 1;
					_capacity = 1;
					return iterator(&_vec_ptr[0]);
				}
				size_type pos_counter = 0;
				for (iterator it = this->begin(); it != position; it++)
					pos_counter++;
				if (_size == _capacity) { // has to reallocate
					if (!_capacity)
						MEM_realloc(1);
					else
						MEM_realloc(_capacity * 2);
				}
				for (size_type i = _size; i > pos_counter; i--)
				{
					_alloc.construct(&(_vec_ptr[i]), _vec_ptr[i - 1]);
					_alloc.destroy(&(_vec_ptr[i - 1]));
				}
				_alloc.construct(&(_vec_ptr[pos_counter]), val);
				_size++;
				return (iterator(&(_vec_ptr[pos_counter])));
			}
			
			void insert (iterator position, size_type n, const value_type& val) {
				
				if (!_vec_ptr)
				{
					_vec_ptr = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_vec_ptr[i], val);
					_size = n;
					_capacity = n;
					return;
				}
				size_type pos_counter = 0;
				for (iterator it = this->begin(); it != position; it++)
					pos_counter++;
				if (_size + n >= _capacity)
				{
					if (!_capacity)
						MEM_realloc(n);
					else
						MEM_realloc(_size + n);
				}
				for (size_type i = (_size + n - 1); i >= pos_counter + n; i--)
				{
					_alloc.construct(&(_vec_ptr[i]), _vec_ptr[i - n]);
					_alloc.destroy(&(_vec_ptr[i - n]));
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&(_vec_ptr[pos_counter + i]), val);
				_size += n;
			}
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				
				if (first == last)
					return;
				size_type tmp_size = 0;
				for (InputIterator tmp_it = first; tmp_it != last; tmp_it++)
					tmp_size++;
				
				pointer dup_start = NULL;
				pointer dup_end = NULL;
				size_type dup_capacity = 0;
				pointer pointer_pos = position.base();
				InputIterator it_first = first;
				InputIterator it_last= last;
				pointer tmp = _vec_ptr;

				if (_size + tmp_size >= _capacity)
				{
					dup_capacity = _size + tmp_size;
					if (_size + tmp_size > _capacity * 2)
						dup_capacity = _size + tmp_size;
					else
						dup_capacity = _capacity * 2;
					dup_start = _alloc.allocate(dup_capacity);
					dup_end = dup_start;
					try 
					{
						while(tmp != pointer_pos)
						{
							_alloc.construct(dup_end, *tmp);
							_alloc.destroy(tmp);
							dup_end++;
							tmp++;
						}
						while (it_first != it_last)
						{
							_alloc.construct(dup_end, *it_first);
							dup_end++;
							it_first++;
						}
						while (tmp != (_vec_ptr + _size))
						{
							_alloc.construct(dup_end, *tmp);
							_alloc.destroy(tmp);
							dup_end++;
							tmp++;
						}
					}
					catch (...)
					{
						while (dup_start != dup_end)
							_alloc.destroy(dup_end--);
						_alloc.destroy(dup_start);
						_alloc.deallocate(dup_start, dup_capacity);
						throw;
					}
					_alloc.deallocate(_vec_ptr, _capacity);
					_vec_ptr = dup_start;
					_capacity = dup_capacity;
					_size += tmp_size;
				}
				else {

					size_type pos_counter = 0;
					for (iterator it = this->begin(); it != position; it++)
						pos_counter++;

					for (size_type i = (_size + tmp_size - 1); i >= (pos_counter + tmp_size); i--)
					{
						_alloc.construct(&(_vec_ptr[i]), _vec_ptr[i - tmp_size]);
						_alloc.destroy(&(_vec_ptr[i - tmp_size]));
					}
					for (size_type i = 0; i < tmp_size; i++)
						_alloc.construct(&(_vec_ptr[pos_counter + i]), *first++);
					_size += tmp_size;
				}
				
				// RALF OLD NO EXCEPTION HANDLING
				// if (_size + tmp_size >= _capacity)
				// {
				// 	if (!_capacity)
				// 		MEM_realloc(tmp_size);
				// 	else
				// 		MEM_realloc(_size + tmp_size);
				// }
				// for (size_type i = (_size + tmp_size - 1); i >= (pos_counter + tmp_size); i--)
				// {
				// 	_alloc.construct(&(_vec_ptr[i]), _vec_ptr[i - tmp_size]);
				// 	_alloc.destroy(&(_vec_ptr[i - tmp_size]));
				// }
				// for (size_type i = 0; i < tmp_size; i++)
				// 	_alloc.construct(&(_vec_ptr[pos_counter + i]), *first++);
				// _size += tmp_size;
			}

			iterator erase (iterator position) {
				
				size_type pos_counter = 0;
				for (iterator it = this->begin(); it != position; it++)
					pos_counter++;
				_alloc.destroy(&(_vec_ptr[pos_counter]));
				if (pos_counter < (_size - 1))
				{
					for (size_type i = pos_counter; i < _size - 1; i++)
					{
						_alloc.construct(&(_vec_ptr[i]), _vec_ptr[i + 1]);
						_alloc.destroy(&(_vec_ptr[i + 1]));
					}
				}
				_size--;
				return (iterator(&(_vec_ptr[pos_counter])));
			}
			
			iterator erase (iterator first, iterator last) {
				
				iterator tmp = first;
				difference_type tmp_size = last - first;
				while (first != this->end())
				{
					_alloc.destroy(&(*first));
					if (last != this->end())
					{
						_alloc.construct(&(*first), *last);
						last++;
					}
					first++;
				}
				_size -= tmp_size;
				return (tmp);
			}

			void swap (vector& x) {
				
				pointer tmp_ptr = _vec_ptr;
				allocator_type tmp_alloc = _alloc;
				size_type tmp_size = _size;
				size_type tmp_capacity = _capacity;
				
				_vec_ptr = x._vec_ptr;
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				
				x._vec_ptr = tmp_ptr;
				x._alloc = tmp_alloc;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}

			void clear(void) {
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_vec_ptr[i]));
				_size = 0;
			}

			void resize(size_type n, value_type val = value_type()) {
				
				if (n > _capacity) {
					size_type tmp_capacity = _capacity;
					while (tmp_capacity < n)
						tmp_capacity *= 2;
					MEM_realloc(tmp_capacity, val);
				}
				else if (n > _size) {
					for (size_type i = _size; i < n; i++)
						_alloc.construct(&(_vec_ptr[i]), val);
					// _size = n;
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
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		
		return (!(lhs == rhs));
	}

	template< class T, class Alloc >
	bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
				
	template< class T, class Alloc >
	bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {

		return (!(rhs < lhs));
	}

	template< class T, class Alloc >
	bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		
		return (rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		
		return (!(lhs < rhs));
	}

} // namespace ft

//---------------------------SWAP (non-member)--------------------------------//

namespace std {

	template< class T, class Alloc >
	void swap(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ) {
		
		lhs.swap(rhs);
	}
} // namespace std

#endif