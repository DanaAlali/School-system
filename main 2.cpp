#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include <random>
using namespace std;
class Student {
    int student_no;
     public:
     int age;
     string first_name;
     string last_name;
     
     void new_student();
     void change_information();
     void show_student_no();
     
     int create_student_no();
     
     string set_firstname();
     string set_lastname();
     
     Student (const int &age, const string &fisrt_name, const string last_name, const int  &student_no)
     {}
     
     Student() {}
};

class Teacher {
    string lastname;
    int age;
    int teacher_no;
    
     public:
     
     void new_teacher();
     void add_grades(int);
     void remove_grades(int);
     void file_students();

     int create_teacher_no(); //create a random teacher number.
     
     Teacher(const string &lastname, const int &age, const int &teacher_no)
     {}
     
     Teacher() {}
};

vector <Student>students;
vector <int>grades;
 
 void clear()
 {
     cout<<"\n ";
 }
 
void intro()
{
    clear();
    cout<<"\n\t GRADE BOOK";
    cout<<"\n\t By: Shaden";
    
}

void Student::new_student()
{
    intro();
    int random_key;
    cout<<"\n\n first name:";
    cin>> first_name;
    cout<<"last name :";
    cin>>last_name;
    cout<<"age:";
    cin>>age;
    cout<<"your student number is:"<<student_no<<endl;
     
     Student new_student (age, first_name, last_name, student_no);
     
     students.push_back(new_student);
}
void Student::change_information()
{
    intro();
int random_key;
    cout<< "first name :";
    cin>> first_name;
    
    cout<< "last name :";
    cin>> last_name;
    
    cout <<"age:";
    cin>>age;
    
    cout << "Your student number is :"<< student_no << endl;
}

void Student::show_student_no()
{
    cout<< " Your student number is :"<< student_no<< endl;
}

int Student::create_student_no()
{
    for(int i = 1; i < 11; i++)
    {
        student_no = rand()%11;
    }
    return student_no;
}
  int Teacher::create_teacher_no()
{
    for(int i = 1; i <11; i++)
    {
        teacher_no = rand()%11;
    }
    return teacher_no;
}

void Teacher::new_teacher()
{
    clear();
    cout<< "last name :";
    cin >> lastname;
    
    cout<< "age :";
    cin >> age;
    
    teacher_no =
    create_teacher_no();
    cout<< "your teacher number is :" << teacher_no << endl;
}
void Teacher::remove_grades(int grade)
{
    int index;
    cout<< " Enter index:";
    cin>> index;
    grades.erase(grades.begin() + index);
}
void Teacher::add_grades(int grade )    
    {
        cout<< "Enter grade :";
        cin >> grade;
        
        if ( grade > 10)
        {
            cout << " Please enter a grade smaller than 10"<< endl;
        }
        else
        {
            grades.push_back(grade);
        }
    }
    
    void Teacher:: file_students()
    {
        fstream myFile;
        myFile << "first name" << "  " << " last name" << "  "<< "age" << endl;
        
        for ( int i = 1; i < students.size(); i++){
            myFile <<
            students[i].first_name << " "<<
            students[i].last_name << " "<<
            students[i].age << endl;
        }
    }
    
    int main()
    {
        Teacher tch;
        Student std;
        
        string teacher_or_student;
        cout<<" Are u a student or teacher?";
        cin>> teacher_or_student;
         if (teacher_or_student =="teacher"){
             
             int ch;
             
             do{
               cout<<"[1].new teacher."<<endl;
               cout<<"[2].add grades."<<endl;
               cout<<"[3].remove grades."<<endl;
               cout<<"[4].file all students."<<endl;
               cout<<"[5].exit."<<endl;
               cout<<"choice";
               cin>>ch;
               
                    switch(ch){
                     case 1:
                     tch.new_teacher();
                     break;
                     
                     case 2 :
                     int grade ;
                     cout<<"press 1.";
                     cin>> grade;
                     
                     tch.add_grades(grade);
                     break;
                     
                     case 3:
                     cout<<"entere a grade:";
                     cin>>grade;
                     
                     tch.remove_grades(grade);
                     break;
                     
                     case 4:
                     tch.file_students();
                     
                     default:
                     cout<<"try again";
                     break;
                 }
                 
             }
             
             while(ch !=5);
         
         }else{
             int ch;
             do{
              cout<<"\n[1].new student."<<endl;
               cout<<"[2].change student information ."<<endl;
               cout<<"[3].show student number."<<endl;
               cout<<"[4].exit."<<endl;
               cout<<"choice";
               cin>>ch;
               switch(ch){
                   case 1:
                   std.new_student();
                   break;
                   
                   case 2:
                    std.change_information();
                    break;
                    
                    case 3:
                    std.show_student_no();
                    break;
                    default :
                    cout<<"try again.";
                    break;
                  
               }
             } while (ch !=4 );
         }
                     
}


