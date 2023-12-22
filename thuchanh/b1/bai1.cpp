#include<bits/stdc++.h>
using namespace std;

// Cấu trúc để lưu trữ dữ liệu log cuộc gọi
struct CallLog {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

// Hàm kiểm tra xem một số điện thoại có hợp lệ không
bool isValidPhoneNumber(const string& phone) {
    if (phone.length() != 10) {
        return false;
    }
    for (char c : phone) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Hàm tính thời gian dựa trên định dạng hh:mm:ss
int calculateTimeInSeconds(const string& timeStr) {
    struct tm timeStruct = {};
    sscanf(timeStr.c_str(), "%d:%d:%d", &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec);
    time_t timeInSeconds = mktime(&timeStruct);
    return static_cast<int>(timeInSeconds);
}

int main() {
    map<string, int> callCounts;
    map<string, int> totalDurations;
    string line;

    // Đọc và xử lý dữ liệu log cuộc gọi
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        size_t pos = line.find("call ");
        if (pos != string::npos) {
            CallLog log;
            line = line.substr(pos + 5); // Bỏ qua "call "
            sscanf(line.c_str(), "%s %s %s %s %s",
                &log.from_number[0],
                &log.to_number[0],
                &log.date[0],
                &log.from_time[0],
                &log.end_time[0]);

            if (isValidPhoneNumber(log.from_number) && isValidPhoneNumber(log.to_number)) {
                callCounts[log.from_number]++;
                int startTime = calculateTimeInSeconds(log.from_time);
                int endTime = calculateTimeInSeconds(log.end_time);
                totalDurations[log.from_number] += (endTime - startTime);
            }
        }
    }

    // Xử lý các truy vấn
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        if (line == "?check_phone_number") {
            bool allValid = true;
            for (const auto& entry : callCounts) {
                if (!isValidPhoneNumber(entry.first)) {
                    allValid = false;
                    break;
                }
            }
            cout << (allValid ? "1" : "0") << endl;
        } else if (line.find("?number_calls_from ") == 0) {
            string phone_number = line.substr(20); // Bỏ qua "?number_calls_from "
            cout << callCounts[phone_number] << endl;
        } else if (line == "?number_total_calls") {
            int totalCalls = 0;
            for (const auto& entry : callCounts) {
                totalCalls += entry.second;
            }
            cout << totalCalls << endl;
        } else if (line.find("?count_time_calls_from ") == 0) {
            string phone_number = line.substr(23); // Bỏ qua "?count_time_calls_from "
            cout << totalDurations[phone_number] << endl;
        }
    }

    return 0;
}
