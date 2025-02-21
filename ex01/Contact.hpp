#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	
	public:
		Contact();
		~Contact();
		bool	setContact(void);
		bool	unsetContact(void);
		void	displayShort(int index);
		void	displayFull(void);
		bool	isEmpty(void);
};

#endif
