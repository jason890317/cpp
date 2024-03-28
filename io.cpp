#include <iostream>
#include <iterator>
#include<vector>
int main() {
    std::istream_iterator<char> int_iter(std::cin), eof;
    std::vector<char> a;
    // Copy all characters from cin to cout
    std::copy(int_iter, eof, back_inserter(a));
    
    for(auto i:a)
    {
        std::cout<<i;
    }
    std::cout<<a.size();
    return 0;
}
