#include "functionalities.h"

std::function<void(conatiner &data)> createObjects = [](conatiner &data)
{
    listConatiner l1;
    listConatiner l2;
    listConatiner l3;

    l1.emplace_back(std::make_unique<Automobile>(1, "001x", 45.6f, 4, CAR_CATEGORY::SUV));
    l1.emplace_back(std::make_unique<Automobile>(2, "002x", 145.6f, 5, CAR_CATEGORY::HATCHBACK));

    l2.emplace_back(std::make_unique<Automobile>(3, "003x", 245.6f, 6, CAR_CATEGORY::SEDAN));
    l2.emplace_back(std::make_unique<Automobile>(4, "004x", 345.6f, 2, CAR_CATEGORY::HATCHBACK));

    l3.emplace_back(std::make_unique<Automobile>(5, "005x", 445.6f, 3, CAR_CATEGORY::SUV));

    data.emplace(std::make_pair("Phase 1", std::move(l1)));
    data.emplace(std::make_pair("Phase 2", std::move(l2)));
    data.emplace(std::make_pair("Phase 3", std::move(l3)));
};

std::function<void(conatiner &obj)> averagePrice = [](conatiner &obj)
{
    float sum = 0.0f;
    int count = 0;
    std::vector<float> price;
    for (auto &[k, v] : obj)
    {
        count += v.size();
        sum += std::accumulate(v.begin(), v.end(), 0.0f, [](float total, std::unique_ptr<Automobile> &a)
                               { return total + a->getCarPrice(); });
    }
    std::cout << sum / count << "\n";
};

std::function<void(conatiner &data, std::list<std::string> locations)> avgLocationCarPrice =
    [](conatiner &data, std::list<std::string> locations)
{
    float sum;
    int count = 0;
    for (auto &keys : locations)
    {
        if (auto itr = data.begin(); itr != data.end())
        {
            count += itr->second.size();
            sum = std::accumulate(itr->second.begin(), itr->second.end(), 0.0f, [](float total, std::unique_ptr<Automobile> &a)
                                  { return total + a->getCarPrice(); });
        }
    }
    std::cout << sum / count << "\n";
};

std::optional<std::function<void(conatiner &data)>> listABoveThreshold =
    [](conatiner &data)
{
    std::list<std::unique_ptr<Automobile>> list(data.size());
    for (auto &[k, v] : data)
    {
        if (auto itr = v.begin(); itr != v.end())
        {
            if (itr->get()->getCarPrice() > 1000000.0f)
            {
                list.emplace_back(itr);
            }
        }
    }
    if (list.size() == 0)
    {
        std::cout << "None is above threshold\n";
    }
    else
    {
        for (auto &it : list)
        {
            std::cout << it.get()->getCarModel() << " ";
        }
    }
};

// std::function<std::string(conatiner &obj, std::variant<int, std::string> number)> findCarModel =
//     [](conatiner &obj, std::variant<int, std::string> number)
// {
//     std::string ans;
//     for (auto &[k, v] : obj)
//     {
//         std::visit([&](auto &number)
//                    {
//             if(obj.begin()->second.begin()->get()->getSerialNumber() == number){
//                 ans = obj.begin()->second.begin()->get()->getCarModel();
//             } },
//                    v.begin()->get()->getSerialNumber());
//     }
//     return ans;
// };
