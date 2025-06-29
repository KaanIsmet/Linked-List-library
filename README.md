# C++ Template LinkedList

A modern, header-only, template-based singly linked list implementation in C++17.

## 🌟 Features

- **Template-based**: Works with any type (`int`, `string`, custom classes)
- **Header-only**: Easy to integrate - just include one file
- **Memory-safe**: Automatic cleanup with RAII (Resource Acquisition Is Initialization)
- **STL-style interface**: Familiar API design following C++ conventions
- **Exception-safe**: Uses `std::optional` for safe element retrieval
- **const-correct**: Proper const member functions for read-only operations

## 🚀 Quick Start

```cpp
#include "LinkedList.hpp"
#include <iostream>

int main() {
    LinkedList<int> numbers;
    
    // Add elements
    numbers.pushHead(1);      // [1]
    numbers.pushTail(2);      // [1] -> [2]
    numbers.pushHead(0);      // [0] -> [1] -> [2]
    
    // Check list properties
    std::cout << "Length: " << numbers.getLength() << std::endl;  // Output: 3
    std::cout << "Empty: " << numbers.isEmpty() << std::endl;     // Output: 0 (false)
    
    // Remove elements safely
    auto head = numbers.popHead();
    if (head) {
        std::cout << "Removed from head: " << *head << std::endl;  // Output: 0
    }
    
    auto tail = numbers.popTail();
    if (tail) {
        std::cout << "Removed from tail: " << *tail << std::endl;  // Output: 2
    }
    
    return 0;
}
```

## 📚 API Reference

### Constructors

| Function | Description |
|----------|-------------|
| `LinkedList()` | Create an empty list |
| `LinkedList(const T& val)` | Create a list with one element |

### Element Access & Modification

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `void pushHead(const T& val)` | O(1) | Add element to the front |
| `void pushTail(const T& val)` | O(1) | Add element to the back |
| `std::optional<T> popHead()` | O(1) | Remove and return front element |
| `std::optional<T> popTail()` | O(n) | Remove and return back element |

### List Information

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `bool isEmpty() const` | O(1) | Check if list is empty |
| `size_t getLength() const` | O(n) | Get number of elements |

### List Operations

| Function | Time Complexity | Description |
|----------|----------------|-------------|
| `void clear()` | O(n) | Remove all elements |

## 💡 Usage Examples

### Working with Different Types

```cpp
// Integer list
LinkedList<int> numbers;
numbers.pushTail(42);
numbers.pushTail(100);

// String list  
LinkedList<std::string> words;
words.pushHead("world");
words.pushHead("hello");

// Custom class list
struct Person {
    std::string name;
    int age;
    Person(const std::string& n, int a) : name(n), age(a) {}
};

LinkedList<Person> people;
people.pushTail(Person("Alice", 25));
people.pushTail(Person("Bob", 30));
```

### Safe Element Removal

```cpp
LinkedList<int> list;
list.pushTail(1);
list.pushTail(2);

// Safe removal - returns std::optional
auto element = list.popHead();
if (element.has_value()) {
    std::cout << "Got: " << element.value() << std::endl;
} else {
    std::cout << "List was empty" << std::endl;
}

// Alternative syntax
if (element) {
    std::cout << "Got: " << *element << std::endl;
}
```

### Processing All Elements

```cpp
LinkedList<int> list;
for (int i = 1; i <= 5; ++i) {
    list.pushTail(i);
}

// Process and remove all elements
std::cout << "Elements: ";
while (!list.isEmpty()) {
    auto val = list.popHead();
    if (val) {
        std::cout << *val << " ";
    }
}
std::cout << std::endl;
```

## 🔧 Requirements

- **C++17 or later** (for `std::optional` support)
- Any modern C++ compiler (GCC 7+, Clang 4+, MSVC 2017+)

## 📦 Installation

### Option 1: Direct Include
1. Download `LinkedList.hpp`
2. Include it in your project:
   ```cpp
   #include "LinkedList.hpp"
   ```

### Option 2: Git Submodule
```bash
git submodule add https://github.com/yourusername/cpp-linkedlist.git
```

### Option 3: Copy to System Include
```bash
# Linux/macOS
sudo cp LinkedList.hpp /usr/local/include/

# Then include system-wide
#include <LinkedList.hpp>
```

## 🏗️ Building Examples

```bash
# Compile with C++17
g++ -std=c++17 -Wall -Wextra example.cpp -o example

# Run
./example
```

## 🧪 Running Tests

```bash
# Compile test file
g++ -std=c++17 -Wall -Wextra tests/test_linkedlist.cpp -o test_linkedlist

# Run tests
./test_linkedlist
```

## ⚡ Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push Head | O(1) | O(1) |
| Push Tail | O(1) | O(1) |
| Pop Head | O(1) | O(1) |
| Pop Tail | O(n) | O(1) |
| Get Length | O(n) | O(1) |
| Search | O(n) | O(1) |
| Clear | O(n) | O(1) |

## 🎯 Design Decisions

### Why `std::optional`?
- **Safety**: No undefined behavior when popping from empty lists
- **Modern C++**: Expressive and type-safe error handling
- **Explicit**: Forces users to handle the "empty list" case

### Why Header-Only?
- **Simplicity**: No compilation dependencies
- **Templates**: Template code must be visible at instantiation
- **Performance**: Enables compiler optimizations

### Why Singly-Linked?
- **Memory efficiency**: One pointer per node vs. two for doubly-linked
- **Simplicity**: Easier to understand and implement
- **Common use case**: Most applications don't need backward traversal

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🚧 Future Enhancements

- [ ] Iterator support for range-based for loops
- [ ] Move semantics (C++11)
- [ ] Copy constructor and assignment operator
- [ ] Comparison operators (`==`, `!=`, `<`)
- [ ] Reverse iterator
- [ ] `emplace` methods for in-place construction
- [ ] Custom allocator support

## 📖 Learning Resources

- [C++ Templates](https://en.cppreference.com/w/cpp/language/templates)
- [std::optional](https://en.cppreference.com/w/cpp/utility/optional)
- [RAII in C++](https://en.cppreference.com/w/cpp/language/raii)
- [Linked Lists Data Structure](https://en.wikipedia.org/wiki/Linked_list)

---

⭐ **Star this repository if you found it helpful!**
