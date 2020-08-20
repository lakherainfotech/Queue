#include <iostream>
#include <string>
#define MAX_SIZE 10
using namespace std;

struct Patient
{
	string firstName;
	string lastName;
	string insuranceType;
	long ssnNumber;
	string address;
	string visitDate;
};

class Queue
{
private:
	Patient patient[MAX_SIZE];
	int front;
	int rear;
	int count;
public:
	Queue()
	{
		front = 0;
		rear = -1;
		count = 0;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is already empty \n";
		}
		else 
		{
			cout << "Removing patient with first name: " << patient[front].firstName << '\n';
			front = (front + 1) % MAX_SIZE;
			count--;
		}
	}
	void enqueue(Patient patient)
	{
		if (isFull())
		{
			cout << "Queue is full no further patient can be added\n";
		}
		else 
		{
			cout << "Patient Added to queue " << '\n';
			rear = (rear + 1) % MAX_SIZE;
			this->patient[rear] = patient;
			count++;
		}
		
	}
	 Patient peek()
	 {
		if (isEmpty())
		{
			cout << "List is empty......";
			Patient tempPatient;
			tempPatient.firstName == "123";
			return tempPatient;
		}
		return patient[front];
	 }

	 Patient getPatient(int patientNumber)
	 {
		 return patient[patientNumber];
	 }

	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return(size() == 0);
	}
	bool isFull()
	{
		return (size() == MAX_SIZE);
	}
};
int main()
{
	Queue queue;
	string firstName;
	string lastName;
	string insuranceType;
	long ssnNumber;
	string address;
	string visitDate;
	int userChoice;
	int patientCount = 0;
	int currentPatient = 0;
	int nextPatient;
	int previousPatient;
	Patient temp;
    cout << "\n Welcome To Patient Managment System \n" ;
	while (true)
	{
		cout << "\n Select From The Below Options" << endl;
		cout << "1. Add patient" << endl;	
		cout << "2. Next patient" << endl;
		cout << "3. Previous patient" << endl;
		cout << "4. Delete patient" << endl;
		cout << "5. View current" << endl;
		cout << "6. To exit" << endl;
		cout << "Your option: ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 1: 
		{
			if (!queue.isFull()) 
			{
				cout << "Enter the patient information" << endl;
				cout << " First Name: ";
				cin.ignore();
				getline(cin, firstName);
				cout << " Last Name: ";
				getline(cin, lastName);
				cout << " Insurance Type: ";
				getline(cin, insuranceType);
				cout << " SSN Number: ";
				cin >> ssnNumber;
				cout << " Address: ";
				cin.ignore();
				getline(cin, address);
				cout << " Visit Date: ";
				getline(cin, visitDate);
				Patient patient;
				patient.firstName = firstName;
				patient.lastName = lastName;
				patient.address = address;
				patient.insuranceType = insuranceType;
				patient.ssnNumber = ssnNumber;
				patient.visitDate = visitDate;
				queue.enqueue(patient);
				patientCount++;
			}
			else 
			{
				cout << "Queue is full" << endl;
			}
			
			break;
		}
		case 2: 
		{
			int size = queue.size();
			nextPatient = currentPatient + 1;
			if (nextPatient < patientCount)
			{
				Patient patient = queue.getPatient(nextPatient);
				if (patient.firstName != "")
				{
					cout << "Current Patient Information" << endl;
					cout << "First Name:  " << patient.firstName << endl;
					cout << "Last Name:  " << patient.lastName << endl;
					cout << "Address:  " << patient.address << endl;
					cout << "SSN:  " << patient.ssnNumber << endl;
					cout << "Insurance Type:  " << patient.insuranceType << endl;
					cout << "Visit Date:  " << patient.visitDate << endl;
					currentPatient++;
				}
			}
			else 
			{
				cout << "No next patient in queue" << endl;
			}
			
			break;
		}
		case 3:
		{
			int size = queue.size();
			previousPatient = currentPatient - 1;
			if (previousPatient >= 0)
			{
				Patient patient = queue.getPatient(previousPatient);
				if (patient.firstName != "")
				{
					cout << "Current Patient Information" << endl;
					cout << "First Name:  " << patient.firstName << endl;
					cout << "Last Name:  " << patient.lastName << endl;
					cout << "Address:  " << patient.address << endl;
					cout << "SSN:  " << patient.ssnNumber << endl;
					cout << "Insurance Type:  " << patient.insuranceType << endl;
					cout << "Visit Date:  " << patient.visitDate << endl;
					currentPatient--;
				}
			}
			else
			{
				cout << "No previous patient in queue" << endl;
			}
			break;
		}
		case 4:
		{
			queue.dequeue();
			break;
		}
		case 5:
		{
			if (queue.isEmpty())
			{
				cout << "No Patient is in the list" << endl;
			}
			else if(currentPatient<=patientCount)
			{
				
				Patient patient = queue.getPatient(currentPatient);
				if (patient.firstName != "123")
				{
					cout << "Current Patient Information" << endl;
					cout << "First Name:  " << patient.firstName << endl;
					cout << "Last Name:  " << patient.lastName << endl;
					cout << "Address:  " << patient.address << endl;
					cout << "SSN:  " << patient.ssnNumber << endl;
					cout << "Insurance Type:  " << patient.insuranceType << endl;
					cout << "Visit Date:  " << patient.visitDate << endl;
				}
				
			}
			break;
		}
		case 6:
		{
			cout << "Exiting the program....." << endl;
			exit(0);
		}
		default:
		{
			cout << "You have entered wrong option" << endl;
		}
		
		}
			
			
			

	}
}

