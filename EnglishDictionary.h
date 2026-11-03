#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include <iostream>
#include <string>
#include "NodeDictionaryG.h"

class EnglishDictionary{

    private:
        std::string name;  
        NodeDictionaryG<std::string, std::string> dictionary; 

    public:
        EnglishDictionary(std::string n) : name(n) {

        }  

        ~EnglishDictionary(){

        }

        int words() const{
            return dictionary.size();
        }

        int uniqueWords() const{
            return dictionary.uniqueKeys();
        } 

        bool empty() const{
            return dictionary.empty();
        }  

        void add(Entry<std::string, std::string> e){
            dictionary.put(e.getK(), e.getV());
        }

        void deleteFirst(std::string word){
            dictionary.erase(word);
        }

        void deleteWord(std::string word){
            Range<std::string, std::string> r = dictionary.findAll(word);

            dictionary.erase(r);
        } 

        void printDictionary(bool forward){
            static IteratorG<std::string, std::string> p(nullptr);
            static int count = 0;
            static bool printing = false;
            static bool direction = true;

            if(dictionary.empty()){
                return;
            }

            if(!printing){
                printing = true;
                direction = forward;
                count = 0;

                if(direction){
                    p = dictionary.begin();
                }

                else{
                    p = dictionary.end();
                    --p;
                }
            }

            if(count == dictionary.size()) {
                printing = false;
                count = 0;
                return;
            }

            std::cout<< " - " <<p.entry().getK()<<" - " <<p.entry().getV()<<std::endl;

            count++;

            if(direction){
                ++p;
            }

            else{
                --p;
            }

            printDictionary(direction);
        }

        void printDictionary(std::string word){
            Range<std::string, std::string> r = dictionary.findAll(word);
            dictionary.print(r);
        } 

        Entry<std::string, std::string> find(std::string word){
            IteratorG<std::string, std::string> p = dictionary.find(word);

            if(p == dictionary.end()){
                return Entry<std::string, std::string>();
            }

            return p.entry();
        }
};

#endif
