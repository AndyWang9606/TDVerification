// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "TDVerification.h"
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <shobjidl.h> 

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
std::string TotalLine;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TDVERIFICATION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TDVERIFICATION));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TDVERIFICATION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TDVERIFICATION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


/* Description: Converts ASCII Characters to Integers in a string starting from postion with a certain length
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: void
 * param [in] start - Index of starting position
 * param [in] length - the number of characters to be converted.
 * param [out] a[] - converted ingeters stored in a[]
 *********************************/
void ConvertCharToInt(int start, int length, int a[])
{
    int i = 0;
    
    for (i = start; i <= start + length; i++)
    {

        if (isdigit(TotalLine[i])) 
        {
            a[i] = TotalLine[i] - '0';
        }
        else if (TotalLine[i] >= 'A' && TotalLine[i] <= 'Z')
        {
            a[i] = TotalLine[i] - 'A' + 10;
        }
        else if (TotalLine[i] == '<')
        {
            a[i] = 0;
        }
    }  
}

/* Description: Checks check digit
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: true - pass check digit; false - fail
 * param [in] start - Index of starting position
 * param [in] length - the number of characters to be read.
 * param [in] a[] - ingeter array to be calculated
 *********************************/
bool CheckDigit(int start, int length, int a[])
{
    int multiplier[3] = { 7, 3, 1 };
    int i = 0;
    int s = 0;
    int m = 0;  //For seperate check digits

    for (i = start; i <= start + length - 2; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    if (s % 10 == a[start + length - 1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Description: Checks overall check digit for Passport
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: true - pass check digit; false - fail
 * param [in] a[] - ingeter array to be calculated
 *********************************/
bool TotalCheckDigitPassport(int a[])
{
    int multiplier[3] = { 7, 3, 1 };
    int i = 0;
    int s = 0;
    int m = 0;  //For seperate check digits

    for (i = 45; i <= 54; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 58; i <= 64; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 66; i <= 72; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 73; i <= 87; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    if (s % 10 == a[88])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Description: Checks overall check digit for Travel Document Ver. 1
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: true - pass check digit; false - fail
 * param [in] a[] - ingeter array to be calculated
 *********************************/
bool TotalCheckDigitTD1(int a[])
{
    int multiplier[3] = { 7, 3, 1 };
    int i = 0;
    int s = 0;
    int m = 0;  //For seperate check digits

    for (i = 5; i <= 29; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 31; i <= 37; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 39; i <= 45; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 49; i <= 59; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    
    if (s % 10 == a[60])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Description: Checks overall check digit for Travel Document Ver. 2
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: true - pass check digit; false - fail
 * param [in] a[] - ingeter array to be calculated
 *********************************/
bool TotalCheckDigitTD2(int a[])
{
    int multiplier[3] = { 7, 3, 1 };
    int i = 0;
    int s = 0;
    int m = 0;  //For seperate check digits

    for (i = 37; i <= 46; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 50; i <= 56; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 58; i <= 71; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    if (s % 10 == a[72])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Description: Checks overall check digit for Visa Type A
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: true - pass check digit; false - fail
 * param [in] a[] - ingeter array to be calculated
 *********************************/
bool TotalCheckDigitVisaA(int a[])
{
    int multiplier[3] = { 7, 3, 1 };
    int i = 0;
    int s = 0;
    int m = 0;  //For seperate check digits

    for (i = 45; i <= 54; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 58; i <= 64; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 66; i <= 72; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    for (i = 73; i <= 87; i++)
    {
        s = s + a[i] * multiplier[m % 3];
        m++;
    }
    if (s % 10 == a[88])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Description: Checks if passport is valid
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: 0 - succeed,
 *         1 - First Check Digit Failed,
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed,
 *         4 - Optional Check Digit Failed,
 *         5 - Overall Check Digit Failed
 *********************************/
int VerifyPassport()
{
    int data[200];
    ConvertCharToInt(45, 44, data);
    if (!CheckDigit(45, 10, data))
    {
        return 1;
    }
    if (!CheckDigit(58, 7, data))
    {
        return 2;
    }
    if (!CheckDigit(66, 7, data))
    {
        return 3;
    }
    if (!CheckDigit(73, 15, data))
    {
        return 4;
    }
    if (!TotalCheckDigitPassport(data))
    {
        return 5;
    }
    return 0;
}

/* Description: Checks if Visa Type B is valid
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: 0 - succeed,
 *         1 - First Check Digit Failed,
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed,
 *         4 - Optional Check Digit Failed,
 *         5 - Overall Check Digit Failed
 *********************************/
int VerifyVisaA()
{
    int data[200];
    ConvertCharToInt(45, 44, data);
    if (!CheckDigit(45, 10, data))
    {
        return 1;
    }
    if (!CheckDigit(58, 7, data))
    {
        return 2;
    }
    if (!CheckDigit(66, 7, data))
    {
        return 3;
    }
    if (!CheckDigit(73, 15, data))
    {
        return 4;
    }
    if (!TotalCheckDigitVisaA(data))
    {
        return 5;
    }
    return 0;
}

/* Description: Checks if passport is valid
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: 0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *********************************/
int VerifyVisaB()
{
    int data[200];
    ConvertCharToInt(37, 36, data);
    if (!CheckDigit(37, 10, data))
    {
        return 1;
    }
    if (!CheckDigit(50, 7, data))
    {
        return 2;
    }
    if (!CheckDigit(58, 7, data))
    {
        return 3;
    }
    return 0;
}

/* Description: Checks if Travel Document Ver. 1 is valid
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: 0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *         4 - Overall Check Digit Failed,
 *         10 - Optional Check Digit Failed
 *********************************/
int VerifyTD1()
{
    int data[200];
    int i;
    int index = 0;
    ConvertCharToInt(0, 61, data);
    if (TotalLine[14] != '<')
    {
        if (!CheckDigit(5, 10, data))
        {
            return 1;
        }
        if (TotalLine[29] != '<')
        {
            if (!CheckDigit(15, 15, data))
            {
                return 10;
            }
        }
    }
    else
    {
        for (i = 15; i < 30; i++)
        {
            if (TotalLine[i] == '<')
            {
                index = i;
                break;
            }
        }
        if (!CheckDigit(5, index - 5, data))
        {
            return 1;
        }
    }
    if (!CheckDigit(31, 7, data))
    {
        return 2;
    }
    if (!CheckDigit(39, 7, data))
    {
        return 3;
    }
    if (!TotalCheckDigitTD1(data))
    {
        return 4;
    }
    return 0;

}

/* Description: Checks if Travel Document Ver. 2 is valid
 *
 * Author: Andy Wang   May 11, 2020
 *
 * Return: 0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *         4 - Overall Check Digit Failed,
 *         10 - Optional Check Digit Failed
 *********************************/
int VerifyTD2()
{
    int data[200];
    int i;
    int index;
    ConvertCharToInt(37, 36, data);
    if (!CheckDigit(37, 10, data))
    {
        return 1;
    }
    if (!CheckDigit(50, 7, data))
    {
        return 2;
    }
    if (!CheckDigit(58, 7, data))
    {
        return 3;
    }
    if (TotalLine[65] != '<')
    {
        for (i = 65; i < 71; i++)
        {
            if (TotalLine[i] == '<')
            {
                index = i;
                break;
            }
        }
        if (!CheckDigit(65, index - 65, data))
        {
            return 10;
        }
    }
    if (!TotalCheckDigitTD2(data))
    {
        return 4;
    }
    return 0;
}

// This code snippet demonstrates how to work with the common file dialog interface
// https://docs.microsoft.com/en-us/windows/win32/learnwin32/example--the-open-dialog-box
HRESULT BasicFileOpen(HWND hWnd)
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    HRESULT rtnValue = S_FALSE;
    if (SUCCEEDED(hr))
    {
        IFileOpenDialog* pFileOpen;

        // Create the FileOpenDialog object.
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
            IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

        if (SUCCEEDED(hr))
        {
            // Show the Open dialog box.
            hr = pFileOpen->Show(NULL);

            // Get the file name from the dialog box.
            if (SUCCEEDED(hr))
            {
                IShellItem* pItem;
                hr = pFileOpen->GetResult(&pItem);
                if (SUCCEEDED(hr))
                {
                    PWSTR pszFilePath;

                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                    // Display the file name to the user.
                    if (SUCCEEDED(hr))
                    {
                        std::ifstream myfile;       // file for read (in)
                        std::string  line;
                        
                        myfile.open(pszFilePath);

                        if (myfile.is_open()) 
                        {
                            while (std::getline(myfile, line))
                            {
                                std::cout << line << '\n';
                                line += 0x0A;
                                TotalLine.append(line);
                            }
                            //TotalLine.erase(89); //Erase last "return" character
                            
                            myfile.close();
                            rtnValue = S_OK;
                        }
                        else 
                        {
                            std::cout << "Unable to open file";
                        }
                        //MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
                        CoTaskMemFree(pszFilePath);
                    }
                    pItem->Release();
                }
            }
            else
            {
                rtnValue = S_FALSE;
            }
            pFileOpen->Release();
        }
        CoUninitialize();
    }
    return rtnValue;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            HRESULT t;
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_VERIFY_PASSPORT:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    int t;
                    int msgboxID;
                    t = VerifyPassport();
                    TotalLine.clear();
                    switch (t) 
                    {
                    case 0:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Passed",
                            L"Passport Verification",
                            MB_ICONASTERISK | MB_OK
                        );
                        break; //optional
                    case 1:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed First Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 2:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Second Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 3:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Third Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 4:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Optional Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 5:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Overall Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional

                     // you can have any number of case statements.
                    default: //Optional
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Error",
                            L"Passport Verification",
                            MB_ICONEXCLAMATION | MB_OK
                        );
                        break; //optional
                    }
                }
                break;
            case ID_VERIFY_TD1:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    int t;
                    int msgboxID;
                    t = VerifyTD1();
                    TotalLine.clear();
                    switch (t)
                    {
                    case 0:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Passed",
                            L"Passport Verification",
                            MB_ICONASTERISK | MB_OK
                        );
                        break; //optional
                    case 1:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed First Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 2:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Second Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 3:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Third Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 4:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Overall Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 10:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Optional Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                     // you can have any number of case statements.
                    default: //Optional
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Error",
                            L"Passport Verification",
                            MB_ICONEXCLAMATION | MB_OK
                        );
                        break; //optional
                    }
                }
                break;
            case ID_VERIFY_TD2:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    int t;
                    int msgboxID;
                    t = VerifyTD2();
                    TotalLine.clear();
                    switch (t)
                    {
                    case 0:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Passed",
                            L"Passport Verification",
                            MB_ICONASTERISK | MB_OK
                        );
                        break; //optional
                    case 1:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed First Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 2:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Second Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 3:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Third Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 4:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Overall Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 10:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Optional Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                     // you can have any number of case statements.
                    default: //Optional
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Error",
                            L"Passport Verification",
                            MB_ICONEXCLAMATION | MB_OK
                        );
                        break; //optional
                    }
                }
                break;
            case ID_VERIFY_VISAA:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    int t;
                    int msgboxID;
                    t = VerifyVisaA();
                    TotalLine.clear();
                    switch (t)
                    {
                    case 0:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Passed",
                            L"Passport Verification",
                            MB_ICONASTERISK | MB_OK
                        );
                        break; //optional
                    case 1:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed First Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 2:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Second Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 3:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Third Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 4:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Optional Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 5:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Overall Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional

                     // you can have any number of case statements.
                    default: //Optional
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Error",
                            L"Passport Verification",
                            MB_ICONEXCLAMATION | MB_OK
                        );
                        break; //optional
                    }
                }
                break;
            case ID_VERIFY_VISAB:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    int t;
                    int msgboxID;
                    t = VerifyVisaB();
                    TotalLine.clear();
                    switch (t)
                    {
                    case 0:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Passed",
                            L"Passport Verification",
                            MB_ICONASTERISK | MB_OK
                        );
                        break; //optional
                    case 1:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed First Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 2:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Second Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    case 3:
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Failed Third Check Digit",
                            L"Passport Verification",
                            MB_ICONERROR | MB_OK
                        );
                        break; //optional
                    default: //Optional
                        msgboxID = MessageBox
                        (
                            NULL,
                            L"Error",
                            L"Passport Verification",
                            MB_ICONEXCLAMATION | MB_OK
                        );
                        break; //optional
                    }
                }
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
