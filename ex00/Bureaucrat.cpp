/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:23:52 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/20 19:31:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream> // ostringstream

#if __has_include ("Form.hpp")
# include "Form.hpp"
# include <iostream> // cout
#endif

# define UNUSED	__attribute__ ((unused))

std::string
	ft_concatenate(const std::string & prefix, const unsigned char & suffix)
	throw ();




// ///////// ////////
// frens ·‿·
// ////

std::ostream	& operator << (std::ostream	& s, const Bureaucrat	& b)
{ return s << b.getName() << ", bureaucrat grade " << b.getGrade(); }




// //////// ////////
// outer Class
// ////



// ////
// Bureaucrat


// Canonical Four

Bureaucrat::Bureaucrat		(void)							throw ():
	name ("bureaucratic Bureaucrative"),	grade (c_lowest_grade)		{}
Bureaucrat::Bureaucrat		(const Bureaucrat	& original)	throw ():
	name (original.name), grade (original.grade)						{}
Bureaucrat	& Bureaucrat::operator = (const Bureaucrat	& other) throw ()
{ grade = other.grade; return *this; }
Bureaucrat::~ Bureaucrat	(void)							throw ()	{}


// other Constructors

Bureaucrat::Bureaucrat
		(const std::string	& new_name, const unsigned char	& new_grade)
		throw (GradeTooHighException, GradeTooLowException):
		name (new_name), grade (new_grade) {
	if (grade < c_highest_grade)	throw GradeTooHighException	();
	if (grade > c_lowest_grade)	throw GradeTooLowException	();
}


// Accessors

const std::string		& Bureaucrat::getName(void) const throw ()
		{ return name; }
const unsigned short	& Bureaucrat::getGrade(void) const throw ()
		{ return grade; }


// Mutators

Bureaucrat	& Bureaucrat::operator ++ (void) throw (GradeTooHighException) {
	if (grade == c_highest_grade) throw GradeTooHighException ();
	-- grade;
	return *this;
}
Bureaucrat	Bureaucrat::operator ++ (int) throw (GradeTooHighException) {
	if (grade == c_highest_grade) throw GradeTooHighException ();
	const Bureaucrat	hold (*this);
	-- grade;
	return hold;
}
Bureaucrat	& Bureaucrat::operator -- (void) throw (GradeTooLowException) {
	if (grade == c_lowest_grade) throw GradeTooLowException ();
	++ grade;
	return *this;
}
Bureaucrat	Bureaucrat::operator -- (int) throw (GradeTooLowException) {
	if (grade == c_lowest_grade) throw GradeTooLowException ();
	const Bureaucrat	hold (*this);
	++ grade;
	return hold;
}


// Methods

#if __has_include ("Form.hpp")

void	Bureaucrat::signForm(Form	& f) const throw () {
	const std::string	c_fail_message1 (" couldn't sign "),
						c_fail_message2 (" because ");
	if (f.hasSignature()) {
		std::cout << name << c_fail_message1 << f.getName() << c_fail_message2
			<< "it has a signature already.\n";
		return ;
	}
	try {
		f.beSigned(*this); std::cout << name << " signed " << f.getName()
			<< '\n';
	}
	catch (const std::exception	& e) {
		std::cout << name << c_fail_message1 << f.getName() << c_fail_message2
			<< e.what() << ".\n";
	}
}
#endif




// //////// ////////
// inner Classes
// ////



// ////
// GradeTooHighException


// Constants

const std::string	Bureaucrat::GradeTooHighException::what
	= ft_concatenate("Grade cannot be higher than ", + c_highest_grade);


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
	= ft_concatenate("Grade cannot be lower than ", + c_lowest_grade);


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
