#ifndef ITERATORG_H
#define ITERATORG_H

#include "DNodeG.h"

template<typename K, typename V>
class NodeDictionaryG;

template<typename K, typename V>
class IteratorG {
    private:
        DNodeG<K,V>* v;

        friend class NodeDictionaryG<K,V>;

    public:
        IteratorG(DNodeG<K,V>* u = nullptr) : v(u){

        }

        const V& operator*(){
            return v->elm.getV();
        } 

        bool operator==(const IteratorG& p) const{
            return v == p.v;
        }  

        bool operator!=(const IteratorG& p) const{
            return v != p.v;
        } 

        IteratorG& operator++(){
            v = v->next;
            return *this;
        } 

        IteratorG& operator--(){
            v = v->prev;
            return *this;
        } 

        const Entry<K,V>& entry(){
            return v->elm;
        }
};

#endif
