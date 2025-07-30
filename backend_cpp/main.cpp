#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// Function declarations
void collectHealthData();
void viewHealthLog();
void analyzeHealthData();

void showMenu() {
    cout << "\n🩺 Bhaskar's Personal Health Tracker 🩺\n";
    cout << "=======================================\n";
    cout << "1. 📝 Enter new health data\n";
    cout << "2. 📖 View health log\n";
    cout << "3. 📊 Analyze health trends\n";
    cout << "4. ❌ Exit\n";
    cout << "---------------------------------------\n";
    cout << "👉 Choose an option (1-4): ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        cout << "\n";

        switch (choice) {
            case 1:
                collectHealthData();
                break;
            case 2:
                viewHealthLog();
                break;
            case 3:
                analyzeHealthData();
                break;
            case 4:
                cout << "👋 Thank you for using Bhaskar's Tracker. Stay healthy and hydrated!\n";
                break;
            default:
                cout << "⚠️ Invalid option. Please enter a number between 1 and 4.\n";
        }

        cout << "\n---------------------------------------\n";

    } while (choice != 4);

    return 0;
}

// 📥 Function: Collect New Health Data
void collectHealthData() {
    ofstream file("health_log.txt", ios::app);
    if (!file) {
        cout << "❌ Error opening file.\n";
        return;
    }

    string date;
    float weight, height;
    int heartRate, steps;

    cout << "📅 Enter today's date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "⚖️ Enter weight (kg): ";
    cin >> weight;
    cout << "📏 Enter height (cm): ";
    cin >> height;
    cout << "❤️ Enter heart rate (bpm): ";
    cin >> heartRate;
    cout << "👟 Enter step count: ";
    cin >> steps;
    cin.ignore(); // flush newline

    file << date << "," << weight << "," << height << "," << heartRate << "," << steps << "\n";
    file.close();
    cout << "✅ Data saved successfully.\n";
}

// 📚 Function: View Health Log
void viewHealthLog() {
    ifstream file("health_log.txt");
    if (!file) {
        cout << "📭 No data found.\n";
        return;
    }

    string line;
    cout << "🧾 Health Log:\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

// 📈 Function: Analyze Health Data (basic avg heart rate)
void analyzeHealthData() {
    ifstream file("health_log.txt");
    if (!file) {
        cout << "📭 No data found to analyze.\n";
        return;
    }

    string line;
    int totalHeartRate = 0, count = 0;
    while (getline(file, line)) {
        size_t pos1 = line.find_last_of(','); // steps
        size_t pos2 = line.find_last_of(',', pos1 - 1); // heart rate
        string hrStr = line.substr(pos2 + 1, pos1 - pos2 - 1);
        totalHeartRate += stoi(hrStr);
        count++;
    }
    file.close();

    if (count > 0) {
        cout << "📊 Average Heart Rate: " << totalHeartRate / count << " bpm\n";
    } else {
        cout << "⚠️ No valid entries found.\n";
    }
}
