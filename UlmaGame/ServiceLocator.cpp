#include "ServiceLocator.h"

using namespace UlmaEngine;

std::unordered_map<std::type_index, std::any> ServiceLocator::s_registeredInstances = {};

ServiceLocator::~ServiceLocator() {
	std::unordered_map <std::type_index, std::any>().swap(s_registeredInstances);
}
