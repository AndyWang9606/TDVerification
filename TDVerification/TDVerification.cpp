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
#include <stdio.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
std::string TotalLine;
std::string CountryCode[] = { 
"ABW",
"AFG",
"AGO",
"AIA",
"ALA",
"ALB",
"AND",
"ARE",
"ARG",
"ARM",
"ASM",
"ATA",
"ATF",
"ATG",
"AUS",
"AUT",
"AZE",
"BDI",
"BEL",
"BEN",
"BES",
"BFA",
"BGD",
"BGR",
"BHR",
"BHS",
"BIH",
"BLM",
"BLR",
"BLZ",
"BMU",
"BOL",
"BRA",
"BRB",
"BRN",
"BTN",
"BVT",
"BWA",
"CAF",
"CAN",
"CCK",
"CHE",
"CHL",
"CHN",
"CIV",
"CMR",
"COD",
"COG",
"COK",
"COL",
"COM",
"CPV",
"CRI",
"CUB",
"CUW",
"CXR",
"CYM",
"CYP",
"CZE",
"D<<",
"DEU",
"DJI",
"DMA",
"DNK",
"DOM",
"DZA",
"ECU",
"EGY",
"ERI",
"ESH",
"ESP",
"EST",
"ETH",
"FIN",
"FJI",
"FLK",
"FRA",
"FRO",
"FSM",
"GAB",
"GBD",
"GBN",
"GBO",
"GBP",
"GBR",
"GBS",
"GEO",
"GGY",
"GHA",
"GIB",
"GIN",
"GLP",
"GMB",
"GNB",
"GNQ",
"GRC",
"GRD",
"GRL",
"GTM",
"GUF",
"GUM",
"GUY",
"HKG",
"HMD",
"HND",
"HRV",
"HTI",
"HUN",
"IDN",
"IMN",
"IND",
"IOT",
"IRL",
"IRN",
"IRQ",
"ISL",
"ISR",
"ITA",
"JAM",
"JEY",
"JOR",
"JPN",
"KAZ",
"KEN",
"KGZ",
"KHM",
"KIR",
"KNA",
"KOR",
"KWT",
"LAO",
"LBN",
"LBR",
"LBY",
"LCA",
"LIE",
"LKA",
"LSO",
"LTU",
"LUX",
"LVA",
"MAC",
"MAF",
"MAR",
"MCO",
"MDA",
"MDG",
"MDV",
"MEX",
"MHL",
"MKD",
"MLI",
"MLT",
"MMR",
"MNE",
"MNG",
"MNP",
"MOZ",
"MRT",
"MSR",
"MTQ",
"MUS",
"MWI",
"MYS",
"MYT",
"NAM",
"NCL",
"NER",
"NFK",
"NGA",
"NIC",
"NIU",
"NLD",
"NOR",
"NPL",
"NRU",
"NZL",
"OMN",
"PAK",
"PAN",
"PCN",
"PER",
"PHL",
"PLW",
"PNG",
"POL",
"PRI",
"PRK",
"PRT",
"PRY",
"PSE",
"PYF",
"QAT",
"REU",
"ROU",
"RUS",
"RWA",
"SAU",
"SDN",
"SEN",
"SGP",
"SGS",
"SHN",
"SJM",
"SLB",
"SLE",
"SLV",
"SMR",
"SOM",
"SPM",
"SRB",
"SSD",
"STP",
"SUR",
"SVK",
"SVN",
"SWE",
"SWZ",
"SXM",
"SYC",
"SYR",
"TCA",
"TCD",
"TGO",
"THA",
"TJK",
"TKL",
"TKM",
"TLS",
"TON",
"TTO",
"TUN",
"TUR",
"TUV",
"TWN",
"TZA",
"UGA",
"UKR",
"UMI",
"UNA",
"UNK",
"UNO",
"URY",
"USA",
"UZB",
"VAT",
"VCT",
"VEN",
"VGB",
"VIR",
"VNM",
"VUT",
"WLF",
"WSM",
"XCC",
"XOM",
"XXA",
"XXB",
"XXC",
"XXX",
"YEM",
"ZAF",
"ZMB",
"ZWE"
};

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
bool DocTypeCheck(int TDType)
{
    unsigned char docType;
    docType = TotalLine[0];
    switch (TDType)
    {
    case 1: // Passport
        if (docType != 'P')
        {
            return false;
        }
        break;
    case 2: // VisaA & VisaB
        if (docType != 'V')
        {
            return false;
        }
        break;
    case 3: // TD1 & TD2
        if (docType != 'A' && docType != 'C' && docType != 'I')
        {
            return false;
        }
        if (docType == 'I' && TotalLine[1] == 'C')
        {
            return false;
        }
        if (TotalLine[1] == 'V')
        {
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}
int binarySearch(int start, int end, std::string code) 
{  
    int mid = (start + end) / 2;
    
    while (start <= end)
    {
        if (CountryCode[mid] == code)
        {
            return mid;
        }
        else if (CountryCode[mid] > code)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
// Add in code-x parameter for multiple incorrect country code
int CountryCodeCheck(int TDType, int code)
{
    std::string code1, code2;
    switch (TDType)
    {
    case 1:   //Passport
        code1 = TotalLine.substr(2, 3);
        code2 = TotalLine.substr(55, 3);
        if(binarySearch(0, 248, code1) == -1 && code == 1)
        {
            return 1;
        }
        if (binarySearch(0, 248, code2) == -1 && code == 2)
        {
            return 2;
        }
        break;
    case 2:   //VisaA
        code1 = TotalLine.substr(2, 3);
        code2 = TotalLine.substr(55, 3);
        if (binarySearch(0, 248, code1) == -1 && code == 1)
        {
            return 1;
        }
        if (binarySearch(0, 248, code2) == -1 && code == 2)
        {
            return 2;
        }
        break;
    case 3:   //VisaB
        code1 = TotalLine.substr(2, 3);
        code2 = TotalLine.substr(47, 3);
        if (binarySearch(0, 248, code1) == -1 && code == 1)
        {
            return 1;
        }
        if (binarySearch(0, 248, code2) == -1 && code == 2)
        {
            return 2;
        }
        break;
    case 4:   //TD1
        code1 = TotalLine.substr(2, 3);
        code2 = TotalLine.substr(46, 3);
        if (binarySearch(0, 248, code1) == -1 && code == 1)
        {
            return 1;
        }
        if (binarySearch(0, 248, code2) == -1 && code == 2)
        {
            return 2;
        }
        break;
    case 5:   //TD2
        code1 = TotalLine.substr(2, 3);
        code2 = TotalLine.substr(47, 3);
        if (binarySearch(0, 248, code1) == -1 && code == 1)
        {
            return 1;
        }
        if (binarySearch(0, 248, code2) == -1 && code == 2)
        {
            return 2;
        }
        break;
    default:
        break;
    }
    return 0;
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
 * Author: Andy Wang   Nov. 21, 2021
 *
 * Return: 
 * Array that stores errors based on index:
 *         0 - Succeed,
 *         1 - First Check Digit Failed,
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed,
 *         4 - Overall Check Digit Failed,
 *         5 - Invalid First Country Code,
 *         6 - Invalid Second Country Code,
 *         7 - Invalid Document Type
 *         10 - Optional Check Digit Failed,
 *********************************/
int* VerifyPassport()
{
    static int errors[8];
    std::fill(errors, errors + _countof(errors), 0);
    int data[200];
    ConvertCharToInt(45, 44, data);
    if (DocTypeCheck(1) == false)
    {
        errors[6] = 7;
    }
    if (CountryCodeCheck(1, 1) == 1)
    {
        errors[4] = 5;
    }
    if (CountryCodeCheck(1, 2) == 2)
    {
        errors[5] = 6;
    }
    if (!CheckDigit(45, 10, data))
    {
        errors[0] = 1;
    }
    if (!CheckDigit(58, 7, data))
    {
        errors[1] = 2;
    }
    if (!CheckDigit(66, 7, data))
    {
        errors[2] = 3;
    }
    if (!CheckDigit(73, 15, data))
    {
        errors[7] = 10;
    }
    if (!TotalCheckDigitPassport(data))
    {
        errors[3] = 4;
    }
    return errors;
}

/* Description: Checks if Visa Type A is valid
 *
 * Author: Andy Wang   Nov. 21, 2021
 *
 * Return: 
 * Array that stores errors based on index:
 *         0 - succeed,
 *         1 - First Check Digit Failed,
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed,
 *         4 - Overall Check Digit Failed
 *         5 - Invalid First Country Code
 *         6 - Invalid Second Country Code
 *         7 - Invalid Document Type
 *********************************/
int* VerifyVisaA() {
    static int errors[8];
    std::fill(errors, errors + _countof(errors), 0);
    int data[200];
    ConvertCharToInt(45, 44, data);
    if (DocTypeCheck(2) == false)
    {
        errors[6] = 7;
    }
    if (CountryCodeCheck(2, 1) == 1)
    {
        errors[4] = 5;
    }
    if (CountryCodeCheck(2, 2) == 2)
    {
        errors[5] = 6;
    }
    if (!CheckDigit(45, 10, data))
    {
        errors[0] = 1;
    }
    if (!CheckDigit(58, 7, data))
    {
        errors[1] = 2;
    }
    if (!CheckDigit(66, 7, data))
    {
        errors[2] = 3;
    }
    if (!TotalCheckDigitVisaA(data))
    {
        errors[3] = 4;
    }
    return errors;
}

/* Description: Checks if passport is valid
 *
 * Author: Andy Wang   Nov. 21, 2021
 *
 * Return: 
 * Array that stores errors based on index:
 *         0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *         4 - Invalid First Country Code,
 *         5 - Invalid Second Country Code
 *         6 - Invalid Document Type
 *********************************/
int* VerifyVisaB() {
    static int errors[6];
    std::fill(errors, errors + _countof(errors), 0);
    int data[200];
    ConvertCharToInt(37, 36, data);
    if (DocTypeCheck(2) == false)
    {
        errors[5] = 6;
    }
    if (CountryCodeCheck(3, 1) == 1)
    {
        errors[3] = 4;
    }
    if (CountryCodeCheck(3, 2) == 2)
    {
        errors[4] = 5;
    }
    if (!CheckDigit(37, 10, data))
    {
        errors[0] = 1;
    }
    if (!CheckDigit(50, 7, data))
    {
        errors[1] = 2;
    }
    if (!CheckDigit(58, 7, data))
    {
        errors[2] = 3;
    }
    return errors;
}

/* Description: Checks if Travel Document Ver. 1 is valid
 *
 * Author: Andy Wang   Nov. 21, 2021
 *
 * Return: 
 * Array that stores errors based on index:
 *         0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *         4 - Overall Check Digit Failed,
 *         5 - Invalid First Country Code,
 *         6 - Invalid Second Country Code,
 *         7 - Invalid Document Type
 *********************************/
int* VerifyTD1() {
    static int errors[8];
    std::fill(errors, errors + _countof(errors), 0);
    int data[200];
    int i;
    int index = 0;
    ConvertCharToInt(0, 61, data);
    if (DocTypeCheck(3) == false)
    {
        errors[6] = 7;
    }
    if (CountryCodeCheck(4, 1) == 1)
    {
        errors[4] = 5;
    }
    if (CountryCodeCheck(4, 2) == 2)
    {
        errors[5] = 6;
    }
    if (TotalLine[14] != '<')
    {
        if (!CheckDigit(5, 10, data))
        {
            errors[0] = 1;
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
            errors[0] = 1;
        }
    }
    if (!CheckDigit(31, 7, data))
    {
        errors[1] = 2;
    }
    if (!CheckDigit(39, 7, data))
    {
        errors[2] = 3;
    }
    if (!TotalCheckDigitTD1(data))
    {
        errors[3] = 4;
    }
    return errors;

}

/* Description: Checks if Travel Document Ver. 2 is valid
 *
 * Author: Andy Wang   Nov. 21, 2021
 *
 * Return: 
 * Array that stores errors based on index:
 *         0 - succeed, 
 *         1 - First Check Digit Failed, 
 *         2 - Second Check Digit Failed,
 *         3 - Third Check Digit Failed, 
 *         4 - Overall Check Digit Failed,
 *         5 - Invalid First Country Code,
 *         6 - Invalid Second Country Code,
 *         7 - Invalid Docuent Type,
 *********************************/
int* VerifyTD2()
{
    static int errors[8];
    std::fill(errors, errors + _countof(errors), 0);
    int data[200];
    int i;
    int index;
    ConvertCharToInt(37, 36, data);
    if (DocTypeCheck(3) == false)
    {
        errors[6] = 7;
    }
    if (CountryCodeCheck(5, 1) == 1)
    {
        errors[4] = 5;
    }
    if (CountryCodeCheck(5, 2) == 2)
    {
        errors[5] = 6;
    }
    if (!CheckDigit(37, 10, data))
    {
        errors[0] = 1;
    }
    if (!CheckDigit(50, 7, data))
    {
        errors[1] = 2;
    }
    if (!CheckDigit(58, 7, data))
    {
        errors[2] = 3;
    }
    if (!TotalCheckDigitTD2(data))
    {
        errors[3] = 4;
    }
    return errors;
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

/* Description: Creates modular message boxes based on
 * errors and document type
 *
 * Author: Andy Wang   April 7, 2023
 *
 * param [int] errors[] - array storing the errors present
 *        int  docType - represents the document type
 *********************************************************/
void CreateMessageBox(int errors[], int docType)
{
    std::wstring documentTypes[] = {
    L"Passport",
    L"Visa A",
    L"Visa B",
    L"TD1",
    L"TD2"
    };
    std::wstring errorMessages[] = {
    L" Failed First Check Digit",
    L" Failed Second Check Digit",
    L" Failed Third Check Digit",
    L" Failed Overall Check Digit",
    L" Has Invalid First Country Code",
    L" Has Invalid Second Country Code",
    L"Invalid Document Type",
    L" Failed Optional Check Digit"
    };
    std::wstring finalErrorMessage;
    int counter = 0;
    int msgboxID;
    int i;
    int mm = 0;
    int errorArrContent;

    if (docType == 2) {
        for (i = 0; i < 6; i++)
        {
            errorArrContent = *(errors + i);
            mm = i;
            mm++;

            if (errorArrContent == 6) {
                finalErrorMessage = errorMessages[6];
                break;
            }
            if (errorArrContent != 0) {
                counter++;
                if (counter == 1) {
                    if (errorArrContent == 4 || errorArrContent == 5) {
                        finalErrorMessage = documentTypes[docType] + (errorMessages[i + 1]);
                    }
                    else {
                        finalErrorMessage = documentTypes[docType] + (errorMessages[i]);
                    }
                }
                else {
                    if (errorArrContent == 4 || errorArrContent == 5) {
                        finalErrorMessage = finalErrorMessage.append(L"\n" + documentTypes[docType] + (errorMessages[i + 1]));
                    }
                    else {
                        finalErrorMessage = finalErrorMessage.append(L"\n" + documentTypes[docType] + (errorMessages[i]));;
                    }
                }
            }

        }
        if (counter == 0) {
            msgboxID = MessageBox
            (
                NULL,
                documentTypes[docType].append(L" Passed").c_str(),
                L"Passport Verification",
                MB_ICONASTERISK | MB_OK
            );
            return;
        }
    }
    else {
        
        for (i = 0; i < 8; i++)
        {
            errorArrContent = *(errors + i);
            mm = i;
            mm++;

            if (errorArrContent == 7) {
                finalErrorMessage = errorMessages[6];
                break;
            }
            if (errorArrContent != 0) {
                counter++;
                if (counter == 1) {
                    finalErrorMessage = documentTypes[docType] + (errorMessages[i]);
                }
                else {
                    finalErrorMessage = finalErrorMessage.append(L"\n" + documentTypes[docType] + (errorMessages[i]));
                }
            }

        }
        if (counter == 0) {
            msgboxID = MessageBox
            (
                NULL,
                documentTypes[docType].append(L" Passed").c_str(),
                L"Passport Verification",
                MB_ICONASTERISK | MB_OK
            );
            return;
        }
    }
    msgboxID = MessageBox
    (
        NULL,
        finalErrorMessage.c_str(),
        L"Passport Verification",
        MB_ICONERROR | MB_OK
    );
}
void PassportCheck()
{
    int* t;
    int counter = 0;
    int msgboxID;
    t = VerifyPassport();
    TotalLine.clear();
    CreateMessageBox(t, 0);
}
void VisaACheck() {
    int* t;
    int msgboxID;
    int counter = 0;
    t = VerifyVisaA();
    TotalLine.clear();
    CreateMessageBox(t, 1);
}
void VisaBCheck() {
    int* t;
    int msgboxID;
    int counter = 0;
    t = VerifyVisaB();
    TotalLine.clear();
    CreateMessageBox(t, 2);
}
void TD1Check()
{
    int* t;
    int msgboxID;
    int counter = 0;
    t = VerifyTD1();
    TotalLine.clear();
    CreateMessageBox(t, 3);
}
void TD2Check()
{
    int* t;
    int msgboxID;
    int counter = 0;
    t = VerifyTD2();
    TotalLine.clear();
    CreateMessageBox(t, 4);
}
void ErrorDoc()
{
    int msgboxID;
    msgboxID = MessageBox
    (
        NULL,
        L"Document Type Nonexistent",
        L"Passport Verification",
        MB_ICONERROR | MB_OK
    );
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
            
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_HELP_README:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About);
                break;
            case ID_VERIFY_AUTO:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    switch (TotalLine[0])
                    {
                    case 'P':
                        PassportCheck();
                        break;
                    case 'V':
                        if (TotalLine.length() == 90)
                        {
                            VisaACheck();
                        }
                        if (TotalLine.length() == 74)
                        {
                            VisaBCheck();
                        }
                        break;
                    case 'A':
                    case 'C':
                    case 'I':
                        if (TotalLine.length() == 93)
                        {
                            TD1Check();
                            break;
                        }
                        if (TotalLine.size() == 74)
                        {
                            TD2Check();
                            break;
                        }
                        break;
                    default:
                        ErrorDoc();
                        break;
                    }
                }
                break;
            case ID_VERIFY_PASSPORT:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    PassportCheck();
                }
                break;
            case ID_VERIFY_TD1:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    TD1Check();
                }
                break;
            case ID_VERIFY_TD2:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    TD2Check();
                }
                break;
            case ID_VERIFY_VISAA:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    VisaACheck();
                }
                break;
            case ID_VERIFY_VISAB:
                t = BasicFileOpen(hWnd);
                if (t == S_OK)
                {
                    VisaBCheck();
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
