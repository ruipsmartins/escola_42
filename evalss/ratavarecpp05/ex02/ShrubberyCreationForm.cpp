#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : 
AForm(copy) {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy) {
		const_cast<std::string&>(this->target) = copy.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	this->canBeExecuted(executor);
	std::ofstream outFile;
	outFile.open((this->target + "_shrubbery").c_str());
	outFile <<
	"                                                         .\n"
	"                                              .         ;\n"
	"                 .              .              ;%     ;;\n"
	"                   ,           ,                :;%  %;\n"
	"                    :         ;                   :;%;'     .,\n"
	"           ,.        %;     %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
	"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'\n"
	"                        `@%.  `;@%.      ;@@%;\n"
	"                          `@%.  `@%%    ;@@%;\n"
	"                            ;@%. :@%%  %@@%;\n"
	"                              %@bd%%%bd%%:;\n"
	"                                #@%%%%%:;;\n"
	"                                %@@%%%::;\n"
	"                                %@@@%(o);  . '\n"
	"                                %@@@o%;:(.,'\n"
	"                            `.. %@@@o%::;\n"
	"                               `)@@@o%::;\n"
	"                                %@@(o)::;\n"
	"                               .%@@@@%::;\n"
	"                              ;%@@@@%::;.\n"
	"                              ;%@@@@%%:;;;.\n"
	"                          ...;%@@@@@%%:;;;;,..";
	outFile.close();
}