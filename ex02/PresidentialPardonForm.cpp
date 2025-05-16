/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:36:18 by lgasc             #+#    #+#             */
/*   Updated: 2025/04/11 18:20:33 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream> // cout

#define	CSI	"\x1B["
#define	GR(sequence)	CSI #sequence "m" // graphic


// Constants

const PresidentialPardonForm::SigningGrade
	PresidentialPardonForm::  c_signing_grade (25);
const PresidentialPardonForm::ExecutionGrade
	PresidentialPardonForm::c_execution_grade ( 5);


// Canonical Four

// No default constructor, due to `target` requirement

PresidentialPardonForm::      PresidentialPardonForm
	(const PresidentialPardonForm	& original) throw (): AForm (original) {}

PresidentialPardonForm	& PresidentialPardonForm::operator =
	(const PresidentialPardonForm	& other   ) throw ()
{ AForm::operator = (other); return *this; }

PresidentialPardonForm::compl PresidentialPardonForm
	(      void                  	          ) throw ()                   {}


// other Constructors

PresidentialPardonForm::PresidentialPardonForm	(
	const std::string	& name_arg,
	const std::string	& target_arg
) throw (): AForm (
	name_arg,
	c_signing_grade, c_execution_grade, target_arg
) {}

PresidentialPardonForm::PresidentialPardonForm	(
	const std::string	& target_arg
) throw (const std::domain_error): AForm (
	target_arg + " presidential pardon Formular",
	c_signing_grade, c_execution_grade, target_arg
) {}


// Methods

bool	PresidentialPardonForm::executeAssumingBureacraticApproval(void)
const throw () {
	std::cout << "\t" GR(7)"\tATTENTION PLEASE\t" GR(27)"\t\n"
		GR(1)"The following information be o' great importance:" GR(22)"\n"
		"\t" GR(3)"President Zaphod Beeblebrox today gave pardon to "
		<< getTarget() << "." GR(23)"\n"
		GR(4)"There shall be no repeat." GR(24)"\n"
		GR(2)"You may now resume." GR(22)"\n";
	return true;
}
