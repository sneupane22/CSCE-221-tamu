

#include <ostream>
using namespace std;

template <typename T>
class My_vec {
	
	//member variables
	int size, capacity;
	T *ptr; // array holding the vector
	
public:	
	//member functions
    
    
    My_vec(); // default destructor defined
    
    My_vec(const My_vec& vec); // copy constructor  makes an object than sets it equal to the right side defined
    ~My_vec() { delete [] ptr; } // destructor defined
	
	My_vec& operator=(const My_vec& vec); // overload the equal operator never makes an object, it already exists, and just changes it. defined
	int get_size() const; // defined
	int get_capacity() const; // defined
    
    
    T& operator[](int i); //defined
	T& operator[](int i) const; //defined
    
	bool is_empty() const; //defined
	T& elem_at_rank(int r) const; // defined
	void insert_at_rank(int r, const T& elem); // insert element at rank, also increase the size defined
	void replace_at_rank(int r, const T& elem); // replace at the rank defined
	void remove_at_rank(int r); //remove at the rank, also decrease the size defined
	
};
    template <typename T>
	ostream& operator<<(ostream& out, const My_vec<T>& vec); //defined
    template <typename T>
	int find_max_index(const My_vec<T>& v,int size); // return rank of highest valued element
    template <typename T>
	void sort_max(My_vec<T>& vec);



template <typename T>
My_vec<T>::My_vec(): size(0), capacity(10), ptr(new T[capacity]) {} //default constructor no arguments provided

template <typename T>
//copy constructor
My_vec<T>::My_vec(const My_vec& vec)
{
    size = vec.size;
    capacity = vec.capacity; // copy the capacities
    ptr = new char[capacity]; // allocate new array
    for(int i = 0; i < size; i++) // copy all the vector contents
        ptr[i] = vec.ptr[i];
}

template <typename T>
//overloaded = (check)
My_vec<T>& My_vec<T>::operator=(const My_vec& vec)
{
    if (this != &vec) // avoid self assignment
    {
        delete [] ptr; // delete old array
        size = vec.size;
        capacity = vec.capacity;
        ptr = new char[capacity]; // allocate new array
        for(int i = 0; i < size; i++)
            ptr[i] = vec.ptr[i];
    }
    return* this;
}

template <typename T>
//size function
int My_vec<T>::get_size() const
{
    return size;
}

template <typename T>
//capacity function
int My_vec<T>::get_capacity() const
{
    return capacity;
}


template <typename T>
// overload [] not const
T& My_vec<T>::operator[](int i)
{
    return ptr[i]; // returns reference
}

template <typename T>
// overload [] const
T& My_vec<T>::operator[](int i) const
{
    
    return ptr[i]; // returns reference
}

template <typename T>
//is it empty? increment size in subscript overload?
bool My_vec<T>::is_empty() const
{
    if(size == 0)
        return true;
    else
        return false;
}

template <typename T>
//elem at rank
T& My_vec<T>::elem_at_rank(int r) const
{
    return ptr[r];
}

template <typename T>
//insert at rank
void My_vec<T>::insert_at_rank(int r, const T& elem)
{
    if(r<= capacity-1)
        ++size;
    if(r>capacity)
    {
        capacity *= 2;
        ++size;
    }
    for(int i = size; i>r; --i)
    {
        ptr[i] = ptr[i-1];
    }
    ptr[r] = elem;
    
}

template <typename T>
//replace at rank // check is size still same and not being incremented
void My_vec<T>::replace_at_rank(int r, const T& elem)
{
    ptr[r] = elem;
}

template <typename T>
//remove at rank
void My_vec<T>::remove_at_rank(int r)
{
    
    for(int i = r+1; i<get_size(); ++i)
    {
        ptr[i-1] = ptr[i];
    }
    --size;
    
}

template <typename T>
// overload <<
ostream& operator<<(ostream& out, const My_vec<T>& vec)
{
    for (int i = 0; i<vec.get_size(); ++i)
    {
        out << vec[i] << " ";
    }
    return out; //needed or else seg fault
}


template <typename T>
//find the max
int find_max_index(const My_vec<T>& v,int size)
{
    int high_val = 0;
    for(int i = 0; i<(size-1); ++i)
    {
        if(v[i+1]>v[i])
        {
            high_val = i+1;
        }
    }
    return high_val;
}

template <typename T>
// sort low to high
void sort_max(My_vec<T>& vec)
{
    T temp;
    for(int i = 0; i<=(vec.get_size()-1); ++i)
    {
        for(int r = 0; r<= (vec.get_size()-2); ++r)
        {
            if(vec[r]<vec[r+1])
            {
                temp=vec[r];
                vec[r]=vec[r+1]; // swapping characters
                vec[r+1]=temp;
            }
        }
        
    }
}
