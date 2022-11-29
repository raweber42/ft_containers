/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:55:35 by raweber           #+#    #+#             */
/*   Updated: 2022/11/29 07:37:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# define COLOR_DEFAULT "\033[0m"
# define COLOR_RED "\033[31;1m"
# define COLOR_GREEN "\033[32;1m"
# define COLOR_YELLOW "\033[33;1m"
# define COLOR_BLUE "\033[34;1m"
# define COLOR_MAGENTA "\033[35;1m"
# define COLOR_CYAN "\033[36;1m"
# define COLOR_WHITE "\033[37;1m"
# ifndef DEBUG
#  define DEBUG 0
# endif
