#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<ctype.h>
#include<windows.h>
#include<cstring>
#include"class_domesticbook.cpp"
#include"class_internationalbook.cpp"


class passenger: public domestic_book,public international_book
{
protected:
    char f_name[20],l_name[20],email[50];
    int age,gender;
    long long c_no;

public:
    void p_detail(int x)
    {
        if(x==1)
        {
            j_detail();
        }
        else
        {
            j_detaili();
        }
        cout << "\n\n\nEnter passenger details";
        cout << "\nFirst Name:      ";
        cin >> f_name;
        cout << "\nLast Name:       ";
        cin >> l_name;
    }
    int gender_check()
    {
        cout << "\nGender:\nMale-press:1::\nFemale-press:2::\t";
        cin >> gender;
        if(gender>2)
        {
            cout << "\n\n**********Wrong input entered.Try again******\n\n" << endl;
            return gender_check();
        }
    }
    void more_details()
    {
        cout << "\nAge:             ";
        cin >> age;
        cout << "\nEmail Id:        ";
        cin >> email;
        cout << "\nContact no.:     ";
        cin >> c_no;
        cout << "\n\nDetails Entered:\n";
        cout << "\nName:            " << f_name << " " << l_name << endl;
        cout << "Gender:          " << gender << endl;
        cout << "Age:             " << age << endl;
        cout << "Email id:        " << email << endl;
        cout << "Contact No.:     " << c_no << endl;
        cout<<"\n";

    }


    int getpnr()
    {
        return pnr;
    }
    int getfno()
    {
        return fd_no;
    }
    int getpnri()
    {
        return pnri;
    }
    int getfnoi()
    {
        return fi_no;
    }
    void disp()
    {
         cout<<"\nConfirm your details\n\n";
         cout<<"\n\nFlight no:      "<<fd_no<<endl;
         cout<<"PNR:                " << pnr << endl;
         cout<<"Flight:             " << f_d << endl;
         cout<<"Name:               " << f_name << " " << l_name << endl;
         cout<<"DOJ:                " << doj << endl;
         cout<<"Departure Time:     " << tojd << endl;
         cout<<"Arrival Time:       " << toja ;
         cout<<"\n\n";
     }

    void dispi()
    {
        cout<<"\nConfirm your details\n\n";
        cout<<"Flight no:           "<<fi_no<<endl;
        cout<<"PNR:                 " << pnri << endl;
        cout<<"Flight:              " << f_i << endl;
        cout<<"Name:                " << f_name << " " << l_name << endl;
        cout<<"DOJ:                 " << doji << endl;
        cout<<"Departure Time:      " << tojdi << endl;
        cout<<"Arrival Time:        " << tojai ;
    }
};
