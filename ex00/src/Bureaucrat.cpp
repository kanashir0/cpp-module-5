/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:39:07 by codespace         #+#    #+#             */
/*   Updated: 2026/07/11 12:08:36 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("No name"), _grade(150) {
    std::cout << "A default bureaucrat has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << _name << " bureaucrat with grade " << _grade << " has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "A bureaucrat has been copied." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "A bureaucrat has been destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "A bureaucrat has been assigned values from another one." << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return *this;
}

const std::string&  Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

void    Bureaucrat::incrementGrade(void) {
    if (_grade <= HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade(void) {
    if (_grade >= LOWEST_GRADE)
        throw GradeTooHighException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade is too low!";
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}