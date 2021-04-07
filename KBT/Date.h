#ifndef DATE
#define DATE

struct Date {

    static int GetDay, GetMonth, GetYear;
    static std::string FullDateNow;
    static void SetDate();
};

void Date::SetDate() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    Date::GetDay = tPtr->tm_mday;
    Date::GetMonth = (tPtr->tm_mon) + 1;
    Date::GetYear = (tPtr->tm_year) + 1900;
    Date::FullDateNow = std::to_string(GetDay) + '/' + std::to_string(GetMonth) + '/' + std::to_string(GetYear);
}

int Date::GetDay = 0;
int Date::GetMonth = 0;
int Date::GetYear = 0;
std::string Date::FullDateNow = "None";


#endif // DATE