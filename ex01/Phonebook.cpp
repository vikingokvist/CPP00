#include <iostream>
#include <string>


class Phonebook
{
	public:
		std::string name;
		int phone;
};

void	PrintUserName(Phonebook &contact)
{
	std::cout << "Name: " << contact.name << std::endl;
}

void	PrintUserPhone(Phonebook &contact)
{
	std::cout << "Phone: " << contact.phone << std::endl;
}

int	main(void)
{
	Phonebook new_contact;
	Phonebook new_contact2;

	new_contact.name = "John";
	new_contact.phone = 999646780;
	new_contact2.name = "Jean";
	new_contact2.phone = 99947621;
	PrintUserName(new_contact);
	PrintUserPhone(new_contact);
	PrintUserName(new_contact2);
	PrintUserPhone(new_contact2);
	return (0);
}