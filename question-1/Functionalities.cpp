#include "Functionalities.h"
#include <list>
#include <optional>
#include <future>

using pointer = std::shared_ptr<Car>;
using container = std::list<pointer>;

std::function<std::optional<container>(container &, float)> carsAboveThreshold = [](container &carlist, float threshold)
{
    container resultList(carlist.size());

    if (carlist.empty())
    {
        throw std::runtime_error("List passed is empty !\n");
    }
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold passed is not appropiate!\n");
    }

    auto itr = std::copy_if(carlist.begin(), carlist.end(), resultList.begin(),
                            [&](std::shared_ptr<Car> &obj)
                            {
                                return obj.get()->getCarPrice() > threshold;
                            });

    resultList.resize(std::distance(resultList.begin(), itr));
    if (resultList.size() == 0)
    {
        return container();
    }
    else
    {
        return container(resultList);
    }
};
/*


    VehicleType should be a future value as we are getting it from user so make it a future and then try to call it from main 


*/
std::function<std::optional<std::list<float>>(container&, VehicleType)> returnCarPriceList = [](container &carlist, VehicleType type)
{
    if (carlist.empty())
    {
        throw std::runtime_error("List passed is empty !\n");
    }
    std::list<float> resultlist(carlist.size());

    auto itr = std::transform(carlist.begin(), carlist.end(), resultlist.begin(),
                              [&](std::shared_ptr<Car> &obj)
                              {
                                  if (obj.get()->getVehicleType() == type)
                                  {
                                      return obj.get()->getCarPrice();
                                  }
                                  else{
                                    return float();
                                  }
                              });

    resultlist.resize(std::distance(resultlist.begin(), itr));

    if (resultlist.size() == 0)
    {
        return std::list<float>{};
    }
    else
    {
        return resultlist;
    }
};


//FOR BETTER UNDERSTANDING MAKE BELOW FUNCTION also a async. make container a future object and then call it from main



std::function<std::optional<std::list<std::string>>(container &)> returnCarColorContainer = [](container &carobjectlist)
{
    std::list<std::string> result(carobjectlist.size());
    auto itr=std::transform(carobjectlist.begin(), carobjectlist.end(), result.begin(),
                   [](pointer &obj)
                   {
                       if (obj.get()->getVehicleType() == VehicleType::PRIVATE)
                       {
                           return obj.get()->getCarColour();
                       }
                       else{
                        return std::string();
                       }
                       
                   });
    
      result.resize(std::distance(result.begin(), itr));

    if (result.size() == 0)
    {
        return std::optional<std::list<std::string>>();
    }
    else
    {
        return std::optional<std::list<std::string>> (result);
    }
};


std::function<float(container &)> averageInsuranceAmount = [](container &carobjlist)
{
    if (carobjlist.empty())
    {
        throw std::runtime_error("List passed is empty !\n");
    }
    float total = 0.0f;
    int count = 0;
    for (auto &obj : carobjlist)
    {
        if (obj->getVehicleType() == VehicleType::COMMERCIAL &&
            obj->getVehicleRegistration() == 2023 &&
            obj->getVehicleInsurancePlan().get()->getInsuranceType() == InsuranceType::ZERO_DEBT)
        {
            total += obj.get()->getVehicleInsurancePlan().get()->getInsuranceAmount();
            count++;
        }
    }
    return total / count;
};
