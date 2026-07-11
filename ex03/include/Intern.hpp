/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:23:39 by gyasuhir          #+#    #+#             */
/*   Updated: 2026/07/11 15:23:39 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern {
	private:
		AForm*	_makeShrubberyForm(const std::string& target);
		AForm*	_makeRobotomyForm(const std::string& target);
		AForm*	_makePresidentialForm(const std::string& target);

	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);

		Intern&	operator=(const Intern& other);
		
		AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif
