#pragma once
#include <iostream>
#define DEBUG

#ifdef DEBUG
namespace System {
	class Debug {
	public:
		template<class T>
		inline static void Log(T t) {
			std::cout << t << std::endl;
		}
	};
}
#endif // DEBUG