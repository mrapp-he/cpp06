/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:06:07 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/10/02 13:30:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac < 2)
		return (std::cerr << "Missing argument!" << std::endl, 1);
	else if (ac > 2)
		return (std::cerr << "Too many arguments!" << std::endl, 1);
	ScalarConverter::convert(av[1]);
	return (0);
}
