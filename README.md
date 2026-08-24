# Vehicle Management System

A menu-driven C application for managing an in-memory vehicle collection. It supports record creation, lookup, update, deletion, reporting, grouping, and one-step undo operations.

## Features

- Add vehicles with duplicate numeric ID detection.
- List all registered vehicles.
- Update a vehicle's brand, manufacturing year, and engine capacity.
- Delete a vehicle by ID.
- Search by numeric ID or text in model, brand, or type fields.
- Bulk-delete vehicles older than a supplied year.
- Report total count, average engine capacity, oldest year, and newest year.
- Group records by the supported types: `car`, `bike`, `bus`, and `truck`.
- Undo the most recent add, delete, or update operation.

## Data Model

| Field | Description |
|---|---|
| `id` | Unique numeric vehicle identifier. |
| `vehicleType` | Text vehicle type. Grouping recognizes `car`, `bike`, `bus`, and `truck`. |
| `vehicleModel` | Model name entered as a single token. |
| `vehicleBrand` | Brand name entered as a single token. |
| `year` | Manufacturing year. |
| `engineCC` | Engine capacity in cubic centimeters. |

## Build and Run

Compile the two source files directly:

```bash
gcc -std=c11 -Wall -Wextra main.c init.c -o vehicle_management
./vehicle_management
```

The repository also includes a `Makefile` whose default target compiles to `exec` and immediately runs the program:

```bash
make
```

## Menu Operations

| Option | Operation |
|---:|---|
| 1 | Add vehicle |
| 2 | Show vehicles |
| 3 | Update vehicle information |
| 4 | Delete vehicle |
| 5 | Search by ID or text |
| 6 | Bulk-delete by year threshold |
| 7 | Display summary statistics |
| 8 | Group by supported type |
| 9 | Undo the most recent change |
| 0 | Exit |

## Implementation Notes

Vehicle records are stored in a fixed in-memory array with a maximum capacity of 200 entries. The application does not write records to disk, so all records are lost when the process exits.

The startup code invokes the external `sl` command before displaying the menu. This command is not required for vehicle operations; if it is not installed, the shell may print a message and the application continues.

## Limitations

- Data is not persisted between runs.
- Text input is read with `%s`, so model, brand, and type values cannot contain spaces.
- Grouping only recognizes lowercase `car`, `bike`, `bus`, and `truck` type values.
- Undo retains a fixed-size history and applies only the most recent supported operation.

## Project Structure

```text
.
├── Makefile
├── init.c
├── init.h
├── main.c
└── README.md
```
