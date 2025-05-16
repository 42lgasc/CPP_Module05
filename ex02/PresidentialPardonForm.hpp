/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:31:02 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/13 16:44:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include <string>

# define WARN_UNUSED_RESULT	__attribute__ ((warn_unused_result))

class PresidentialPardonForm: public AForm {
public:
	static const SigningGrade  	c_signing_grade;
	static const ExecutionGrade	c_execution_grade;

private:
	typedef PresidentialPardonForm	t_self;

	              PresidentialPardonForm	(void) throw ();
public:
	  PresidentialPardonForm	             (const t_self &) throw ();
	t_self                  	& operator = (const t_self &) throw ();
	virtual compl PresidentialPardonForm	(void) throw ();

	explicit PresidentialPardonForm	(const t_name &, const t_target &)
		throw ();
	explicit PresidentialPardonForm	(                const t_target &)
		throw (const std::domain_error);

# if not (defined DEBUG and DEBUG)
private:
# endif
	virtual bool	executeAssumingBureacraticApproval(void)
		const throw () WARN_UNUSED_RESULT;
};
#endif
