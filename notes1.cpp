//templating happens *at compile time*

//the compiler will see which versions of the template your program needs and generate those classes for you
//example: if you use std::vector<int> and std::vector<float> then the compiler willgenerate 2 versions of the vecor class (1 for ints and 1 for floats)

//copy operator -> copies the house to another house
//move operator -> "steals the house"...copies the house and deletes the old house

//kinda just like...copy everything from the old house (all the variables) and then set the pointer to nullptr

//iterators are wrappers around pointers that provides cfunctionality for iterating ghtourgh items in a container
//often internally manage a simple pointer
//come in different forms...we use random acess iterator for vector. can move left & right and can acess arbitrary elements in its underlying container
//in conclusion iterator = fancy pointer