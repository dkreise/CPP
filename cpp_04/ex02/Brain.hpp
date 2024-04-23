#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain & src);
		~Brain(void);

		Brain & operator=(const Brain & r);

		void printIdeas(void) const;
		void addIdea(std::string idea);

	private:
		std::string _ideas[100];
		unsigned int _ind;
		unsigned int _last_ind;
};

#endif