/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:01:28 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/06 16:38:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

#include <ostream>
#include <stdexcept> // domain_error
#include <string>

#if defined DEBUG && DEBUG
# include "PresidentialPardonForm.hpp"

# include <iostream> // clog, endl

# define	LOG(TEXT)	\
	(std::clog << "\x1B[7;90m" << __PRETTY_FUNCTION__ \
		<< " @ " __FILE__":" << __LINE__ << TEXT << "\x1B[27;39m" << std::endl)
#else
# define	LOG(TEXT) // noop
#endif




// //////// ////////
// outer Class
// ////



// ////
// AForm


// Constants

const AForm::SigningGrade  	AForm::c_highest_signing_grade   (  8);
const AForm::SigningGrade  	AForm:: c_lowest_signing_grade   (246);
const AForm::ExecutionGrade	AForm::c_highest_execution_grade (  5);
const AForm::ExecutionGrade	AForm:: c_lowest_execution_grade (179);


// Canonical Four

// No default constructor, due to necessary fields
// `signing_grade`, `execution_grade`, and `target`.

AForm::AForm	                    (const AForm	& f    ) throw ():
	name (f.name),	signature (false),	signing_grade (f.signing_grade),
	execution_grade (f.execution_grade),	target (f.target)             {}

///We do a little forgin'...
AForm       	& AForm::operator = (const AForm	& other) throw ()
{ signature = other.hasSignature(); return *this; }

AForm::compl AForm	(       void	       ) throw () {}


// other Constructors

AForm::AForm	(const std::string	& name_arg, const SigningGrade	& sg,
		const ExecutionGrade	& eg, const std::string	& target_arg)
	throw (GradeTooHighException, GradeTooLowException):
		name (name_arg),	signature (false),
		signing_grade (sg),	execution_grade (eg),	target (target_arg) {
	const std::auto_ptr<const Error>	o (checkValidity());
	
	LOG ('\t' << this
		<< '\t' << name_arg << '\t' << name << '\t' << getName()
		<< '\t' << target_arg << '\t' << target << '\t' << getTarget()
		<< '\t' << sizeof (char) << ' ' << sizeof (char *)
		<< ' ' << sizeof (void (*)(void))
		<< ' ' << sizeof (void (AForm::*)(void))
		<< ' ' << sizeof (void (PresidentialPardonForm::*)(void))
		<< ' '
		<< sizeof & PresidentialPardonForm::executeAssumingBureacraticApproval
		<< '\t' << sizeof (AForm) << ' ' << sizeof *this
		<< '\t' << sizeof (GradeTooHighException)
		<< ' ' << sizeof (GradeTooLowException)
		<< ' ' << sizeof o << ' ' << sizeof o->error
		<< '\t' << sizeof (PresidentialPardonForm)
		<< ' ' << sizeof *new PresidentialPardonForm ("ignacio"));

	if (not o.get()) return;
	switch (o->kind) {
		case Error::Too_High:
			throw static_cast<const GradeTooHighException &> (o->error);
		case Error::Too_Low:
			throw static_cast<const GradeTooLowException &> (o->error);
	}
}


// Accessors

const   std::string        	& AForm::getName          (void) const throw ()
                           	   { return name           ; }
const AForm::SigningGrade  	& AForm::getSigningGrade  (void) const throw ()
                           	   { return signing_grade  ; }
const        bool          	& AForm::hasSignature     (void) const throw ()
                           	   { return signature      ; }
const AForm::ExecutionGrade	& AForm::getExecutionGrade(void) const throw ()
                           	   { return execution_grade; }
const   std::string        	& AForm::getTarget        (void) const throw ()
                           	   { return target         ; }


// Methods

void	AForm::beSigned(const Bureaucrat	& b) throw (GradeTooLowException) {
	LOG ('\t' << signature << '\t' << hasSignature()
		<< '\t' << b.getGrade() << '\t' << signing_grade);
	if (b.getGrade() < signing_grade)
		throw GradeTooLowException ();
	signature = true;
	LOG ('\t' << signature << '\t' << hasSignature());
}

bool	AForm::execute(const Bureaucrat	& executor) const
throw (GradeTooLowException) {
	LOG ('\t' << signature << '\t' << hasSignature()
		<< '\t' << executor.getGrade() << '\t' << execution_grade);
	if (not hasSignature()) return false;
	if (executor.getGrade() < execution_grade) throw GradeTooLowException ();
	LOG ("execution approval");
	return executeAssumingBureacraticApproval();
}

// `executeAssumingBureacraticApproval` be purely abstract


// frens ·‿·

std::ostream	& operator << (std::ostream	& s, const AForm	& f) {
	return s << f.getName() << " ("
		"targets "         <<          f.getTarget        () << ","
		" requires grade " <<          f.getSigningGrade  () << " to sign,"
		" has"             << & " no" [f.hasSignature     () * 3]
		                                                     << " signature,"
		" requires grade " <<          f.getExecutionGrade() << " to execute"
		")";
}


// Utilities

std::auto_ptr<const AForm::Error>	AForm::checkValidity(void) const throw () {
	if (signing_grade > c_highest_signing_grade
			or execution_grade > c_highest_execution_grade)
		return std::auto_ptr<const Error>
			(new Error (Error::Too_High, *new GradeTooHighException));
	if (signing_grade < c_lowest_signing_grade
			or execution_grade < c_lowest_execution_grade)
		return std::auto_ptr<const Error>
			(new Error (Error::Too_Low, *new GradeTooLowException));
	return std::auto_ptr<const Error> ();
}




// //////// ////////
// inner Classes
// ////



// ////
// SigningGrade


// Canonical Four

// No default constructor, due to value requirement
AForm::SigningGrade::SigningGrade	(const SigningGrade	& original) throw ():
	Grade (original)                                                         {}
AForm::SigningGrade	& AForm::SigningGrade::operator = (const SigningGrade
		& other) throw () { Grade::operator = (other); return *this; }
AForm::SigningGrade::compl
                     SigningGrade	(      void        	          ) throw () {}


// other Constructors

AForm::SigningGrade::SigningGrade
	(const unsigned char	& grade) throw (): Grade (grade) {}



// ////
// ExecutionGrade


// Canonical Four

// No default constructor, due to value requirement

AForm::ExecutionGrade::ExecutionGrade
	(const ExecutionGrade	& original) throw (): Grade (original) {}

AForm::ExecutionGrade	& AForm::ExecutionGrade::operator =
	(const ExecutionGrade	& other   ) throw ()
{ Grade::operator = (other); return *this; }

AForm::ExecutionGrade::compl ExecutionGrade
	(      void          	          ) throw ()                   {}


// other Constructors

AForm::ExecutionGrade::ExecutionGrade
	(const unsigned char	& grade) throw (): Grade (grade) {}



// ////
// GradeTooHighException


// Constants

const std::string	AForm::GradeTooHighException::c_what ("Grade be too high");


// Canonical Four

AForm::GradeTooHighException::      GradeTooHighException	(void) throw ():
	std::domain_error (       c_what  )                                     {}

AForm::GradeTooHighException::
GradeTooHighException	(const GradeTooHighException	& original) throw ():
	std::domain_error (original) {}

AForm::GradeTooHighException	& AForm::GradeTooHighException::operator =
	(const GradeTooHighException	& other) throw ()
{ std::domain_error::operator = (other); return *this; }

AForm::GradeTooHighException::compl GradeTooHighException	(void) throw () {}



// ////
// GradeTooLowException


// Constants

const std::string	AForm::GradeTooLowException::c_what ("Grade be too low");


// Canonical Four

AForm::GradeTooLowException::      GradeTooLowException	(void) throw ():
		std::domain_error (       c_what  ) {}

AForm::GradeTooLowException::
GradeTooLowException	(const GradeTooLowException	& original) throw ():
		std::domain_error (original.what()) {}

AForm::GradeTooLowException	& AForm::GradeTooLowException::operator =
	(const GradeTooLowException	& other   ) throw ()
{ std::domain_error::operator = (other); return *this; }

AForm::GradeTooLowException::compl GradeTooLowException	(void) throw () {}



// ////
// Error


// Canonical Four

AForm::Error::Error	(void) throw ():
	kind (),	error (*new std::domain_error ("[(missing) domain error]")) {}
// No copy constructor, due to cloning requirement
AForm::Error	& AForm::Error::operator = (const AForm::Error &) throw ()
{ return *this; }
AForm::Error::compl Error	(void) throw () { delete & error; }


// other Constructors

AForm::Error::Error	(const e_kind	& k, const std::domain_error	& e)
	throw ():	kind (k),	error (e) {}




#if defined DEBUG and DEBUG
# undef    LOG
#endif
