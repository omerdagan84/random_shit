#include <stdio.h>
#include <string>

FILE* file = nullptr;

bool open(std::string mode)
{
	file = fopen("test.code", mode.c_str());
	if (!file) return true;
	return false;
}

void close()
{
	std::fflush(file);
	std::fclose(file);
	file = nullptr;
}

int main()
{
	int ret;
	open("wb"); // open file in write binary mode

	std::string str = "abcdefghijklmnop";

	auto sz = str.size();
	fwrite(&sz, sizeof sz, 1, file); // first write size of string
	fwrite(str.c_str(), sizeof(char), sz, file); // second write the string

	close(); // flush the file and close it

	open("rb"); // open file in read binary mode

	std::string retrived_str = "";

	sz = -1;
	fread(&sz, sizeof(size_t), 1, file); // it has the right value (i.e 14) but it seems it seeks 8 bytes more!
	retrived_str.resize(sz+1);
	ret = fread(&retrived_str[0], sizeof(char), sz, file); // it missed the first 8 char

	close(); // flush the file and close it

	std::cout << retrived_str << std::endl;

	return 0;
}
