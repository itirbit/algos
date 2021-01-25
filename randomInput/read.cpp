#include <fstream>
#include <iostream>

int main()
{
	std::fstream fs;
	fs.open("input.txt", std::fstream::in);
	if (fs.is_open())
	{
		std::string line;
		while(getline(fs,line, ' '))
		{
			std::cout << line << '\n';
		}
	}
	else 
	{
		std::cout << "unable to open file\n";
	}
	fs.close();
}
