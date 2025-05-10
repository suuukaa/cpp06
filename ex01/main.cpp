#include "Serializer.hpp"

int main() {
    Data original = {"Soukaina", 1337};
    
    uintptr_t raw = Serializer::serialize(&original);
    Data* copy = Serializer::deserialize(raw);

    std::cout << "Original: " << original.digit << ", " << original.string << std::endl;
    std::cout << "Copy:     " << copy->digit << ", " << copy->string << std::endl;
}