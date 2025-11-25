#include "MyVector.h"
#include "stdexcept"

// push_back
template<typename T>
void MyVector<T>::push_back(const T& v){
    if(length==cap){
        size_t nc = cap?cap*2:1;
        T* nd = new T[nc];
        for(size_t i=0;i<length;i++) nd[i]=data[i];
        delete[] data; data=nd; cap=nc;
    }
    data[length++] = v;
}

// pop_back
template<typename T>
void MyVector<T>::pop_back(){ if(length) --length; }

// size
template<typename T>
size_t MyVector<T>::size() const{ return length; }

// operator[]
template<typename T>
T& MyVector<T>::operator[](int i){ return data[i]; }

// operator==
template<typename T>
bool MyVector<T>::operator==(const MyVector& o) const{
    if(length!=o.length) return false;
    for(size_t i=0;i<length;i++)
        if(data[i]!=o.data[i]) return false;
    return true;
}

// operator!=
template<typename T>
bool MyVector<T>::operator!=(const MyVector& o) const{ return !(*this==o); }

// operator<
template<typename T>
bool MyVector<T>::operator<(const MyVector& o) const{
    size_t m = length<o.length?length:o.length;
    for(size_t i=0;i<m;i++){
        if(data[i]<o.data[i]) return true;
        if(data[i]>o.data[i]) return false;
    }
    return length < o.length;
}

// operator>
template<typename T>
bool MyVector<T>::operator>(const MyVector& o) const{ return o < *this; }

// operator<=
template<typename T>
bool MyVector<T>::operator<=(const MyVector& o) const{ return !(*this>o); }

// operator>=
template<typename T>
bool MyVector<T>::operator>=(const MyVector& o) const{ return !(*this<o); }

// Iterator 
template<typename T>
T& MyVector<T>::Iterator::operator*(){ return *ptr; }

template<typename T>
typename MyVector<T>::Iterator&
MyVector<T>::Iterator::operator++(){ ++ptr; return *this; }

template<typename T>
typename MyVector<T>::Iterator&
MyVector<T>::Iterator::operator--(){ --ptr; return *this; }

template<typename T>
typename MyVector<T>::Iterator
MyVector<T>::Iterator::operator+(int n) const{ return Iterator(ptr+n); }

template<typename T>
typename MyVector<T>::Iterator
MyVector<T>::Iterator::operator-(int n) const{ return Iterator(ptr-n); }

template<typename T>
bool MyVector<T>::Iterator::operator==(const Iterator& o) const{
    return ptr==o.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator!=(const Iterator& o) const{
    return ptr!=o.ptr;
}

template<typename T>
int MyVector<T>::Iterator::operator-(const Iterator& o) const{
    return int(ptr - o.ptr);
}

// begin
template<typename T>
typename MyVector<T>::Iterator MyVector<T>::begin(){ return Iterator(data); }

// end
template<typename T>
typename MyVector<T>::Iterator MyVector<T>::end(){ return Iterator(data+length); }

// insert
template<typename T>
typename MyVector<T>::Iterator
MyVector<T>::insert(Iterator pos,const T& v){
    size_t idx = pos - begin();
    if(length==cap){
        size_t nc=cap?cap*2:1;
        T* nd=new T[nc];
        for(size_t i=0;i<length;i++) nd[i]=data[i];
        delete[] data; data=nd; cap=nc;
    }
    for(size_t i=length;i>idx;i--) data[i]=data[i-1];
    data[idx]=v; ++length;
    return Iterator(data+idx);
}

// erase
template<typename T>
typename MyVector<T>::Iterator
MyVector<T>::erase(Iterator pos){
    size_t idx = pos - begin();
    for(size_t i=idx;i+1<length;i++) data[i]=data[i+1];
    --length;
    return Iterator(data+idx);
}

// clear
template<typename T>
void MyVector<T>::clear(){ length=0; }

// at
template<typename T>
T& MyVector<T>::at(size_t i){
    if(i>=length) throw std::out_of_range("MyVector::at");
    return data[i];
}

// front
template<typename T>
T& MyVector<T>::front(){ return data[0]; }

// back
template<typename T>
T& MyVector<T>::back(){ return data[length-1]; }

// capacity
template<typename T>
size_t MyVector<T>::capacity() const{ return cap; }

// empty
template<typename T>
bool MyVector<T>::empty() const{ return length==0; }

// int 템플릿 인스턴스화
template class MyVector<int>;
