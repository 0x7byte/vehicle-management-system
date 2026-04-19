# 🚗 Vehicle Management System  
### Structured Command-Line Application in C

---

## 📌 Overview

The **Vehicle Management System** is a menu-driven command-line application developed in C.  
It simulates a lightweight vehicle database system using structured programming and manual data management techniques.

The system allows users to add, view, search, update, and delete vehicle records while ensuring data consistency and integrity.

This project demonstrates practical implementation of structured data handling without using external databases or file storage.

---

## 🎯 Objectives

- Implement structured data management using `struct`
- Handle multiple records using arrays
- Enforce unique identifiers
- Maintain record consistency during updates and deletions
- Design a continuous menu-driven system
- Apply modular programming principles

---

## 🏗️ System Design

### 🔹 Data Structure

Each vehicle record contains:

- Vehicle ID (Unique Numeric Identifier)
- Vehicle Type (Car, Bike, Bus, Truck, etc.)
- Model Name
- Brand / Manufacturer
- Year of Manufacture
- Engine Capacity (cc or descriptive text)

Optional attributes may include:
- Color
- Seat Count
- Fuel Type

All records are stored in an internal array structure.

---

## ⚙️ Core Functionalities

### 1️⃣ Add New Vehicle
- Accepts all vehicle attributes
- Validates uniqueness of Vehicle ID
- Inserts record into storage
- Confirms successful addition

### 2️⃣ Display All Vehicles
- Lists all stored vehicles
- Displays complete details in formatted structure
- Handles empty system condition

### 3️⃣ Search Vehicle
Supports:
- Search by Vehicle ID
- Search by Vehicle Type
- Search by Model Name

Displays full details of matching records.

### 4️⃣ Update Vehicle
- Locate vehicle using ID
- Display existing information
- Modify selected fields
- Save updated record without affecting others

### 5️⃣ Delete Vehicle
- Remove record by ID
- Shift array elements to maintain continuity
- Confirm deletion success

### 6️⃣ Exit System
- Clean and safe termination

---

## 🔐 Functional Constraints Implemented

- Manual data storage (arrays and structures only)
- No external database or file handling
- Maximum record limit (configurable)
- Unique Vehicle ID enforcement
- Input validation for numeric and text fields
- Continuous menu loop until explicit exit
- Record integrity preservation after update/delete

---

## 🚀 Advanced Features (Extended Capabilities)

The system architecture supports extension for:

- Multi-condition filtering
- Sorting by year, brand, or engine capacity
- Duplicate detection across attributes
- Bulk delete operations
- Partial updates for matching records
- Summary statistics generation
- Grouping vehicles by category
- Dynamic capacity expansion
- Cloning vehicle templates
- Undo last operation feature

---

## 📁 Project Structure

```
.
├── main.c      → Program entry point & menu loop
├── init.c      → Core logic implementation
├── init.h      → Function declarations & structures
├── Makefile    → Build automation
└── README.md   → Documentation
```

---

## 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Makefile Build System
- Structured Programming Concepts

---

## 🔧 Compilation & Execution

### Build the project:

```bash
make
```

### Run the executable:

```bash
./program_name
```

### Clean build files:

```bash
make clean
```

---

## 📊 Learning Outcomes

By completing this project:

- Gained hands-on experience managing structured records
- Understood limitations of flat array-based storage
- Practiced modular and maintainable code design
- Improved logical problem-solving skills
- Learned how real-world systems maintain data integrity

---

## 🧠 Academic Significance

This project simulates foundational database-like operations using only core C programming constructs.  
It reinforces concepts such as:

- Structured data modeling
- Manual memory organization
- Algorithmic record manipulation
- Data validation techniques
- Program modularization

---

## 👤 Author

0x7byte

---

## 📄 License

Developed for academic and educational purposes.
