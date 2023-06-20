#ifndef DATA_H
#define DATA_H
#include<iostream>

class Data
{
private:
    int dataId;
    int dataGender;
    bool dataMaritalStatus;
    bool dataEducationStatus;
    int dataApplicantIncome;
    int dataLoanAmount;
    int dataPropertyArea;
    bool dataLoanStatus;
public:
    Data() = delete;
    Data(const Data &obj) = default;
    Data(int id,int gender,bool marital,bool education,int income,int loan,int area,bool status);
    ~Data();

    int getDataId() const { return dataId; }
    void setDataId(int dataId_) { dataId = dataId_; }

    int getDataGender() const { return dataGender; }
    void setDataGender(int dataGender_) { dataGender = dataGender_; }

    bool isDataMaritalStatus() const { return dataMaritalStatus; }
    void setDataMaritalStatus(bool dataMaritalStatus_) { dataMaritalStatus = dataMaritalStatus_; }

    bool isDataEducationStatus() const { return dataEducationStatus; }
    void setDataEducationStatus(bool dataEducationStatus_) { dataEducationStatus = dataEducationStatus_; }

    int getDataApplicantIncome() const { return dataApplicantIncome; }
    void setDataApplicantIncome(int dataApplicantIncome_) { dataApplicantIncome = dataApplicantIncome_; }

    int getDataLoanAmount() const { return dataLoanAmount; }
    void setDataLoanAmount(int dataLoanAmount_) { dataLoanAmount = dataLoanAmount_; }

    int getDataPropertyArea() const { return dataPropertyArea; }
    void setDataPropertyArea(int dataPropertyArea_) { dataPropertyArea = dataPropertyArea_; }

    bool isDataLoanStatus() const { return dataLoanStatus; }
    void setDataLoanStatus(bool dataLoanStatus_) { dataLoanStatus = dataLoanStatus_; }

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs);
};

#endif // DATA_H
