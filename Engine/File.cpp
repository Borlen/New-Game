#include "File.h"

std::string File::GetString(std::string filePath)
{
	std::string string;
	std::ifstream file("game.txt");

	string = file.get();
	if (!file.good())
	{
		return "";
	}

	for (string += file.get(); file.good(); string += file.get())
	{
	}

	file.close();
	return string;
}
