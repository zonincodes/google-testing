#include <data_structures/data_structures.h>
#include <iostream>
#include <vector>
#include <string>
const char* Person::getname(){
    return name;
}

int Person::getage(){
    return age;
}

template <typename T>
std::ostream &operator<<(std::ostream& s, std::vector<T> v){
    s << "Size: " << v.size() << "\nCapacity: " << v.capacity() << " Elements:\n";
    for(const auto& element: v)
        s << "\t" << element << "\n";
    return s;
}

void ostreamTest()
{
    const std::vector<std::string> characters{
        "Bobby Wyne",
        "Lawrence Waterhouse",
        "Gunter Bischoff",
        "Earl Comstock"
    };

    std::cout << characters << std::endl;

    const std::vector<bool> bits{ true, false, true, false};
    std::cout << std::boolalpha << bits << std::endl;
}
