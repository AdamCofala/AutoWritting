#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <locale>
#include <windows.h>
using namespace std;

string text;
string alf;
string Dalf; 

void wczytaj(){
    ifstream input("text.txt"); // input file from it will be reading
    string line;
    while (getline(input, line)){
        text+=line;
    }

    ifstream alfabet("alf.txt"); // input a alphabet of diacretic characters from polish
    string line2;
    while (getline(alfabet, line2)){
        alf+=line2;
    }

    ifstream Dalfabet("duzealf.txt"); // input a alphabet of capital diacretic characters from polish 
    string line3;
    while (getline(Dalfabet, line3)){
        Dalf+=line3;
    }
    
}

int literatyp(char litera){
    // duża
    char bufferduzych[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for(int i = 0; i<26; i++){
        if(litera==bufferduzych[i]) return 1;
    }

    for(int i = 0; i<alf.length(); i++){
        if(litera==alf[i]) return 2;
    }

    for(int i = 0; i<Dalf.length(); i++){
        if(litera==Dalf[i]) return 3;
    }
    
   return 0;
}


int main(){

    wczytaj();
    cout << "PRESS ANYTING TO START (EXCEPT FORM ALF+F4)" << endl; 
    _getch();
    system("cls");
    cout << "SET COURSOR TO THE RIGHT PLACE" << endl;
    Sleep (3000);
    system("cls");
    for(int i = 5; i > 0; i--){
    cout << "START BEGIN AFTER " << i << " SECONDS" << endl; 
    Sleep (1000);
    system("cls");
    }
    cout << "WRITING..." << endl; 
    int N = text.length();
    for (int i=0; i<N; i++){
        char character = text[i];
        Sleep(60);
        cout << (char)character; // viewport in console window
        switch (literatyp(character)){
            case 1:
                keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, 0), 0, 0);
                keybd_event(VkKeyScan(character), 0, 0, 0);
                keybd_event(VkKeyScan(character), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, 0), KEYEVENTF_KEYUP, 0);
                break;
            case 2:
                //cout << "X";
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event(VK_MENU, 0, 0, 0);
                keybd_event(VkKeyScan(character), 0, 0, 0);
                keybd_event(VkKeyScan(character), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                break;
            case 3:
                keybd_event(VK_CONTROL, 0, 0, 0);
                keybd_event(VK_MENU, 0, 0, 0);
                keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, 0), 0, 0);
                keybd_event(VkKeyScan(character), 0, 0, 0);
                keybd_event(VkKeyScan(character), 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_LSHIFT, MapVirtualKey(VK_LSHIFT, 0), KEYEVENTF_KEYUP, 0);
                keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
                keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
                break;
            case 0:
                keybd_event(VkKeyScan(character), 0, 0, 0);
                keybd_event(VkKeyScan(character), 0, KEYEVENTF_KEYUP, 0);
                break;
            default:
                break;

        }

    }

    cout << "WRITTING COMPLETE" << endl; 

    return 0;
}
