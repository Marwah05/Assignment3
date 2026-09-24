1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.  
Since we created two news, new Data and new Node, then we need two deletes for them, delete doomed->data and delete doomed respectively. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?  
When we didn't have a destructor, our array stored T values directly, which made it unnecessary to clean up heap objects since there were no separate ones to clean up.
However, after changing to T*, addFront() started storing its pointers to objects created with new, so now our list has to delete them. If we had forgotten to write one,
there would be no error with the compiler and the program will run just fine. But that also means the heap objects will stay in the memory and cause a memory leak, too.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?  
addFront() has ownership of the pointer, so that means it is also allowed to delete the stored object later.
search() on the other hand doesn't take ownership because it just looks at the object to search, it doesn't add or remove, therefore it will never be able to delete.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?  

ArrayList<T> and LinkedList<T> inherit from List<T>, and it also allowed our List pointer to refer to different child classes and use their version 
of the function whenever it used them so inheritance is the first mechanism. The other one is templates, it allowed makeList() to be parameterized by
T so that it can stay agnostic no matter what type of data it holds. 

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
I personally chose explicit, it specifically tells C++ to not turn T* into a Node<T>. Without it, C++ might make a Node when we intended to only pass a pointer.
For an example, leaving a constructor that takes an int value would cause C++ to automatically use it when we pass an integer. However, using explicit prevents this from happening because
it stops the conversion from happening and makes us create a new Node.