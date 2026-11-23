/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:06:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/10/02 13:30:33 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
        literal == "+inff" || literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal[literal.size() - 1] == 'f') {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        } else {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
    } else if (literal.find_first_not_of("-+0123456789.fF") != std::string::npos) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } else if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
    } else {
        if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos && literal.find('F') == std::string::npos) {
            long intValue = std::atol(literal.c_str());

            if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max()) {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            } else {
                if (intValue >= 0 && intValue <= 127) {
                    if (intValue >= 32 && intValue <= 126)
                        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
                    else
                        std::cout << "char: Non displayable" << std::endl;
                } else
                    std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(intValue) << std::endl;
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << std::endl;
            }
        } else if (literal[literal.size() - 1] == 'f' || literal[literal.size() - 1] == 'F') {
            float floatValue = std::atof(literal.c_str());
            long intValue = static_cast<long>(floatValue);

            if (std::isnan(floatValue) || std::isinf(floatValue)
                || intValue < std::numeric_limits<int>::min()
                || intValue > std::numeric_limits<int>::max()) {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << floatValue << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
            } else {
                if (floatValue >= 0 && floatValue <= 127) {
                    if (floatValue >= 32 && floatValue <= 126)
                        std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
                    else
                        std::cout << "char: Non displayable" << std::endl;
                } else
                    std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
                std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << std::endl;
            }
        } else {
            double doubleValue = std::atof(literal.c_str());
            long intValue = static_cast<long>(doubleValue);

            if (std::isnan(doubleValue) || std::isinf(doubleValue)
                || intValue < std::numeric_limits<int>::min()
                || intValue > std::numeric_limits<int>::max()) {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
                std::cout << "double: " << doubleValue << std::endl;
            } else {
                if (doubleValue >= 0 && doubleValue <= 127) {
                    if (doubleValue >= 32 && doubleValue <= 126)
                        std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
                    else
                        std::cout << "char: Non displayable" << std::endl;
                } else
                    std::cout << "char: impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
            }
        }
    }
}
