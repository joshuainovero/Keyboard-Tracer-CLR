#include <iostream>
#include <fstream>
#include <Windows.h>
#include <thread>

using namespace std::literals::chrono_literals;

int main() {

	while (true) {
		std::this_thread::sleep_for(10ms);
		std::ifstream ReadLogs("Logs");
			std::string Log;
			ReadLogs >> Log;
			std::cout << "Key pressed : " << Log << "\n";
		ReadLogs.close();
		system("cls");
	}
	

	return EXIT_SUCCESS;
}