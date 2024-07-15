#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("*no target*") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void ShrubberyCreationForm::executeForm(void) const
{
    std::ofstream treeFile;
    
    treeFile.open((this->_target + "_shrubbery").c_str());
    if (treeFile.is_open() == false)
    {
        std::cerr << "Error: file was unable to open." << std::endl;
        return ;
    }
    treeFile << std::endl;
    treeFile << "                @@@@@@@," << std::endl;
    treeFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    treeFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    treeFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    treeFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    treeFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    treeFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    treeFile << "       |o|        | |         | |" << std::endl;
    treeFile << "       |.|        | |         | |" << std::endl;
    treeFile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    treeFile.close();
}