/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <random>

using namespace std;
const char alphabet1[] = "abcdefghijklmnopqrstuvwxyz";
const char alphabet2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char number[] = "0123456789";
const int N = 8;
const int pass_count = 3;
string password = "";

// https://stackoverflow.com/questions/21237905/how-do-i-generate-thread-safe-uniform-random-numbers
int intRand(const int & min, const int & max) {
    static thread_local mt19937* generator = nullptr;
    if (!generator) generator = new mt19937(clock() + this_thread::get_id().hash());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(*generator);
}

void Random(int i){ 
	char random;
	    if (i == 0){ 
		    random = alphabet1[my_rand(0,25)];
		  //  cout << random << endl;
		}
		if (i == 1){ 
		    random = number[my_rand(0,9)];
		  //  cout << random << endl;
		}
		if (i == 2){ 
		    random = alphabet2[my_rand(0,25)];
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




