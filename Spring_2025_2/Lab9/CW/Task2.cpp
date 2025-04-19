#include <iostream>

using namespace std;

const int MAX_LOGS = 1000;
const int MAX_MESSAGE_LENGTH = 256;

enum Severity {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    char logs[MAX_LOGS][MAX_MESSAGE_LENGTH];
    int logCount;

    void getSeverityString(Severity severity, char* buffer) const {
        if (severity == INFO) {
            copyString(buffer, "INFO");
        } else if (severity == WARNING) {
            copyString(buffer, "WARN");
        } else {
            copyString(buffer, "ERROR");
        }
    }

    void copyString(char* dest, const char* src) const {
        int i = 0;
        while (src[i] != '\0' && i < MAX_MESSAGE_LENGTH - 1) {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '\0';
    }

    void appendString(char* dest, const char* src) const {
        int i = 0;
        while (dest[i] != '\0' && i < MAX_MESSAGE_LENGTH - 1) ++i;

        int j = 0;
        while (src[j] != '\0' && i < MAX_MESSAGE_LENGTH - 1) {
            dest[i++] = src[j++];
        }
        dest[i] = '\0';
    }

    void storeLog(const char* message, Severity severity, const char* module) {
        if (logCount >= MAX_LOGS) {
            for (int i = 1; i < MAX_LOGS; ++i) {
                copyString(logs[i - 1], logs[i]);
            }
            --logCount;
        }

        char formatted[MAX_MESSAGE_LENGTH];
        formatted[0] = '\0';

        char severityStr[10];
        getSeverityString(severity, severityStr);

        appendString(formatted, "[");
        appendString(formatted, severityStr);
        appendString(formatted, "][");
        appendString(formatted, module);
        appendString(formatted, "] ");
        appendString(formatted, message);

        copyString(logs[logCount], formatted);
        ++logCount;
    }

public:
    Logger() {
        logCount = 0;
    }

    void log(const char* message, Severity severity, const char* module) {
        storeLog(message, severity, module);
    }

    friend class LogAuditor;
};

class LogAuditor {
private:
    const char* correctPassword = "admin";

    bool isPasswordCorrect(const char* input) const {
        int i = 0;
        while (correctPassword[i] != '\0' && input[i] != '\0') {
            if (correctPassword[i] != input[i]) return false;
            ++i;
        }
        return correctPassword[i] == input[i];
    }

public:
    void retrieveLogs(const Logger& logger, const char* password) {
        if (!isPasswordCorrect(password)) {
            cout << "Access denied: Incorrect password" << endl;
            return;
        }

        cout << "\n=== Logs ===\n";
        for (int i = 0; i < logger.logCount; ++i) {
            cout << logger.logs[i] << endl;
        }
    }
};

void networkModule(Logger& logger) {
    logger.log("Connected to server", INFO, "Network");
    logger.log("Connection dropped", WARNING, "Network");
}

void databaseModule(Logger& logger) {
    logger.log("Query executed", INFO, "Database");
    logger.log("Query failed", ERROR, "Database");
}

int main() {
    Logger logger;
    LogAuditor auditor;

    networkModule(logger);
    databaseModule(logger);

    char password[20];
    cout << "Enter auditor password: " << endl;
    cin >> password;

    auditor.retrieveLogs(logger, password);

    return 0;
}
