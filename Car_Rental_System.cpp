#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class Login
{
public:
    string name, surname, email;
    string phoneNO, password, pass;

    void setName(string name)
    {
        this->name = name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setphone(string phoneNO)
    {
        this->phoneNO = phoneNO;
    }
    void setPassword(string password)
    {
        this->password = password;
    }

    void getName()
    {
        cout << "NAME :- " << name << " " << surname << endl;
    }

    void getEmail()
    {
        cout << "EMAIl :- " << email << endl;
    }

    void getPhone()
    {
        cout << "PHONE NUMBER :- " << phoneNO << endl;
    }
    void To_Display()
    {
        cout << "\nPRESS 1 TO CREATE NEW ACCOUNT." << endl;
        cout << "\nPRESS 2 TO DIRECTLY LOG-IN." << endl;
    }
};

class Input : public Login
{
public:
    void enterName(Login *obj, Input *in)
    {
        cout << "\nENTER YOUR NAME :- ";
        cin >> name;
        for (int i = 0; i < name.length(); i++)
        {
            if (isdigit(name[i]))
            {
                cout << "\nENTER NAME WHICH CONTAINS ONLY CHRACTERS." << endl;
                in->enterName(obj, in);
            }
        }

        obj->setName(name);
    }

    void enterSurname(Login *obj, Input *in)
    {
        cout << "\nENTER YOUR SURNAME :- ";
        cin >> surname;
        for (int i = 0; i < surname.length(); i++)
        {
            if (isdigit(surname[i]))
            {
                cout << "\nEnter surname which contains only characters" << endl;
                in->enterSurname(obj, in);
            }
        }
        obj->setSurname(surname);
    }

    void enterEmail(Login *obj, Input *in)
    {
        cout << "\nEnter your Email ID: ";
        cin >> email;
        int add = 0, com = 0, dot = 0;
        int len = email.length();
        for (int i = 0; i < email.length(); i++)
        {
            if (!isalpha(email[0]))
            {
                cout << "\nFirst element of mail should be a charachter!!\n";
                cout << "Example: abc@gmail.com\n";
                in->enterEmail(obj, in);
            }

            if (email[i] == '@' && email[len - 4] == '.')
            {
                add++;
            }
        }
        if (add != 1)
        {
            cout << "\nEnter a valid email address";
            cout << "\nExample: abc@gmail.com\n";
            in->enterEmail(obj, in);
        }
        obj->setEmail(email);
    }

    void enterPhone(Login *obj, Input *in)
    {
        cout << "\nENTER YOUR PHONE NUMBER :- ";
        cin >> phoneNO;

        //int count=0;
        string temp = phoneNO;
        int len = temp.length();
        // while(temp>0){
        //     temp=temp/10;
        //     count++;
        // }
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(phoneNO[i]))
            {
                cout << "\nENTER DIGITS ONLY." << endl;
                break;
            }
        }
        if (len != 10)
        {
            cout << "\nINVALID NUMBER!!!" << endl;
            in->enterPhone(obj, in);
        }

        obj->setphone(phoneNO);
    }

    void enterPassword(Login *obj, Input *in)
    {
        cout << "\nSETUP PASSWORD FOR YOUR ACCOUNT (6-DIGIT NUMBER): ";
        cin >> password;

        int len = password.length();
        // while(temp>0){
        //     temp=temp/10;
        //     count++;
        // }
        if (len != 6)
        {
            cout << "\nYour password doesn't contain 6-digits!" << endl;
            in->enterPassword(obj, in);
        }
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(password[i]))
            {
                cout << "\nPassword should only contain digits!" << endl;
                in->enterPassword(obj, in);
            }
        }
        obj->setPassword(password);
    }
    void filecreation()
    {
        ofstream file;
        string p = password + ".txt";
        file.open(p);
        file.close();
        ofstream out(p);
        out << "NAME :-  " << name << " " << surname << endl;
        out << "\nemail :- " << email << endl;
        out << "\nPHONE NUMBER :-  " << phoneNO << endl;
        out << "\nPASSWORD :-  " << password << endl;
        out.close();
        cout << "\n\t\tACCOUNT CREATED SUCCESSFULLY\n"
             << endl;
    }

    void welcome()
    {
        //system("color 6f");
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\t Welcome to CAR-RENTAL SYSTEM" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\t\tSIGN UP" << endl;
    }

    void login_in()
    {
    for_sine_up:
        string to_check, to_print;

        cout << "\nENTER YOUR PASSWORD :-  ";
        cin >> pass;
        int i = 0;

        if (isdigit(pass[i]) && pass.length() == 6)
        {
            i++;
        }
        else
        {
            cout << "\nINVALID PASSWORD!!!" << endl;
            goto for_sine_up;
        }

        to_check = pass + ".txt";
        ifstream in(to_check);
        if (in.is_open())
        {
        }
        else
        {
            cout << "\nTHEIR IS NO ACCOUNT WITH PASSWORD :- " << pass << endl;
            cout << "\nCREATE ACCOUNT FIRST OR ENTER CORRECT PASSWORD.\n"
                 << endl;
            exit(0);
        }
        system("cls");
        cout << "\n\t\tACCOUNT DETAILS\n\n";
        //THIS INFORMATION SHOULD BE DISPLAY ON NEW PAGE.
        for (int i = 0; i < 7; i++)
        {
            getline(in, to_print);
            cout << to_print << endl;
        }
        in.close();
    }
};
class car_info : public Input
{
public:
    string seats, AC, Driver;
    float hours;
    void cars()
    {
        cout << "\n\t\tAVAILABLE CARS" << endl;
        cout << "1: Audi S5 sportback." << endl;
        cout << "2: Toyota Fortuner." << endl;
        cout << "3: Tata Nexon EV." << endl;
        cout << "4: Ford Aspire." << endl;
        cout << "5: Maruti Suzuki Vitara Brezza." << endl;
        cout << "6: Honda City." << endl;
    }
    void audidetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nAudi\t"
             << "\tS5 Sportback"
             << "\t10 km/l"
             << "\t\tWhite"
             << "\t\t4"
             << endl;
    }
    void audidetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nAudi\t"
             << "\tA8 Sportback"
             << "\t6 km/l"
             << "\t\tBlue"
             << "\t\t7"
             << endl;
    }
    void toyotadetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nToyota\t"
             << "\tFortuner"
             << "\t12 km/l"
             << "\t\tBlack"
             << "\t\t4"
             << endl;
    }
    void toyotadetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nToyota\t"
             << "\tFortuner"
             << "\t8 km/l"
             << "\t\tRed"
             << "\t\t7"
             << endl;
    }
    void tatadetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nTata\t"
             << "\tNexon EV"
             << "\t10 km/l"
             << "\t\tGrey"
             << "\t\t4"
             << endl;
    }
    void tatadetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nTata\t"
             << "\tNexon EV"
             << "\t6 km/l"
             << "\t\tBlue"
             << "\t\t7"
             << endl;
    }
    void forddetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nFord\t"
             << "\tAspire"
             << "\t\t20 km/l"
             << "\t\tWhite"
             << "\t\t4"
             << endl;
    }
    void forddetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nFord\t"
             << "\tAspire"
             << "\t\t13 km/l"
             << "\t\tSilver"
             << "\t\t7"
             << endl;
    }
    void marutidetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour" << endl;
        cout << "\nMaruti Suzuki\t"
             << "Vitara Brezza"
             << "\t17 km/l"
             << "\t\tRed"
             << endl;
    }
    void marutidetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nMaruti Suzuki"
             << "\tVitara Brezza"
             << "\t10 km/l"
             << "\t\tYellow"
             << "\t\t7"
             << endl;
    }
    void hondadetail4()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nHonda\t"
             << "\tHonda city"
             << "\t24 km/l"
             << "\t\tWhite"
             << "\t\t4"
             << endl;
    }
    void hondadetail7()
    {
        cout << "\n\t\tCAR SPECEFICATION" << endl;
        cout << "\nNAME\t\t"
             << "MODEL"
             << "\t\tAverage"
             << "\t\tColour"
             << "\t\tSeats"
             << endl;
        cout << "\nHonda\t"
             << "\tHonda city"
             << "\t20 km/l"
             << "\t\tGrey"
             << "\t\t7"
             << endl;
    }
    void Audi()
    {

        cout << "\nHow many seats do you want in your Audi S5 sportback(4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            audidetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            audidetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            Audi();
        }
    }
    void Toyota()
    {

        cout << "\nHow many seats do you want in your Toyota Fortuner(4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            toyotadetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            toyotadetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            Toyota();
        }
    }
    void tata()
    {

        cout << "\nHow many seats do you want in your Tata Nexon EV (4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            tatadetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            tatadetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            tata();
        }
    }
    void ford()
    {

        cout << "\nHow many seats do you want in your Ford Aspire. (4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            forddetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            forddetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            ford();
        }
    }
    void maruti()
    {

        cout << "\nHow many seats do you want in your Maruti Suzuki Vitara Brezza.. (4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            marutidetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            marutidetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            maruti();
        }
    }
    void honda()
    {

        cout << "\nHow many seats do you want in your Honda City.. (4 or 7):-  ";
        cin >> seats;
        if (seats == "4")
        {
            system("cls");
            hondadetail4();
        }
        else if (seats == "7")
        {
            system("cls");
            hondadetail7();
        }
        else
        {
            cout << "\nPlease select between 4 and 7." << endl;
            honda();
        }
    }
    void For_Ac()
    {

        cout << "\nDo you want AC in your car" << endl;
        cout << "\nIf yes then extra charges will be applied for it." << endl;
        cout << "\nPress (1 for Yes) or (0 for No) :-  ";
        cin >> AC;
        if (AC == "1")
        {
            cout << "\nYou have chosen an AC car." << endl;
        }
        else if (AC == "0")
        {
            cout << "\nYou have chosen a Non-AC car." << endl;
        }
        else
        {
            cout << "\nPlease select between 1 and 0." << endl;
            cout << "\n\n"
                 << endl;
            For_Ac();
        }
        Sleep(2200);
        system("cls");
    }
    void For_Driver()
    {
        cout << "\nDo you want a driver for your car." << endl;
        cout << "\nIf yes then extra charges will be applied for it." << endl;
        cout << "\nPress (1 for Yes) or (0 for No) :-  ";
        cin >> Driver;
        if (Driver == "1")
        {
            cout << "\nYou will get a driver for your car." << endl;
        }
        else if (Driver == "0")
        {
            cout << "\nYou will not get a driver for your car." << endl;
        }
        else
        {
            cout << "\nPlease select between 1 and 0." << endl;
            cout << "\n\n"
                 << endl;
            For_Driver();
        }
        Sleep(2000);
        system("cls");
    }
    void For_Hours()
    {

        cout << "\nFor how many hours do you want to take this car on rent :-  ";
        // cout << " We charge 5000 Rs per hour for Audi S5 sportback :-  ";
        cin >> hours;
        if (sizeof(hours) == 4 && hours > 0)
        {
            cout << "\nThe time you have chosen is " << hours << " hours";
        }

        else
        {
            cout << "\ninvalid input" << endl;
            For_Hours();
        }
        Sleep(2200);
        system("cls");
    }
    void To_Confirm(string password, int b)
    {
        string s, p;
        cout << "\n\n\t\tCONFIRMATION" << endl;
        p = password + ".txt";
        ifstream in(p);
        cout << '\n';
        for (int i = 0; i < 1; i++)
        {
            getline(in, s);
            cout << s;
        }
        cout << '\n';
        if (AC == "1")
        {
            cout << "\nAC car";
        }
        else if (AC == "0")
        {
            cout << "\nNon-AC car";
        }
        if (Driver == "1")
        {
            cout << " with Driver\n";
        }
        else if (Driver == "0")
        {
            cout << " with no driver\n";
        }
        if (seats == "4" && b == 1)
        {
            Sleep(2000);
            audidetail4();
        }
        else if (seats == "4" && b == 2)
        {
            Sleep(2000);
            toyotadetail4();
        }
        else if (seats == "4" && b == 3)
        {
            Sleep(2000);
            tatadetail4();
        }
        else if (seats == "4" && b == 4)
        {
            Sleep(2000);
            forddetail4();
        }
        else if (seats == "4" && b == 5)
        {
            Sleep(2000);
            marutidetail4();
        }
        else if (seats == "4" && b == 6)
        {
            Sleep(2000);
            hondadetail4();
        }

        {
            if (seats == "7" && b == 1)
            {
                Sleep(2000);
                audidetail7();
            }
            else if (seats == "7" && b == 2)
            {
                Sleep(2000);
                toyotadetail7();
            }
            else if (seats == "7" && b == 3)
            {
                Sleep(2000);
                tatadetail7();
            }
            else if (seats == "7" && b == 4)
            {
                Sleep(2000);
                forddetail7();
            }
            else if (seats == "7" && b == 5)
            {
                Sleep(2000);
                marutidetail7();
            }
            else if (seats == "7" && b == 6)
            {
                Sleep(2000);
                hondadetail7();
            }
        }
    }
    void Bill()
    {
        int price4 = 5000 * hours;
        int price7 = 6000 * hours;
        int a, b;

        if (seats == "4")
        {
            Sleep(2000);
            cout << "\n\nWe charge 5000 Rs per hour for a 4 seatter." << endl;
            cout << "\nThe time you have chosen is " << hours << " hour(s)." << endl;
            cout << "\nSo, the Price is :- " << price4 << " Rs." << endl;
            cout << "\n";
            if (AC == "1" && Driver == "1")
            {
                Sleep(2000);
                a = 1000;
                b = 500 * hours;
                cout << "\nAlso, you have chosen an AC car extra chrages are applied." << endl;
                cout << "\nWe charge 1000 Rs for an AC car." << endl;
                Sleep(2000);
                cout << "\nAnd you also want a driver for your car, we charge 500 Rs per hour for a driver." << endl;
                cout << "\nSo the total price of driver is :-  " << b << " Rs." << endl;
                cout << "\n\nThe Total Price is :-  " << price4 + a + b << " Rs." << endl;
            }
            else if (AC == "0" && Driver == "1")
            {
                Sleep(2000);
                b = 500 * hours;
                Sleep(2000);
                cout << "\nAlso, you want a driver for your car, we charge 500 Rs per hour for a driver." << endl;
                cout << "\nSo the total price of driver is :-  " << b << " Rs." << endl;
                cout << "\n\nThe Total Price is :-  " << price4 + b << " Rs." << endl;
            }
            else if (AC == "1" && Driver == "0")
            {
                Sleep(2000);
                a = 1000;
                cout << "\nAlso, you have chosen an AC car extra chrages are applied." << endl;
                cout << "\nWe charge 1000 Rs for an AC car." << endl;
                cout << "\n\nThe Total Price is :-  " << price4 + a << " Rs." << endl;
            }
            else
            {
                cout << "\n\nThe Total Price is :-  " << price4 << " Rs." << endl;
            }

            cout << "\n\n";
            string For_Confirmation;
            cout << "\nPress 1 to confirm or Press any key to cancel the request of car rent :-  ";
            cin >> For_Confirmation;
            if (For_Confirmation == "1")
            {
                cout << "\n\nYour car is booked, you will get your car in less than 30 minutes." << endl;
                cout << "\n\t\tT H A N K   Y O U ! ! !\n\n"
                     << endl;
            }
            else
            {
                cout << "Your request has been cancelled." << endl;
            }
        }
        else
        {
            if (seats == "7")
            {
                Sleep(2000);
                cout << "\n\nWe charge 6000 Rs per hour for a 7 seatter." << endl;
                cout << "\nThe time you have chosen is " << hours << " hour(s)." << endl;
                cout << "\nSo, the Price is :- " << price7 << " Rs." << endl;
                cout << "\n";
                if (AC == "1" && Driver == "1")
                {
                    Sleep(2000);
                    a = 1000;
                    b = 500 * hours;
                    cout << "\nAlso, you have chosen an AC car extra chrages are applied." << endl;
                    cout << "\nWe charge 1000 Rs for an AC car." << endl;
                    Sleep(2000);
                    cout << "\nAnd you also want a driver for your car, we charge 500 Rs per hour for a driver." << endl;
                    cout << "\nSo the total price of driver is :-  " << b << " Rs." << endl;
                    cout << "\n\nThe Total Price is :-  " << price7 + a + b << " Rs." << endl;
                }
                else if (AC == "0" && Driver == "1")
                {
                    Sleep(2000);
                    b = 500 * hours;
                    Sleep(2000);
                    cout << "\nAlso, you want a driver for your car, we charge 500 Rs per hour for a driver." << endl;
                    cout << "\nSo the total price of driver is :-  " << b << " Rs." << endl;
                    cout << "\n\nThe Total Price is :-  " << price7 + b << " Rs." << endl;
                }
                else if (AC == "1" && Driver == "0")
                {
                    Sleep(2000);
                    a = 1000;
                    cout << "\nAlso, you have chosen an AC car extra chrages are applied." << endl;
                    cout << "\nWe charge 1000 Rs for an AC car." << endl;
                    cout << "\n\nThe Total Price is :-  " << price7 + a << " Rs." << endl;
                }
                else
                {
                    cout << "\n\nThe Total Price is :-  " << price7 << " Rs." << endl;
                }

                cout << "\n\n";
                string For_Confirmation;
                cout << "\nPress 1 to confirm or Press any key to cancel the request of car rent :-  ";
                cin >> For_Confirmation;
                if (For_Confirmation == "1")
                {
                    cout << "\n\nYour car is booked, you will get your car in less than 30 minutes." << endl;
                    cout << "\n\t\tTHANK YOU!!!\n\n"
                         << endl;
                }
                else
                {
                    cout << "Your request has been cancelled." << endl;
                }
            }
        }
    }
};
int main()
{

    Login p1;
    Input in;
    car_info c1;

    in.welcome();
    p1.To_Display();
    int a;
    cout << "\nSELECT THE NUMBER :-  ";
    cin >> a;
    switch (a)
    {
    case 1:
        in.enterName(&p1, &in);
        in.enterSurname(&p1, &in);
        in.enterPhone(&p1, &in);
        in.enterEmail(&p1, &in);
        in.enterPassword(&p1, &in);
        in.filecreation();
        exit(0);
        break;

    case 2:
        in.login_in();
        break;

    default:
        cout<<"Please enter between 1 and 2./n"<<endl;
        exit(0);
        break;
    }
    c1.cars();
    int b;
    cout << "\nSELECT THE CAR YOU WANT :-  ";
    cin >> b;
    switch (b)
    {
    case 1:
        c1.Audi();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    case 2:
        c1.Toyota();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    case 3:
        c1.tata();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    case 4:
        c1.ford();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    case 5:
        c1.maruti();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    case 6:
        c1.honda();
        c1.For_Ac();
        c1.For_Driver();
        c1.For_Hours();
        c1.To_Confirm(in.pass, b);
        c1.Bill();
        break;
    default:
        break;
    }

    return 0;
}