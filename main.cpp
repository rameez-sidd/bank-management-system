#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// GLOBAL VARIABLES DECLARATIONS :--
char head = 'a';
typedef unsigned long long Type;


// A STRUCT DEFINITION :--
struct Address{
    string city;
    string state;
    string area;
    string country;
    string PINCODE;
};


// FILE DECLARATIONS :--
ifstream TransIn;
ofstream TransOut;
ifstream NameIn;
ofstream NameOut;
ifstream BalIn;
ofstream BalOut;
ifstream TypeIn;
ofstream TypeOut;
ifstream IndividualAccIn;
ofstream IndividualAccOut;
ifstream IndividualPINIn;
ofstream IndividualPINOut;
ifstream DetailsIn;
ofstream DetailsOut;

// FUNCTION DECLARATIONS :--
void welcomeScreen();
void headCreateNew();
void headBal();
void headDepo();
void headWith();
void headTrans();
void headSend();
bool isNumber(const string&);
void choice(char);
void mainMenu();
void setcolor(int);
int calcAge(int, int, int);
char* displayCurrentDateAndTime();


// CLASS DECLARATIONS :--
class InputBank{
protected:
    string name, fName, mName, gender, typeOfAcc, mobNum, aadhar;
    int age, openAmt;
    Address add;
    int d,m,y;
public:
    void getName(){
        headCreateNew();
        cout << left << setw(30) << "\n Enter Name" << ": ";
        getline(cin, name);
        checkName();
    }
    void checkName(){
        if(isNumber(name)){
            setcolor(16*0+4);
            cout << " Invalid Name \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            getName();
        }
    }
    void showName(){
        headCreateNew();
        cout << left << setw(30) << "\n Enter Name" << ": "<< name << endl;
    }
    void getFatherName(){
        cout << left << setw(30) << "\n Enter Father Name" << ": Mr. ";
        getline(cin, fName);
        checkFatherName();
    }
    void checkFatherName(){
       if(isNumber(fName)){
            setcolor(16*0+4);
            cout << " Invalid Name \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            getFatherName();
        }
    }
    void showFatherName(){
        cout << left << setw(30) << "\n Enter Father Name" << ": Mr. " << fName << endl;
    }
    void getMotherName(){
        cout << left << setw(30) << "\n Enter Mother Name" << ": Mrs. ";
        getline(cin, mName);
        checkMotherName();
    }
    void checkMotherName(){
       if(isNumber(mName)){
            setcolor(16*0+4);
            cout << " Invalid Name \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            getMotherName();
        }
    }
    void showMotherName(){
        cout << left << setw(30) << "\n Enter Mother Name" << ": Mrs. " << mName << endl;
    }
    void getGender(){
        char g;
        cout << "\n Select Gender " << endl;
        cout << " -------------" << endl;
        cout << " 1. Male" << endl;
        cout << " 2. Female" << endl;
        cout << left << setw(29) << " 3. Not to Say" << ": " ;
        cin >> g;
        checkGender(g);
    }
    void checkGender(int g){
        if(g=='1'){
            gender = "Male";
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
        }
        else if(g=='2'){
            gender = "Female";
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
        }
        else if(g=='3'){
            gender = "Not to Say";
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
        }
        else{
            setcolor(16*0+4);
            cout << " Invalid Choice \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            getGender();
        }
    }
    void showGender(){
        cout << left << setw(30) << "\n Select Gender" << ": " << gender << endl;
    }
    void getAge(){

        cout << "\n Enter Date of Birth ";
        cout << left << setw(8) << "( DD )" << ": ";
        cin >> d;
        cout << right << setw(29) << "( MM )  " << ": ";
        cin >> m;
        cout << right << setw(29) << "( YY )  " << ": ";
        cin >> y;
        cin.ignore();
        age = calcAge(d,m,y);
        checkAge();
    }
    void checkAge(){
        if(age<15){
            setcolor(16*0+4);
            cout << " Invalid Age \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            getAge();
        }
        else{
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
        }
    }
    void showAge(){
        cout << left << setw(30) << "\n Enter Date of Birth" << ": " << d << "/" << m << "/" << y << endl;
    }
    void getMobNum(){
        cout << left << setw(30) << "\n Enter Mobile Number" << ": ";
        getline(cin, mobNum);
        checkMobNum();
    }
    void checkMobNum(){
        if(!isNumber(mobNum)){
            setcolor(16*0+4);
            cout << " Invalid Mobile Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            getMobNum();
        }
        if(mobNum.length()<10 || mobNum.length()>10){
            setcolor(16*0+4);
            cout << " Invalid Mobile Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            getMobNum();
        }
    }
    void showMobNum(){
        cout << left << setw(30) << "\n Enter Mobile Number" << ": " << mobNum << endl;
    }
    void getAadhar(){
        cout << left << setw(30) << "\n Enter Aadhar Number" << ": ";
        getline(cin, aadhar);
        checkAadhar();
    }
    void checkAadhar(){
        if(!isNumber(aadhar)){
            setcolor(16*0+4);
            cout << " Invalid Aadhar Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            getAadhar();
        }
        if(aadhar.length()<12 || aadhar.length()>12){
            setcolor(16*0+4);
            cout << " Invalid Aadhar Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            getAadhar();
        }
    }
    void showAadhar(){
        cout << left << setw(30) << "\n Enter Aadhar Number" << ": " << aadhar << endl;
    }
    void getCity(){
        cout << left << setw(30) << "\n Enter City" << ": ";
        getline(cin, add.city);
        checkCity();
    }
    void checkCity(){
        if(isNumber(add.city)){
            setcolor(16*0+4);
            cout << " Invalid City \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            getCity();
        }
    }
    void showCity(){
        cout << left << setw(30) << "\n Enter City" << ": " << add.city << endl;
    }
    void getState(){
        cout << left << setw(30) << "\n Enter State" << ": ";
        getline(cin, add.state);
        checkState();
    }
    void checkState(){
        if(isNumber(add.state)){
            setcolor(16*0+4);
            cout << " Invalid State \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showCity();
            getState();
        }
    }
    void showState(){
        cout << left << setw(30) << "\n Enter State" << ": " << add.state << endl;
    }
    void getArea(){
        cout << left << setw(30) << "\n Enter Area/Locality" << ": ";
        getline(cin, add.area);
    }
    void showArea(){
        cout << left << setw(30) << "\n Enter Area/Locality" << ": " << add.area << endl;
    }
    void getCountry(){
        cout << left << setw(30) << "\n Enter Country" << ": ";
        getline(cin, add.country);
        checkCountry();
    }
    void checkCountry(){
        if(isNumber(add.country)){
            setcolor(16*0+4);
            cout << " Invalid Country \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showCity();
            showState();
            showArea();
            getCountry();
        }
    }
    void showCountry(){
        cout << left << setw(30) << "\n Enter Country" << ": " << add.country << endl;
    }
    void getPINCode(){
        cout << left << setw(30) << "\n Enter PIN Code" << ": ";
        cin >> add.PINCODE;
        checkPINCode();
    }
    void checkPINCode(){
        if(!isNumber(add.PINCODE)){
            setcolor(16*0+4);
            cout << " Invalid PIN CODE \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showCity();
            showState();
            showArea();
            showCountry();
            getPINCode();
        }
        if(add.PINCODE.length()<6 || add.PINCODE.length()>6){
            setcolor(16*0+4);
            cout << " Invalid PIN CODE \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showCity();
            showState();
            showArea();
            showCountry();
            getPINCode();
        }
    }
    void showPINCode(){
        cout << left << setw(30) << "\n Enter PIN Code" << ": " << add.PINCODE << endl;
    }
    void getAddress(){
        getCity();
        getState();
        getArea();
        getCountry();
        getPINCode();
    }
    void showAddress(){
        showCity();
        showState();
        showArea();
        showCountry();
        showPINCode();
    }
    void getTypeOfAcc(){
        char t;
        cout << "\n Select Type of Account" << endl;
        cout << " ----------------------" << endl;
        cout << left << setw(29) << " 1. Saving" << endl;
        cout << left << setw(29) << " 2. Current" << ": ";
        cin >> t;
        checkTypeOfAcc(t);
    }
    void checkTypeOfAcc(char t){
        if(t=='1'){
            typeOfAcc = "SAVING";
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showAddress();
            showTypeOfAcc();
        }
        else if(t=='2'){
            typeOfAcc = "CURRENT";
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showAddress();
            showTypeOfAcc();
        }
        else{
            setcolor(16*0+4);
            cout << " Invalid Account Type \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showAddress();
            getTypeOfAcc();

        }
    }
    void showTypeOfAcc(){
        cout << left << setw(30) << "\n Select Type of Account" << ": " << typeOfAcc << endl;
    }
    void getOpenAmt(){
        cout << left << setw(30) << "\n Enter Opening Amount" << ": ";
        cin >> openAmt;
        checkOpenAmt();
    }
    void checkOpenAmt(){
        if(openAmt<1000){
            setcolor(16*0+4);
            cout << " Invalid Amount (Must be Greater than 1000) \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            showName();
            showFatherName();
            showMotherName();
            showGender();
            showAge();
            showMobNum();
            showAadhar();
            showAddress();
            showTypeOfAcc();
            getOpenAmt();

        }
    }
    void showOpenAmt(){
        cout << left << setw(30) << "\n Enter Opening Amount" << ": " << openAmt << endl;
    }

};

class CreateNewAccount : public InputBank{
protected:
    Type generatedAccNum;
    Type generatedPIN;
    int currentBalance;
public:
    void openDetailsFileForWriting(){
        string filename = "Data\\Details\\Other Info\\" + name + "_details.txt";
        DetailsOut.open(filename.c_str(), ios::out);

    }
    void closeDetailsFileForWriting(){
        DetailsOut.close();
    }
    void openOtherDetailsFileForWriting(){
        string tempAccNum = to_string(generatedAccNum);
        string accountNumberFile = "Data\\Details\\Account Number\\" + tempAccNum + ".txt";
        string PINFile = "Data\\Details\\PIN\\" + name + "_PIN.txt";
        string nameFile = "Data\\Details\\Name\\" + name + "_name.txt";
        string BalanceFile = "Data\\Details\\Balance\\" + name + "_balance.txt";
        string TypeFile = "Data\\Details\\Type of Account\\" + name + "_type.txt";
        string TransactionFile = "Data\\Details\\Transactions\\" + name + "_transactions.txt";
        IndividualAccOut.open(accountNumberFile.c_str(), ios::out);
        IndividualPINOut.open(PINFile.c_str(), ios::out);
        NameOut.open(nameFile.c_str(), ios::out);
        BalOut.open(BalanceFile.c_str(), ios::out);
        TypeOut.open(TypeFile.c_str(), ios::out);
        TransOut.open(TransactionFile.c_str(), ios::app);

    }
    void closeOtherDetailsFileForWriting(){
        IndividualAccOut.close();
        IndividualPINOut.close();
        NameOut.close();
        BalOut.close();
        TypeOut.close();
        TransOut.close();
    }
    void openAccNumFileForReading(){
        string strGenAccNum = to_string(generatedAccNum);
        string accountNumberFile = "Data\\Details\\Account Number\\" + strGenAccNum + ".txt";
        IndividualAccIn.open(accountNumberFile.c_str(), ios::in);
    }
    void closeAccNumFileForReading(){
        IndividualAccIn.close();
    }
    void getDetails(){
        cin.ignore();
        getName();
        getFatherName();
        getMotherName();
        getGender();
        getAge();
        getMobNum();
        getAadhar();
        getAddress();
        getTypeOfAcc();
        getOpenAmt();
        validateAccountNumber();
        validatePIN();
        verifying();
        successScreen();
        storeDetails();
    }
    Type generateAccNum(){
        return rand()/(float)RAND_MAX * (99999999999-10000000000) + 10000000000 ;
    }
    Type generatePIN(){
        return rand()/(float)RAND_MAX * (9999-1000) + 1000 ;
    }
    void validateAccountNumber(){
        srand(unsigned(time(0)));
        generatedAccNum = generateAccNum();
        openAccNumFileForReading();
        if(!IndividualAccIn){
            return;
        }
        else{
            closeAccNumFileForReading();
            validateAccountNumber();
        }
    }
    void validatePIN(){
        srand(unsigned(time(0)));
        generatedPIN = generatePIN()-58;

    }
    void verifying(){
        Sleep(600);
        char c = 254;
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << setw(27) << " " << "VERIFYING YOUR CREDENTIALS" << endl << endl;
        for (int j = 0; j < 3; j++){
            cout << "\r                                           \r                                   ";
            for (int i = 0; i < 8; i++){
                cout << c;
                Sleep(150);
            }
        }


    }
    void successScreen(){
        Sleep(1500);
        system("cls");
        cout << "\n\n\n";
        cout << setw(25) << " ";
        setcolor(16*2+7);
        cout << "                               " << endl;
        setcolor(7);
        cout << setw(25) << " ";
        setcolor(16*2+7);
        cout << " C O N G R A T U L A T I O N S " << endl;
        setcolor(7);
        cout << setw(25) << " ";
        setcolor(16*2+7);
        cout << "                               " << endl;
        setcolor(7);
        cout << "\n";
        cout << setw(19) << " ";
        cout << " You have successfully opened your Account " << endl << endl;
        cout << "\n\n";
        cout << setw(25) << " ";
        setcolor(16*7+0);
        cout << " ACCOUNT NUMBER ";
        setcolor(7);
        cout << " : " << generatedAccNum << endl << endl;
        cout << setw(25) << " ";
        setcolor(16*7+0);
        cout << " PIN ";
        setcolor(7);
        cout << "            : " << generatedPIN << endl;
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << " Thank You for visiting our bank, please come back again :) ";


    }
    void storeDetails(){
        storeOtherDetails();
        openDetailsFileForWriting();
        DetailsOut << "Name : " << name << endl;
        DetailsOut << "Age : " << age << endl;
        DetailsOut << "Gender : " << gender << endl;
        DetailsOut << "Date of Birth : " << d << "/" << m << "/" << y << endl;
        DetailsOut << "Father Name : " << fName << endl;
        DetailsOut << "Mother Name : " << mName << endl;
        DetailsOut << "Mobile Number : " << mobNum << endl;
        DetailsOut << "Aadhar Number : " << aadhar << endl;
        DetailsOut << "Address : " << add.area << endl;
        DetailsOut << "          " << add.city << endl;
        DetailsOut << "          " << add.state << " " << add.PINCODE << endl;
        DetailsOut << "          " << add.country << endl;
        closeDetailsFileForWriting();
    }
    void storeOtherDetails(){
        currentBalance = openAmt;
        openOtherDetailsFileForWriting();
        NameOut << name;
        BalOut << currentBalance << endl;
        TypeOut << typeOfAcc << endl;
        TransOut << " New Account Opened ( with Opening Amount " << openAmt << " ) on " << displayCurrentDateAndTime() << endl;
        IndividualAccOut << name;
        IndividualPINOut << generatedPIN << endl;
        closeOtherDetailsFileForWriting();
    }
};

class CheckBalance : public CreateNewAccount{
protected:
    ifstream tempNameFile;
    ifstream tempTypeFile;
    fstream tempBalFile;
    string getAccNum;
    string getPIN;
    string tempName;
    string printName;
    string printType;
    string printBal;
public:
    void openAccNumFileForReading(){
        string accountNumberFile = "Data\\Details\\Account Number\\" + getAccNum + ".txt";
        IndividualAccIn.open(accountNumberFile.c_str(), ios::in);
    }
    void closeAccNumFileForReading(){
        IndividualAccIn.close();
    }
    void openPINFileForReading(){
        string PINFile = "Data\\Details\\PIN\\" + tempName + "_PIN.txt";
        IndividualPINIn.open(PINFile.c_str(), ios::in);
    }
    void closePINFileForReading(){
        IndividualPINIn.close();
    }
    void openNameAndTypeFiles(){
        string filename1 = "Data\\Details\\Name\\" + tempName + "_name.txt";
        tempNameFile.open(filename1.c_str(), ios::in);
        string filename2 = "Data\\Details\\Type of Account\\" + tempName + "_type.txt";
        tempTypeFile.open(filename2.c_str(), ios::in);
    }
    void closeNameAndTypeFiles(){
        tempNameFile.close();
        tempTypeFile.close();
    }
    void openBalFile(){
        string filename3 = "Data\\Details\\Balance\\" + tempName + "_balance.txt";
        tempBalFile.open(filename3.c_str(), ios::in | ios::out);
    }
    void closeBalFile(){
        tempBalFile.close();
    }
    void checkHead(){
        if(head == 'b'){
            headBal();
        }
        else if(head == 'd'){
            headDepo();
        }
        else if(head == 'w'){
            headWith();
        }
        else if(head == 't'){
            headTrans();
        }
        else if(head == 's'){
            headSend();
        }
    }
    void inputAccNum(){
        checkHead();
        cout << setw(21) << " ";
        cout << "Enter Your Account Number : ";
        cin >> getAccNum;
        openAccNumFileForReading();
        verifyAccNum();
        closeAccNumFileForReading();
    }
    void verifyAccNum(){
        if (!IndividualAccIn)
        {
            cout << setw(21) << " ";
            setcolor(16*0+4);
            cout << "Invalid Account Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            inputAccNum();
        }
        else{
            while(!IndividualAccIn.eof()){
                getline(IndividualAccIn, tempName);
            }

        }


    }
    void displayNameAndType(){
        openNameAndTypeFiles();

        while(!tempNameFile.eof()){
            getline(tempNameFile, printName);
        }
        while(!tempTypeFile.eof()){
            tempTypeFile >> printType;
        }
        system("cls");
        checkHead();
        cout << setw(27) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(27) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
        closeNameAndTypeFiles();

    }
    void inputPIN(){
        cout << "\n\n\n\n";
        cout << setw(27) << " ";
        cout << "To check Your Balance" << endl;
        cout << setw(27) << " ";
        cout << "---------------------" << endl;
        cout << setw(27) << " ";
        cout << "Enter Your PIN : ";
        cin >> getPIN;
        verifyPIN();
    }
    void verifyPIN(){
        openPINFileForReading();
        string p;
        while(!IndividualPINIn.eof()){
            IndividualPINIn >> p;
        }
        if(getPIN!=p){
            cout << setw(27) << " ";
            setcolor(16*0+4);
            cout << "Wrong PIN \a" << endl;
            setcolor(7);
            Sleep(1200);
            closePINFileForReading();
            showContent();
            inputPIN();
        }
    }
    void showContent(){
        system("cls");
        checkHead();
        cout << setw(27) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(27) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;

    }
    void verifyScreen(){
        cout << "\n\n\n";
        setcolor(16*0+3);
        for (int j = 0; j < 3; j++){
            cout << "\r                           Verifying    \r                           Verifying";
            for (int i = 0; i < 4; i++){
                cout << ".";
                Sleep(300);
            }
        }
        setcolor(7);
    }
    void displayBal(){
        openBalFile();
        while(!tempBalFile.eof()){
            tempBalFile >> printBal;
        }
        system("cls");
        headBal();
        cout << "\n\n";
        cout << setw(25) << " ";
        cout << "Your Current Balance is  : " << printBal << endl;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << " Thank You for visiting our bank, please come back again :) ";
        closeBalFile();
    }

};

class Deposit: virtual public CheckBalance{
protected:
    int depoAmt;
    int readCurrentBal;
    ofstream tempTransFile;

public:
    void openTransFile(){
        string filename1 = "Data\\Details\\Transactions\\" + tempName + "_transactions.txt";
        tempTransFile.open(filename1.c_str(), ios::app);
    }
    void closeTransFile(){
        tempTransFile.close();
    }
    void inputDepositAmount(){
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "Enter Deposit Amount  : ";
        cin >> depoAmt;

    }
    void inputPIN(){
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "To verify" << endl;
        cout << setw(27) << " ";
        cout << "---------" << endl;
        cout << setw(27) << " ";
        cout << "Enter Your PIN : ";
        cin >> getPIN;
        verifyPIN();
    }
    void verifyPIN(){
        openPINFileForReading();
        string p;
        while(!IndividualPINIn.eof()){
            IndividualPINIn >> p;
        }
        if(getPIN!=p){
            cout << setw(27) << " ";
            setcolor(16*0+4);
            cout << "Wrong PIN \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            closePINFileForReading();
            showContent();
            inputPIN();
        }
    }
    void showContent(){
        system("cls");
        checkHead();
        cout << setw(27) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(27) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "Enter Deposit Amount  : " << depoAmt << endl;

    }
    void updateBal(){
        openBalFile();
        while(!tempBalFile.eof()){
            tempBalFile >> readCurrentBal;
        }
        closeBalFile();

        openBalFile();
        currentBalance = readCurrentBal + depoAmt;
        tempBalFile << currentBalance << endl;
        system("cls");
        headDepo();
        cout << "\n";
        cout << setw(27) << " ";
        setcolor(16*0+2);
        cout << "AMOUNT DEPOSITED SUCCESSFULLY" << endl;
        setcolor(7);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << " Thank You for visiting our bank, please come back again :) ";
        closeBalFile();
    }
    void updateTrans(){
        openTransFile();
        tempTransFile << depoAmt << " rupees Deposited on " << displayCurrentDateAndTime();
        closeTransFile();
    }

};

class Withdraw : virtual public CheckBalance{
protected:
    int withdrawAmt;
    int readCurrentBal;
    ofstream tempTransFile;
public:
    void openTransFile(){
        string filename1 = "Data\\Details\\Transactions\\" + tempName + "_transactions.txt";
        tempTransFile.open(filename1.c_str(), ios::app);
    }
    void closeTransFile(){
        tempTransFile.close();
    }
    void inputWithdrawAmount(){
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "Enter Withdraw Amount  : ";
        cin >> withdrawAmt;
        verifyWithdrawAmount();
    }
    void verifyWithdrawAmount(){
        openBalFile();
        while(!tempBalFile.eof()){
            tempBalFile >> readCurrentBal;
        }
        closeBalFile();
        if(readCurrentBal < withdrawAmt){
            cout << setw(27) << " ";
            setcolor(16*0+4);
            cout << "Not Enough Available Balance \a" << endl;
            setcolor(7);
            Sleep(1400);
            system("cls");
            showContent();
            inputWithdrawAmount();
        }
        if((readCurrentBal-withdrawAmt)<1000){
            cout << setw(27) << " ";
            setcolor(16*0+4);
            cout << "Minimum Remaining Balance must be 1000 \a" << endl;
            setcolor(7);
            Sleep(1400);
            system("cls");
            showContent();
            inputWithdrawAmount();
        }
    }
    void showWithdrawAmount(){
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "Enter Withdraw Amount  : " << withdrawAmt << endl;
    }
    void showContent(){
        system("cls");
        checkHead();
        cout << setw(27) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(27) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;

    }
    void inputPIN(){
        cout << "\n\n";
        cout << setw(27) << " ";
        cout << "To verify" << endl;
        cout << setw(27) << " ";
        cout << "---------" << endl;
        cout << setw(27) << " ";
        cout << "Enter Your PIN : ";
        cin >> getPIN;
        verifyPIN();
    }
    void verifyPIN(){
        openPINFileForReading();
        string p;
        while(!IndividualPINIn.eof()){
            IndividualPINIn >> p;
        }
        if(getPIN!=p){
            cout << setw(27) << " ";
            setcolor(16*0+4);
            cout << "Wrong PIN \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            closePINFileForReading();
            showContent();
            showWithdrawAmount();
            inputPIN();
        }
    }
    void updateBal(){
        openBalFile();
        currentBalance = readCurrentBal - withdrawAmt;
        tempBalFile << currentBalance << endl;
        system("cls");
        headWith();
        cout << "\n";
        cout << setw(27) << " ";
        setcolor(16*0+2);
        cout << "AMOUNT WITHDRAWN  SUCCESSFULLY" << endl;
        setcolor(7);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << " Thank You for visiting our bank, please come back again :) ";
        closeBalFile();
    }
    void updateTrans(){
        openTransFile();
        tempTransFile << withdrawAmt << " rupees Withdrawn on " << displayCurrentDateAndTime();
        closeTransFile();
    }
};

class Transaction : virtual public CheckBalance{
protected:
    ifstream tempTransFile;
public:
    void openTransFileForReading(){
        string filename1 = "Data\\Details\\Transactions\\" + tempName + "_transactions.txt";
        tempTransFile.open(filename1.c_str(), ios::in);
    }
    void closeTransFileForReading(){
        tempTransFile.close();
    }
    void displayNameAndType(){
        openNameAndTypeFiles();

        while(!tempNameFile.eof()){
            getline(tempNameFile, printName);
        }
        while(!tempTypeFile.eof()){
            tempTypeFile >> printType;
        }
        system("cls");
        checkHead();
        cout << setw(23) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(23) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
        closeNameAndTypeFiles();

    }
    void inputPIN(){
        cout << "\n\n\n";
        cout << setw(23) << " ";
        cout << "To See Your Transaction History" << endl;
        cout << setw(23) << " ";
        cout << "-------------------------------" << endl;
        cout << setw(23) << " ";
        cout << "Enter Your PIN : ";
        cin >> getPIN;
        verifyPIN();
    }
    void verifyPIN(){
        openPINFileForReading();
        string p;
        while(!IndividualPINIn.eof()){
            IndividualPINIn >> p;
        }
        if(getPIN!=p){
            cout << setw(23) << " ";
            setcolor(16*0+4);
            cout << "Wrong PIN \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            closePINFileForReading();
            showContent();
            inputPIN();
        }
    }
    void showContent(){
        system("cls");
        checkHead();
        cout << setw(23) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(23) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;

    }
    void verifyScreen(){
        cout << "\n\n\n\n\n";
        setcolor(16*0+3);
        for (int j = 0; j < 3; j++){
            cout << "\r                       Verifying    \r                       Verifying";
            for (int i = 0; i < 4; i++){
                cout << ".";
                Sleep(300);
            }
        }
        setcolor(7);
    }
    void showTransactions(){
        openTransFileForReading();
        string line;
        system("cls");
        headTrans();
        char point = 254;
        while(!tempTransFile.eof()){
            getline(tempTransFile, line);
            if(line!=" "){
                cout << " " << point << " " << line << endl;
            }
        }
        cout << "\n";
        cout << " Thank You for visiting our bank, please come back again :) ";
        closeTransFileForReading();
    }

};

class SendMoney{
protected:
    ifstream tempNameFile;
    ifstream tempTypeFile;
    fstream tempBalFile;
    fstream tempBalFileRecp;
    ofstream tempTransFile;
    ofstream tempTransFileRecp;
    string getAccNum;
    string getRecipientAccNum;
    string getPIN;
    string tempName;
    string tempNameRecp;
    string printName;
    string printType;
    string printBal;
    int readCurrentBal;
    int readCurrentBalRecp;
    int f=0;
    int g=0;
    int sendAmt;
public:
    void openTransFile(){
        string filename1 = "Data\\Details\\Transactions\\" + tempName + "_transactions.txt";
        tempTransFile.open(filename1.c_str(), ios::app);
    }
    void closeTransFile(){
        tempTransFile.close();
    }
    void openTransFileRecp(){
        string filename1 = "Data\\Details\\Transactions\\" + tempNameRecp + "_transactions.txt";
        tempTransFileRecp.open(filename1.c_str(), ios::app);
    }
    void closeTransFileRecp(){
        tempTransFileRecp.close();
    }
    void openAccNumFileForReading(){
        string accountNumberFile = "Data\\Details\\Account Number\\" + getAccNum + ".txt";
        IndividualAccIn.open(accountNumberFile.c_str(), ios::in);
    }
    void closeAccNumFileForReading(){
        IndividualAccIn.close();
    }
    void openAccNumFileForReadingRecp(){
        string accountNumberFile = "Data\\Details\\Account Number\\" + getRecipientAccNum + ".txt";
        IndividualAccIn.open(accountNumberFile.c_str(), ios::in);
    }
    void closeAccNumFileForReadingRecp(){
        IndividualAccIn.close();
    }
    void openPINFileForReading(){
        string PINFile = "Data\\Details\\PIN\\" + tempName + "_PIN.txt";
        IndividualPINIn.open(PINFile.c_str(), ios::in);
    }
    void closePINFileForReading(){
        IndividualPINIn.close();
    }
    void openNameAndTypeFiles(){
        string filename1 = "Data\\Details\\Name\\" + tempName + "_name.txt";
        tempNameFile.open(filename1.c_str(), ios::in);
        string filename2 = "Data\\Details\\Type of Account\\" + tempName + "_type.txt";
        tempTypeFile.open(filename2.c_str(), ios::in);
    }
    void closeNameAndTypeFiles(){
        tempNameFile.close();
        tempTypeFile.close();
    }
    void openBalFile(){
        string filename3 = "Data\\Details\\Balance\\" + tempName + "_balance.txt";
        tempBalFile.open(filename3.c_str(), ios::in | ios::out);
    }
    void closeBalFile(){
        tempBalFile.close();
    }
    void openBalFileOfRecipient(){
        string filename3 = "Data\\Details\\Balance\\" + tempNameRecp + "_balance.txt";
        tempBalFileRecp.open(filename3.c_str(), ios::in | ios::out);
    }
    void closeBalFileOfRecipient(){
        tempBalFileRecp.close();
    }
    void inputAccNum(){
        headSend();
        cout << setw(21) << " ";
        cout << "Enter Your Account Number  : ";
        cin >> getAccNum;
        openAccNumFileForReading();
        verifyAccNum();
        closeAccNumFileForReading();
    }
    void verifyAccNum(){
        if (!IndividualAccIn)
        {
            cout << setw(21) << " ";
            setcolor(16*0+4);
            cout << "Invalid Account Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            inputAccNum();
        }
        else{
            while(!IndividualAccIn.eof()){
                getline(IndividualAccIn, tempName);
            }

        }
    }
    void displayNameAndType(){
        openNameAndTypeFiles();

        while(!tempNameFile.eof()){
            getline(tempNameFile, printName);
        }
        while(!tempTypeFile.eof()){
            tempTypeFile >> printType;
        }
        system("cls");
        headSend();
        cout << setw(23) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(23) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
        closeNameAndTypeFiles();

    }
    void inputRecipientAccNum(){
        system("cls");
        headSend();
        cout << setw(17) << " ";
        cout << "Enter Recipient's Account Number  : ";
        cin >> getRecipientAccNum;
        verifyNotSame();
        openAccNumFileForReadingRecp();
        verifyAccNumRecp();
        closeAccNumFileForReadingRecp();
    }
    void verifyNotSame(){
        if(getRecipientAccNum==getAccNum){
            cout << setw(17) << " ";
            setcolor(16*0+4);
            cout << "Invalid Account Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            inputRecipientAccNum();
        }
    }
    void verifyAccNumRecp(){


        if (!IndividualAccIn)
        {
            cout << setw(17) << " ";
            setcolor(16*0+4);
            cout << "Invalid Account Number \a" << endl;
            setcolor(7);
            Sleep(1200);
            inputRecipientAccNum();
        }
        else{
            while(!IndividualAccIn.eof()){
                getline(IndividualAccIn, tempNameRecp);

            }

        }
    }
    void inputSendingMoney(){
        cout << "\n\n";
        cout << setw(23) << " ";
        cout << "Enter Amount to Send  : ";
        cin >> sendAmt;
        verifyAmount();
    }
    void verifyAmount(){
        openBalFile();
        while(!tempBalFile.eof()){
            tempBalFile >> readCurrentBal;
        }
        closeBalFile();
        if(readCurrentBal < sendAmt){
            cout << setw(23) << " ";
            setcolor(16*0+4);
            cout << "Not Enough Available Balance \a" << endl;
            setcolor(7);
            Sleep(1400);
            system("cls");
            showContent();
            inputSendingMoney();
        }
        if((readCurrentBal-sendAmt)<1000){
            cout << setw(23) << " ";
            setcolor(16*0+4);
            cout << "Minimum Remaining Balance must be 1000 \a" << endl;
            setcolor(7);
            Sleep(1400);
            system("cls");
            showContent();
            inputSendingMoney();
        }
    }

    void updateBalances(){
        openBalFile();
        int currentBalance = readCurrentBal - sendAmt;
        tempBalFile << currentBalance << endl;
        closeBalFile();

        openBalFileOfRecipient();
        while(!tempBalFileRecp.eof()){
            tempBalFileRecp >> readCurrentBalRecp;
        }
        closeBalFileOfRecipient();
        openBalFileOfRecipient();
        int currentBalanceRecp = readCurrentBalRecp + sendAmt;
        tempBalFileRecp << currentBalanceRecp << endl;
        closeBalFileOfRecipient();

    }
    void updateTrans(){
        openTransFile();
        tempTransFile << sendAmt << " rupees Sent to " << tempNameRecp << " on " << displayCurrentDateAndTime();
        closeTransFile();

        openTransFileRecp();
        tempTransFileRecp << sendAmt << " rupees Received from " << tempName << " on " << displayCurrentDateAndTime();
        closeTransFileRecp();

    }
    void inputPIN(){
        cout << "\n\n";
        cout << setw(17) << " ";
        cout << "To Send Money" << endl;
        cout << setw(17) << " ";
        cout << "-------------" << endl;
        cout << setw(17) << " ";
        cout << "Enter Your PIN : ";
        cin >> getPIN;
        verifyPIN();
    }
    void verifyPIN(){
        openPINFileForReading();
        string p;
        while(!IndividualPINIn.eof()){
            IndividualPINIn >> p;
        }
        if(getPIN!=p){
            cout << setw(17) << " ";
            setcolor(16*0+4);
            cout << "Wrong PIN \a" << endl;
            setcolor(7);
            Sleep(1200);
            system("cls");
            closePINFileForReading();
            showContent2();
            inputPIN();
        }
    }
     void verifyScreen(){
        cout << "\n\n\n\n\n";
        setcolor(16*0+3);
        for (int j = 0; j < 3; j++){
            cout << "\r                 Verifying    \r                 Verifying";
            for (int i = 0; i < 4; i++){
                cout << ".";
                Sleep(300);
            }
        }
        setcolor(7);
    }
    void sentSuccessfull(){
        system("cls");
        headSend();
        cout << setw(25) << " ";
        setcolor(16*0+2);
        cout << "MONEY SENT SUCCESSFULLY to " << tempNameRecp << endl;
        setcolor(7);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << " Thank You for visiting our bank, please come back again :) ";
    }
    void showContent2(){
        headSend();
        cout << setw(17) << " ";
        cout << "Enter Recipient's Account Number  : " << getRecipientAccNum << endl;
    }
    void showContent3(){
        headSend();
        cout << setw(23) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(23) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
        cout << "\n\n";
        cout << setw(23) << " ";
        cout << "Enter Amount to Send  : " << sendAmt << endl;
        cout << "\n\n";
        cout << setw(23) << " ";
        cout << "Enter Recipient's Account Number  : " << getRecipientAccNum << endl;
    }
    void showContent(){
        headSend();
        cout << setw(23) << " ";
        cout << "HELLO " << printName << endl;
        cout << setw(23) << " ";
        cout << "You have a ( " << printType << " ) Account" << endl;
    }


};




int main(){
    welcomeScreen();
    mainMenu();
    getch();
    return 0;
}

void welcomeScreen(){
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << setw(11) << " " << " __  __                 __      __  __  __      __      _ _ " << endl;
	cout << setw(11) << " " << "| _||__||\\ ||_/    |\\/||__||\\ ||__||  _|__ |\\/||__ |\\ |  |" << endl;
	cout << setw(11) << " " << "|__||  || \\|| \\    |  ||  || \\||  ||__||__ |  ||__ | \\|  |" << endl << endl;
	cout << setw(11) << " " << "------------------------------------------------------------" << endl;

	cout << setw(27) << " " << " __      __ _ _  __" << endl;
	cout << setw(27) << " " << "|__ \\_/ |__  |  |__ |\\/|" << endl;
	cout << setw(27) << " " << " __| |   __| |  |__ |  |" << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << setw(25) << " " << "copyright @ Rameez Siddiqui";


    getch();
}

void mainMenu(){
    char n;
    system("cls");
    cout << "\n\n\n\n";
    cout << setw(26) << " ";
    cout << " 1. OPEN NEW ACCOUNT" << endl << endl;
    cout << setw(26) << " ";
    cout << " 2. CHECK BALANCE" << endl << endl;
    cout << setw(26) << " ";
    cout << " 3. CASH DEPOSIT" << endl << endl;
    cout << setw(26) << " ";
    cout << " 4. CASH WITHDRAW" << endl << endl;
    cout << setw(26) << " ";
    cout << " 5. TRANSACTION HISTORY" << endl << endl;
    cout << setw(26) << " ";
    cout << " 6. SEND MONEY" << endl << endl;
    cout << setw(26) << " ";
    cout << " 7. EXIT" << endl << endl;
    cout << setw(26) << " ";
    cout << "-----------------------------" << endl;
    cout << setw(26) << " ";
    cout << " Enter Your Choice : ";
    cin >> n;
    choice(n);
}

void choice(char n){
    if(n=='1'){
        system("cls");
        CreateNewAccount n;
        n.getDetails();
        //n.successScreen();
    }
    else if(n=='2'){
        head = 'b';
        system("cls");
        CheckBalance c;
        c.inputAccNum();
        c.displayNameAndType();
        Sleep(1250);
        c.inputPIN();
        c.verifyScreen();
        c.displayBal();
    }
    else if(n=='3'){
        head = 'd';
        system("cls");
        Deposit d;
        d.inputAccNum();
        d.displayNameAndType();
        Sleep(1250);
        d.inputDepositAmount();
        Sleep(1000);
        d.inputPIN();
        d.verifyScreen();
        d.updateBal();
        d.updateTrans();
    }
    else if(n=='4'){
        head = 'w';
        system("cls");
        Withdraw w;
        w.inputAccNum();
        w.displayNameAndType();
        Sleep(1250);
        w.inputWithdrawAmount();
        Sleep(1000);
        w.inputPIN();
        w.verifyScreen();
        w.updateBal();
        w.updateTrans();
    }
    else if(n=='5'){
        head = 't';
        system("cls");
        Transaction t;
        t.inputAccNum();
        t.displayNameAndType();
        t.inputPIN();
        t.verifyScreen();
        t.showTransactions();
    }
    else if(n=='6'){
        head = 's';
        system("cls");
        SendMoney s;
        s.inputAccNum();
        s.displayNameAndType();
        Sleep(1200);
        s.inputSendingMoney();
        s.inputRecipientAccNum();
        Sleep(1000);
        s.inputPIN();
        s.updateBalances();
        s.updateTrans();
        s.verifyScreen();
        s.sentSuccessfull();
    }
    else if(n=='7'){
        exit(0);
    }
    else{
        cout << setw(26) << " ";
        setcolor(16*0+4);
        cout << " Invalid Choice \a" << endl;
        setcolor(7);
        Sleep(1200);
        mainMenu();

    }
}
bool isNumber(const string& str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}
void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}

int calcAge(int d, int m, int y){
    struct tm date = {0};
    date.tm_year = y-1900;
    date.tm_mon  = m-1;
    date.tm_mday = d;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    int age = (difftime(current, normal) + 86400L/2) / 86400L;
    return age/365;
}
char* displayCurrentDateAndTime(){
    time_t now = time(0);
    char* date_time = ctime(&now);
    return date_time;
}
void headCreateNew(){
    cout << "\n\n";
    cout << setw(22) << " ";
    setcolor(16*7+0);
    cout << "                                      " << endl;
    setcolor(7);
    cout << setw(22) << " ";
    setcolor(16*7+0);
    cout << "   O P E N    N E W   A C C O U N T   " << endl;
    setcolor(7);
    cout << setw(22) << " ";
    setcolor(16*7+0);
    cout << "                                      " << endl;
    setcolor(7);
    cout << "\n\n";
}
void headBal(){
    cout << "\n\n";
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << "                           " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << " C H E C K   B A L A N C E " << endl;
    setcolor(7);
    cout << setw(27) << " ";
    setcolor(16*7+0);
    cout << "                           " << endl;
    setcolor(7);
    cout << "\n\n";
}
void headDepo(){
    cout << "\n\n";
    cout << setw(34) << " ";
    setcolor(16*7+0);
    cout << "               " << endl;
    setcolor(7);
    cout << setw(34) << " ";
    setcolor(16*7+0);
    cout << " D E P O S I T " << endl;
    setcolor(7);
    cout << setw(34) << " ";
    setcolor(16*7+0);
    cout << "               " << endl;
    setcolor(7);
    cout << "\n\n";
}
void headWith(){
    cout << "\n\n";
    cout << setw(33) << " ";
    setcolor(16*7+0);
    cout << "                 " << endl;
    setcolor(7);
    cout << setw(33) << " ";
    setcolor(16*7+0);
    cout << " W I T H D R A W " << endl;
    setcolor(7);
    cout << setw(33) << " ";
    setcolor(16*7+0);
    cout << "                 " << endl;
    setcolor(7);
    cout << "\n\n";
}
void headTrans(){
    cout << "\n\n";
    cout << setw(21) << " ";
    setcolor(16*7+0);
    cout << "                                       " << endl;
    setcolor(7);
    cout << setw(21) << " ";
    setcolor(16*7+0);
    cout << " T R A N S A C T I O N   H I S T O R Y " << endl;
    setcolor(7);
    cout << setw(21) << " ";
    setcolor(16*7+0);
    cout << "                                       " << endl;
    setcolor(7);
    cout << "\n\n";
}
void headSend(){
    cout << "\n\n";
    cout << setw(30) << " ";
    setcolor(16*7+0);
    cout << "                     " << endl;
    setcolor(7);
    cout << setw(30) << " ";
    setcolor(16*7+0);
    cout << " S E N D   M O N E Y " << endl;
    setcolor(7);
    cout << setw(30) << " ";
    setcolor(16*7+0);
    cout << "                     " << endl;
    setcolor(7);
    cout << "\n\n";
}
