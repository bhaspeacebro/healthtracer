#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("health_log.txt");

    if (!inFile.is_open()) {
        cout << "❌ Unable to open health_log.txt\n";
        return 1;
    }

    string line;
    int count = 0;
    float totalSleep = 0, totalSteps = 0, totalWater = 0;

    while (getline(inFile, line)) {
        if (line.find("Sleep (hrs):") != string::npos) {
            float sleep = stof(line.substr(line.find(":") + 2));
            totalSleep += sleep;
        }
        else if (line.find("Steps:") != string::npos) {
            float steps = stof(line.substr(line.find(":") + 2));
            totalSteps += steps;
        }
        else if (line.find("Water (L):") != string::npos) {
            float water = stof(line.substr(line.find(":") + 2));
            totalWater += water;
            count++;  // Only count full entries when water line appears
        }
    }

    inFile.close();

    if (count == 0) {
        cout << "📝 No valid entries found.\n";
        return 0;
    }

    cout << "📊 Health Analytics Summary:\n";
    cout << "----------------------------\n";
    cout << "Total Entries: " << count << "\n";
    cout << "Average Sleep: " << totalSleep / count << " hrs\n";
    cout << "Total Steps: " << totalSteps << "\n";
    cout << "Total Water Intake: " << totalWater << " L\n";

    return 0;
}
