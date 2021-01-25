#include <fstream>

int main(int argc, char** argv)
{
	std::fstream fs;
	fs.open("input.txt", std::fstream::out);
	srand(time(NULL));
	int n = rand() % 100;
	for (int i = 0; i < n; ++i)
	{
		fs << rand()% 1000 << ' ';
	}
	fs.close();
	return 0;
}
