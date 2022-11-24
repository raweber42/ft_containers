/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:13:41 by raweber           #+#    #+#             */
/*   Updated: 2022/11/24 16:05:41 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

//------------ENABLE_IF--------------------------------------
	
	template<bool, typename>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {
		typedef T type;
	};


//------------FT::PAIR MEMBER FUNCTIONS------------------------------------

	template<typename T1, typename T2>
	struct pair {

		typedef T1	first_type;
		typedef T2	second_type;

		first_type		first;
		second_type		second;

		pair() : first(), second() {}
		
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
		
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		pair& operator=(const pair& pr) {
			
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

//------------FT::PAIR NON-MEMBER FUNCTIONS------------------------------------

	template< class T1, class T2 >
	std::pair<T1, T2> make_pair( T1 t, T2 u ) {
		return (pair<T1, T2>(t, u));
	}

	template< class T1, class T2 >
	bool operator==( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {
		
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template< class T1, class T2 >
	bool operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {
		
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {
		
		if (lhs.first < rhs.first)
			return (true);
		else if (lhs.first > rhs.first)
			return (false);
		else if (lhs.second < rhs.second)
			return (true);
		else
			return (false);
	}

	template< class T1, class T2 >
	bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {
		
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {
		
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) {

		return (!(lhs < rhs));
	}


//------------FT_BINARY_FUNCTION--------------------------------------

	template< typename Arg1, typename Arg2, typename Result >
	struct binary_function {
		typedef Arg1				first_argument_type;
		typedef Arg2				second_argument_type;
		typedef Result				result_type;
	};

//------------FT_LESS-------------------------------------------------


	template< typename T>
	struct less : binary_function<T, T, bool> {
		bool operator()(T x, T y) const { (return x < y) }
	};


//------------INTEGRAL_CONSTANT--------------------------------------


	template<typename T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() { return v; }
	};

	template<typename T, T v>
	const T integral_constant<T, v>::value;

	typedef integral_constant<bool, false> false_type;
	typedef integral_constant<bool, true> true_type;

	
//------------IS_INTEGRAL--------------------------------------


	template<typename T> struct is_integral : public false_type {};
	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<short> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long> : public true_type {};
	template<> struct is_integral<long long> : public true_type {};

	template<> struct is_integral<unsigned short> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long> : public true_type {};
	template<> struct is_integral<unsigned long long> : public true_type {};


//--------------COMPARE EQUALITY OF TYPES-------------------------

	
	template<typename, typename>
	struct are_same : public false_type {};
	
	template<typename T>
	struct are_same<T, T> : public true_type {};

	
//------------HELPER_FUNCTIONS--------------------------------------


	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ) {
		
		while ((first1 != last1) && (first2 != last2))
		{
			if (!(*first1 < *first2))
				return (false);
			first1++;
			first2++;
		}
		if (first1 != last1 && (first2 == last2))
			return (false);
		return (true);
	}

	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}
} // end namespace ft

#endif