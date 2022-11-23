/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:13:41 by raweber           #+#    #+#             */
/*   Updated: 2022/11/23 17:02:55 by raweber          ###   ########.fr       */
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