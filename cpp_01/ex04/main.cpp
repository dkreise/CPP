#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string word1;
	std::string word2;
	std::string line;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		std::cout << "Please put name of the file and two strings" << std::endl;
		return (1);
	}
	filename = argv[1]; // protect it?
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream ifs(filename);
	std::getline(ifs, line);
	//ifs >> word1 >> word2;
	ifs.close();

	std::ofstream ofs(filename += ".replace");
	//ofs << word1 << " " << word2;
	ofs << line;
	ofs.close();
}