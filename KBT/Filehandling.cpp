#include "Filehandling.h"
#include <vector>

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

	std::ofstream UpdateDatesLogged("DatesLogged", std::ios_base::app);
		UpdateDatesLogged << newDate << std::endl;
	UpdateDatesLogged.close();
}

std::string FILEHANDLE::averageRecordedStrokes() {
	std::string strValue;
	uint32_t total{ 0 }, intValue{ 0 };
	uint32_t averageStrokes;
	std::ifstream ReadRecordedStrokes("RecordedStrokes");
		while (std::getline(ReadRecordedStrokes, strValue)) {
			intValue += std::stoi(strValue);
			total++;
		}
	averageStrokes = intValue / total;
	return std::to_string(averageStrokes);
}

void FILEHANDLE::updateRecordedStrokes() {
	if (FILEHANDLE::getCurrStrokes() != "0") {
		std::ofstream UpdateRecordedStrokes("RecordedStrokes", std::ios_base::app);
			UpdateRecordedStrokes << getCurrStrokes() << std::endl;
		UpdateRecordedStrokes.close();
	}
}

std::string FILEHANDLE::getHighestStrokes() {
	std::vector<int> allStrokes{};
	std::string strVal;
	std::ifstream ReadRecordedStrokes("RecordedStrokes");
		while (std::getline(ReadRecordedStrokes, strVal))
			allStrokes.push_back(std::stoi(strVal));
	ReadRecordedStrokes.close();
	
	int highestStroke = allStrokes.at(0);
	for (size_t i = 0; i < allStrokes.size(); ++i) {
		if (allStrokes.at(i) > highestStroke)
			highestStroke = allStrokes.at(i);
	}
	
	return std::to_string(highestStroke);
	
}
std::string FILEHANDLE::getLowestStrokes() {
	std::vector<int> allStrokes{};
	std::string strVal;
	std::ifstream ReadRecordedStrokes("RecordedStrokes");
		while (std::getline(ReadRecordedStrokes, strVal))
			allStrokes.push_back(std::stoi(strVal));
	ReadRecordedStrokes.close();

	int lowestStroke = allStrokes.at(0);
	for (size_t i = 0; i < allStrokes.size(); ++i) {
		if (allStrokes.at(i) < lowestStroke)
			lowestStroke = allStrokes.at(i);
	}

	return std::to_string(lowestStroke);
}


bool FILEHANDLE::CheckFileExist(const char* Filename) {
	std::ifstream file(Filename);
	return !file.fail();
}