ex00

------Copy Constructors------

- When to use them?
When your program includes dynamic allocation(new keyword) or customized argument inputs.

When the object is usually made and the constructor is called, normally the implicit version is created immediately(this made a shallow copy). For the deep copy(using of "new" keyword)you need a copy constructor. 

- Keynotes

- Shallow Copy

    Copies only the pointer, not the actual data it points to.

    Both objects end up pointing to the same memory.

    When one object changes the data, the other sees it too.

    When one object is destroyed, the pointer is deleted — the other object now points to freed memory (dangling pointer).
    - so copied obj is dependent on the original pointer
    e.g 
        MyClass obj1(10);
        MyClass obj2 = obj1; // shallow copy — same pointer

-Deep Copy

    Copies the actual data by allocating new memory and copying the contents.

    Each object has its own copy.

    No shared memory = no conflict or accidental overwrites.
    e.g 
        // Inside the copy constructor
        data = new int(*other.data); // create new memory and copy the value
     - so copied obj is independent on the original pointer

-----Copy Assignment Operator-----

- used when assigning the existing object to another existing object(mostly used when in need to updating the object)

Syntax of a Copy Assignment Operator

Here’s how you write one:

class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        if (this != &other) { // protect against self-assignment
            // free old resources if any
            // copy values from 'other' into this object
        }
        return *this;
    }
};

    MyClass& is the return type (so you can do chained assignments like a = b = c;).

    const MyClass& is the input parameter (best practice to avoid unnecessary copying).

    *this is returned to allow chaining.


------- Quick Recap of the Two: -----
Feature	Copy Constructor	Copy Assignment Operator
When is it called?	When a new object is being created from an existing one	When one existing object is assigned to another
Syntax	ClassName(const ClassName& other)	ClassName& operator=(const ClassName& other)
Example usage	ClassName b = a;	b = a; (both a and b already exist)
Memory behavior	Often used for initialization	Often used for overwriting/updating