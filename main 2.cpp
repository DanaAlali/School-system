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
    cout<<"\n\n First name:";
    cin>> first_name;
    cout<<"Last name :";
    cin>>last_name;
    cout<<"Age:";
    cin>>age;
    cout<<"Your Student Number Is:"<<student_no<<endl;
     
     Student new_student (age, first_name, last_name, student_no);
     
     students.push_back(new_student);
}
void Student::change_information()
{
    intro();
int random_key;
    cout<< "First Name :";
    cin>> first_name;
    
    cout<< "Last Name :";
    cin>> last_name;
    
    cout <<"Age:";
    cin>>age;
    
    cout << "Your Student Number Is :"<< student_no << endl;
}

void Student::show_student_no()
{
    cout<< " Your Student Number Is :"<< student_no<< endl;
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
    cout<< "Last Name :";
    cin >> lastname;
    
    cout<< "Age :";
    cin >> age;
    
    teacher_no =
    create_teacher_no();
    cout<< "Your Teacher Number Is :" << teacher_no << endl;
}
void Teacher::remove_grades(int grade)
{
    int index;
    cout<< " Enter Index:";
    cin>> index;
    grades.erase(grades.begin() + index);
}
void Teacher::add_grades(int grade )    
    {
        cout<< "Enter Grade :";
        cin >> grade;
        
        if ( grade > 10)
        {
            cout << " Please Enter A Grade Smaller Than 10"<< endl;
        }
        else
        {
            grades.push_back(grade);
        }
    }
    
    void Teacher:: file_students()
    {
        fstream myFile;
        myFile << "First Name" << "  " << " Last Name" << "  "<< "Age" << endl;
        
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
        cout<<" Are You A Student Or Teacher? (If You Are Student Choose S , If You Are Teacher Choose T) ";
        cin>> teacher_or_student;
         if (teacher_or_student =="T"){
             
             int ch;
             
             do{
               cout<<"[1].New Teacher."<<endl;
               cout<<"[2].Add Grades."<<endl;
               cout<<"[3].Remove Grades."<<endl;
               cout<<"[4].File All Students."<<endl;
               cout<<"[5].Exit."<<endl;
               cout<<"Choice";
               cin>>ch;
               
                    switch(ch){
                     case 1:
                     tch.new_teacher();
                     break;
                     
                     case 2 :
                     int grade ;
                     cout<<"Press 1.";
                     cin>> grade;
                     
                     tch.add_grades(grade);
                     break;
                     
                     case 3:
                     cout<<"Entere A Grade:";
                     cin>>grade;
                     
                     tch.remove_grades(grade);
                     break;
                     
                     case 4:
                     tch.file_students();
                     
                     default:
                     cout<<"Try Again";
                     break;
                 }
                 
             }
             
             while(ch !=5);
         
         }else{
             int ch;
             do{
              cout<<"\n[1].New Student."<<endl;
               cout<<"[2].Change Student Information ."<<endl;
               cout<<"[3].Show Student Number."<<endl;
               cout<<"[4].Exit."<<endl;
               cout<<"Choice";
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
                    cout<<"Try Again.";
                    break;
                  
               }
             } while (ch !=4 );
         }
                     
}


