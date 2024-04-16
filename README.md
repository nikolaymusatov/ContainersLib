# ContainersLib
## Information
This project contains library that implements the basic standard C++ container classes. Implementations provide a full set of standard methods and attributes for element handling, container capacity checking and iteration.

- The project is developed in C++ language of C++17
- Project is implemented as a static library `containers.a` with the `containers.h` header file which includes different header files with implementations of the specified containers (`list.h`, `map.h` and etc.) .
- Implementation includes classes `List`, `Map`, `Queue`, `Set`, `Multiset`, `Stack`, `Vector`, `Array` 
- Classes are template
- Full coverage of container classes methods with unit-tests was prepared using the GTest library
- Makefile for building and testing the library is provided (with targets containers.a, clean, test, test_leaks, gcov_report)

## Containers description
### List
This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | definition                                                                                          |
|------------------------|-----------------------------------------------------------------------------------------------------|
| `value_type`           | `T` defines the type of an element (T is a template parameter)                                      |
| `reference`            | `T &` defines the type of the reference to an element                                               |
| `const_reference`      | `const T &` defines the type of the constant reference                                              |
| `iterator`             | internal class `ListIterator<T>` defines the type for iterating through the container               |
| `const_iterator`       | internal class `ListConstIterator<T>` defines the constant type for iterating through the container |
| `size_type`            | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

This table contains the main public methods for interacting with the class:

| Functions      | Definition                                                                                                  |
|----------------|-------------------------------------------------------------------------------------------------------------|
| `List()`       | default constructor, creates an empty list                                                                  |
| `List(size_type n)`  | parameterized constructor, creates the list of size n                                                 |
| `List(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates a list initizialized using std::initializer_list<T>                                                                                                       |
| `List(const list &l)`| copy constructor                                                                                      |
| `List(list &&l)`     | move constructor                                                                                      |
| `~List()`            | destructor                                                                                            |
| `operator=(const List &l)` | assignment operator overload for copying an object                                              |
| `operator=(List &&l)`| assignment operator overload for moving an object                                                     |

*List Element access*

This table contains the public methods for accessing the elements of the class:

| Element access            | Definition                                      |
|---------------------------|-------------------------------------------------|
| `const_reference front()` | access the first element                        |
| `const_reference back()`  | access the last element                         |

*List Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators                | Definition                                       |
|--------------------------|--------------------------------------------------|
| `iterator begin()`       | returns an iterator to the beginning             |
| `iterator end()`         | returns an iterator to the end                   |

*List Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity                 | Definition                                       |
|--------------------------|--------------------------------------------------|
| `bool empty()`           | checks whether the container is empty            |
| `size_type size()`       | returns the number of elements                   |
| `size_type max_size()`   | returns the maximum possible number of elements  |

*List Modifiers*

This table contains the public methods for modifying a container:

| Modifiers      | Definition                                                                                                                         |
|----------------|------------------------------------------------------------------------------------------------------------------------------------|
| `void clear()`          | clears the contents                                                                                                       |
| `iterator insert(iterator pos, const_reference value)` | inserts element into concrete pos and returns the iterator that points to the new element  |
| `void erase(iterator pos)`          | erases an element at pos                                                                                      |
| `void push_back(const_reference value)`      | adds an element to the end                                                                           |
| `void pop_back()`   | removes the last element                                                                                                      |
| `void push_front(const_reference value)`      | adds an element to the head                                                                         |
| `void pop_front()`   | removes the first element                                                                                                    |
| `void swap(List& other)`                   | swaps the contents                                                                                     |
| `void merge(List& other)`                   | merges two sorted lists                                                                               |
| `void splice(const_iterator pos, List& other)`                   | transfers elements from list other starting from pos                             |
| `void reverse()`                   | reverses the order of the elements                                                                             |
| `void unique()`                   | removes consecutive duplicate elements                                                                          |
| `void sort()`                   | sorts the elements                                                                                                |

### Map
*Map Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`             | `Key` the first template parameter (Key)                                               |
| `mapped_type`          | `T` the second template parameter (T)                                                  |
| `value_type`           | `std::pair<const key_type,mapped_type>` Key-value pair                                 |
| `reference`            | `value_type &` defines the type of the reference to an element                         |
| `const_reference`      | `const value_type &` defines the type of the constant reference                        |
| `iterator`             | class `MapIterator<K, T>` as internal iterator of tree subclass; defines the type for iterating through the container                                                                                                         |
| `const_iterator`       | class `MapConstIterator<K, T>` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                                                                                     |
| `size_type`            | `size_t` defines the type of the container size (standard type is size_t)              |

*Map Member functions*

This table contains the main public methods for interacting with the class:

| Member functions      | Definition                                                                              |
|-----------------------|-----------------------------------------------------------------------------------------|
| `Map()`               | default constructor, creates an empty map                                               |
| `Map(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the map initizialized using std::initializer_list<T>                                                                                          |
| `Map(const Map &m)`   | copy constructor                                                                        |
| `Map(Map &&m)`        | move constructor                                                                        |
| `~Map()`              | destructor                                                                              |
| `operator=(const Map &m)`  | assignment operator overload for copying an object                                 |
| `operator=(Map &&m)`  | assignment operator overload for moving an object                                       |

*Map Element access*

This table contains the public methods for accessing the elements of the class:

| Element access                  | Definition                                                                    |
|---------------------------------|-------------------------------------------------------------------------------|
| `T& at(const Key& key)`         | access a specified element with bounds checking                               |
| `T& operator[](const Key& key)` | access or insert specified element                                            |

*Map Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`     | returns an iterator to the beginning                                                   |
| `iterator end()`       | returns an iterator to the end                                                         |

*Map Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`         | checks whether the container is empty                                                  |
| `size_type size()`     | returns the number of elements                                                         |
| `size_type max_size()` | returns the maximum possible number of elements                                        |

*Map Modifiers*

This table contains the public methods for modifying a container:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`         | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)`| inserts a node and returns an iterator to where the element is in the container and bool denoting whether the insertion took place                                                                         |
| `std::pair<iterator, bool> insert(const Key& key, const T& obj)`| inserts a value by key and returns an iterator to where the element is in the container and bool denoting whether the insertion took place                                                      |
| `std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj)`| inserts an element or assigns to the current element if the key already exists                                                                                                            |
| `void erase(iterator pos)`| erases an element at pos                                                            |
| `void swap(Map& other)`   | swaps the contents                                                                  |
| `void merge(Map& other)`  | splices nodes from another container                                                |

*Map Lookup*

This table contains the public methods for viewing the container:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool contains(const Key& key)`| checks if there is an element with key equivalent to key in the container      |

### Queue
*Queue Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`           | `T` the template parameter T                                                           |
| `reference`            | `T &` defines the type of the reference to an element                                  |
| `const_reference`      | `const T &` defines the type of the constant reference                                 |
| `size_type`            | `size_t` defines the type of the container size (standard type is size_t)              |

*Queue Member functions*

This table contains the main public methods for interacting with the class:


| Functions              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `Queue()`              | default constructor, creates an empty queue                                            |
| `Queue(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates queue initizialized using std::initializer_list<T>                                                                                          |
| `Queue(const Queue &q)`| copy constructor                                                                       |
| `Queue(Queue &&q)`     | move constructor                                                                       |
| `~Queue()`             | destructor                                                                             |
| `operator=(const Queue &q)` | assignment operator overload for copying an object                                |
| `operator=(Queue &&q)` | assignment operator overload for moving an object                                      |

*Queue Element access*

This table contains the public methods for accessing the elements of the class:

| Element access                     | Definition                                      |
|------------------------------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Queue Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity                | Definition                                      |
|-------------------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`      | returns the number of elements                  |

*Queue Modifiers*

This table contains the public methods for modifying a container:

| Modifiers               | Definition                                       |
|-------------------------|--------------------------------------------------|
| `void push(const_reference value)`| inserts an element at the end          |
| `void pop()`            | removes the first element                        |
| `void swap(Queue& other)`  | swaps the contents                            |

### Stack

*Stack Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type       | Definition                                                                |
|-------------------|---------------------------------------------------------------------------|
| `value_type`      | `T` the template parameter T                                              |
| `reference`       | `T &` defines the type of the reference to an element                     |
| `const_reference` | `const T &` defines the type of the constant reference                    |
| `size_type`       | `size_t` defines the type of the container size (standard type is size_t) |

*Stack Member functions*

This table contains the main public methods for interacting with the class:

| Functions         | Definition                                                                |
|-------------------|---------------------------------------------------------------------------|
| `Stack()`         | default constructor, creates an empty stack                               |
| `Stack(std::initializer_list<value_type> const &items)` | initializer list constructor, creates stack initizialized using std::initializer_list<T>                                                                        |
| `Stack(const Stack &s)` | copy constructor                                                    |
| `Stack(Stack &&s)`| move constructor                                                          |
| `~Stack()`        | destructor                                                                |
| `operator=(const Stack &&s)`| assignment operator overload for moving an object               |
| `operator=(Stack &&s)`  | assignment operator overload for moving an object                   |

*Stack Element access*

This table contains the public methods for accessing the elements of the class:

| Element access           | Definition                                       |
|--------------------------|--------------------------------------------------|
| `const_reference top()`  | accesses the top element                         |

*Stack Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity           | Definition                                      |
|--------------------|-------------------------------------------------|
| `bool empty()`     | checks whether the container is empty           |
| `size_type size()` | returns the number of elements                  |

*Stack Modifiers*

This table contains the public methods for modifying a container:

| Modifiers                         | Definition                                       |
|-----------------------------------|--------------------------------------------------|
| `void push(const_reference value)`| inserts an element at the top                    |
| `void pop()`                      | removes the top element                          |
| `void swap(Stack& other)`         | swaps the contents                               |


### Set

*Set Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type              | Definition                                                                             |
|------------------------  |----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                               |
| `value_type`             | `Key` value type (the value itself is a key)                                           |
| `reference`              | `value_type &` defines the type of the reference to an element                         |
| `const_reference`        | `const value_type &` defines the type of the constant reference                        |
| `iterator`               | class `SetIterator<T>` as the internal iterator of tree subclass; defines the type for iterating through the container                                                                                                           |
| `const_iterator`         | class `SetConstIterator<T>` as the internal const iterator of tree subclass; defines the constant type for iterating through the container                                                                                               |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)              |

*Set Member functions*

This table contains the main public methods for interacting with the class:

| Member functions      | Definition                                                                                |
|-----------------------|-------------------------------------------------------------------------------------------|
| `Set()`               | default constructor, creates an empty set                                                 |
| `Set(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>                                                                                            |
| `Set(const Set &s)`   | copy constructor                                                                          |
| `Set(Set &&s)`        | move constructor                                                                          |
| `~Set()`              | destructor                                                                                |
| `operator=(const Set &s)` | assignment operator overload for moving an object                                     |
| `operator=(Set &&s)`  | assignment operator overload for moving an object                                         |

*Set Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`     | returns an iterator to the beginning                                                   |
| `iterator end()`       | returns an iterator to the end                                                         |

*Set Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity                     | Definition                                      |
|------------------------------|-------------------------------------------------|
| `bool empty()`               | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Set Modifiers*

This table contains the public methods for modifying a container:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`         | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)` | inserts a node and returns an iterator to where the element is in the container and bool denoting whether the insertion took place                                                                    |
| `void erase(iterator pos)` | erases an element at pos                                                           |
| `void swap(Set& other)`    | swaps the contents                                                                 |
| `void merge(Set& other);`  | splices nodes from another container                                               |

*Set Lookup*

This table contains the public methods for viewing the container:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator find(const Key& key)`  | finds an element with a specific key                                         |
| `bool contains(const Key& key)`  | checks if the container contains an element with a specific key              |

### Multiset
*Multiset Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type              | Definition                                                                             |
|--------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                               |
| `value_type`             | `Key` value type (the value itself is a key)                                           |
| `reference`              | `value_type &` defines the type of the reference to an element                         |
| `const_reference`        | `const value_type &` defines the type of the constant reference                        |
| `iterator`               | class `MultisetIterator<T>` as internal iterator of tree subclass; defines the type for iterating through the container                                                                                                           |
| `const_iterator`         | class `MultisetConstIterator<T>` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                                                                               |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)              |

*Multiset Member functions*

This table contains the main public methods for interacting with the class:

| Member functions         | Definition                                                                             |
|--------------------------|----------------------------------------------------------------------------------------|
| `Multiset()`             | default constructor, creates an empty set                                              |
| `Multiset(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>                                                                                            |
| `Multiset(const Multiset &ms)`  | copy constructor                                                                |
| `Multiset(Multiset &&ms)`  | move constructor                                                                     |
| `~Multiset()`            | destructor                                                                             |
| `operator=(const Multiset &ms)` | assignment operator overload for moving an object                               |
| `operator=(Multiset &&ms)` | assignment operator overload for moving an object                                    |

*Multiset Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`     | returns an iterator to the beginning                                                   |
| `iterator end()`       | returns an iterator to the end                                                         |

*Multiset Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                      |
|------------------------|-------------------------------------------------|
| `bool empty()`         | checks whether the container is empty           |
| `size_type size()`     | returns the number of elements                  |
| `size_type max_size()` | returns the maximum possible number of elements |

*Multiset Modifiers*

This table contains the public methods for modifying a container:

| Modifiers              | Definition                                                                                           |
|------------------------|------------------------------------------------------------------------------------------------------|
| `void clear()`         | clears the contents                                                                                  |
| `iterator insert(const value_type& value)` | inserts a node and returns an iterator to where the element is in the container  |
| `void erase(iterator pos)`                 | erases an element at pos                                                         |
| `void swap(Multiset& other)`               | swaps the contents                                                               |
| `void merge(Multiset& other)`              | splices nodes from another container                                             |

*Multiset Lookup*

This table contains the public methods for viewing the container:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `size_type count(const Key& key)` | returns the number of elements matching a specific key                      |
| `iterator find(const Key& key)`   | finds element with a specific key                                           |
| `bool contains(const Key& key)`   | checks if the container contains element with a specific key                |
| `std::pair<iterator,iterator> equal_range(const Key& key)` | returns range of elements matching a specific key  |
| `iterator lower_bound(const Key& key)`  | returns an iterator to the first element not less than the given key  |
| `iterator upper_bound(const Key& key)`  | returns an iterator to the first element greater than the given key   |

### Vector

*Vector Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`           | `T` defines the type of the element (T is template parameter)                          |
| `reference`            | `T &` defines the type of the reference to an element                                  |
| `const_reference`      | `const T &` defines the type of the constant reference                                 |
| `iterator`             | internal class `VectorIterator<T>` defines the type for iterating through the container|
| `const_iterator`       | internal class `VectorConstIterator<T>` defines the constant type for iterating through the container                                                                                                         |
| `size_type`            | `size_t` defines the type of the container size (standard type is size_t)              |

*Vector Member functions*

This table contains the main public methods for interacting with the class:

| Functions              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `Vector()`             | default constructor, creates an empty vector                                           |
| `Vector(size_type n)`  | parameterized constructor, creates the vector of size n                                |
| `Vector(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates a vector initizialized using std::initializer_list<T>                                                                                          |
| `Vector(const Vector &v)`  | copy constructor                                                                   |
| `Vector(Vector &&v)`  | move constructor                                                                        |
| `~Vector()`           | destructor                                                                              |
| `operator=(const Vector &v)`| assignment operator overload for moving an object                                 |
| `operator=(Vector &&v)`    | assignment operator overload for moving an object                                  |

*Vector Element access*

This table contains the public methods for accessing the elements of the class:

| Element access                | Definition                                                                      |
|-------------------------------|---------------------------------------------------------------------------------|
| `reference at(size_type pos)` | access a specified element with bounds checking                                 |
| `reference operator[](size_type pos)` | access a specified element                                              |
| `const_reference front()`     | access the first element                                                        |
| `const_reference back()`      | access the last element                                                         |
| `T* data()`                   | direct access the underlying array                                              |

*Vector Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators             | Definition                                      |
|-----------------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`      | returns an iterator to the end                  |

*Vector Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`         | checks whether the container is empty                                                  |
| `size_type size()`     | returns the number of elements                                                         |
| `size_type max_size()` | returns the maximum possible number of elements                                        |
| `void reserve(size_type size)` | allocate storage of size elements and copies current array elements to a newely allocated array                                                                                                             |
| `size_type capacity()` | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()` | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

This table contains the public methods for modifying a container:


| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`         | clears the contents                                                                    |
| `iterator insert(iterator pos, const_reference value)` | inserts elements into concrete pos and returns the iterator that points to the new element                                                                                                           |
| `void erase(iterator pos)` | erases an element at pos                                                           |
| `void push_back(const_reference value)` | adds an element to the end                                            |
| `void pop_back()` | removes the last element                                                                    |
| `void swap(Vector& other)` | swaps the contents                                                                 |

### Array

*Array Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`           | `T` defines the type of an element (T is template parameter)                           |
| `reference`            | `T &` defines the type of the reference to an element                                  |
| `const_reference`      | `const T &` defines the type of the constant reference                                 |
| `iterator`             | `T *` defines the type for iterating through the container                             |
| `const_iterator`       | `const T *` defines the constant type for iterating through the container              |
| `size_type`            | `size_t` defines the type of the container size (standard type is size_t)              |

*Array Member functions*

This table contains the main public methods for interacting with the class:

| Functions              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `Array()`              | default constructor, creates an empty array                                            |
| `Array(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates array initizialized using std::initializer_list<T>                                                                                          |
| `Array(const Array &a)`| copy constructor                                                                       |
| `Array(Array &&a)`     | move constructor                                                                       |
| `~Array()`             | destructor                                                                             |
| `operator=(array &&a)` | assignment operator overload for moving an object                                      |

*Array Element access*

This table contains the public methods for accessing the elements of the class:

| Element access                        | Definition                                                              |
|---------------------------------------|-------------------------------------------------------------------------|
| `reference at(size_type pos)`         | access a specified element with bounds checking                         |
| `reference operator[](size_type pos)` | access a specified element                                              |
| `const_reference front()`             | access the first element                                                |
| `const_reference back()`              | access the last element                                                 |
| `iterator data()`                     | direct access to the underlying array                                   |

*Array Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators           | Definition                                      |
|---------------------|-------------------------------------------------|
| `iterator begin()`  | returns an iterator to the beginning            |
| `iterator end()`    | returns an iterator to the end                  |

*Array Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity                | Definition                                      |
|-------------------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`      | returns the number of elements                  |
| `size_type max_size()`  | returns the maximum possible number of elements |

*Array Modifiers*

This table contains the public methods for modifying a container:

| Modifiers                            | Definition                                               |
|--------------------------------------|----------------------------------------------------------|
| `void swap(Array& other)`            | swaps the contents                                       |
| `void fill(const_reference value)`   | assigns the given value to all elements in the container |