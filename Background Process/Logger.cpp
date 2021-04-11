#include <Windows.h>
#include <fstream>
#include <thread>

using namespace std::literals::chrono_literals;

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    while (true) {
        std::this_thread::sleep_for(10ms);
        for (int KEY = 8; KEY <= 190; KEY++) {
            if (GetAsyncKeyState(KEY) == -32767) {
                //For total strokes
                uint32_t strokes;
                std::ifstream ReadStrokes("Logs");
                    ReadStrokes >> strokes;
                    std::ofstream UpdateStrokes("Logs");
                        strokes++;
                        UpdateStrokes << strokes;
                    UpdateStrokes.close();
                ReadStrokes.close();

                //For current strokes
                uint32_t currentStrokes;
                std::ifstream ReadCurrStrokes("CurrentLogs");
                    ReadCurrStrokes >> currentStrokes;
                    std::ofstream UpdateCurrStrokes("CurrentLogs");
                        currentStrokes++;
                        UpdateCurrStrokes << currentStrokes;
                    UpdateCurrStrokes.close();
                ReadCurrStrokes.close();
                
            }
        }
    }
    //system("pause");
    return EXIT_SUCCESS;
}
