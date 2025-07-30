#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

// ✅ Helper: Generate timestamp string
std::string getTimestamp() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return std::string(buffer);
}

// ✅ Helper: Validate user input
bool isValid(float heartRate, float sleepHours, float waterIntake) {
    return heartRate > 0 && sleepHours > 0 && waterIntake > 0;
}

// 📄 Placeholder: View Health Log (to be expanded later)
void viewHealthLog() {
    std::cout << "📄 View log feature coming soon!\n";
}

// 📊 Placeholder: Analyze Health Data (to be expanded later)
void analyzeHealthData() {
    std::cout << "📊 Analytics module is under development.\n";
}

// 📝 Core: Collect and log health data
void collectHealthData() {
    float heartRate, sleepHours, waterIntake;

    std::cout << "\n📥 Enter today's health data:\n";
    std::cout << "❤️ Heart rate (bpm): ";
    std::cin >> heartRate;

    std::cout << "🛌 Sleep hours: ";
    std::cin >> sleepHours;

    std::cout << "💧 Water intake (liters): ";
    std::cin >> waterIntake;

    if (!isValid(heartRate, sleepHours, waterIntake)) {
        std::cout << "❌ Invalid input. Please enter positive values.\n";
        return;
    }

    std::string timestamp = getTimestamp();

    // ✍️ Save data to log
    std::ofstream outfile("healthlog.txt", std::ios::app);
    if (outfile.is_open()) {
        outfile << "[Entry - " << timestamp << "]\n";
        outfile << "Heart Rate   : " << heartRate << " bpm\n";
        outfile << "Sleep Hours  : " << sleepHours << " hrs\n";
        outfile << "Water Intake : " << waterIntake << " L\n";
        outfile << "-----------------------------\n";
        outfile.close();

        std::cout << "\n✅ Health data saved successfully!\n";

        // 🔐 Auto-backup
        std::ifstream src("healthlog.txt", std::ios::binary);
        std::ofstream dst("backup_healthlog.txt", std::ios::binary);
        dst << src.rdbuf();
    } else {
        std::cout << "❌ Error saving health data.\n";
    }
}
