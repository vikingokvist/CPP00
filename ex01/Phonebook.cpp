#include "Phonebook.hpp"

Phonebook::Phonebook(void) : index(1) {}

void	Phonebook::addContact(void)
{
	if (index >= 9)
		index = 1;
	if (!contacts[index - 1].setContact())
		return ;
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

	int			index = -1;
	std::string input;

	std::cout << std::endl << "Enter Index for Full Details: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		index = input[0] - '0';
		if (index >= 1 && index <= 8)
		{
			if (!contacts[index - 1].isEmpty())
				contacts[index - 1].displayFull();
			else
				std::cout << std::endl << "No Contact Found at this Index!!!" << std::endl;
		}

	}
	else
		std::cout << std::endl << "Invalid Index!!!" << std::endl;
}