/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:35:56 by gyasuhir          #+#    #+#             */
/*   Updated: 2026/07/11 13:38:32 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main(void) {
	{
		std::cout << YELLOW << "1. Valid form" << RESET << std::endl;
		try {
			std::cout << "- ";
			Form validForm("Form A", 50, 100);
			std::cout << validForm << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "2. Invalid form" << RESET << std::endl;
		try {
			std::cout << "- Trying to create a form with grade to sign 0" << std::endl;
			Form invalidForm1("Form B", 0, 100);
			std::cout << invalidForm1 << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			std::cout << "- Trying to create a form with grade to execute 151" << std::endl;
			Form invalidForm2("Form C", 50, 151);
			std::cout << invalidForm2 << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "3. Successfully sign a form and retry" << RESET << std::endl;
		try {
			std::cout << "- ";
			Bureaucrat	bigBoss("Big Boss", 1);
			std::cout << bigBoss << std::endl;
			std::cout << std::endl;
			
			std::cout << "- ";
			Form		topSecret("Top Secret", 1, 1);
			std::cout << topSecret << std::endl;
			std::cout << std::endl;

			std::cout << "- Big Boss signs the form" << std::endl;
			bigBoss.signForm(topSecret);
			std::cout << std::endl;
			std::cout << "- Big Boss tries to sign the form again..." << std::endl;
			bigBoss.signForm(topSecret);
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "4. Failed to sign a form" << RESET << std::endl;
		try {
			std::cout << "- ";
			Bureaucrat	paperPusher("Paper Pusher", 150);
			std::cout << paperPusher << std::endl;
			std::cout << std::endl;
			
			std::cout << "- ";
			Form		topSecret("Top Secret", 1, 1);
			std::cout << topSecret << std::endl;
			std::cout << std::endl;

			std::cout << "- Paper Pusher tries to sign the form..." << std::endl;
			paperPusher.signForm(topSecret);
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << RED << "Exception caught: "<< RESET << e.what() << std::endl;
		}
	}
	return 0;
}
