#include <iostream>
#include <string>
using namespace std;

class Hospital {
public:
    struct Record {
        string pname, address, disease;
        double phoneno, insuranceno, age, insu;
    };

    static const int MAX_PATIENTS = 10; // Define the maximum number of patients
    Record database[MAX_PATIENTS]; // Array to store patient records
    int numPatients = 0; // Keep track of the number of patients

    void getdata() {
        cout << "******************************************" << endl;
        cout << "****Hello There Welcome To Hospital ABC***" << endl;
        cout << "****We hope our patients get well soon****" << endl;
        cout << "******************************************" << endl;

        cout << "Enter the number of patients arrived here: ";
        cin >> numPatients;

        for (int i = 0; i < numPatients; i++) {
            Record& patient = database[i];
            cout << "******************************************" << endl;
            cout << "Please Enter Details of patient No: " << i + 1 << endl;
            cout << "******************************************" << endl;
            cout << "Enter Patient Name: ";
            cin >> patient.pname;
            cout << "Enter Age: ";
            cin >> patient.age;
            cout << "Enter Address: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, patient.address); // Use getline for the full address
            cout << "Enter Disease: ";
            cin >> patient.disease;
            cout << "Enter Phone number: ";
            cin >> patient.phoneno;
            cout << "Does the patient have any insurance?\n 1 for Yes, 2 for No: ";
            cin >> patient.insu;

            if (patient.insu == 1) {
                cout << "Enter Insurance Number: ";
                cin >> patient.insuranceno;
            } else {
                cout << "Create it Soon..." << endl;
            }

            cout << "Data for patient " << i + 1 << " is saved." << endl;
            cout << "******************************************" << endl;
        }
    }

    void displayPatientsList() {
        cout << "List of Patients:" << endl;
        cout << "******************************************" << endl;
        for (int i = 0; i < numPatients; i++) {
            cout << "Patient No " << i + 1 << ": " << database[i].pname << endl;
        }
        cout << "******************************************" << endl;
    }

    void displayPatientData(int patientIndex) {
        if (patientIndex >= 1 && patientIndex <= numPatients) {
            cout << "******************************************" << endl;
            cout << "Patient " << patientIndex << " Data:****" << endl;
            cout << "******************************************" << endl;
            Record& patient = database[patientIndex - 1];
            cout << "Name: " << patient.pname << "\nAge: " << patient.age
                 <<  "\nAddress: " << patient.address << "\nDisease: " << patient.disease
                 << "\nPhone Number: " << patient.phoneno;

            if (patient.insu == 1) {
                cout << "\nInsurance Number: " << patient.insuranceno;
            } else {
                cout << "\nNo Insurance.";
            }

            cout << endl;
            cout << "******************************************" << endl;
        } else {
            cout << "Invalid patient number. Please enter a valid patient number." << endl;
        }
    }
};

class Doctor:public Hospital{
    public:
    string drname,gender,address;
    double age,number,hpid;
     void getdata() {

        cout << "Enter Name of doctor ";
        cin >> drname;
     }
};
int main() {
    Hospital hp;
    hp.getdata();

    while (true) {
        hp.displayPatientsList();

        int patientIndex;
        cout << "Enter the patient number (index) you want to access (1-" << hp.numPatients << ") or enter 0 to exit: ";
        cin >> patientIndex;
        
        if (patientIndex == 0) {
    cout<<"--------------------\nVisit again to our hospital\n--------------------\nThank You for using this program made by Psyphon"<<endl;
            break; // Exit the loop and the program
        } else if (patientIndex >= 1 && patientIndex <= hp.numPatients) {
            hp.displayPatientData(patientIndex);
        } else {
            cout << "Invalid patient number. Please enter a valid patient number." << endl;
        }
    }

    return 0;
}
