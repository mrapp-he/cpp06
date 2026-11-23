/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:42:52 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:42:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
# include <iostream>

int main(void) {
	Data data;
	Data* ptr = &data;
	uintptr_t raw;
	Data* restored;

	data.value = 42;
	std::cout << "before: " << data.value << std::endl;
	raw = Serializer::serialize(ptr);
	restored = Serializer::deserialize(raw);
	std::cout << "after: " << restored->value << std::endl;
	return (0);
}
