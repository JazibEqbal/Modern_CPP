#include "SensorReading.h"
#include "ReadingType.h"
#include "functional"
#include <variant>
#include <algorithm>
#include <list>
#include <optional>

using dataContainer = std::list<SensorReading *>;
using vType = std::variant<int, std::string>;

/*
    Find the sensor ID for sensor with highest sensorReadingValue
*/


// function from one data container to vType
std::function<vType(dataContainer)> findSensorId = [](dataContainer data)
{
    auto itr = std::max_element(
        data.begin(), 
     
        data.end(), 
     
        [](SensorReading* obj1, SensorReading* obj2){  
            return obj1->getReadingValue() < obj2->getReadingValue(); 
        }
    );
    return (*itr)->getSensorId();
};

// function from dataContainer & list of vType to float

/*
               1, 4, 5
1
2               
3
4
5
*/


std::function<float(dataContainer, std::list<vType>)> findAverageReadingValue=[](dataContainer data, std::list<vType> idList){
    float total = 0.0f;
    int count  = 0;
    
    for( auto id : idList ){

        for(auto* ptr : data){

            if(ptr->getSensorId() == id){
                total += ptr->getReadingValue();
                count++;
            }

        }
    }

    return (total/count);

};

/*
    taking one id from the user as a parmeter.
    It then finds the iterator to the element matching with the ID
    We can then return the reading type
*/

// // function from dataContainer & vType to ReadingType
std::function<ReadingType(dataContainer, vType)> findSensorReadingType=[](dataContainer data, vType id){
    
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&]( SensorReading* ptr  ){   return ptr->getSensorId() == id;   }
    );
    if(itr == data.end()){
        throw std::runtime_error("Did not find with this sensor ID");
    }
    return (*itr)->getReadingType();
};

/*
    We need to copy all elements whose senorReading is above threshold 
    into results and return it!
*/

// // function from dataContainer & float to dataContainer
std::function<std::optional<dataContainer>(dataContainer, float)> findInstancesAboveThreshold=[](dataContainer data, float threshold){
    dataContainer results(data.size());

    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        results.begin(),
        [threshold](SensorReading* ptr){  return ptr->getReadingValue() > threshold;   }
    );

    //after copy, adjust the final size of your results variable
    results.resize(     std::distance(results.begin(), itr)     );

    return results;
};

// // function from dataContainer & int to dataContainer
std::function<std::optional<dataContainer>(dataContainer, int)> findFirstNInstances=[](dataContainer data, int N){
    
    if(N > data.size() || N < 0){
        std::runtime_error("Invalid N value");
    }
    
    auto itr = std::next(  data.begin() , N  );
  
    //create results list by copying data from beginning to itr position
    dataContainer results(data.begin(), itr);

    return results;
};

/*

    copy, copy if
    find_if
    next
    distance
    accumulate
    transform
    max_element


*/