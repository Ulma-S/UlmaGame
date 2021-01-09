#pragma once
#include <string>
#include "Singleton.h"

namespace UlmaEngine {
	namespace Core {
		class FileLoader : public Singleton<FileLoader> {
		public:
			~FileLoader();

			bool LoadFile(const std::string& fileName, char** out) const;

		protected:
			friend Singleton<FileLoader>;
			FileLoader();
		};
	}
}