#include "../include/data.h"

Data::Data() {
}

void Data::set_file_name(string file_name) {
    file_name_ = file_name;
}

int Data::OpenFile() {
    try {
        data_file_ = new fstream(file_name_);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    bool open = data_file_->is_open();
    return open;
}

int Data::CloseFile() {
    data_file_->close();
    return 0;
}

int Data::ReadData() {
    if (OpenFile()) {
        std::string line;
        while (getline(*data_file_, line)) {
            try
            {
                data_.push_back(line);
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
                this->CloseFile();
                return -1;
            }
        }
    } else {
        return -2;
    }
    this->CloseFile();
    return 0;
}

int Data::WriteData() {
    if (this->OpenFile())
    {
        list<string>::iterator data_ptr = data().begin();
        while (data_ptr != this->data().end())
        {
            try
            {
                *data_file_ << *(data_ptr) << "/n";
            } catch  (exception &e)
            {
                cout << e.what() << endl;
                this->CloseFile();
                return -1;
            }
        }
    this->CloseFile();
    }
    return -1;
}

void Data::set_data(std::list<std::string> data) {
    this->data_ = data;
}

std::list<std::string> Data::data() {
    return this->data_;
}
