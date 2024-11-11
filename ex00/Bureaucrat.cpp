/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:23:52 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/11 19:07:51 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream> // ostringstream

# define UNUSED	__attribute__ ((unused))

std::string
	ft_concatenate(const std::string & prefix, const unsigned char & suffix)
	throw ();




// ///////// ////////
// frens ·‿·
// ////

std::ostream
		& operator << (std::ostream	& s, const Bureaucrat	& b) throw ()
		{ return s << b.getName() << ", bureaucrat grade " << b.getGrade(); }




// //////// ////////
// outer Class
// ////



// ////
// Bureaucrat


// Canonical Four

// No default constructor, due to name requirement.
Bureaucrat::Bureaucrat		(const Bureaucrat	& original) throw ():
		name (original.name), grade (original.grade)	{}
Bureaucrat					& Bureaucrat::operator = (const Bureaucrat	& other)
		throw () { grade = other.grade; return *this; }
Bureaucrat::~ Bureaucrat	(void) throw ()				{}


// other Constructors

Bureaucrat::Bureaucrat
		(const std::string	& new_name, const unsigned char	& new_grade)
		throw (GradeTooHighException, GradeTooLowException):
		name (new_name), grade (new_grade) {
	if (grade < highest_grade)	throw GradeTooHighException	();
	if (grade > lowest_grade)	throw GradeTooLowException	();
}


// Accessors

const std::string		& Bureaucrat::getName(void) const throw ()
		{ return name; }
const unsigned short	& Bureaucrat::getGrade(void) const throw ()
		{ return grade; }


// Mutators

Bureaucrat	& Bureaucrat::operator ++ (void) throw (GradeTooHighException) {
	if (grade == highest_grade) throw GradeTooHighException ();
	++ grade;
	return *this;
}
Bureaucrat	Bureaucrat::operator ++ (int) throw (GradeTooHighException) {
	if (grade == highest_grade) throw GradeTooHighException ();
	const Bureaucrat	hold (*this);
	++ grade;
	return hold;
}
Bureaucrat	& Bureaucrat::operator -- (void) throw (GradeTooLowException) {
	if (grade == lowest_grade) throw GradeTooLowException ();
	-- grade;
	return *this;
}
Bureaucrat	Bureaucrat::operator -- (int) throw (GradeTooLowException) {
	if (grade == lowest_grade) throw GradeTooLowException ();
	const Bureaucrat	hold (*this);
	-- grade;
	return hold;
}




// //////// ////////
// inner Classes
// ////



// ////
// GradeTooHighException


// Constants

const std::string	Bureaucrat::GradeTooHighException::what
	= ft_concatenate("Grade cannot be higher than ", + highest_grade);


// Canonical Four

Bureaucrat::GradeTooHighException::GradeTooHighException	(void)	throw ():
		std::domain_error (what)											{}
Bureaucrat::GradeTooHighException::GradeTooHighException
		(const GradeTooHighException	& original)					throw ():
		std::domain_error (original)										{}
Bureaucrat::GradeTooHighException
		& Bureaucrat::GradeTooHighException::operator =
		(UNUSED const GradeTooHighException	& other) throw () { return *this; }
Bureaucrat::GradeTooHighException::~ GradeTooHighException	(void) throw ()	{}



// ////
// GradeTooLowException


// Constants

const std::string	Bureaucrat::GradeTooLowException::what
	= ft_concatenate("Grade cannot be lower than ", + lowest_grade);


// Canonical Four

Bureaucrat::GradeTooLowException::GradeTooLowException	(void)	throw ():
		std::domain_error (what)											{}
Bureaucrat::GradeTooLowException::GradeTooLowException
		(const GradeTooLowException	& original)					throw ():
		std::domain_error (original)										{}
Bureaucrat::GradeTooLowException
		& Bureaucrat::GradeTooLowException::operator =
		(UNUSED const GradeTooLowException	& other) throw () { return *this; }
Bureaucrat::GradeTooLowException::~ GradeTooLowException	(void) throw ()	{}




// //////// ////////
// Utilities
// ////

std::string	ft_concatenate(
		const std::string	& prefix, const unsigned char	& suffix) throw () {
	std::ostringstream	s;
	s << prefix << static_cast <unsigned short>(suffix);
	return s.str();
}
