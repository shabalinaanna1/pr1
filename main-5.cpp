/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <thread>
#include <ctime>

using namespace std;
const char alphabet1[] = "abcdefghijklmnopqrstuvwxyz";
const char alphabet2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char number[] = "0123456789";
const int N = 8;
const int pass_count = 3;
string password = "";

void Random(int i){ 
	char random;
	    if (i == 0){ 
		    random = alphabet1[rand() % 26];
		  //  cout << random << endl;
		}
		if (i == 1){ 
		    random = number[rand() % 10];
		  //  cout << random << endl;
		}
		if (i == 2){ 
		    random = alphabet2[rand() % 26];
		  //  cout << random << endl;
		}
		if (password.length() < N){
		    password = password + random;
		}
}

void create_password(){
    thread threads[3];
    while (password.length() < N){
        for (int i = 0; i < 3; i++){
            threads[i] =  thread(Random,i);
            threads[i].join();
        }
    }
    cout << "Password: " << password << endl;
}

int main() {
	srand(time(0));
	for (int k = 0; k < pass_count; k++){
	    create_password();
	}
	return 0;
}




