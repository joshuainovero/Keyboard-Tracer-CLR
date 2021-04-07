#ifndef FILEHANDLING
#define FILEHANDLING

#include <string>
#include <fstream>

struct FILEHANDLE {
	static std::string getTotalStrokes();
	static std::string getCurrStrokes();
	static bool CheckFileExist(const char* Filename);
};





#endif // FILEHANDLING