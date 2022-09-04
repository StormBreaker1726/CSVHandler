/**
 * @file test1.cpp
 * @author João Víctor Costa de Oliveira (joaovictoroliveira1452@gmail.com)
 * @brief A simple test for the library
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../CSVHandler/CSV.hpp"
#include <iostream>
#include <vector>
#include <string>

bool write()
{
    CSVWriter csv_test_writer("csv_test_writer.csv", 3, true);

    std::vector<std::string> row;

    row.push_back("i");
    row.push_back("b");
    row.push_back("b+i");

    csv_test_writer.write_in_file(row);

    int b = 1;


    for (size_t i = 0; i < 5; i++)
    {
        row.clear();
        row.push_back(std::to_string(i));
        row.push_back(std::to_string(b));
        row.push_back(std::to_string(i+b));
        csv_test_writer.write_in_file(row);    
    }

    csv_test_writer.close();
    return true;
}

bool read()
{
    CSVReader csv_test_reader("csv_test_writer.csv", 3);

    std::vector<std::vector<std::string>> reader_return = csv_test_reader.read_from_file();

    std::cout<<"\n\nContent:"<<std::endl;
    for (size_t i = 0; i < reader_return.size(); i++)
    {
        for (size_t j = 0; j < reader_return.at(i).size(); j++)
        {
            std::cout<<reader_return.at(i).at(j)<<", ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n\n\n"<<std::endl;

    return true;
}

int main()
{
    std::cout<<"\n\nWrite: "<<std::boolalpha<<write()<<"\n\n"<<std::endl;

    std::cout<<"\n\n"<<std::endl;

    read();
}
