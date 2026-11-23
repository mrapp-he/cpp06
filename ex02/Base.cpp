/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:21 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/10/02 13:38:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	switch (std::rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p) {
	if (p == NULL)
		return;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
