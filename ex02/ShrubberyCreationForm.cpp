/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:38:12 by lgasc             #+#    #+#             */
/*   Updated: 2025/03/10 16:45:17 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream> // ofstream
#include <ios> // ios_base::app
#include <string>

#if defined DEBUG && DEBUG
# include <iostream> // clog, endl

# define	   LOG	GR ( 7;90)
# define	NO_LOG	GR (27;39)

# define	CSI	"\x1B["
# define	GR(sequence)	CSI #sequence "m" // graphic
#endif


// Constants

const ShrubberyCreationForm::SigningGrade
	ShrubberyCreationForm::c_signing_grade   (145);
const ShrubberyCreationForm::ExecutionGrade
	ShrubberyCreationForm::c_execution_grade (137);


// Canonical Four

// No default constructor, due to `target` requirement.

ShrubberyCreationForm::      ShrubberyCreationForm
	(const ShrubberyCreationForm	& original) throw (): AForm (original) {
#if defined DEBUG && DEBUG
	std::clog << LOG GR(34) << __PRETTY_FUNCTION__ << '\t' << this
		<< '\t' << & getName() << NO_LOG"\tDEBUG:\t" << DEBUG << std::endl;
#endif
}

ShrubberyCreationForm	& ShrubberyCreationForm::operator =
	(const ShrubberyCreationForm	& other   ) throw ()                   {
#if defined DEBUG && DEBUG
	std::clog << LOG GR(35) << __PRETTY_FUNCTION__
		<< '\t' << this       << '\t' << & getName() << NO_LOG << std::endl;
#endif

	AForm::operator = (other);
	return *this;
}

ShrubberyCreationForm::compl ShrubberyCreationForm
	(      void                 	          ) throw ()                   {
#if defined DEBUG && DEBUG
	std::clog << LOG GR(33) << __PRETTY_FUNCTION__
		<< '\t' << this       << '\t' << & getName() << NO_LOG << std::endl;
#endif
}


// other Constructors

ShrubberyCreationForm::ShrubberyCreationForm	(
	const std::string	& name_arg,
	const std::string	& target_arg
) throw (): AForm (
	name_arg,
	c_signing_grade, c_execution_grade, target_arg
) {
#if defined DEBUG && DEBUG
	std::clog << LOG GR(32) << __PRETTY_FUNCTION__
		<< '\t' << this       << '\t' << & getName() << NO_LOG << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm	(
	const std::string	& target_arg
) throw (): AForm (
	target_arg + " shrubbery creation Formular",
	c_signing_grade, c_execution_grade, target_arg
) {
#if defined DEBUG && DEBUG
	std::clog << LOG GR(36) << __PRETTY_FUNCTION__
		<< " @ " __FILE__":" << __LINE__
		<< '\t' << this       << '\t' << & getName() << '\t' << getName()
		<< '\t' << target_arg << '\t' << getTarget() << NO_LOG << std::endl;
#endif
}


// Methods

bool	ShrubberyCreationForm::executeAssumingBureacraticApproval(void)
    		const throw () {
	// Append shrubs if the file already exist
	std::ofstream
		file ((getTarget() + "_shrubbery").c_str(), std::ios_base::app);
	if (not file) return false;

	file
		<< "    .~\"\"\"~~.,  \n"
		   "  .{   , *  ... \n"
		   " {  \"\"\"   {    }\n"
		   "{   * .~.{   * }\n"
		   " ',,~`\\  /""/~..' \n"
		   "       )  )     \n"
		   "       / /      \n"
		   "   __~'  L_     \n"
		<< '\n'
		<< " .\"\"~~. \n"
		   "{ o    }\n"
		   " \"\"\\~/\" \n"
		   "  _| L  \n"
		<< '\n'
		<< "{.\"}\n"
		   " || \n";

	return true;
}
