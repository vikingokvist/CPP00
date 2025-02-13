#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	index = 1;
}

void	Phonebook::addContact(void)
{
	if (index >= 9)
		index = 1;
	contacts[index - 1].setContact();
	index++;
}

void	Phonebook::searchContact(void)
{
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|" 
		<< std::endl;
	
	for (int i = 0; i < 8; i++)
		contacts[i].displayShort(i);

	int			index;
	std::string input;

	std::cout << std::endl << "Enter Index for Full Details: ";
	std::cin.ignore();
	if (!(std::getline(std::cin, input)))
	{
		std::cout << std::endl << "Invalid Index" << std::endl;
		return ;
	}
	for (int i = 0; input[i]; i++)
	{
		if (!std::isdigit(input[i]))
		{
				std::cout << std::endl << "Invalid Index" << std::endl;
				return ;
		}
	}
	index = input[0];
	if (index >= 1 && index <= 8)
	{
		if (!contacts[index - 1].isEmpty())
			contacts[index - 1].displayFull();
		else
			std::cout << std::endl << "No Contact Found at this Index!!!" << std::endl << std::endl;
	}
	else
		std::cout << std::endl << "Invalid Index" << std::endl;

}