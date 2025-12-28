#include <iostream>
#include <fstream>

std::string search_and_replace(std::string buffer, std::string s1, std::string s2)
{
    std::string newbuffer;
    size_t start_p = 0;
    size_t found_p = buffer.find(s1);

    while (found_p != std::string::npos)
    {
        newbuffer += buffer.substr(start_p, found_p - start_p);
        newbuffer += s2;
        start_p = found_p + s1.length();
        found_p = buffer.find(s1, start_p);
    }
    newbuffer += buffer.substr(start_p);

    return newbuffer;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "You must provide 3 arguments : filename & s1 & s2" << std::endl;
        return -1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cout << "Argument cant be empty" << std::endl;
        return -1;
    }
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Failed to open the file" << std::endl;
        return -1;
    }
    std::string newfilename = filename + ".replace";
    std::ofstream newfile(newfilename.c_str());
    if (!newfile.is_open())
    {
        std::cout << "Failed to open the new file" << std::endl;
        file.close();
        return -1;
    }

    std::string buffer;
    char c;
    while (file.get(c))
        buffer += c;
    if (buffer.empty())
    {
        std::cout << filename << " is empty!" << std::endl;
        return -1;
    }
    std::string newcontent = search_and_replace(buffer, s1, s2);
    newfile << newcontent;
    file.close();
    newfile.close();
    return 0;
}