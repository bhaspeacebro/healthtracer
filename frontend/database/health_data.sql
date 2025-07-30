-- Users table
CREATE TABLE Users (
    UserID INT PRIMARY KEY AUTO_INCREMENT,
    UserName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE NOT NULL,
    PasswordHash VARCHAR(255) NOT NULL
);

-- Daily health logs
CREATE TABLE HealthLogs (
    LogID INT PRIMARY KEY AUTO_INCREMENT,
    UserID INT,
    LogDate DATE NOT NULL,
    Weight DECIMAL(5,2),
    Height DECIMAL(5,2),
    BloodPressure VARCHAR(10),
    HeartRate INT,
    CaloriesBurned INT,
    StepsCount INT,
    FOREIGN KEY (UserID) REFERENCES Users(UserID)
);

-- Optional activities
CREATE TABLE Activities (
    ActivityID INT PRIMARY KEY AUTO_INCREMENT,
    LogID INT,
    ActivityType VARCHAR(50),
    DurationMinutes INT,
    FOREIGN KEY (LogID) REFERENCES HealthLogs(LogID)
);
