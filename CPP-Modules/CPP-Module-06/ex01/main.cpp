#include "Serializer.hpp"

int main()
{
    Data data;
    data.data_size = 42;
    data.data_name = "test";

    uintptr_t raw = Serializer::serialize(&data);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << result << std::endl;
    std::cout << "Pointers match: " << (&data == result ? "yes" : "no") << std::endl;
    std::cout << "data_name: " << result->data_name << std::endl;
    std::cout << "data_size: " << result->data_size << std::endl;

    return 0;
}