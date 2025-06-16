#ifndef NO_HPP
#define NO_HPP

template <typename T>
struct No{
    T item;
    No<T>* prox;
};

#endif