/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:00 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/28 23:20:51 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <exception>
#include <iostream> // boolalpha, cerr, cout, endl

void	ft_warn(const std::exception &);


int	main(void) {
	const Form	f,	f2 (f);
	Form		f3;
	f3 = f2;
	Form	mapping ("source Mapping"),	splicing ("line Splicing"),
		lexing ("Lexing"),	preprocessing ("Preprocessing", 13, 80),
		determination ("encoding Determination"),
		concatenation ("Concatenation"),	compiling ("Compiling", 62, 57),
		instantiation ("template Instantiation"),	linking ("Linking", 41, 93);

	try {
		Form ("school Acquisition",
				++ Form::SigningGrade (Form::c_highest_signing_grade),
				Form::ExecutionGrade (86));
	}
	catch (const std::exception	& e) { ft_warn(e); }
	try {
		Form ("school Acquisition", -- Form::SigningGrade
				(Form::c_lowest_signing_grade), Form::ExecutionGrade (86));
	}
	catch (const std::exception	& e) { ft_warn(e); }
	try {
		Form ("school Acquisition", Form::SigningGrade (25),
				++ Form::ExecutionGrade (Form::c_highest_execution_grade));
	}
	catch (const std::exception	& e) { ft_warn(e); }
	try {
		Form ("school Acquisition", Form::SigningGrade (25),
				-- Form::ExecutionGrade (Form::c_lowest_execution_grade));
	}
	catch (const std::exception	& e) { ft_warn(e); }

	std::cout << std::boolalpha << "{ " << mapping.getName() << ", "
		<< mapping.getSigningGrade() << ", " << mapping.getExecutionGrade()
		<< ", " << mapping.hasSignature() << " }\n";

	std::cout << splicing << '\n';

	preprocessing.beSigned(Bureaucrat ("Bruce Wayne", 11));
	try { compiling.beSigned(Bureaucrat ()); }
	catch (const std::exception	& e) { ft_warn(e); }

	Bureaucrat ("His Highness Reiko", 6).signForm(compiling);
	Bureaucrat ().signForm(linking);
	Bureaucrat ().signForm(compiling);
}


void	ft_warn(const std::exception	& e)
{ std::cerr << "\x1B[33m" << e.what() << "\x1B[39m\n"; }
