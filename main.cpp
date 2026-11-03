#include <iostream>
#include <string>
#include "EnglishDictionary.h"

int main() {
    EnglishDictionary dictionary("English Dictionary");

    dictionary.add(Entry<std::string, std::string>(
        "devotion",
        "Love, loyalty, or enthusiasm for a person, activity, or cause."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "devotion",
        "The fact or state of being strongly dedicated to something."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "devotion",
        "A religious act of prayer or worship."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "trigger",
        "A small device that releases a spring or mechanism."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "trigger",
        "Something that causes an event or reaction."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "trigger",
        "To cause something to start or happen."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "trigger",
        "An event that causes an emotional response."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "department",
        "A division of a large organization dealing with a specific area."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "networking",
        "The process of interacting with others to exchange information."
    ));

    dictionary.add(Entry<std::string, std::string>(
        "networking",
        "The practice of connecting computers or devices together."
    ));

    std::cout << "Total definitions: " << dictionary.words() << std::endl;
    std::cout << "Unique words: " << dictionary.uniqueWords() << std::endl;

    std::cout << "\nDictionary forward:" << std::endl;
    dictionary.printDictionary(true);

    std::cout << "\nDictionary backward:" << std::endl;
    dictionary.printDictionary(false);

    std::cout << "\nDefinitions for networking:" << std::endl;
    dictionary.printDictionary(std::string("networking"));

    std::cout << "\nDelete first definition of devotion." << std::endl;
    dictionary.deleteFirst("devotion");

    std::cout << "\nDelete first definition of trigger." << std::endl;
    dictionary.deleteFirst("trigger");

    std::cout << "\nDelete all definitions of networking." << std::endl;
    dictionary.deleteWord("networking");

    std::cout << "\nDictionary after deletions:" << std::endl;
    dictionary.printDictionary(true);

    std::cout << "\nTotal definitions: " << dictionary.words() << std::endl;
    std::cout << "Unique words: " << dictionary.uniqueWords() << std::endl;

    return 0;
}
