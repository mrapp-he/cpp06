/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:07 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/10/02 13:30:20 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
	Base* randomObject = generate();

	std::cout << "pointer: ";
	identify(randomObject);
	std::cout << "reference: ";
	identify(*randomObject);

	delete randomObject;
	return 0;
}
