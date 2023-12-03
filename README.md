# Bus-Reservation-System

This C++ program implements a simple Bus Reservation System. Users can perform various operations such as creating bus records, displaying all bus records, searching for specific bus records, modifying bus records, and deleting bus records.

## Features

- **Create Bus Record:** Add new bus records to the system.
- **Display All Bus Records:** View details of all existing bus records.
- **Search Specific Bus Record:** Find information about a specific bus using its number.
- **Modify Bus Record:** Update details of a particular bus record.
- **Delete Bus Record:** Remove a bus record from the system.

## Usage

1. **Create Bus Record:** Choose option 1 to add a new bus record. Enter the required details, and the record will be saved in the "busRecord.txt" file.

2. **Display All Bus Records:** Choose option 2 to view all bus records stored in the "busRecord.txt" file.

3. **Search Specific Bus Record:** Choose option 3, enter the bus number, and the program will display information about that specific bus.

4. **Modify Bus Record:** Choose option 4, enter the bus number you want to modify, provide the updated details, and the program will modify the record accordingly.

5. **Delete Bus Record:** Choose option 5, enter the bus number you want to delete, and the program will remove that bus record from the system.

## File Structure

- **busRecord.txt:** The file where bus records are stored.

## How to Run

Compile the program and run the executable. Follow the on-screen instructions to navigate through different options.

```bash
g++ main.cpp -o bus_reservation
./bus_reservation
