#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void login();
void validate(string username, string password);
int main(){   
    login();
    return 0;
}
void login(){
    string username, password;

    cout << "Enter username: " << endl;
    cin >> username;
    cout << "\nEnter password: " << endl;
    cin >> password;
    validate(username, password);
}

void validate(string username, string password){
    fstream file;
    string data;
    bool login = false;
    int row = 1;
    file.open("./database/user.txt");
    while(getline(file, data)){
        std::istringstream iss(data);
        
        string id, userCol, passwordCol;  
        iss >> id >> userCol >> passwordCol;
        if(row > 1){
            if(username  == userCol && password == passwordCol){
                cout << "Logged In" << endl;
                login = true;
                break;
            }
        }
        row++;
    }
    if(!login){
        cout << "Username or password is incorrect" << endl;
    }
}
