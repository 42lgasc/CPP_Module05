/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:17:21 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/06 16:53:22 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream> // cout, cerr #+DEBUG clog, endl

#include <cstdlib> // srand, rand
#include <ctime>

#define	CSI	"\x1B["
#define	GR(sequence)	CSI #sequence "m" // graphic


// Constants

const RobotomyRequestForm::SigningGrade
	RobotomyRequestForm::c_signing_grade   (72);
const RobotomyRequestForm::ExecutionGrade
	RobotomyRequestForm::c_execution_grade (45);


// Canonical Four

// No default constructor, due to `target` requirement

RobotomyRequestForm::      RobotomyRequestForm
	(const RobotomyRequestForm	& original) throw (): AForm (original)
{                                          }

RobotomyRequestForm	& RobotomyRequestForm::operator =
	(const RobotomyRequestForm	& other) throw ()
{ AForm::operator = (other); return *this; }

RobotomyRequestForm::compl RobotomyRequestForm	(void) throw ()
{                                          }


// other Constructors

RobotomyRequestForm::RobotomyRequestForm	(
	const std::string	& name_arg,
	const std::string	& target_arg
) throw (): AForm (
	name_arg,
	c_signing_grade, c_execution_grade, target_arg
) {
#if defined DEBUG && DEBUG
	std::clog << GR(7;37) << __PRETTY_FUNCTION__ << '\t' << this
		<< '\t' << & target_arg << '\t' << target_arg
		<< '\t' << & getTarget() << '\t' << getTarget() << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm	(
	const std::string	& target_arg
) throw (): AForm (
	target_arg + " robotomy request Formular",
	c_signing_grade, c_execution_grade, target_arg
) {}


// Methods

bool	RobotomyRequestForm::executeAssumingBureacraticApproval(void)
		const throw () {
	std::cout << GR(1;2;3;5)"**DRRRIIIIILLLLLLL**" GR(22;23;25)"\n";
	// FIXME: This might be a wrong way to seed, and thus might not be random.
	if (std::srand(std::time(static_cast<time_t *> (NULL))), std::rand() % 2) {
		std::cout << "Robotomimzation of " << getTarget() << " successfull\n";
		return true;
	 } else {
		std::cerr << "Robotomimzation of " << getTarget()
			<< " ends total in failure.\n";
		return false;
	 }
}
