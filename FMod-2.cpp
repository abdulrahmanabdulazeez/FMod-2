//FMOD-2:
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int randN;
#define high 100
#define format 10

void exit(){
    exit(0);
}

void prompt(),help(),contactAuthor();
void C_File(),D_File(),Ec_Dc_File(),Re_File(),CFE(),Chk_File_E(),Read_Fi();
void C_D_File();
void logCreator();

void MainMenu(){
    cout << "---------------------------------------------\n\n";
    cout << " FMOD " << "Created by AbdulRahman AbdulAzeez\n\n";
    cout << "------------------------------------------V2.0\n";
    cout << "Version 3 Coming Soon!!!\n\n";
}

void cdFull(){
    MainMenu();
}

int main(void){
MainMenu();

cout << " [1]  Create/Delete a File.\n";
cout << " [2]  Encrypt/Decrypt a File(available in the next version).\n";
cout << " [3]  Rename a File.\n";
cout << " [4]  Read a File's content.\n";
cout << " [5]  Check a File's existence.\n";
cout << " [6]  Check if a File is empty or not.\n";
cout << " [7]  Help.\n";
cout << " [0]  Contact Author.\n";
cout << " [00] Exit.\n";
cout << "\nPassword Generation will be made available in the next Version!\n\n";
cout << "Select an Option: ";
string opt;
cin >> opt;

while(opt!="1"&&opt!="2"&&opt!="3"&&opt!="4"&&opt!="5"&&opt!="6"&&opt!="7"&&opt!="0"&&opt!="00"){
    cout << "\n\aInvalid Option!!\n\n";
    system("PAUSE");
    system("CLS");
    main();
}

if(opt=="1"){
    system("CLS");
    MainMenu();
    C_D_File();
}
else if(opt=="2"){
    system("CLS");
    MainMenu();
    Ec_Dc_File();
}
else if(opt=="3"){
    system("CLS");
    MainMenu();
    Re_File();
}
else if(opt=="4"){
    system("CLS");
    MainMenu();
    Read_Fi();
}
else if(opt=="5"){
    system("CLS");
    MainMenu();
    CFE();
}
else if(opt=="6"){
    system("CLS");
    MainMenu();
    Chk_File_E();
}
else if(opt=="7"){
    system("CLS");
    MainMenu();
    help();
}
else if(opt=="0"){
    system("CLS");
    MainMenu();
    contactAuthor();
}
else if(opt=="00"){
    exit();
}
else {
    exit(0);
}

return 0;
}

void C_D_File(){
    cout << " [1]  Create a File.\n";
    cout << " [2]  Delete a File.\n";
    cout << " [3]  Back\n";
    int opt;
    cout << "\n Select an Option: ";
    cin >> opt;
        while(opt!=1&&opt!=2&&opt!=3){
            cout << " Wrong Option";
            system("CLS");
            cdFull();
            C_D_File();
        }

        switch(opt){
            case 1:
                system("cls");
                cdFull();
                C_File();
                break;
            case 2:
                system("cls");
                cdFull();
                D_File();
                break;
            case 3:
                system("cls");
                main();
                break;
        }
}

void C_File(){
    cout << "Enter the filename you want to create: ";
    string Fname;
    cin >> Fname;
    cout << "\nEnter the format(txt,html,dat e.t.c) you want it to be created in: ";
    char Fmat[high];
    cin >> Fmat;
    char dot[format]=".";
    strcat(dot,Fmat);
    fstream CFile;
    CFile.open(Fname+dot, ios::out);
    cout << "\nCreating File....\n\n";
        if(CFile){
            cout << "\aFile created successfully!\n";
        }
        else {
            cerr << "\aError creating File!\n";
        }
        CFile.close();
        prompt();
}

void D_File(){
    cout << "Enter the file name/path you want to delete: ";
    char fname[high];
    cin >> fname;
    int remover;
    remover=remove(fname);
    cout << "\nDeleting File......\n\n";
        if(!remover){
            cout << "\aFile Deletion successful.!";
        }
        else {
                    cerr << "\aError deleting file.!\n\n";
                    cout << "A file called logs.txt has been created on your desktop \nwith information about why the error occured!";
                    srand(time(0));
                    randN=rand()%10000;
                    cout << "\n\nCase/Reference ID: " << randN << endl;
                    cout << "\nNote that the Case ID above is the same with the case ID in logs.txt in your PC. \nIf different from the logs.txt in your PC, the ERROR is not related \nto the file(logs.txt).";
                    logCreator();
        }
        prompt();
}

void Ec_Dc_File(){
    cout << "\nComing Sooon!!!!!\n\n";
    cout << "Will be available in version 3\n";
    prompt();
}

void Read_Fi(){
    cout << "Enter the File's name you want to read content(s) from: ";
    char fname[high];
    cin >> fname;
    fstream rdFile;
    rdFile.open(fname, ios::in);
    string dis_F_Con;
    cout << "\nReading file.....\n\n";
        if(rdFile){
            while(getline(rdFile,dis_F_Con)){
                    cout << dis_F_Con;
            }
        }
        else if(!rdFile){
            cerr << "\a\nERROR: Unable to read file!\n\n";
            cout << "A file called logs.txt has been created on your desktop \nwith information about why the error occured!";
            srand(time(0));
            randN=rand()%10000;
            cout << "\n\nCase/Reference ID: " << randN << endl;
            cout << "\nNote that the Case ID above is the same with the case ID in logs.txt in your PC\nIf different from the logs.txt in your PC, the ERROR is not related \nto the file(logs.txt).";
            logCreator();
        }
        else {
            cout << "File is empty!";
        }
    prompt();
    rdFile.close();
}

void Re_File(){
    cout << "Enter the current File's name/path you want to rename: ";
    char fname[high];
    cin >> fname;
    cout << "Enter the File's new name: ";
    char NewName[high];
    cin >> NewName;
    int renamer;
    renamer=rename(fname,NewName);
    cout << "\nRenaming File....\n\n";
        if(!renamer==0){
            cerr << "\aError renaming file.!\n\n";
            cout << "A file called logs.txt has been created on your desktop \nwith information about why the error occured!";
            srand(time(0));
            randN=rand()%10000;
            cout << "\n\nCase/Reference ID: " << randN << endl;
            cout << "\nNote that the Case ID above is the same with the case ID in logs.txt in your PC\nIf different from the logs.txt in your PC, the ERROR is not related \nto the file(logs.txt).";
            logCreator();
        }
        else {
            cout << "\aFile renamed successfully.!";
        }
        prompt();
}

void CFE(){
    cout << "Enter File name/path you want to check existence: ";
    char fname[high];
    cin >> fname;
    fstream checker;
    checker.open(fname, ios::in);
    cout << "\nChecking File's existence.....\n\n";
        if(checker){
            cout << "\a\nFile found.!";
        }
        else {
            cout << "\a\nFile does not exists.!";
        }
        checker.close();
        prompt();
}

void Chk_File_E(){
    cout << "Enter the File's name/path you want to check if empty or not: ";
    string fname;
    cin >> fname;
    fstream EmpOrNot;
    EmpOrNot.open(fname, ios::in);
    EmpOrNot.seekg(0, ios::end);
    cout << "\nReading file......\n";
        if(EmpOrNot.tellg()==0){
            cout << "\nFile is empty";
        }
        else{
                if(!EmpOrNot){
                    cerr << "\n\aError Occured.!\n\n";
                    cout << "A file called logs.txt has been created on your desktop \nwith information about why the error occured!";
                    srand(time(0));
                    randN=rand()%10000;
                    cout << "\n\nCase/Reference ID: " << randN << endl;
                    cout << "\nNote that the Case ID above is the same with the case ID in logs.txt in your PC\nIf different from the logs.txt in your PC, the ERROR is not related \nto the file(logs.txt).";
                    logCreator();
                    prompt();
                }
            cout << "\nFile is not empty";
        }
    EmpOrNot.close();
    prompt();
}

void prompt(){
    cout << "\n\n\nDo you want to go to main menu?[Yes/No]: ";
    string choice;
    cin >> choice;
            while(choice!="Yes"&&choice!="yes"&&choice!="YES"&&choice!="No"&&choice!="no"&&choice!="NO"){
                cout << "\nWrong Option\n\n";
                system("pause");
                system("CLS");
                main();
            }
        if (choice=="Yes"||choice=="yes"||choice=="YES"){
            system("cls");
            main();
        }
        if (choice=="No"||choice=="no"||choice=="NO"){
            exit(0);
        }
        else {
            exit(0);
    }
}

void help(){
    cout << "\nFMOD(File Moderator) is a program which helps a user manipulate files in different ways.\n";
    cout << "It makes manipulation of files easy, fast and great with inclusion of features like:\n";
    cout << "- File Deletion.\n";
    cout << "- File Creation.\n";
    cout << "- Renaming of Files.\n";
    cout << "- Validation of contents of file.\n";
    cout << "- Checking File existence.\n\n";
    cout << "Note that, Version 3 will also be made more comprehensive for very easy use.\n";
    cout << "Version 3 will soon be released and password generation and writing the generated passwords to a file\n";
    cout << "will be included as well as encryption and decryption of the generated password file for safety of you privacy.\n\n";
    cout << "We hope you have a great experience working with this program!!!\n\n";
    system("PAUSE");
    system("CLS");
    main();
}

void contactAuthor(){
    cout << "You can contact me @\n";
    cout << "https://web.facebook.com/abdulrahman.abdulazeez.5243/\n\n\n";
    system("PAUSE");
    system("CLS");
    main();
}

void logCreator(){
    fstream log;
    log.open("logs.txt",ios::out | ios::app);
    log << "------------------------------------------------------------------------------------------";
    log << "\nDate created: " << __DATE__ << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    log << "Time: "<< ltm->tm_hour << ":";
    log << ltm->tm_min << ":";
    log << ltm->tm_sec << endl;
    log << "Case ID: " << randN;
    log << "\n\nError Information:\n";
    log << "The target/specified file could not be found.\nTherefore we could not perform the related task!!\n";
    log << "\nPossible fix(es): \n";
    log << "Make sure the File you want to work on exists, \nthe file's name is correct and the file's extension also is correct else the error might \nstill show up.\n";
    log << "If you are having problem searching for the file, you might want to consider using the\ncheck file's existence option available in out tool/program for a more easy search.";
    log << "\n------------------------------------------------------------------------------------------\n\n\n";
    log.close();
}









