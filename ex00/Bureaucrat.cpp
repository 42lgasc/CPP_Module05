/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:23:52 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/28 22:05:45 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream> // ostringstream

#if __has_include ("Form.hpp")
# include "Form.hpp"
# include <iostream> // cout
#endif

static std::string
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


// Constants

const Bureaucrat::Grade
Bureaucrat::c_highest_grade (1),	Bureaucrat::c_lowest_grade (150);


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
	if (grade < c_lowest_grade)		throw GradeTooLowException	();
	if (grade > c_highest_grade)	throw GradeTooHighException	();
}


// Accessors

const std::string
& Bureaucrat::getName(void)		const throw () { return name; }
const Bureaucrat::Grade
& Bureaucrat::getGrade(void)	const throw () { return grade; }


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

Bureaucrat::GradeTooHighException::GradeTooHighException	(void)
							throw (): std::domain_error (what)				{}
Bureaucrat::GradeTooHighException::GradeTooHighException
(const t_self	& original)	throw (): std::domain_error (original)			{}
Bureaucrat::GradeTooHighException
& Bureaucrat::GradeTooHighException::operator = (const t_self & other) throw ()
{ std::domain_error::operator = (other); return *this; }
Bureaucrat::GradeTooHighException::~ GradeTooHighException	(void) throw ()	{}



// ////
// GradeTooLowException


// Constants

const std::string	Bureaucrat::GradeTooLowException::what
	= ft_concatenate("Grade cannot be lower than ", + c_lowest_grade);


// Canonical Four

Bureaucrat::GradeTooLowException::GradeTooLowException	(void)	throw ():
	std::domain_error (what)												{}
Bureaucrat::GradeTooLowException::GradeTooLowException
(const GradeTooLowException	& original)							throw ():
	std::domain_error (original)											{}
Bureaucrat::GradeTooLowException	&
Bureaucrat::GradeTooLowException::operator =
(const GradeTooLowException	& other) throw ()
{ std::domain_error::operator = (other); return *this; }
Bureaucrat::GradeTooLowException::~ GradeTooLowException	(void) throw ()	{}



// ////
// Grade


// Canonical Four

// No default constructor, due to value requirement
Bureaucrat::Grade::Grade
(const Grade	& original) throw ():	g (original.g) {}
Bureaucrat::Grade
& Bureaucrat::Grade::operator = (const Grade	& other) throw ()
{ g = other.g; return *this; }
Bureaucrat::Grade::~ Grade	(void) throw () {}


// other Constructors

Bureaucrat::Grade::Grade	(const unsigned char	& grade) throw ():
	g (grade) {}


// Operators

Bureaucrat::Grade
& Bureaucrat::Grade::operator ++ (void) throw () { -- g; return *this; }
Bureaucrat::Grade	Bureaucrat::Grade::operator ++ (int) throw ()
{ Grade	before (*this); ++ *this; return before; }
Bureaucrat::Grade
& Bureaucrat::Grade::operator -- (void) throw () { ++ g; return *this; }
Bureaucrat::Grade	Bureaucrat::Grade::operator -- (int) throw ()
{ Grade	before (*this); -- *this; return before; }

bool	Bureaucrat::Grade::operator < (const Grade	& other) const throw ()
{ return g > other.g; }
bool	Bureaucrat::Grade::operator > (const Grade	& other) const throw ()
{ return other < *this; }
bool	Bureaucrat::Grade::operator <= (const Grade	& other) const throw ()
{ return not operator > (other); }
bool	Bureaucrat::Grade::operator >= (const Grade	& other) const throw ()
{ return not operator < (other); }
bool	Bureaucrat::Grade::operator == (const Grade	& other) const throw ()
{ return g == other.g; }
bool	Bureaucrat::Grade::operator != (const Grade	& other) const throw ()
{ return not operator == (other); }


// Conversions

Bureaucrat::Grade::operator unsigned short	(void) const throw () { return g; }




// //////// ////////
// Utilities
// ////

std::string	ft_concatenate(
		const std::string	& prefix, const unsigned char	& suffix) throw () {
	std::ostringstream	s;
	s << prefix << static_cast <unsigned short>(suffix);
	return s.str();
}
