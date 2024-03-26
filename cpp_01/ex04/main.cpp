#include <iostream>
#include <fstream>

int invalid_args(std::ifstream & ifs, std::ofstream & ofs, int len1)
{
	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error: file was unable to open" << std::endl;
		return (1);
	}
	if (len1 == 0)
	{
		std::cout << "Error: first string is empty" << std::endl;
		return (1);
	}
	return (0);
}

void replace(std::ifstream & ifs, std::ofstream & ofs, std::string s1, std::string s2)
{
	std::string line;
	int len1;
	int len2;
	int pos;
	int line_len;

	len1 = s1.length();
	len2 = s2.length();
	while (std::getline(ifs, line))
	{
		pos = line.find(s1);
		line_len = line.length();
		while (pos >= 0 && pos < line_len)
		{
			line.erase(pos, len1);
			line.insert(pos, s2);
			pos = line.find(s1, pos + len2);
			line_len = line.length();
		}
		ofs << line << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		std::cout << "Please put name of the file and two strings" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	std::ifstream ifs(filename);
	std::ofstream ofs(filename += ".replace");

	if (invalid_args(ifs, ofs, s1.length()))
		return (1);

	replace(ifs, ofs, s1, s2);
	
	ifs.close();
	ofs.close();

	return (0);
}