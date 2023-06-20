#include "Data.h"

Data::Data(int id, int gender, bool marital, bool education, int income, int loan, int area, bool status)
: dataId{id}, dataGender{gender}, dataMaritalStatus{marital}, dataEducationStatus{education},
  dataApplicantIncome{income}, dataLoanAmount{loan}, dataPropertyArea{area}, dataLoanStatus{status} {}

Data::~Data()
{
    std::cout<<"Data with id: "<<this->dataId<<" destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Data &rhs) {
    os << "dataId: " << rhs.dataId
       << " dataGender: " << rhs.dataGender
       << " dataMaritalStatus: " << rhs.dataMaritalStatus
       << " dataEducationStatus: " << rhs.dataEducationStatus
       << " dataApplicantIncome: " << rhs.dataApplicantIncome
       << " dataLoanAmount: " << rhs.dataLoanAmount
       << " dataPropertyArea: " << rhs.dataPropertyArea
       << " dataLoanStatus: " << rhs.dataLoanStatus;
    return os;
}
