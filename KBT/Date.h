#ifndef DATE
#define DATE

class Date {
private:
    int GetDay, GetMonth, GetYear;
public:
    std::string FullDateNow{};
    void SetDate() {
        time_t t = time(NULL);
        tm* tPtr = localtime(&t);
        GetDay = tPtr->tm_mday;
        GetMonth = (tPtr->tm_mon) + 1;
        GetYear = (tPtr->tm_year) + 1900;
        FullDateNow = std::to_string(GetDay) + '/' + std::to_string(GetMonth) + '/' + std::to_string(GetYear);
    }
};

#endif // DATE