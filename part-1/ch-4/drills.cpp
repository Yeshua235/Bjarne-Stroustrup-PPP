#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

int main() {
    try {
        std::cout << "Success! 1-4\n";

        std::string res = "7";
        int int_res = std::stoi(res); // modification:  Added code (stoi - string-to-int)
        std::vector<int> v0(10);
        v0[5] = int_res;
        std::cout << "Success! 5\n";

        std::vector<int> v1(10); v1[5] = 7;
        if (v1[5] == 7) std::cout << "Success! 6\n";

        if (true) std::cout << "Success! 7\n"; else std::cout << "Fail!\n";

        bool c0 = false; if (!c0) std::cout << "Success! 8\n"; else std::cout << "Fail! 8\n";

        std::string s = "ape"; bool c1 = "fool" < s; if (!c1) std::cout << "Success! 9\n";

        if (!(s=="fool")) std::cout << "Success! 10\n";

        if (!(s=="fool")) std::cout << "Success! 11\n";

        if (s<"fool") std::cout << "Success! 12\n";

        std::vector<char> v2(5); for (std::vector<char>::size_type i = 0; i<v2.size(); ++i); std::cout << "Success! 13\n";

        std::vector<char> v3(5); for (std::vector<char>::size_type i = 0; i<=v3.size(); ++i); std::cout << "Success! 14\n";

        std::string s1 = "Success! 15"; for (int i = 0; i<11; ++i) std::cout << s1[i]; std::cout << std::endl;

        if (true) std::cout << "Success! 16\n"; else std::cout << "Fail!\n";

        int x = 2000; char c = x; if (!(c==2000)) std::cout << "Success! 17\n";

        std::string s2 = "Success! 18\n"; for (int i = 0; i<13; ++i) std::cout << s2[i];

        std::vector<int> v4(5); for (std::vector<int>::size_type i = 0; i<=v4.size(); ++i); std::cout << "Success! 19\n";

        int i = 0; int j = 9; while (i<10) ++i; if (j<i) std::cout << "Success! 20\n";

        //int x1 = 2; double d = 5/(x1-2); if (d==2*x1+0.5) std::cout << "Success! 21\n"; // raises "Floating point exception" an hardware level signal from the OS and a c++ exception object. Hence it can't be caught using any of the catch expressions below


        std::string s3 = "Success! 22\n"; for (int i = 0; i<13; ++i) std::cout << s3[i];

        int ii = 0; int ji = 0; while (ii<10) ++ii; if (ji<ii) std::cout << "Success! 23\n";

        int xi = 4; double di = 5/(xi-2); if (!(di==2*xi+0.5)) std::cout << "Success! 24\n";

        std::cout << "Success! 25." << std::endl;

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << '\n';
        return 1;
        
    } catch (...) {
        std::cerr << "Oops: Unknown exception!\n";
        return 2;
    }

}
