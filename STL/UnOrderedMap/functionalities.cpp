#include "functionalities.h"

using myPointer = std::unique_ptr<AutoMobile>;

using CarPriceList = std::list<myPointer>;

using container = std::unordered_map<std::string, CarPriceList>;

using Variant = std::variant<std::string, int>;

std::function<void(container &data)> CreateAutomobileObjects = [](container &data)
{
    std::list<myPointer> l1;
    std::list<myPointer> l2;
    std::list<myPointer> l3;

    l1.emplace_back(std::make_unique<AutoMobile>("101D", "URUS", 5000000.0f, 6, CarCategory::SUV));
    l1.emplace_back(std::make_unique<AutoMobile>("102D", "M3COUPE", 3500000.0f, 4, CarCategory::SEDAN));

    l2.emplace_back(std::make_unique<AutoMobile>("103D", "AGERA R", 2000000.0f, 2, CarCategory::HATCHBACK));
    l2.emplace_back(std::make_unique<AutoMobile>("104D", "VEYRON", 3000000.0f, 2, CarCategory::HATCHBACK));

    l3.emplace_back(std::make_unique<AutoMobile>("105D", "CHIRON", 1500000.0f, 3, CarCategory::SEDAN));

    data.emplace(std::make_pair("Phase 1", std::move(l1))); // std:::move converts lvalue to rvalue
    data.emplace(std::make_pair("Phase 2", std::move(l2)));
    data.emplace(std::make_pair("Phase 3", std::move(l3)));
};

std::function<void(container &)> FindAverageCarPrice = [](container &data)
{
    float sum;
    int cnt = 0;
    for (auto &[x, y] : data)
    {
        // std::list<float> carPrice(y.size());
        // std::for_each(y.begin(),y.end(),[&](myPointer a){
        //     carPrice.emplace_back(a->getCarPrice());
        // });
        sum = std::accumulate(y.begin(), y.end(), 0.0f, [](float total, myPointer &a)
                              { return total + a.get()->getCarPrice(); });
        cnt += y.size();
    }
    std::cout << sum / cnt << "\n";
};

std::function<void(container &, std::list<std::string> &)> FindAverageCarPriceOfAllUnits = [](container &data, std::list<std::string> &carKeys)
{
    float sum;
    int cnt = 0;
    for (auto &keys : carKeys)
    {
        if (auto itr = data.find(keys); itr != data.end())
        {
            sum = std::accumulate(itr->second.begin(), itr->second.end(), 0.0f, [](float total, myPointer &a)
                                  { return total + a.get()->getCarPrice(); });
            cnt += itr->second.size();
        }
    }
    std::cout << sum / cnt << "\n";
};

std::function<void(container &, std::future<Variant> &)> FindCarModelusingSerialNumber =
    [](container &data, std::future<Variant> &fu)
{
    Variant serial = fu.get();
    std::visit([](auto arg)
               { std::cin >> arg; },
               serial);
    // auto itr=data.find(serial);
    // if(itr==data.end()){
    //     throw std::runtime_error("Serial number not found!\n");
    // }
    for (auto &[x, y] : data)
    {
        for (auto &a : y)
        {
            if (a.get()->getCarSerialNumber() == serial)
            {
                std::cout << a.get()->getCarModel() << "\n";
            }
        }
    }
};

std::function<void(container &)> FindGreaterThanCarPrice = [](container &data)
{
    std::list<std::unique_ptr<AutoMobile>> CarPriceList;
    for (auto &[x, y] : data)
    {
        for (auto &a : y)
        {
            if (a.get()->getCarPrice() > 100000.0f)
            {
                CarPriceList.push_back(a);
            }
        }
    }
};
