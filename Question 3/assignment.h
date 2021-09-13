#include<iostream>
#include<string>
using namespace std;
class Assignment {
private:
   string assignmentName;
   string dueDate;
public:
   Assignment(string name = "",string date = "");
   friend ostream& operator<<(ostream& out, Assignment as);
   bool operator==(Assignment& as);
   string getName()const;
   string getDate()const;
};
Assignment::Assignment(string name,string date) {
   assignmentName = name;
   dueDate = date;
}
ostream& operator<<(ostream& out, Assignment as) {
   out << as.assignmentName << ", " << as.dueDate;
   return out;
}
bool Assignment::operator==(Assignment& as) {
   return this->assignmentName==as.assignmentName && this->dueDate==as.dueDate;
}
string Assignment::getName()const {
   return assignmentName;
}
string Assignment::getDate()const{
   return dueDate;
}
