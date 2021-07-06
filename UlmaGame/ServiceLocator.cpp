#include "ServiceLocator.h"

using namespace UlmaEngine;

std::unordered_map<std::type_index, std::any> ServiceLocator::s_registeredInstances = {};