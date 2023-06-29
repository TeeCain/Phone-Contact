#include <iostream>
#include <string>
using namespace std;


class ContactNode {
private:
    string contactName;
    string contactPhoneNumber;
    ContactNode* nextNodePtr;

public:

   // Constructor for name and phone number
    ContactNode(string name, string phoneNumber) {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }
    
   // Accessor for contactName
    string GetName() {
        return contactName;
    }
    
   // Accessor for contactPhoneNumber
    string GetPhoneNumber() {
        return contactPhoneNumber;
    }
   
   // Inserts node after the current node
    void InsertAfter(ContactNode* nodePtr) {
        ContactNode* tmpNext = nextNodePtr;
        nextNodePtr = nodePtr;
        nodePtr->nextNodePtr = tmpNext;
    }
    
   // Accessor for nextNodePtr
    ContactNode* GetNext() {
        return nextNodePtr;
    }

   // Prints the contact information
    void PrintContactNode() {
        cout << "Name: " << contactName << endl;
        cout << "Phone number: " << contactPhoneNumber << endl;
    }
};

int main() {
    string name, phoneNumber;
    ContactNode* head = nullptr;
    ContactNode* currNode = nullptr;

   // Reads name and phone number of 3 contacts
    for (int i = 1; i <= 3; ++i) {
        getline(cin, name);
        getline(cin, phoneNumber);
        
        //Outputs person, name, and number
        cout << "Person " << i << ": ";
        cout << name << ", " << phoneNumber << endl;

         // Creates a new ContactNode with the entered information
        ContactNode* newNode = new ContactNode(name, phoneNumber);

         // Inserts the new node into the linked list
        if (i == 1) {
            head = newNode;
            currNode = newNode;
        } else {
            currNode->InsertAfter(newNode);
            currNode = newNode;
        }
    }
    
    cout << endl;
    cout << "CONTACT LIST" << endl;
    currNode = head;
    int personNum = 1;

   //Linked list
    while (currNode != nullptr) {
        currNode->PrintContactNode();
        cout << endl;
        currNode = currNode->GetNext();
        personNum++;
    }


    return 0;
}
