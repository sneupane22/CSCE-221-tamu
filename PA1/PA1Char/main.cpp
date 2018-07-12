
// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){
try{
    My_vec v; // define an object v of My_vec type
    v.insert_at_rank(0,'B'); // insert 'B' at the rank 0 into the vector v
    cout << v << endl; // use the overloaded operator << to display vector elements
    cout << "Size of v is " << v.get_size() << endl; // display the vector v size
    
    cout << endl;


    v.insert_at_rank(0,'A'); // insert 'A' at the rank 0 into the vector v
    cout << v << endl; // use the overloaded operator << to display vector elements
    cout << "Size of v is " << v.get_size() << endl; // display the vector v size
    cout << "Max value index is: " << find_max_index(v,v.get_size()) << endl;
    
    cout << endl;
    
    try {
        v.insert_at_rank(10, 'D'); //v.insert_at_rank(10,'D');// insert 'D' at the rank 10 into the vector v //THROW RANGE ERROR
        throw "Range error: cannot insert D at rank 10.";
    }
    catch(const char* err) {
        cerr << err << endl;
    }
    cout << v << endl;// use the overloaded operator << to display vector elements
	cout << "Size is " << v.get_size() << endl;// display the vector v size
    
    cout << endl;

    v.insert_at_rank(2,'T');// SINCE NO CHARACTER AT RANK 2 WE INSERT ONE AT RANK 2 TO TEST REMOVAL FUNCTION
    v.remove_at_rank(2);// remove a character at the rank 2 from the vector v
	cout << v << endl;// use the overloaded operator << to display vector elements
	cout << "Size of v is " << v.get_size() << endl;// display the vector v size
    
    cout << endl;

    v.insert_at_rank(2,'T');// SINCE NO CHARACTER TO REPLACE AT RANK 2 WE INSERT ONE AT RANK 2 TO TEST REPLACE FUNCTION
    v.replace_at_rank(2,'E');// replace a character at the rank 2 by the character 'E'
	cout << v << endl;// use the overloaded operator << to display vector elements
	cout << "Size of v is " << v.get_size() << endl;// display the vector v size
    
    cout << endl;
    
    My_vec v1 = v;// create a copy v1 of the vector v using a copy constructor
    cout << v1 << endl;// use the overloaded operator << to display the vector v1
    cout << endl;
    v1.replace_at_rank(2,'Y');// replace a character at the rank 2 of the vector v1 with the character 'Y'
    cout << v1 << endl; // use the overloaded operator << to display vector v1 elements
    cout << endl;

    My_vec v2;// define an object v2 of My_vec type
    v2.insert_at_rank(0,'K');// insert 'K' at the rank 0 into the vector v2
    cout << v2 << endl;// use the overloaded operator << to display vector elements
    cout << "Size of v2 is " << v2.get_size() << endl;// display the vector v2 size
    cout << endl;

    v2 = v1;// test the assignment operator and copy the vector v1 to v2
    cout << v2 << endl; // use the overloaded operator << to display vector v2
    cout << "Size of v2 is " << v2.get_size() << endl;// display the vector v2 size
    cout << endl;

    cout << "Element of highest value of v2 is in index: " << find_max_index(v2, v2.get_size()) << endl;// test the function find_max_index using v2
    sort_max(v2);// test the function sort_max using v2
    cout << "Sorted (high to low)v2 is: " << v2 << endl;

    cout << endl;
    
    try
    {
        v2.replace_at_rank(14, 'S'); // replace in the vector v2 a character at the rank 14 with 'S' //THROW RANGE ERROR
        throw "Error: cannot replace rank 14 because nothing available to replace.";
    }
    catch(const char* err)
    {
        cerr << err << endl;
    }
    

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}

