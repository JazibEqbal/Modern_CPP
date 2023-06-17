#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SensorReading.h"
#include "ReadingType.h"
#include "functional"
#include <variant>
#include <list>
#include <optional>

using dataContainer = std::list<SensorReading*>;
using vType = std::variant<int,std::string>;


//function from one data container to vType
extern std::function<  vType(dataContainer)  > findSensorId;

// //function from dataContainer & list of vType to float
extern std::function< float (dataContainer, std::list<vType> ) > findAverageReadingValue;

//function from dataContainer & vType to ReadingType
extern std::function<ReadingType(dataContainer, vType)> findSensorReadingType;

//function from dataContainer & float to dataContainer
extern std::function<std::optional<dataContainer>(dataContainer, float)> findInstancesAboveThreshold;

//function from dataContainer & int to dataContainer
extern std::function<std::optional<dataContainer>(dataContainer,int)> findFirstNInstances;

#endif // FUNCTIONALITIES_H 