#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
    public:
        Array<T>(void) : _n(0)
        {
            this->_elems = NULL;
        }
        Array<T>(unsigned int n) : _n(n)
        {
            this->_elems = new T[n];
        }
        Array<T>(Array<T> const & src) : _n(src.size())
        {
            int src_n = src.size();
            if (src_n != 0)
            {
                this->_elems = new T[src_n];
                for (int i = 0; i < src_n; i ++)
                    this->_elems[i] = src._elems[i]; // src[i] is working?
            }
            else
                this->_elems = NULL;
        }
        ~Array<T>(void)
        {
            if (this->_n != 0)
                delete [] this->_elems;
        }
        
        Array<T> &  operator=(Array const & src)
        {
            if (this->_elems != NULL)
                delete [] this->_elems;
            int src_n = src.size();
            this->_n = src_n;
            if (src_n != 0)
            {
                this->_elems = new T[src_n];
                for (int i = 0; i < src_n; i ++)
                    this->_elems[i] = src._elems[i];
            }
            else
                this->_elems = NULL;
            return (*this);
        }
        T & operator[](unsigned int i) const
        {
            if (this->_elems == NULL)
                throw std::logic_error("Array does not exist.");
            if (i >= this->_n)
                throw std::out_of_range("Index is out of range.");
            return (this->_elems[i]);
        }

        unsigned int size(void) const
        {
            return (this->_n);
        }

    private:
        T* _elems;
        unsigned int _n;
};

#endif