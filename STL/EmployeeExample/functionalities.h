#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employe.h"
#include <list>
#include <optional>
#include <algorithm>
#include <iostream>

std::optional<std::list<Employe*>> FindEmployeeAboveThreshold(std::list<Employe *> &obj, float threshold);

std::optional<const Employe*> FindEmployeeWithGivenId(std::list<Employe *> &obj, std::string id);

float FindCombinedSalary(std::list<Employe *> &obj);

#endif // FUNCTIONALITIES_H
