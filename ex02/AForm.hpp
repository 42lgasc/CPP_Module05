/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:07 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/13 16:56:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

# include "Bureaucrat.hpp"

# include <memory> // auto_ptr
# include <ostream>
# include <stdexcept> // domain_error
# include <string>
# ///`<cstdint>` requires C++11
# include <stdint.h> // uintmax_t

# define	WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))
# define	VIEW              	const throw () WARN_UNUSED_RESULT

# define	DEFAULT_CONSTRUCTOR(C)	C      	(void) throw ()
# define	   COPY_CONSTRUCTOR(C)	C	             (const C &) throw ()
# define	   COPY_ASSIGNMENT( C)	C	& operator = (const C &) throw ()
# define	DESTRUCTOR(         C)	compl C	(void) throw ()


class AForm {
public:
	// inner Classes

	class SigningGrade: public Bureaucrat::Grade {
		DEFAULT_CONSTRUCTOR (SigningGrade); // inadequate
		   COPY_ASSIGNMENT  (SigningGrade); // unnecessary??
	public:
		   COPY_CONSTRUCTOR (SigningGrade);
		DESTRUCTOR          (SigningGrade);
	
		explicit SigningGrade	(const unsigned char & grade) throw ();
	};

	class ExecutionGrade: public Bureaucrat::Grade {
		DEFAULT_CONSTRUCTOR (ExecutionGrade); // inadequate
		   COPY_ASSIGNMENT  (ExecutionGrade); // unnecessary??
	public:
		   COPY_CONSTRUCTOR (ExecutionGrade);
		DESTRUCTOR          (ExecutionGrade);
	
		explicit ExecutionGrade	(const unsigned char & grade) throw ();
	};

	class GradeTooHighException: public std::domain_error {
		static const std::string	c_what;
	
		   COPY_ASSIGNMENT  (GradeTooHighException); // unnecessary??
	public:
		DEFAULT_CONSTRUCTOR (GradeTooHighException);
		   COPY_CONSTRUCTOR (GradeTooHighException);
		virtual DESTRUCTOR  (GradeTooHighException);
	};

	class GradeTooLowException: public std::domain_error {
		static const std::string	c_what;
	
		   COPY_ASSIGNMENT  (GradeTooLowException); // unnecessary??
	public:
		DEFAULT_CONSTRUCTOR (GradeTooLowException);
		   COPY_CONSTRUCTOR (GradeTooLowException);
		virtual DESTRUCTOR  (GradeTooLowException);
	};

	typedef const std::string	t_name,	t_target;

private:
	typedef SigningGrade	Sg;
	typedef ExecutionGrade	Eg;


	// Constants

	///No specification for these values,
	///those are made-up for demonstration sake.
	static const Sg	c_highest_signing_grade,  	c_lowest_signing_grade;
	static const Eg	c_highest_execution_grade,	c_lowest_execution_grade;


	// Fields

	const t_name  	  name;
	        bool  	  signature;
	const   Sg    	& signing_grade;
	const   Eg    	& execution_grade;
	const t_target	  target;


	// Canonical Four

	DEFAULT_CONSTRUCTOR (AForm); // insufficent
protected:
	   COPY_CONSTRUCTOR (AForm);
	   COPY_ASSIGNMENT  (AForm);
	virtual  DESTRUCTOR (AForm) = 0;


	// other Constructors

	explicit AForm	(const t_name &, const Sg &, const Eg &, const t_target &)
		throw (GradeTooHighException, GradeTooLowException);


	// Accessors

public:
	const t_target	& getName          (void) VIEW;
	const t_target	& getTarget        (void) VIEW;
	const   Sg    	& getSigningGrade  (void) VIEW;
	const   bool  	& hasSignature     (void) VIEW;
	const   Eg    	& getExecutionGrade(void) VIEW;


	// Methods

	void	beSigned(const Bureaucrat &) throw (GradeTooLowException);
	bool	execute(const Bureaucrat & executor) const
		throw (GradeTooLowException) WARN_UNUSED_RESULT;

private:
	///Returns whether success occur
	virtual bool	executeAssumingBureacraticApproval(void) VIEW = 0;


	// Utilities

	class Error {
		DEFAULT_CONSTRUCTOR (Error); // insufficent
		   COPY_CONSTRUCTOR (Error); // requires cloning + unnecessary??
		   COPY_ASSIGNMENT  (Error); // immutable
	public:
		         DESTRUCTOR (Error);
	
		const enum e_kind { Too_High, Too_Low }	kind;
		const std::domain_error	& error;
	
		///This takes ownership of the error.
		explicit Error	(const e_kind &, const std::domain_error &) throw ();
	};
	std::auto_ptr<const Error>	checkValidity(void) VIEW;
};


// frens ·‿·

std::ostream	& operator << (std::ostream &, const AForm &);


# undef	WARN_UNUSED_RESULT
# undef	VIEW

# undef	DEFAULT_CONSTRUCTOR
# undef	   COPY_CONSTRUCTOR
# undef	   COPY_ASSIGNMENT
# undef	         DESTRUCTOR
#endif
