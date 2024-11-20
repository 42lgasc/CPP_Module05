/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:25:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/20 18:28:41 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <ostream>
# include <string>
# include <stdexcept> // domain_error

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))
# define VIEW				const throw () WARN_UNUSED_RESULT

class Form;


// frens ·‿·

class Bureaucrat;

std::ostream	& operator << (std::ostream &, const Bureaucrat &);


// outer Class

class Bureaucrat {
	// inner Classes

	class GradeTooHighException: public std::domain_error {
		static const std::string	what;
	
		GradeTooHighException
			& operator = (const GradeTooHighException &) throw ();
	public:
		GradeTooHighException	(void)							throw ();
		GradeTooHighException	(const GradeTooHighException &)	throw ();
		~ GradeTooHighException	(void)							throw ();
	};

	class GradeTooLowException: public std::domain_error {
		static const std::string	what;
	
		GradeTooLowException
			& operator = (const GradeTooLowException &) throw ();
	public:
		GradeTooLowException	(void)							throw ();
		GradeTooLowException	(const GradeTooLowException &)	throw ();
		~ GradeTooLowException	(void)							throw ();
	};


	// Constants

public:
	static const unsigned char	c_highest_grade = 1,	c_lowest_grade = 150;


	// Fields

private:
	const std::string	name;
	unsigned short		grade;


	// Canonical Four

public:
	Bureaucrat		(void)							throw ();
	Bureaucrat		(const Bureaucrat &)			throw ();
	Bureaucrat	& operator = (const Bureaucrat &)	throw ();
	~ Bureaucrat	(void)							throw ();


	// other Constructors

	explicit Bureaucrat	(const std::string & name,
			const unsigned char & grade = + c_lowest_grade)
		throw (GradeTooHighException, GradeTooLowException);


	// Accessors

	const std::string		& getName(void)		VIEW;
	const unsigned short	& getGrade(void)	VIEW;


	// Mutators

	Bureaucrat	& operator	++ (void)	throw (GradeTooHighException),
				operator	++ (int)	throw (GradeTooHighException)
					WARN_UNUSED_RESULT,
				& operator	-- (void)	throw (GradeTooLowException),
				operator	-- (int)	throw (GradeTooLowException)
					WARN_UNUSED_RESULT;


	// Methods

	void	signForm(Form &) const throw ();
};
#endif
