/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:01:28 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/28 23:18:35 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream> // endl

#define UNUSED	__attribute__ ((unused))




// //////// ////////
// outer Class
// ////



// ////
// Form


// Constants

const Form::SigningGrade
Form::c_highest_signing_grade (8),		Form::c_lowest_signing_grade (62);
const Form::ExecutionGrade
Form::c_highest_execution_grade (57),	Form::c_lowest_execution_grade (94);


// Canonical Four

Form::Form		(void)				throw ():
	name ("formal Formular"),	signing_grade (c_highest_signing_grade),
	signature (false),	execution_grade (c_highest_execution_grade)	{}
Form::Form		(const Form	& f)	throw ():
	name (f.name),	signing_grade (f.signing_grade),
	signature (f.signature),	execution_grade (f.execution_grade)	{}
Form	& Form::operator = (const Form & other) throw ()
{ signature = other.hasSignature(); return *this; }
Form::~ Form	(void)				throw ()						{}


// other Constructors

Form::Form	(const std::string	& new_name) throw ():	name (new_name),
	signing_grade (c_highest_signing_grade),	signature (false),
	execution_grade (c_highest_execution_grade) {}

Form::Form	(const std::string	& new_name,
		const unsigned char	& new_signing_grade,
		const unsigned char	& new_execution_grade) throw (std::domain_error):
	name (new_name),	signing_grade (new_signing_grade),
	signature (false),	execution_grade (new_execution_grade)
{ t_result	r (checkValidity()); if (r.get() != NULL) throw *r; }
Form::Form	(const std::string	& new_name, const SigningGrade	& sg,
		const ExecutionGrade	& eg) throw (std::domain_error):
	name (new_name),	signing_grade (sg),	signature (false),
	execution_grade (eg)
{ t_result	r (checkValidity()); if (r.get() != NULL) throw *r; }


// Accessors

const std::string			& Form::getName(void)			const throw ()
{ return name; }
const Form::SigningGrade	& Form::getSigningGrade(void)	const throw ()
{ return signing_grade; }
const bool					& Form::hasSignature(void)		const throw ()
{ return signature; }
const Form::ExecutionGrade	& Form::getExecutionGrade(void)	const throw ()
{ return execution_grade; }


// Methods

void	Form::beSigned(const Bureaucrat	& b) throw (GradeTooLowException) {
	if (SigningGrade (b.getGrade()) < signing_grade)
		throw GradeTooLowException ();
	signature = true;
}


// frens ·‿·

std::ostream	& operator << (std::ostream	& s, const Form	& f) {
	return s << f.getName() << ", requires grade " << f.getSigningGrade()
		<< " to sign, has " << & "no signature, requires grade "
		[f.hasSignature() * 3] << f.getExecutionGrade() << " to execute";
}


// Utilities

Form::t_result	Form::checkValidity(void) const throw () {
	if (signing_grade < c_lowest_signing_grade
			or execution_grade < c_lowest_execution_grade)
	{ t_result	r (new GradeTooLowException); return r; }
	if (signing_grade > c_highest_signing_grade
			or execution_grade > c_highest_execution_grade)
	{ t_result	r (new GradeTooHighException); return r; }
	t_result	r;
	return r;
}




// //////// ////////
// inner Classes
// ////



// ////
// SigningGrade


// Canonical Four

// No default constructor, due to value requirement
Form::SigningGrade::SigningGrade	(const SigningGrade	& original)	throw ():
	Grade (original)								{}
Form::SigningGrade
& Form::SigningGrade::operator = (const SigningGrade	& other) throw ()
{ Grade::operator = (other); return *this; }
Form::SigningGrade::~ SigningGrade	(void) throw ()	{}


// other Constructors

Form::SigningGrade::SigningGrade	(const unsigned char	& grade) throw ():
	Grade (grade) {}


// Operators

const Bureaucrat::Grade	& Form::SigningGrade::operator *(void) const throw ()
{ return *this; }
Form::SigningGrade	& Form::SigningGrade::operator ++ (void) throw ()
{ Grade::operator -- (); return *this; }
Form::SigningGrade	& Form::SigningGrade::operator -- (void) throw ()
{ Grade::operator ++ (); return *this; }
bool	Form::SigningGrade::operator < (const SigningGrade	& other)
	const throw () { return Grade::operator < (other); }
bool	Form::SigningGrade::operator > (const SigningGrade	& other)
	const throw () { return other < *this; }


// frens ·‿·

std::ostream	& operator << (std::ostream	& o, const Form::SigningGrade	& g)
{ return o << *g; }



// ////
// ExecutionGrade


// Canonical Four

// No default constructor, due to value requirement
Form::ExecutionGrade::ExecutionGrade	(const ExecutionGrade	& original)
	throw (): Grade (original)							{}
Form::ExecutionGrade
& Form::ExecutionGrade::operator = (const ExecutionGrade	& other) throw ()
{ Grade::operator = (other); return *this; }
Form::ExecutionGrade::~ ExecutionGrade	(void) throw ()	{}


// other Constructors

Form::ExecutionGrade::ExecutionGrade	(const unsigned char	& grade)
	throw (): Grade (grade) {}


// Operators

const Bureaucrat::Grade	& Form::ExecutionGrade::operator *(void) const throw ()
{ return *this; }
Form::ExecutionGrade	& Form::ExecutionGrade::operator ++ (void) throw ()
{ Grade::operator -- (); return *this; }
Form::ExecutionGrade	& Form::ExecutionGrade::operator -- (void) throw ()
{ Grade::operator ++ (); return *this; }
bool	Form::ExecutionGrade::operator < (const ExecutionGrade	& other)
	const throw () { return Grade::operator < (other); }
bool	Form::ExecutionGrade::operator > (const ExecutionGrade	& other)
	const throw () { return other < *this; }


// frens ·‿·

std::ostream	& operator << (std::ostream	& s, const Form::ExecutionGrade	& g)
{ return s << *g; }



// ////
// GradeTooHighException


// Constants

const std::string	Form::GradeTooHighException::c_what ("Grade be too high");


// Canonical Four

Form::GradeTooHighException::GradeTooHighException
(void) throw ():	std::domain_error (c_what)								{}
Form::GradeTooHighException::GradeTooHighException
(UNUSED const t_self	& original) throw (): std::domain_error (c_what)	{}
Form::GradeTooHighException
& Form::GradeTooHighException::operator = (const t_self	& other) throw ()
{ std::domain_error::operator = (other); return *this; }
Form::GradeTooHighException::~ GradeTooHighException	(void) throw ()		{}



// ////
// GradeTooLowException


// Constants

const std::string	Form::GradeTooLowException::c_what ("Grade be too low");


// Canonical Four

Form::GradeTooLowException::GradeTooLowException	(void) throw ():
	std::domain_error (c_what)												{}
Form::GradeTooLowException::GradeTooLowException
(UNUSED const t_self	& original) throw (): std::domain_error (c_what)	{}
Form::GradeTooLowException
& Form::GradeTooLowException::operator = (const t_self	& other) throw ()
{ std::domain_error::operator = (other); return *this; }
Form::GradeTooLowException::~ GradeTooLowException	(void) throw ()			{}
