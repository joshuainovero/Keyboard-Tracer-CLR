#include "Filehandling.h"


std::string FILEHANDLE::getTotalStrokes() {
	std::string TotalKS;
	std::ifstream ReadTotalKS("Strokes");
		ReadTotalKS >> TotalKS;
	ReadTotalKS.close();
	return TotalKS;
}

std::string FILEHANDLE::getCurrStrokes() {
	std::string CurrStrokes;
	std::ifstream ReadCurrStrokes("CurrentStrokes");
		ReadCurrStrokes >> CurrStrokes;
	ReadCurrStrokes.close();
	return CurrStrokes;
}

bool FILEHANDLE::CheckFileExist(const char* Filename) {
	std::ifstream file(Filename);
	return !file.fail();
}