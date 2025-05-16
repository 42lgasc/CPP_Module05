/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:25:06 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/13 17:05:27 by lgasc            ###   ########.fr       */
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



// outer Class

class Bureaucrat {
public:
	// inner Classes

	typedef unsigned char	t_grade_num;
	class Grade {
		t_grade_num	g;
	
		      Grade	             (      void   ) throw ();
	public:
		      Grade	             (const Grade &) throw ();
		      Grade	& operator = (const Grade &) throw ();
		compl Grade	             (      void   ) throw ();
	
		explicit Grade	(const unsigned char & grade) throw ();
	
		Grade
			& operator ++ (void) throw (),
			  operator ++ (int ) throw () WARN_UNUSED_RESULT,
			& operator -- (void) throw (),
			  operator -- (int ) throw () WARN_UNUSED_RESULT;
		bool
			operator <  (const Grade &) VIEW,
			operator >  (const Grade &) VIEW,
			operator <= (const Grade &) VIEW,
			operator >= (const Grade &) VIEW,
			operator == (const Grade &) VIEW,
			operator != (const Grade &) VIEW;
	
		// Explicit conversion requires C++11.
		// 	operator unsigned short	(void) const throw ();
		const t_grade_num	& operator *(void) const throw ();

		Grade	operator + (const t_grade_num &) VIEW;
		Grade	operator - (const t_grade_num &) VIEW;
	};

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

	typedef const std::string	t_name;


	// Constants

	static const Grade	c_highest_grade,	c_lowest_grade;


	// Fields

private:
	const t_name 	name;
	        Grade	grade;


	// Canonical Four

public:
	      Bureaucrat	             (      void        ) throw ();
	      Bureaucrat	             (const Bureaucrat &) throw ();
	      Bureaucrat	& operator = (const Bureaucrat &) throw ();
	compl Bureaucrat	             (      void        ) throw ();


	// other Constructors

	explicit Bureaucrat	(const t_name &, const Grade & = c_lowest_grade)
		throw (GradeTooHighException, GradeTooLowException);
	explicit Bureaucrat	(const t_name &, const t_grade_num &)
		throw (GradeTooHighException, GradeTooLowException);


	// Accessors

	const std::string	& getName (void) VIEW;
	const      Grade 	& getGrade(void) VIEW;


	// Mutators

	Bureaucrat
		& operator ++ (void) throw (GradeTooHighException),
		  operator ++ (int ) throw (GradeTooHighException) WARN_UNUSED_RESULT,
		& operator -- (void) throw (GradeTooLowException ),
		  operator -- (int ) throw (GradeTooLowException ) WARN_UNUSED_RESULT;

# if __has_include ("Form.hpp") or __has_include ("AForm.hpp")
	// Methods

#  if   __has_include ( "Form.hpp")
	void	signForm( Form &) const throw ();
#  elif __has_include ("AForm.hpp")
	void	signForm(AForm &) const throw ();
#  endif
# endif
};



// frens ·‿·

std::ostream
	& operator << (std::ostream &, const Bureaucrat &),
	& operator << (std::ostream &, const Bureaucrat::Grade &);
# undef WARN_UNUSED_RESULT
# undef VIEW
#endif
