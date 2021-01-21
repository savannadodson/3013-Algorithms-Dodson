/*****************************************************************************
*                    
*  Author:           Savanna Dodson
*  Email:            savannadodson11@gmail.com
*  Label:            A02
*  Title:            Commenting on the program
*  Course:           CMPS 3013
*  Semester:         Spring Semester 2021
* 
*  Description:
*        Commenting throughout the program
* 
*  Usage:
*        how to use the program if necessary
* 
*  Files:            (list of all source files used in this program)
*****************************************************************************/

#include <iostream>

using namespace std;

int A[100];

struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};


/**
 * List
 * 
 * Description:
 *      This class implements a class called List and allows you 
 *      to make changes to the Linked List such as add, delete, move, 
 *      or print the list of objects. 
 * 
 * Public Methods:
 *      - List()
 *      - void Push(int val)
 *      - void Insert(int val)
 *      - void PrintTail()
 *      - int Pop()
 *      - List operator+(const List &Rhs)
 *      - int operator[](int index)
 *      - friend ostream &operator<<(ostream &os, List L)
 *
 * Private Methods:
 *      - NONE
 *      
 *      
 * 
 * Usage: 
 * 
 *      - List L(filename);
 *      - L1.Push(int val);
 *      - L1.Insert(int val);
 *      - L1.PrintTail();
 *      - L1.Pop();
 *       
 *      
 */

class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public: Push
     * 
     * Description:
     *      adds values to the linked list
     * 
     * Params:
     *      - [int] : value being added into the linked listt
     *     
     *      
     *      
     * 
     * Returns:
     *      - this function does not return anything
     */

    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
/**
     * Public: Insert
     * 
     * Description:
     *      inserts a value to the linked list
     * 
     * Params:
     *      - [int] : value being inserted into the linked listt
     *     
     *      
     *      
     * 
     * Returns:
     *      - this function does not return anything
     */

    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

/**
     * Public: PrintTail
     * 
     * Description:
     *      - prints the value at the end of the linked list
     * 
     * Params:
     *      - NONE
     *     
     *      
     *      
     * 
     * Returns:
     *      - NONE
     */

    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public: Print
     * 
     * Description:
     *      - prints out the Linked List
     * 
     * Params:
     *      - NONE
     *     
     *      
     *      
     * 
     * Returns:
     *      - [int] List : the values in the linked list
     */

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * Public: List operator+
     * 
     * Description:
     *       Create a new list that will contain both when done
     * 
     * Params:
     *      - [const] : values to combine the first list with the second list
     *     
     *      
     *      
     * 
     * Returns:
     *      - the New combined list
     */

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public: Operator[]
     * 
     * Description:
     *       Implementation of [] operator.  This function returns an
     *       int value as if the list were an array.
     * 
     * Params:
     *      - [int] : array of integers
     *     
     *      
     *      
     * 
     * Returns:
     *      - Temp : the list as an arraay
     */


    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Public: ostream &operator
     * 
     * Description:
     *      gets all the data and puts it together to make it into a list
     * 
     * Params:
     *      - ostream &os : the data 
     *      - List : data from the list
     *      
     *      
     * 
     * Returns:
     *      - os : the values all in a list
     */

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    // declaring the variabless
    List L1;
    List L2;

    // goes through 25 values and pushes it into a list
    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }
    // goes through 50 values and pushes it into a list
    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    // prints out the ending of bothof tthe lists
    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    // adds the first and second list together
    List L3 = L1 + L2;
    // prints out the new list 
    cout << L3 << endl;

    // prints out the value in the 5h space
    cout << L3[5] << endl;
    return 0;
}
