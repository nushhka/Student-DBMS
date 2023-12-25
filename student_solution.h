#include <bits/stdc++.h>
using namespace std;

class StudentRecord {
private:
    string studentName;
    string rollNumber;

public:
    string get_studentName() {
        return studentName;
    }

    void set_studentName(string Name) {
        studentName = Name;
    }

    string get_rollNumber() {
        return rollNumber;
    }

    void set_rollNumber(string rollnum) {
        rollNumber = rollnum;
    }
};

class Node {
private:
    Node* next;
    StudentRecord* element;

public:
    Node* get_next() {
        return next;
    }

    StudentRecord* get_element() {
        return element;
    }

    void set_next(Node* value) {
        next = value;
    }

    void set_element(StudentRecord* student) {
        element = student;
    }
};

class Entity {
private:
    string name;
    Node* iterator=nullptr;

public:
    string get_name()const {
        return name;
    }

    void set_name(string Name) {
        name = Name;
    }

    Node* get_iterator()const {
        return iterator;
    }

    void set_iterator(Node* iter) {
        iterator = iter;
    }
};

vector<StudentRecord> students;

class LinkedList : public Entity {
public:
    void add_student(const StudentRecord& student){
        StudentRecord* stud = new StudentRecord(student);
        Node* newnode = new Node();
        newnode->set_element(stud);
        newnode->set_next(nullptr);
        if(get_iterator()==nullptr){
            set_iterator(newnode);
        }
        else{
            newnode->set_next(get_iterator());
            set_iterator(newnode);
        }
    }
    void delete_student(string name){
        Node* current=get_iterator();
        while(current->get_next()->get_element()->get_studentName()!=name){
            current=current->get_next();
        }
        Node* del = current->get_next();
        current->set_next(del->get_next());
        delete del;
    }
};

vector<LinkedList> EntityArray; 

string remove(const string& str) {
    string result = str;
    result.erase(remove(result.begin(), result.end(), '['), result.end());
    result.erase(remove(result.begin(), result.end(), ']'), result.end());
    return result;
}

void read_input_file(string file_path){
    // int i=0,j=0,k=0;
    ifstream iF(file_path);
    if (!iF.is_open()) {
        cerr << "Failed" << endl;
    }
    string l;
    int ct=0,kl=0,ml=0;
    while (getline(iF, l)) { 
        stringstream ss(l);
        string st;
        vector<string> arr;
        while (getline(ss, st, ',')) {
            arr.push_back(st);
        }
        for (string& value : arr) {
            value = remove(value);
        }
        StudentRecord student;
        student.set_studentName(arr[0]);
        student.set_rollNumber(arr[1]);
        students.push_back(student);
    
        ct=2;
         while(ct<arr.size())
        {
            for(ml=0;ml<EntityArray.size();ml++){
                if(EntityArray[ml].get_name()==arr[ct]){
                    EntityArray[ml].add_student(students[kl]);
                    break;
                }
            }
            if(ml==EntityArray.size()){
                LinkedList neww;
                neww.set_name(arr[ct]);
                EntityArray.push_back(neww);
                EntityArray[ml].add_student(students[kl]);
            }ct++;
        }
        kl++;
    }
    iF.close();
};

