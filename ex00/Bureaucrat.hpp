/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:25:06 by lgasc             #+#    #+#             */
/*   Updated: 2025/02/12 18:14:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <ostream>
# include <string>
# include <stdexcept> // domain_error

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))
# define VIEW              	const throw () WARN_UNUSED_RESULT

# if   __has_include ( "Form.hpp")

class  Form;
# elif __has_include ("AForm.hpp")

class AForm;
# endif


// frens ·‿·

class Bureaucrat;

std::ostream	& operator << (std::ostream &, const Bureaucrat &);


// outer Class

class Bureaucrat {
	// inner Classes

	class GradeTooHighException: public std::domain_error {
		typedef GradeTooHighException	t_self;
	
		static const std::string	what;
	
		      GradeTooHighException	& operator = (const t_self &) throw ();
	public:
		      GradeTooHighException	             (        void  ) throw ();
		      GradeTooHighException	             (const t_self &) throw ();
		compl GradeTooHighException	             (        void  ) throw ();
	};
	class GradeTooLowException: public std::domain_error {
		static const std::string	what;
	
		      GradeTooLowException	& operator =
		                          	(const GradeTooLowException &) throw ();
	public:
		      GradeTooLowException	(           void             ) throw ();
		      GradeTooLowException	(const GradeTooLowException &) throw ();
		compl GradeTooLowException	(           void             ) throw ();
	};

public:
	class Grade {
		unsigned char	g;
	
		      Grade	             (      void   ) throw ();
	public:
		      Grade	             (const Grade &) throw ();
		      Grade	& operator = (const Grade &) throw ();
		compl Grade	             (      void   ) throw ();
	
		explicit Grade	(const unsigned char & grade) throw ();
	
		Grade	& operator ++ (void) throw (),
		     	  operator ++ (int ) throw () WARN_UNUSED_RESULT,
		     	& operator -- (void) throw (),
		     	  operator -- (int ) throw () WARN_UNUSED_RESULT;
		bool	operator <  (const Grade &) VIEW,
		    	operator >  (const Grade &) VIEW,
		    	operator <= (const Grade &) VIEW,
		    	operator >= (const Grade &) VIEW,
		    	operator == (const Grade &) VIEW,
		    	operator != (const Grade &) VIEW;
	
		operator unsigned short	(void) const throw ();
	};


	// Constants

	static const Grade	c_highest_grade,	c_lowest_grade;


	// Fields

private:
	const std::string	name;
	           Grade 	grade;


	// Canonical Four

public:
	      Bureaucrat	             (      void        ) throw ();
	      Bureaucrat	             (const Bureaucrat &) throw ();
	      Bureaucrat	& operator = (const Bureaucrat &) throw ();
	compl Bureaucrat	             (      void        ) throw ();


	// other Constructors

	explicit Bureaucrat
		(const std::string & name, const unsigned char & grade = c_lowest_grade)
			throw (GradeTooHighException, GradeTooLowException);


	// Accessors

	const std::string	& getName (void) VIEW;
	const      Grade 	& getGrade(void) VIEW;


	// Mutators

	Bureaucrat	& operator ++ (void) throw (GradeTooHighException),
	          	  operator ++ (int ) throw (GradeTooHighException)
	          		WARN_UNUSED_RESULT,
	          	& operator -- (void) throw (GradeTooLowException),
	          	  operator -- (int ) throw (GradeTooLowException)
	          		WARN_UNUSED_RESULT;


	// Methods

# if   __has_include ( "Form.hpp")
	void	signForm(Form  &) const throw ();
# elif __has_include ("AForm.hpp")
	void	signForm(AForm &) const throw ();
# endif

};
#endif
