/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:48:17 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/13 16:39:29 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <string>

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))

class ShrubberyCreationForm: public AForm {
public:
	static const   SigningGrade	c_signing_grade;
	static const ExecutionGrade	c_execution_grade;

private:
	typedef ShrubberyCreationForm	t_self;

	ShrubberyCreationForm              	(void) throw ();
public:
	ShrubberyCreationForm	             (const t_self &) throw ();
	ShrubberyCreationForm	& operator = (const t_self &) throw ();
	virtual compl ShrubberyCreationForm	(void) throw ();

	explicit ShrubberyCreationForm	(const t_name &, const t_target &) throw ();
	explicit ShrubberyCreationForm	(                const t_target &) throw ();

private:
	virtual bool	executeAssumingBureacraticApproval(void)
		const throw () WARN_UNUSED_RESULT;
};

# undef WARN_UNUSED_RESULT
#endif
