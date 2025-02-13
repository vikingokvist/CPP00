#include "Contact.hpp"

void	Contact::setContact()
{
	std::cout << std::endl;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	std::cout << std::endl << "Contact Added to the Phonebook" << std::endl;
}

void	Contact::displayShort(int index)
{
	std::cout << std::setw(10) << (index + 1) % 9 << "|"
		<< std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
		<< std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
		<< std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName) << "|"
		<< std::endl;
}

void	Contact::displayFull()
{
	std::cout << std::endl;
	std::cout << "Firstname: " << firstName << std::endl;
	std::cout << "Lastname: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << std::endl;
}

bool	Contact::isEmpty()
{
	return (firstName.empty());
}