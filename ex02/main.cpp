/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:44:47 by lgasc             #+#    #+#             */
/*   Updated: 2025/05/15 12:14:32 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <ios> // boolalpha
#include <iostream> // cout, cerr #+DEBUG clog, endl

namespace {
	void	ft_print_test(const AForm &) throw ();
	template <typename E, size_t B>
	void	ft_for_each(E *const (&) [B], void (const E &) throw ()) throw ();
	#if false // ft_bound_for_each
	template <typename E, class T>
	void	ft_bound_for_each(E *const (&) [], const T &, p_bureaucracy_act &)
		throw ();
	#endif
	template <const size_t B>
	void	ft_sign_each(AForm *const (&) [B], const Bureaucrat &) throw ();
}

#define	CSI	"\x1B[" // Control Sequence Introducer
#define	GR(CODES)	CSI #CODES "m" // graphic control sequence


int	main(void) {
	typedef  ShrubberyCreationForm	Scf;
	typedef    RobotomyRequestForm	Rrf;
	typedef PresidentialPardonForm	Ppf;

	const Scf	scf ("beech"),	scf2 (scf),	scf2_2 (Scf ("toy"));
	Scf	scf3 ("birchy shrubbin' Formular", "birch");
	scf3 = scf2, scf3 = Scf ("conker tree");

	#if defined DEBUG && DEBUG
	std::clog
		<< GR (7;90) << __PRETTY_FUNCTION__ << " @ " __FILE__":" << __LINE__
		<< '\t' << scf.getTarget() << '\t' << scf2.getTarget() <<
		'\t' << scf2_2.getTarget() << '\t' << scf3.getTarget() <<
		GR (27;39) << std::endl;
	#endif

	const Rrf	rrf ("Tin Woodman"),	rrf2 (rrf),	rrf2_2 (Rrf ("Brat"));
	Rrf	rrf3   ("earthlin' robotomy request Formular", "Ness and friends");
	rrf3 = rrf2, rrf3 = Rrf ("lord Frieza");

	#if false // try catch
	try {
	#endif
	const Ppf
		ppf    (     "the dust army"  ),
		ppf2   (      ppf             ),
		ppf2_2 (Ppf ("prince Charmin'"));
	Ppf	ppf3 ("thee presidential self pardon Formular", "theeself");
	ppf3 = ppf2, ppf3 = Ppf ("the suction cup man");

	AForm	*const forms []
		= { & scf3, & rrf3, & ppf3, static_cast<AForm *const &> (NULL) };


	std::cout << std::boolalpha, std::cerr << std::boolalpha;

	ft_for_each<AForm>(forms, ft_print_test);

	ft_sign_each(forms, Bureaucrat ("Leice Betton", 146));
	for (size_t	i = 0; forms [i]; ++i)
		std::cout << *forms [i] << "\n";

	if (scf.execute(Bureaucrat ())) std::cerr << GR (1;3;35)"Done.\n";
	else std::cout << GR (36)"Execution require Formular signature.\n";
	if (rrf.execute(Bureaucrat ())) std::cerr << GR (1;3;35)"Done.\n";
	else std::cout << GR (36)"Execution require Formular signature.\n";
	if (ppf.execute(Bureaucrat ())) std::cerr << GR (1;3;35)"Done.\n";
	else std::cout << GR (36)"Execution require Formular signature.\n";


	ft_sign_each(forms, Bureaucrat
			("Abann Daune"  , ShrubberyCreationForm:: c_signing_grade    ));
	ft_sign_each(forms, Bureaucrat
			("Houb Lye"     , RobotomyRequestForm::   c_signing_grade - 1));
	ft_sign_each(forms, Bureaucrat
			("Nipan Seupa"  , RobotomyRequestForm::   c_signing_grade    ));
	ft_sign_each(forms, Bureaucrat
			("Recon Siderre", PresidentialPardonForm::c_signing_grade - 1));
	ft_sign_each(forms, Bureaucrat
			("Jacques Sept" , PresidentialPardonForm::c_signing_grade    ));
	ft_sign_each(forms, Bureaucrat
			("Jeudi Wee"    , PresidentialPardonForm::c_signing_grade + 1));

	const AForm	& as (scf3),	& ar (rrf3),	*const ap (& ppf3);
	try {
		const bool success = as .execute(Bureaucrat
			("Super A", ShrubberyCreationForm::c_execution_grade - 1));
		std::cerr << GR (1;3;35)"Done. ("
			<< "unsuccesfully)" GR ()"\n" [success * 2];
	} catch (const AForm::GradeTooLowException	& e)
	{ std::cout << GR (36)"The executor's " << e.what() << ".\n"; }
	if (ar .execute(Bureaucrat ("Super B"))) std::cerr << "Abstract.\n";
	else std::cout << "Execat\n";
	if (ap->execute(Bureaucrat ("Super C"))) std::cerr << "Abstract.\n";
	else std::cout << "Execat\n";
	#if false // try catch
	} catch (std::domain_error	& e)
	{ std::cerr << GR (31) << e.what() << ", with leak!\n" GR (); }
	#endif

	// TODO
	//executeForm
}

namespace {
	void	ft_print_test(const AForm	& f) throw () {
		std::cout << GR (90)"abstract Form @ " << & f << " {\n"
				"\t     name:           \t" << f.getName          () << ",\n"
				"\t     target:         \t" << f.getTarget        () << ",\n"
				"\thave signature:      \t" << f.hasSignature     () << ",\n"
				"\t     signing   grade:\t" << f.getSigningGrade  () << ",\n"
				"\t     execution grade:\t" << f.getExecutionGrade() << "\n"
			"}:\t" << f << GR (39)"\n";
	}

	template <typename E, size_t B>
	void	ft_for_each(E *const (& array) [B], void	viewing(const E &))
	throw () {
		for (size_t	i = 0; array [i]; ++i) viewing(*array [i]);
	}

	#if false // ft_bound_for_each
	static void	ft_bound_for_each(
		AForm	*const (& forms) [],
		const Bureaucrat	& b,
		p_bureaucracy_act	& a
	) throw () {
		for (size_t	i = 0; forms [i]; ++ i) (b.*a)(*forms [i]);
	}
	#endif

	template <size_t B>
	void	ft_sign_each(AForm	*const (& forms) [B], const Bureaucrat	& b)
	throw () {
		for (size_t	i = 0; forms [i]; ++i) b.signForm(*forms [i]);
	}
}


#undef CSI
#undef GR
