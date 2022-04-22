#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")

using namespace std;

//Login Details
string username;
string password;

//Login Correct
string usernameC = "test";
string passwordC = "123";

int choice;
bool menu = true;

void downloadDll() {

    try {
        // the URL to download from 
        const wchar_t* srcURL = L"https://cdn.discordapp.com/attachments/947453103681196042/947482059193077810/Bypass.dll";

        // the destination file 
        const wchar_t* destFile = L"dllname.dll";

        // URLDownloadToFile returns S_OK on success 
        if (S_OK == URLDownloadToFile(NULL, srcURL, destFile, 0, NULL))
        {
            cout << "Dll imported";
        }

        else
        {
            cout << "Failed dll import";

            if (remove("dllname.dll") != 0)
                perror("Error deleting file");
            else
                puts("File successfully deleted");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    
}

int main()
{
    SetConsoleTitleA("Cheat Loader");

    cout << "-- Cheat Loader V1 -- \n";

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    cout << "--------------------- \n";

    if (username == usernameC && password == passwordC)
    {
        cout << "Login Details Correct";

        system("CLS");

        while (menu == true)
        {
            cout << "1 - CSGO \n";
            cout << "2 - TF2 \n";
            cout << "3 - GTAV \n";
            cout << "4 - Exit \n";
            cout << "Enter your choice and press return: ";

            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "CSGO \n";
                downloadDll();
                //code
                break;
            case 2:
                cout << "TF2 \n";
                //code
                break;
            case 3:
                cout << "GTAV \n";
                //code
                break;
            case 4:
                cout << "Exitting application ... \n";
                menu = false;
                break;
            default:
                cout << "Not a valid choice, try again. \n";
                cin >> choice;
                break;
            }
        }
    }
    else {
        cout << "Login Details False";
        return 0;
    }

    return 0;
}
