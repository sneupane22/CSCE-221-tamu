#include "My_vec.h"



My_vec::My_vec(): size(0), capacity(10), ptr(new char[capacity]) {} //default constructor no arguments provided

//copy constructor
My_vec::My_vec(const My_vec& vec)
{
    size = vec.size;
    capacity = vec.capacity; // copy the capacities
    ptr = new char[capacity]; // allocate new array
    for(int i = 0; i < size; i++) // copy all the vector contents
        ptr[i] = vec.ptr[i];
}

//overloaded = (check)
My_vec& My_vec::operator=(const My_vec& vec)
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

//size function
int My_vec::get_size() const
{
    return size;
}

//capacity function
int My_vec::get_capacity() const
{
    return capacity;
}


// overload [] not const
char& My_vec::operator[](int i)
{
    return ptr[i]; // returns reference
}

// overload [] const
char& My_vec::operator[](int i) const
{

    return ptr[i]; // returns reference
}

//is it empty? increment size in subscript overload?
bool My_vec::is_empty() const
{
    if(size == 0)
        return true;
    else
        return false;
}

//elem at rank
char& My_vec::elem_at_rank(int r) const
{
    return ptr[r];
}

//insert at rank
void My_vec::insert_at_rank(int r, const char& elem)
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

//replace at rank // check is size still same and not being incremented
void My_vec::replace_at_rank(int r, const char& elem)
{
    ptr[r] = elem;
}

//remove at rank
void My_vec::remove_at_rank(int r)
{
    
    for(int i = r+1; i<get_size(); ++i)
    {
        ptr[i-1] = ptr[i];
    }
    --size;
   
}

// overload <<
ostream& operator<<(ostream& out, const My_vec& vec)
{
    for (int i = 0; i<vec.get_size(); ++i)
    {
        out << vec[i] << " ";
    }
    return out; //needed or else seg fault
}

//find the max

int find_max_index(const My_vec& v,int size)
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

// sort low to high
void sort_max(My_vec& vec)
{
    char temp;
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