#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <string>

typedef struct Node_t{
    void *m_item;
	struct Node_t* m_front;
    struct Node_t* m_back;
} *Node;

class Queue {
public:
    /* C'tor of Player class - 2-3 param.
    * @param name - The name of the player.
    * @param maxHP - The maximum healt points the player can have.
    * @param force - The force points the player posses.
    * @return a new instance of Player. */
    Player(std::string name, const int maxHP, const int force = DEFAULT_FORCE);
    
    Player(std::string name);

    Player() = default;

    /* D'tor of Player class. */
    ~Player() = default;


    /* Copy of Player class.
    * @param Player& - reference to another Player object.
    * @return a new instance of Player with copied values as the given Player. */
    Player(const Player&) = default;

    
    /* Prints the Player info*/
    void printInfo() const;

    /* Here we are explicitly telling the compiler to use the default methods */
    Player& operator=(const Player& other) = default;

private:
    Node m_front;
    Node m_back;
    int m_size;

};


#endif //EX3_QUEUE_H
