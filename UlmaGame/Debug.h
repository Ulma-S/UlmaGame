#pragma once
#include <iostream>

#ifdef _DEBUG
namespace UlmaEngine {
	class Debug {
	public:
		template<class T>
		inline static void Log(T t) {
			std::cout << t << std::endl;
		}

		template<class T>
		inline static void LogError(T t) {
			std::cerr << t << std::endl;
		}
	};
}
#endif // DEBUG