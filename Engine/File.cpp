#include "File.h"

std::string File::GetString(std::string filePath)
{
	std::string string;
	std::ifstream file(filePath);

	string = file.get();
	if (!file.good())
	{
		//Add warning empty/nonexistant file?
		return "";
	}

	for (string += file.get(); file.good(); string += file.get())
	{
	}

	file.close();
	return string;
}
