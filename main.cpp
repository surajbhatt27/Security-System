#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout << endl << "          Security System" << endl << endl;

    do{
        cout << "---------------------------------------" << endl;
        cout << "|         1. Register                 |" << endl;
        cout << "|         2. Login                    |" << endl;
        cout << "|         3. Change password          |" << endl;
        cout << "|         4.End program               |" << endl;
        cout << "---------------------------------------" << endl;

        cout << endl << endl;
        cout << "Enter your choice:- ";
        cin >> a;
        cout << endl;
        switch(a) 
        {
            case 1:{
                cout << "-----------------------------" << endl;
                cout << "|---------Register----------|" << endl;
                cout << "|___________________________|" << endl << endl;
                cout << "Please enter username:- ";
                cin >> name;
                cout << "Please enter the password:- ";
                cin >> password0;
                cout << "please enter your age:- " ;
                cin >> age;

                ofstream of1("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0 ;
                    cout << "Registration successful" << endl << endl;
                    of1.close();
                }
            break;
            }

            case 2:{
                i = 0;

                cout << "--------------------------" << endl;
                cout << "|---------Login----------|" << endl;
                cout << "|________________________|" << endl << endl;

                ifstream of2("file.txt");
                cout << "please enter the username:- ";
                cin >> user;
                cout << "please enter the password:- ";
                cin >> pass;

                if(of2.is_open())
                {
                    while (getline(of2, text)){
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                        
                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << endl << "--------Log in successful----------";
                        cout << endl;

                        cout << "Detail: " << endl;
                        cout << "Username: " << user << endl;
                        cout << "Password: " << pass << endl;
                        cout << "Age: " << age << endl;
                    }
                        
                    else {
                        cout << endl << endl;
                        cout << "Incorrect Credentials" << endl;
                    }
                }
                else {
                    cout << "File not found or could not be opened" << endl;
                }

                of2.close();
                break;
            }

            case 3:{
                i = 0;

                cout << "---------------Change password-------------" << endl << endl;

                ifstream of0("file.txt");
                cout << "Enter the old password:- ";
                cin >> old;

                if (of0.is_open())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }

                    if (old == cp[1])
                    {
                        of0.close();
                        ofstream of1("file.txt");

                        if (of1.is_open())
                        {
                            cout << "Enter your new password:- ";
                            cin >> password1;
                            cout << "Enter your password again:- ";
                            cin >> password2;

                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password changed successfully" << endl;
                            }

                            else {
                                cout << "Password do not match" << endl;
                            }
                            of1.close();
                        }
                        
                        else {
                            cout << "Could not open file for writing" << endl;
                        }
                    }
                    else {
                        cout << "Incorrect password" << endl;
                    }
                }
                else {
                    cout << "File not found or could not be opened" << endl;
                }
                of0.close();
                break;
            }

            case 4:{
                cout << "____________Thank you !___________" << endl;
                break;
            }

            default:{
                cout << "Enter a valid choice ";
            }
        }
    }while (a!=4);
    return 0;
}