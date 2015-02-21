#include <bits/stl_map.h>

class Session
{
public:
    Session() {
    }

    bool isLoggedIn_() const {
        return loggedIn_;
    }

    void setLoggedIn_(bool loggedIn_) {
        Session::loggedIn_ = loggedIn_;
    }

    string &getName_() const {
        return name_;
    }

    void setName_(string &name_) {
        Session::name_ = name_;
    }

    string &getType_() const {
        return type_;
    }

    void setType_(string &type_) {
        Session::type_ = type_;
    }

private:
    bool loggedIn_ = false;
    string name_;
    string type_;
    std::map<int, Data()> transActions_;
};
