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
        return std::optional<std::list<std::string>> result;
    }
};