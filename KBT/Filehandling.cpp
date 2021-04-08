#include "Filehandling.h"


std::string FILEHANDLE::getTotalStrokes() {
	std::string TotalKS;
	std::ifstream ReadTotalKS("Logs");
		ReadTotalKS >> TotalKS;
	ReadTotalKS.close();
	return TotalKS;
}



std::string FILEHANDLE::getCurrStrokes() {
	std::string CurrStrokes;
	std::ifstream ReadCurrStrokes("CurrentLogs");
		ReadCurrStrokes >> CurrStrokes;
	ReadCurrStrokes.close();
	return CurrStrokes;
}
void FILEHANDLE::resetCurrStrokes() {
	std::ofstream ResetCurrStrokes("CurrentLogs");
		ResetCurrStrokes << "0";
	ResetCurrStrokes.close();
}


std::string FILEHANDLE::getLoggedDate() {
	std::string LoggedDate;
	std::ifstream ReadLoggedDate("LoggedDate");
		ReadLoggedDate >> LoggedDate;
	ReadLoggedDate.close();
	return LoggedDate;
}
void FILEHANDLE::updateDateFiles(std::string newDate) {
	std::ofstream UpdateLoggedDate("LoggedDate");
		UpdateLoggedDate << newDate;
	UpdateLoggedDate.close();
}



bool FILEHANDLE::CheckFileExist(const char* Filename) {
	std::ifstream file(Filename);
	return !file.fail();
}