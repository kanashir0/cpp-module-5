/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:32:32 by gyasuhir          #+#    #+#             */
/*   Updated: 2026/07/11 12:05:35 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void) {
	{
		std::cout << YELLOW << "1. Default constructor" << RESET << std::endl;
		try {
			Bureaucrat b;
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "2. Parametrized constructor and grade change" << RESET << std::endl;
		try {
			Bureaucrat me("Kanashiro", 50);
			std::cout << me << std::endl;
			std::cout << std::endl;

			std::cout << "- Incrementing grade" << std::endl;
			me.incrementGrade();
			std::cout << me << std::endl;
			std::cout << std::endl;

			std::cout << "- Decrementing grade" << std::endl;
			me.decrementGrade();
			std::cout << me << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
		}
	}
	std::cout <<std::endl;
	{
		std::cout << YELLOW << "3. Invalid grade exceptions" << RESET << std::endl;
		try {
			std::cout << "- Trying to create Chloe with grade 0" << std::endl;
			Bureaucrat chloe("Chloe", 0);
			std::cout << chloe << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			std::cout << "- Trying to create Crash with grade 151" << std::endl;
			Bureaucrat crash("Crash", 151);
			std::cout << crash << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
 		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "4. Increment/Decrement boundary exceptions" << RESET << std::endl;
		try {
			Bureaucrat michael("Big Boss", 1);
			std::cout << "- Trying to increment grade at upper boundary..." << std::endl;
			michael.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat jim("Paper Salesman", 150);
			std::cout << "- Trying to decrement grade at lower boundary..." << std::endl;
			jim.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
		}
	}
	return 0;
}