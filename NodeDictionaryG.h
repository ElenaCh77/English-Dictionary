#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include <iostream>
#include "Range.h"

template <typename K, typename V>
class NodeDictionaryG{
    private:
        int uKeys;
        int n;

        DNodeG<K,V>* header;
        DNodeG<K,V>* trailer;

    public:
       NodeDictionaryG() {
           header = new DNodeG<K,V>();
           trailer = new DNodeG<K,V>();

           header->next = trailer;
           header->prev = nullptr;

           trailer->prev = header;
           trailer->next = nullptr;

           n = 0;
           uKeys = 0;
       }  

        ~NodeDictionaryG(){
            DNodeG<K,V>* current = header;

            while(current != nullptr){
                DNodeG<K,V>* old = current;
                current = current->next;
                delete old;
            }
        }  

        int size() const{
            return n;
        } 

        int uniqueKeys() const{
            return uKeys;
        }  

        bool empty() const{
            return n == 0;
        } 

        IteratorG<K,V> begin() const{
            return IteratorG<K,V>(header->next);
        }  

        IteratorG<K,V> end() const {
            return IteratorG<K,V>(trailer);
        }

        IteratorG<K,V> find(const K& k) const{

            DNodeG<K,V>* current = header->next;

            while(current != trailer) {
                if(current->elm.getK() == k){
                    return IteratorG<K,V> (current);
                }

                current = current->next;
            }

            return end();
        }  

        IteratorG<K,V> put(const K& k, const V& v){
            Range<K,V> r = findAll(k);
            IteratorG<K,V> p = r.getE();

            bool newKey = (find(k) == end());

            DNodeG<K,V>* w = p.v;
            DNodeG<K,V>* u = w->prev;

            DNodeG<K,V>* newNode = new DNodeG<K,V>(Entry<K,V>(k,v), u, w);

            u->next = newNode;
            w->prev = newNode;

            n++;

            if(newKey){
                uKeys++;
            }

            return IteratorG<K,V>(newNode);
        }

        void erase(const K& k){
            IteratorG<K,V> position = find(k);

            if (position != end()) {
                erase(position);
            }
        }

        void erase(const IteratorG<K,V>& p) {
            DNodeG<K,V>* v = p.v;

            K key = v->elm.getK();

            DNodeG<K,V>* w = v->next;
            DNodeG<K,V>* u = v->prev;

            u->next = w;
            w->prev = u;

            delete v;
            n--;

            if(find(key) == end()){
                uKeys--;
            }
        }

        void erase(Range<K,V>& r){
            IteratorG<K,V> p = r.getB();
            IteratorG<K,V> finish = r.getE();

            while(p != finish) {
                IteratorG<K,V> next = p;
                ++next;

                erase(p);
                p = next;
            }
        }

        Range<K,V> findAll(const K& k){
            IteratorG<K,V> first = find(k);

            if(first == end()) {
                return Range<K,V> (end(), end());
            }

            IteratorG<K,V> last = first;

            while (last != end() && last.entry().getK() == k){
                ++last;
            }

            return Range<K,V>(first,last);
        }

        void print(){
            IteratorG<K,V> p = begin();

            while (p != end()) {
                std::cout<<" - " << p.entry().getK()<<" - " <<p.entry().getV()<<std::endl;
                ++p;
            }
        } 

        void print(Range<K,V>& r){
            IteratorG<K,V> p = r.getB();

            while(p != r.getE()) {
                std::cout << " - " << p.entry().getK()<<" - " <<p.entry().getV()<<std::endl;
                ++p;
            }
        }
};

#endif
