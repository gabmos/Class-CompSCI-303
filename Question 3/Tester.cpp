#include "assignment.h"
#include<list>
#include<iterator>
#include <ctime>

int getOption();
void addAssignment(list<Assignment>& assignments);
void removeAssignment(list<Assignment>& assignments);
void displayAssignments(list<Assignment>& assignments);
void earliestAssignments(list<Assignment>& assignments);

int main()
{
   list<Assignment> assignments;
   int opt = getOption();
   while (opt != 5) {
       if (opt == 1) {
           addAssignment(assignments);
       }
       else if (opt == 2) {
           removeAssignment(assignments);
       }
       else if (opt == 3) {
           displayAssignments(assignments);
       }
       else if (opt == 4) {
           earliestAssignments(assignments);
       }
       cout << endl;
       opt = getOption();
   }
   cout << "\nEnding.....\n";
}
int getOption() {
   int opt;
   cout << "USER OPTIONS:-\n1. Add a new assignment\n2. Remove an assignment\n"
       << "3. Provide list of assignment\n4. Earliest due date assignment\n5. Exit\n";
   cin >> opt;
   while (opt < 1 || opt>5) {
       cout << "Error!!!Option must be 1-5\n";
       cout << "USER OPTIONS:-\n1. Add a new assignment\n2. Remove an assignment\n"
           << "3. Provide list of assignment\n4. Earliest due date assignment\n5. Exit\n";
       cin >> opt;
   }
   return opt;
}
void addAssignment(list<Assignment>& assignments) {
   string name, date;
   cin.ignore();
   cout << "Enter assignment name: ";
   getline(cin, name);
   cout << "Enter assignment date(d/m/yyyy): ";
   cin >> date;
   Assignment assignment(name, date);
   time_t now = time(0);
   tm *ltm = localtime(&now);
   string current = to_string(ltm->tm_mday) + "/"+to_string(1+ltm->tm_mon)+"/"+to_string(1900 + ltm->tm_year);
   if (assignment.getDate()<current){
       cout << "Date is less than current date,not added!!!" << endl;
   }
   else {
       bool flag = false;
       list <Assignment> ::iterator it;
       for (it = assignments.begin(); it != assignments.end(); ++it) {
           Assignment as = *it;
           if (as==assignment) {
               cout << "Assignment already added!!!So not newly addd!!!" << endl;
               flag = true;
               break;
           }
       }
       if (!flag) {
           assignments.push_back(assignment);
           cout << "Added successfully!!!\n";
       }
   }
}

void removeAssignment(list<Assignment>& assignments) {
   string name, date;
   cin.ignore();
   cout << "Enter assignment name: ";
   getline(cin, name);
   cout << "Enter assignment date(d/m/yyyy): ";
   cin >> date;
   Assignment assignment(name, date);
   bool flag = false;
   list <Assignment> ::iterator it;
   for (it = assignments.begin(); it != assignments.end(); ++it) {
       Assignment as = *it;
       if (as==assignment) {
           flag = true;
           assignments.erase(it);
           cout << "Assignment removed successfully!!!" << endl;
           break;
       }
   }
   if (!flag) {
       cout << "Not found in list!!!\n";
   }
}
void displayAssignments(list<Assignment>& assignments) {
   list <Assignment> ::iterator it;
   for (it = assignments.begin(); it != assignments.end(); ++it)
       cout << *it << endl;
}
void earliestAssignments(list<Assignment>& assignments) {
   list <Assignment> ::iterator it;
   it = assignments.begin();
   Assignment assignment = *it;
   for (it = assignments.begin(); it != assignments.end(); ++it) {
       Assignment as = *it;
       if (as.getDate()<assignment.getDate()) {
           assignment = as;
       }
   }
   cout << "Earliest assignmnet = " << assignment << endl;
}