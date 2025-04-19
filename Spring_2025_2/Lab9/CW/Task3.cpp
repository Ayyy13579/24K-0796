#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
    private:
    string name;
    int ID;
    int dob;
    string history;
    string currentTreatments;
    string billingInfo;
    public:
    PatientRecord() : name(""), ID(0), dob(0), history(""), currentTreatments("") {}
    void getPublicData() {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Date of Birth: " << dob << endl;
    }
    void getMedicalData() {
        cout << "Medical History: " << history << endl;
        cout << "Current Treatments: " << currentTreatments << endl;
    }
    void updateMedicalData(string newHistory, string newTreatments) {
        history = newHistory;
        currentTreatments = newTreatments;
    }
    void addBillingDetails(string bill) {
        billingInfo = bill;
    }
    void getBillingDetails() {
        cout << "Billing Info: " << billingInfo << endl;
    }
    friend class Doctor;
    friend class Billing;
};

class Doctor {
    private:
    string name;
    int ID;
    string specialization;
    public:
    void updateMedicalData(PatientRecord& record, string newHistory, string newTreatments) {
        record.updateMedicalData(newHistory, newTreatments);
    }
    void getMedicalData(PatientRecord& record) {
        record.getMedicalData();
    }
};

class Billing {
    public:
    void addBillingDetails(PatientRecord& record, string bill) {
        record.addBillingDetails(bill);
    }
    void getBillingDetails(PatientRecord& record) {
        record.getBillingDetails();
    }
};

class Receptionist {
    public:
    void attemptAccess(PatientRecord& record) {
        record.getPublicData();
        record.getMedicalData();
    }
};

int main() {
    PatientRecord patient;
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;

    patient.getPublicData();

    doctor.getMedicalData(patient);
    doctor.updateMedicalData(patient, "Diabetes", "Insulin shots");
    doctor.getMedicalData(patient);

    billing.addBillingDetails(patient, "Paid: $500 for treatment");
    billing.getBillingDetails(patient);

    receptionist.attemptAccess(patient);
};