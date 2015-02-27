#ifndef XSTREAM_DATA_READER_H
#define XSTREAM_DATA_READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;

class Data
{
public:

    Data();

    void set_file_name(string file_name);

    int ReadData();

    int WriteData();

    void set_data(std::list<std::string> data);

    std::list<std::string> data();

//    std::list<std::string>::iterator data_ptr();
    std::list<std::string> data_;


private:
    // save file_name and assign a
    // fstream variable.
    std::string file_name_;
    std::fstream *data_file_;

    // build data representation
//    std::list<std::string> data_;

    // Set open and
    // close file methods to private
    int OpenFile();

    int CloseFile();
};

#endif // XSTREAM_DATA_READER_H