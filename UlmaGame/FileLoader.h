#pragma once
#include <string>
#include "Singleton.h"

namespace System {
	namespace Core {
		class FileLoader : public General::Singleton<FileLoader> {
		public:
			~FileLoader();

			bool LoadFile(const std::string& fileName, char* out) const;

		protected:
			friend General::Singleton<FileLoader>;
			FileLoader();
		};
	}
}