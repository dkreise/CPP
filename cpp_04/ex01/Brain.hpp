#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
	public:
		Brain(void);
		Brain(const Brain & src);
		~Brain(void);

		Brain & operator=(const Brain & r);

	private:
		std::string ideas[100];
};

#endif