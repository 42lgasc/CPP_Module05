/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:25:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/11 19:07:06 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <ostream>
# include <string>
# include <stdexcept> // domain_error

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))


// frens ·‿·

class Bureaucrat;

std::ostream	& operator << (std::ostream &, const Bureaucrat &) throw ();


// outer Class

class Bureaucrat {
	// inner Classes

	class GradeTooHighException: public std::domain_error {
		static const std::string	what;
	
	public:
		GradeTooHighException	(void)							throw ();
		GradeTooHighException	(const GradeTooHighException &)	throw ();
	private:
		GradeTooHighException	& operator = (const GradeTooHighException &)
																throw ();
	public:
		~ GradeTooHighException	(void)							throw ();
	};

	class GradeTooLowException: public std::domain_error {
		static const std::string	what;
	
	public:
		GradeTooLowException	(void)							throw ();
		GradeTooLowException	(const GradeTooLowException &)	throw ();
	private:
		GradeTooLowException	& operator = (const GradeTooLowException &)
																throw ();
	public:
		~ GradeTooLowException	(void)							throw ();
	};


	// Constants

public:
	static const unsigned char	highest_grade = 1,	lowest_grade = 150;


	// Fields

private:
	const std::string	name;
	unsigned short		grade;


	// Canonical Four

	Bureaucrat		(void)							throw ();
public:
	Bureaucrat		(const Bureaucrat &)			throw ();
	Bureaucrat	& operator = (const Bureaucrat &)	throw ();
	~ Bureaucrat	(void)							throw ();


	// other Constructors

	explicit Bureaucrat
		(const std::string & name, const unsigned char & grade = + lowest_grade)
		throw (GradeTooHighException, GradeTooLowException);


	// Accessors

	const std::string		& getName(void)
		const throw () WARN_UNUSED_RESULT;
	const unsigned short	& getGrade(void)
		const throw () WARN_UNUSED_RESULT;


	// Mutators

	Bureaucrat	& operator	++ (void)	throw (GradeTooHighException),
				operator	++ (int)	throw (GradeTooHighException)
					WARN_UNUSED_RESULT,
				& operator	-- (void)	throw (GradeTooLowException),
				operator	-- (int)	throw (GradeTooLowException)
					WARN_UNUSED_RESULT;
};
#endif
