
------When to and when not to return the reference of the result?------
Fixed& operator++(); <-- case like this (use case)--> ++a, a += b, a-= b
- where the variable is pre-incremented, that means the original referenced value is modified, and hence returning the ref is logical but for cases like

Fixed operator+(const Fixed& other)const; (use case)--> a = b + c
- where the new value will be produced from the math operations -> logical to return the value of the new result(doesn't modify the original value of the object)

for both cases, using the former way(returning the value is safe)