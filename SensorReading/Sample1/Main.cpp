#include "SensorReading.h"
#include "ReadingType.h"
#include "functional"
#include <variant>
#include <list>
#include <optional>
#include "Functionalities.h"


using dataContainer = std::list<SensorReading*>;
using vType = std::variant<int,std::string>;

int main(){

    dataContainer data;
    
    data.emplace_back(   new SensorReading(101,"R101",ReadingType::ACCEPTABLE, 10.21) );
    data.emplace_back(   new SensorReading(102,"R102",ReadingType::DEFAULT, 9.67) );
    data.emplace_back(   new SensorReading(103,"R103",ReadingType::ERROR, 2.21) );    
    data.emplace_back(   new SensorReading(104,"R104",ReadingType::ACCEPTABLE, 11.21) );    
    data.emplace_back(   new SensorReading(105,"R105",ReadingType::ACCEPTABLE, 8.21) ); 

    vType ans = findSensorId(data);

    std::cout <<"Sensor ID found ";
    std::visit([](auto& arg){std::cout << arg;}, ans);
    std::cout<<"\n";

    auto thresholdResult = findInstancesAboveThreshold(data, 7.0f);

    if(thresholdResult.has_value()){
        std::cout << "Above threshold found: \n";

        for(auto item : thresholdResult.value()){
            std::cout << *item<<'\n';
        }
    }
    else{
        std::cout << "Above threshold instances not found\n";
    }

    auto result = findFirstNInstances(data,1);
        
    if(result.has_value()){
        std::cout << "First N instances found: \n";
        for(auto item : result.value()){
            std::cout << *item<<'\n';
        }
    }
    else{
        std::cout << "N instances not found\n";
    }
}