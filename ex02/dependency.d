main.o: main.cpp ShrubberyCreationForm.hpp AForm.hpp Bureaucrat.hpp \
  RobotomyRequestForm.hpp PresidentialPardonForm.hpp
ShrubberyCreationForm.o: ShrubberyCreationForm.cpp \
  ShrubberyCreationForm.hpp AForm.hpp Bureaucrat.hpp
RobotomyRequestForm.o: RobotomyRequestForm.cpp RobotomyRequestForm.hpp \
  AForm.hpp Bureaucrat.hpp
PresidentialPardonForm.o: PresidentialPardonForm.cpp \
  PresidentialPardonForm.hpp AForm.hpp Bureaucrat.hpp
AForm.o: AForm.cpp AForm.hpp Bureaucrat.hpp
Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp AForm.hpp
