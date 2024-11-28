/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:07 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/28 23:21:58 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# include <memory> // auto_ptr
# include <ostream>
# include <stdexcept> // domain_error
# include <string>

# include <stdint.h> // uintmax_t

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))
# define VIEW				const throw () WARN_UNUSED_RESULT


// outer Class

class Form {
	// Type declarations

	typedef std::auto_ptr<const std::domain_error>	t_result;


	// inner Classes

	class GradeTooHighException: public std::domain_error {
		typedef GradeTooHighException	t_self;
	
		static const std::string	c_what;
	
		t_self					& operator = (const t_self &)	throw ();
	public:
		GradeTooHighException	(void)							throw ();
		GradeTooHighException	(const t_self &)				throw ();
		~ GradeTooHighException	(void)							throw ();
	};
	class GradeTooLowException: public std::domain_error {
		typedef GradeTooLowException	t_self;
	
		static const std::string	c_what;
	
		t_self					& operator = (const t_self &)	throw ();
	public:
		GradeTooLowException	(void)							throw ();
		GradeTooLowException	(const t_self &)				throw ();
		~ GradeTooLowException	(void)							throw ();
	};

public:
	class SigningGrade: Bureaucrat::Grade {
		SigningGrade	(void)								throw ();
		SigningGrade	& operator = (const SigningGrade &)	throw ();
	public:
		SigningGrade	(const SigningGrade &)				throw ();
		~ SigningGrade	(void)								throw ();
	
		explicit SigningGrade	(const unsigned char & grade) throw ();
	
		const Grade	& operator *(void) VIEW;
		SigningGrade	& operator ++ (void) throw (),
						& operator -- (void) throw ();
		bool	operator < (const SigningGrade &) VIEW,
				operator > (const SigningGrade &) VIEW;
	};
	class ExecutionGrade: Bureaucrat::Grade {
		ExecutionGrade		(void)									throw ();
		ExecutionGrade		& operator = (const ExecutionGrade &)	throw ();
	public:
		ExecutionGrade		(const ExecutionGrade &)				throw ();
		~ ExecutionGrade	(void)									throw ();
	
		explicit ExecutionGrade	(const unsigned char & grade) throw ();
	
		const Grade	& operator *(void) VIEW;
		ExecutionGrade	& operator ++ (void) throw (),
						& operator -- (void) throw ();
		bool	operator < (const ExecutionGrade &) VIEW,
				operator > (const ExecutionGrade &) VIEW;
	};


	// Constants

	///No specification for these values,
	///those are made-up for demonstration sake.
	static const SigningGrade
		c_highest_signing_grade,	c_lowest_signing_grade;
	static const ExecutionGrade
		c_highest_execution_grade,	c_lowest_execution_grade;


	// Fields

private:
	const std::string		name;
	const SigningGrade		signing_grade;
	bool					signature;
	const ExecutionGrade	execution_grade;


	// Canonical Four

public:
	Form	(void)						throw ();
	Form	(const Form &)				throw ();
	Form	& operator = (const Form &)	throw ();
	~ Form	(void)						throw ();


	// other Constructors

	explicit Form	(const std::string & name) throw ();

	Form	(const std::string & name, const unsigned char & signing_grade,
			const unsigned char & execution_grade)	throw (std::domain_error);
	Form	(const std::string & name, const SigningGrade &,
			const ExecutionGrade &)					throw (std::domain_error);


	// Accessors

	const std::string		& getName(void)				VIEW;
	const SigningGrade		& getSigningGrade(void)		VIEW;
	const bool				& hasSignature(void)		VIEW;
	const ExecutionGrade	& getExecutionGrade(void)	VIEW;


	// Methods

	void	beSigned(const Bureaucrat &) throw (GradeTooLowException);


	// Utilities

private:
	t_result	checkValidity(void) VIEW;
};


// frens ·‿·

std::ostream	& operator << (std::ostream &, const Form &),
				& operator << (std::ostream &, const Form::SigningGrade &),
				& operator << (std::ostream &, const Form::ExecutionGrade &);
#endif
