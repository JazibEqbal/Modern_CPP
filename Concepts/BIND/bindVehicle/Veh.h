#ifndef VEH_H
#define VEH_H

#include <iostream>
#include <string>

enum class VEHICLE_TYPE {
    SUV,
    SEDAN,
    ELECTRIC_SUV,
    ICE_TWO_WHEELER,
    ELECTRIC_TWO_WHEELER
};

class Vehicle {
public:
    Vehicle(const std::string& name, VEHICLE_TYPE type, float price)
        : vehicleName(name), vehicleType(type), vehiclePrice(price) {}

    // Deleted copy and default constructors
    Vehicle(const Vehicle&) = delete;
    //Vehicle& operator=(const Vehicle&) = default;
    Vehicle() = delete;
    virtual ~Vehicle();

    // Getters and setters
    std::string getVehicleName() const {
        return vehicleName;
    }

    void setVehicleName(const std::string& name) {
        vehicleName = name;
    }

    VEHICLE_TYPE getVehicleType() const {
        return vehicleType;
    }

    void setVehicleType(VEHICLE_TYPE type) {
        vehicleType = type;
    }

    float getVehiclePrice() const {
        return vehiclePrice;
    }

    void setVehiclePrice(float price) {
        vehiclePrice = price;
    }

    // Pure virtual function calledRtoTax
    virtual float calledRtoTax() = 0;

protected:
    std::string vehicleName;
    VEHICLE_TYPE vehicleType;
    float vehiclePrice;
};

class Car : public Vehicle {
public:
    Car(const std::string& brand, const std::string& name, VEHICLE_TYPE type, float price)
        : Vehicle(name, type, price), carBrand(brand) {}

    float calledRtoTax() override {
        if (getVehicleType() == VEHICLE_TYPE::ELECTRIC_SUV) {
            return 0.0f;  // No tax for electric SUVs
        }
        else if (getVehicleType() == VEHICLE_TYPE::SUV || getVehicleType() == VEHICLE_TYPE::SEDAN) {
            return getVehiclePrice() * 0.1f;  // 10% tax for SUVs and Sedans
        }
        else {
            return 0.0f;  // No tax for other vehicle types
        }
    }
    ~Car(){
        std::cout<<"Des\n";
    }
    // Getters and setters for carBrand
    std::string getCarBrand() const {
        return carBrand;
    }

    void setCarBrand(const std::string& brand) {
        carBrand = brand;
    }

    // Overloaded left shift operator
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car Brand: " << car.getCarBrand() << std::endl;
        os << "Vehicle Name: " << car.getVehicleName() << std::endl;
        os << "Vehicle Type: " << static_cast<int>(car.getVehicleType()) << std::endl;
        os << "Vehicle Price: " << car.getVehiclePrice() << std::endl;
        return os;
    }

private:
    std::string carBrand;
};


#endif // VEH_H
