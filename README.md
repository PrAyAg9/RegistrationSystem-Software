# Student Registration System

![Registration System](https://img.shields.io/badge/Registration-System-blue.svg)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Compilation and Testing](#compilation-and-testing)
- [Frontend and Backend Integration](#frontend-and-backend-integration)
- [Usage](#usage)
- [License](#license)
- [Contributing](#contributing)

## Introduction

The **Student Registration System** is a comprehensive software application designed to manage student registrations, course management, and reporting. It provides a user-friendly interface for students, administrators, and other stakeholders to interact with the registration system. This project is implemented using **C++** for the backend logic, **Flask** for the backend API server, and a combination of **HTML, CSS, and JavaScript** for the frontend interface.

## Features

- **Admin Module**: Allows administrators to manage users, courses, and the system.
- **Master Module**: Handles core functionality such as adding and managing courses.
- **Transaction Module**: Manages user registration for courses.
- **Reports Module**: Generates comprehensive reports based on user activities.
- **Utilities Module**: Contains utility functions for handling backups, restoring data, etc.

## Installation

-1) Clone the Repository
```bash
git clone https://github.com/your-username/student-registration-system.git
cd student-registration-system
```
-2) Install python dependencies
```bash
pip install -r backend/requirements.txt
```
-3) Compilation and Testing
```bash
g++ cpp_service/main.cpp cpp_service/AdminModule.cpp cpp_service/MastersModule.cpp cpp_service/TransactionsModule.cpp cpp_service/ReportsModule.cpp cpp_service/UtilitiesModule.cpp -o registration_system
```
-4) Run the executable
```bash
./registration_system  # On Linux/Mac
registration_system.exe  # On Windows
```

## Project Structure

```bash
project/
├── backend/
│   └── app.py              # Flask backend code
├── cpp_service/
│   ├── main.cpp            # Main C++ code for the system
│   ├── AdminModule.cpp     # Admin module code
│   ├── MastersModule.cpp   # Masters module code
│   ├── TransactionsModule.cpp # Transactions module code
│   ├── ReportsModule.cpp   # Reports module code
│   ├── UtilitiesModule.cpp # Utilities module code
│   └── httplib.h           # C++ HTTP library header file
├── frontend/
│   ├── index.html          # Main HTML file
│   ├── style.css           # CSS file
│   └── app.js              # JavaScript file for AJAX calls
└── README.md               # This README file
```





