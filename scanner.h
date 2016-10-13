#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

class MyScanner {
    public:
        MyScanner(const string filepath){
            iRead.open(filepath, ifstream::in);

            assert(iRead);
        }

        ~MyScanner() {
            iRead.close();
        }

        int nextInt(){
            int n;
            iRead >> n;
            return n;
        }
    private:
        ifstream iRead;
};
