# Optimized Contact Manager

A high-performance contact management system with O(log n) operations using balanced BST (map) and hash maps (unordered_map).

## Features

- **Fast Operations**: All critical operations run in optimal time complexity
  - Add contact: O(log n)
  - Delete contact: O(log n)
  - Search by name: O(log n)
  - Search by phone: O(1) average case
- **Data Persistence**: Contacts are saved to and loaded from a file
- **Sorted Display**: Contacts are automatically sorted by name
- **Duplicate Prevention**: System prevents adding contacts with duplicate names

## Data Structures Used

1. **std::map** (Balanced BST)
   - Stores contacts sorted by name
   - Provides O(log n) operations for add, delete, and search by name

2. **std::unordered_map** (Hash Table)
   - Enables O(1) average case phone number lookups
   - Stores pointers to contact objects for memory efficiency

## How It Works

The system maintains two parallel data structures:
1. A BST sorted by contact names for name-based operations
2. A hash table indexed by phone numbers for quick phone lookups

When a contact is added:
- It's inserted into both structures simultaneously
- The phone hash map stores pointers to avoid data duplication

## Building and Running

### Requirements
- C++17 compatible compiler
- CMake (optional)

### Compilation
```bash
g++ -std=c++17 main.cpp Contact.cpp ContactManager.cpp FileHandler.cpp -o contact_manager
./ContactManager
