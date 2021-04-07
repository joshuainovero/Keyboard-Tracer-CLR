#ifndef FILEHANDLING
#define FILEHANDLING

#include <string>
#include <fstream>

struct FILEHANDLE {
	static std::string getTotalStrokes();

	static std::string getCurrStrokes();
	static void resetCurrStrokes();

	static std::string getLoggedDate();
	static void updateDateFiles(std::string newDate);
	
	static bool CheckFileExist(const char* Filename);
};





#endif // FILEHANDLING