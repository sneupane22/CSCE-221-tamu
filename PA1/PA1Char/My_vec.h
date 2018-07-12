

#include <ostream>
using namespace std;



class My_vec {
	
	//member variables
	int size, capacity;
	char *ptr; // array holding the vector
	
public:	
	//member functions
    
    
    My_vec(); // default destructor defined
    
    My_vec(const My_vec& vec); // copy constructor  makes an object than sets it equal to the right side defined
    ~My_vec() { delete ptr; } // destructor defined
	
	My_vec& operator=(const My_vec& vec); // overload the equal operator never makes an object, it already exists, and just changes it. defined
	int get_size() const; // defined
	int get_capacity() const; // defined
    
    
    char& operator[](int i); //defined
	char& operator[](int i) const; //defined
    
	bool is_empty() const; //defined
	char& elem_at_rank(int r) const; // defined
	void insert_at_rank(int r, const char& elem); // insert element at rank, also increase the size defined
	void replace_at_rank(int r, const char& elem); // replace at the rank defined
	void remove_at_rank(int r); //remove at the rank, also decrease the size defined
	
};
	
	ostream& operator<<(ostream& out, const My_vec& vec); //defined
	int find_max_index(const My_vec& v,int size); // return rank of highest valued element
	void sort_max(My_vec& vec);
