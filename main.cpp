#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cctype>
#include <windows.h>
#include "concol.h"

using namespace std;

void clrscr(){
    system("cls");
}


int length=0;
int combinations=0;
long double tries=1;
int special_char=0;
int lower_alpha=0;
int upper_alpha=0;
int digit=0;
int strength=0;
int range=0;
long double time=0;
int details=0;

char secrete_string[100];
//int coursor=0;


void scan(int i);
void compute();
int fact(int);
void time1();

int main()
{
    SetConsoleTitle("Password Ratings 1.0 by Maulik Raviya");

    system("Color 00");
    int t;
    cout << "\n\n        Password Ratings 1.0 by Maulik Raviya.."<<endl;
    cout<< "\n------------------------------------------------------------------";
    cout << "\nThis app will help to know that.."<<endl;
    cout << "\n How secure your password is! This tiny app can be used to measure(!) your password strength. It also calculates the time to guess your password by an average desktop computer. " <<endl;
    cout << "\n NOTE: We respect your privacy. This app";
    cout << "\n       will NEVER store/remember your password anywhere";
    cout << "\n       in any format.";
    cout << "\n       So don't worry and type your password in the";
    cout << "\n       upcoming screen and watch your result instantly." ;
    cout << "\n TIP : Use upper and lower letters as well as special";
    cout << "\n       characters and digits to increase your password";
    cout << "\n       strength." ;
    cout<< "\n------------------------------------------------------------------";
    cout << "\n\n             ..PRESS ANY KEY TO CONTINUE..";
    cout << "\n   ..[press <space> to continue with advance mode].. ";

    if(getch()==' ') details=1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    do{

        clrscr();
        cout << "\n\n\n\nEnter your password: " ;
        int i;
        //printing ***
        for(i=1;i<=length;i++){
            cout<<"*";
        }

        cout<< "\n\n\n\n ->Strength of your password :\n   "<< strength << " out of 10    " ;
        /*printing bars of strength*/for(int i=1; i<=strength ;i++) cout<< " | ";
        /*printing -*/for(int i=1; i<=10-strength ; i++) cout<< " - ";



        cout<< "\n\n ->Time needed for a average desktop PC to crack your password :\n   " ; time1();
        if(details==1){
           cout<< "\n\n------------------------------------------------------------------";
            cout<< "\nLength the password: "<<length;
            cout<< "\nTries may be needed to guess the password: " << tries;
            cout<< "\nRange of keys      : " << range;
            cout<< "\nUppercase letters  : " << upper_alpha;
            cout<< "\nLowercase letters  : " << lower_alpha;
            cout<< "\nSpecial characters : " << special_char;
            cout<< "\nDigits             : " << digit;
        }

        t = getch();

        scan(t);
        compute();

    }while(t!=13);

    clrscr();
    system("Color F2");
    cout<< "\n\n\n\nA program by Maulik Raviya.";
    cout<< "\n\n\n\n\nContact me/Report bug at..";
    cout<< "\n\ngoogle.com/+MaulikRaviya";
    cout<< "\nfacebook.com/MaulikRaviya";
    cout<< "\n\nThank You for your time.\n\n";
    getch();

 /////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


    return 0;
}
void scan(int input){

    range=0;

    if(input==8){
        if(length>0) {
            input=secrete_string[length-1];

            length--;
            /* Decrement of particular chr_flag..! */
            if( (input>=32 && input<=47) || (input>=58 && input<=64) || (input>=91 && input<=96) || (input>=123 && input<=126) ){
                special_char--;

            }
            else if(input>=65 && input<=90){
                upper_alpha--;

            }
            else if( input>=97 && input<=122 ){
                lower_alpha--;

            }
            else if( input>=48 && input<=57){
                digit--;

            }
            /* END OF Decrement of particular char_flag..! */
        }
    }
    else if((isprint(input))) {

         secrete_string[length]=input;
         length++;


         if( (input>=32 && input<=47) || (input>=58 && input<=64) || (input>=91 && input<=96) || (input>=123 && input<=126) ){
            special_char++;

         }
         else if(input>=65 && input<=90){
            upper_alpha++;

         }
         else if( input>=97 && input<=122 ){
            lower_alpha++;

         }
         else if( input>=48 && input<=57){
            digit++;

         }
    }
    //time to find range..
    if(upper_alpha>0) range+=26;
    if(lower_alpha>0) range+=26;
    if(special_char>0)range+=33;
    if(digit>0) range+=10;
}


void compute(){
        int i;
        tries = 1;
        time=0;

        for(i=1;i<=length;i++)
        tries*=range; //here total tries to crack the passwrd is calculated..

        time= tries/(4.0*(1000000000.0));

        //time to find strength..
        strength=0;

        if(lower_alpha>0) strength++;
        if(upper_alpha>0) strength++;
        if(digit>0) strength++;
        if(special_char>0) strength++;


        if(length>5) strength++;
        if(length>14) strength++;


        if(time>=86400){
            strength+=1;
        }
        if(time>31536000){
            strength+=3;
        }
        if(strength==9 && length>20) strength=10;



}

void time1(){

    if(length==0){
        cout<< "0 nanosecond.";
        system("Color CF");
    }
    else if(time>31536000){
        long double years=time/31536000;

        if(years>=1000000000000000000){
            years/=1000000000000000000;
            cout<< years << " Million Trillion Years.";
            system("Color A1");

        }
        else if(years>=1000000000000){
            years/=1000000000000;
            cout<< years << " Trillion Years.";
            system("Color A1");

        }
        else if(years>=1000000000){
            years/=1000000000;
            cout<< years << " Billion Years.";
            system("Color 2F");

        }
        else if(years>=1000000){
            years/=1000000;
            cout<< years << " Million Years.";
            system("Color 2F");
        }
        else{
            cout<< years << " years.";
            system("Color 3F");
        }

    }
    else if(time>=86400){
        float days=time/86400;
        cout<< days << " days.";
        system("Color E1");
    }
    else if(time >= 3600){
        float hours=time/3600;
        cout<< hours << " hours.";
        system("Color 4F");
    }
    else if(time >= 60){
        float minutes=time/60;
        cout << minutes << " minutes.";
        system("Color 4F");
    }
    else if(time <= 0.001 && time > 0.000001){
        float milli=time*1000;
        cout<< milli << " milliseconds.";
        system("Color CF");
    }
    else if(time <= 0.000001 && time > 0.000000001){
        float micro=time*1000000;
        cout << micro<<" microseconds.";
        system("Color CF");
    }
    else if(time <= 0.000000001 && time > 0.000000000001 ){
        float nano=nano*100000000;
        cout<< nano << " nanoseconds.";
        system("Color CF");
    }
    else if(time <= 0.000000000001){
        cout<< "Instant, Less than a nanosecond.";
        system("Color CF");
    }
    else {
        cout<< time << "seconds";
        system("Color CF");
    }

}
