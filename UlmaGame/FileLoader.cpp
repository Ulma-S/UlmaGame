#include <iostream>
#include <fstream>
#include "FileLoader.h"
#include "Debug.h"

using namespace System::Core;

FileLoader::FileLoader(){}


FileLoader::~FileLoader() {

}


bool FileLoader::LoadFile(const std::string& fileName, char** out) const {
	std::ifstream fstr(fileName, std::ios::binary);
	if (fstr.fail()) {
		System::Debug::LogError(fileName + "ÇÃì«Ç›çûÇ›Ç…é∏îsÇµÇ‹ÇµÇΩÅB");
		return false;
	}

	const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);
	*out = new char[fileSize];
	fstr.read(*out, fileSize);
	return true;
}
