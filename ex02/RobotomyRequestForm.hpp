/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:07:56 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/13 16:43:20 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <string>

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))

class RobotomyRequestForm: public AForm {
public:
	static const SigningGrade  	c_signing_grade;
	static const ExecutionGrade	c_execution_grade;

private:
	RobotomyRequestForm              	(void) throw ();
public:
	RobotomyRequestForm	             (const RobotomyRequestForm &) throw ();
	RobotomyRequestForm	& operator = (const RobotomyRequestForm &) throw ();
	virtual compl RobotomyRequestForm	(void) throw ();

	explicit RobotomyRequestForm	(const t_name &, const t_target &) throw ();
	explicit RobotomyRequestForm	(                const t_target &) throw ();

private:
	virtual bool	executeAssumingBureacraticApproval(void) const
		throw () WARN_UNUSED_RESULT;
};

# undef WARN_UNUSED_RESULT
#endif
