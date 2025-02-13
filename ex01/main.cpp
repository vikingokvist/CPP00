#include "Phonebook.hpp"
#include <iostream>

int		main(void)
{
	Phonebook 	phoneBook;
	std::string command;

	while (true)
	{
		std::cout << std::endl <<"Enter Command: (ADD, SEARCH, EXIT): ";
		if (!(std::getline(std::cin, command)))
		{
			std::cout << std::endl <<"Exiting Phonebook" << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting Phonebook" << std::endl;
			break ;
		}
		else
			std::cout << "Command not found" << std::endl;
	}
	return (0);
}
