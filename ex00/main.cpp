/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:24:24 by lgasc             #+#    #+#             */
/*   Updated: 2024/11/11 18:57:05 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <exception>
#include <iostream> // cerr, cout, endl

void	ft_warn(const std::exception &) throw ();

int	main(void) throw () {
	const Bureaucrat	malcol ("Malcol", 25),	malcol2 (malcol);
	Bureaucrat	malcol3 ("Malcol Ⅲ");
	malcol3 = malcol2;

	try { Bureaucrat ("Iznogoud",	+ Bureaucrat::highest_grade - 1); }
	catch (const std::exception	& e) { ft_warn(e); }
	try { Bureaucrat ("Gero",		+ Bureaucrat::lowest_grade + 1); }
	catch (const std::exception	& e) { ft_warn(e); }

	std::cout << malcol3.getName() << '\n' << malcol3.getGrade() << '\n';

	std::cout <<	malcol3 ++.getGrade() << ' '
		<<			(++ malcol3).getGrade() << ' '
		<<			malcol3 --.getGrade() << ' '
		<<			(-- malcol3).getGrade() << '\n';

	try { ++ Bureaucrat ("System32",		+ Bureaucrat::highest_grade); }
	catch (const std::exception	& e) { ft_warn(e); }
	try {
		std::cout << Bureaucrat ("systemd",	+ Bureaucrat::highest_grade)	++;
	}
	catch (const std::exception	& e) { ft_warn(e); }
	try { -- Bureaucrat ("Clippy",				+ Bureaucrat::lowest_grade); }
	catch (const std::exception	& e) { ft_warn(e); }
	try {
		std::cout << Bureaucrat ("chrome.exe",	+ Bureaucrat::lowest_grade)	--;
	}
	catch (const std::exception	& e) { ft_warn(e); }

	std::cout << malcol << ';' << malcol2 << ';' << malcol3 << '\n';
}

void	ft_warn(const std::exception	& e) throw ()
		{ std::cerr << "\x1B[33m" << e.what() << "\x1B[0m" << std::endl; }
