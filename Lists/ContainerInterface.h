//
// Created by User on 08.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H
#define OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Server.h"
#include "Book.h"
#include "Node.h"
#include <typeinfo>

using namespace std;

/**
 * Template interface structure for the Container interface structure
 */
template <class T>
class ContainerInterface {
public:

    /**
     * Pure virtual function that adds the Element to the List
     *
     * @param val The value that would be added to the List
     */
    virtual void add_node(T val) = 0;

    /**
     * Deletes the last element of the list
     *
     * @return the element in the tail of the list
     */
    virtual bool pop_node() = 0;

    virtual std::string to_string(int index) = 0;

    /**
     * Deletes the element from the list
     * @param element to delete
     * @return true if success
     */
    virtual bool delete_node(T element) = 0;

    /**
     * Checks whether the element is present in the list
     * @param element the element to check
     * @return true if present
     */
    virtual bool is_present(T element) = 0;

    /**
      * Pure virtual function returns the current size of the list
      */
    virtual int get_curr_size() = 0;

    /**
     * Pure virtual function that prints all the data from the list on the screen
     */
    virtual void display() = 0;

    /**
     * Pure virtual function that get the data by index
     */
    virtual T get_by_index(int index) = 0;

    /**
    * Pure virtual function that performs the quicksort algorithm
    */
    virtual void quicksort() = 0;

    /**
    * Pure virtual function that performs the mergesort algorithm
    */
    virtual void mergesort() = 0;

    /**
    * Pure virtual function that performs the selection sort algorithm
    */
    virtual void selection_sort() = 0;

    /**
    * Pure virtual function that performs the bucketsort algorithm
    */
    virtual void bucketsort() = 0;
    /**
     * Pure virtual function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    virtual void countingsort(int exp = 1 , int max_int = 50) = 0;

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    virtual T &operator[](int i) = 0;

    /**
     * @param name The KEY value tp find th server
     * @return the server with the inputted name
     */
    virtual T* get_Server_by_serverID(string name) = 0;

    virtual bool change_companyName_by_serverID(string serverID, string newCompanyName) = 0;

    virtual bool add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) = 0;

    virtual bool delete_Server_by_serverID(string serverID) = 0;

    virtual bool generate(int amount) = 0;

    virtual T* get_book_by_name(string name) = 0;

    virtual bool change_genre_by_name(string name, string newGenre) = 0;

    virtual bool add_book_by_name(string company, string author, int year, string genre, string name) = 0;

    virtual bool delete_book_by_name(string name) = 0;

    //virtual ContainerInterface* union_operation(ContainerInterface* cont1) = 0;

};
/**
 * Template interface structure for the List structure that is based on the linked list
 */
template <class T>
class DLList : public ContainerInterface <T>  {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    /**
     * Returns the max int in the list
     *
     * @return the max int in the list
    */
    int get_max_int();

    /**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
    void swap(Node <T> *a, Node <T> *b);

    /**
     * Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the linked list to sort
     * @param finish The finish of the linked list to sort
     * @return the Index of the end of the sorted part of the linked list
     */
    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the sublist to sort
     * @param finish The end of the sublist to sort
     */
    void _quicksort(Node <T>* start, Node <T>* finish);

    /**
     * The function that divides the linked list in two linked lists
     * The first linked list is saved in the **first, the second linked list is saved in the **second
     *
     * @param start The linked list to divide
     * @param first The first part of the input linked list
     * @param second The second part of the input linked list
     */
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second);

    /**
     * The function that merges two linked lists in one
     *
     * @param first The first linked list
     * @param second The second linked list
     * @return The merged linked list
     */
    Node <T> *merge(Node <T> *first, Node <T> *second);


    /**
    * Function that performs the mergesort algorithm
    *
    * @param source The pointer on the linked list that would be sorted
    */
    void _mergesort(Node <T> **source);

    /**
    * Utility function for countingsort that fills the input arrays with zeros.
    *
    * @param in The input array to fill
    * @param length The length of this array
    */
    void fill_array_0(int in[], int length);
public:

    /**
     * Default constructor
     */
    DLList();

    std::string to_string(int index) override;
    /**
     * Function that get the data by index
     */
    T get_by_index(int index) override;

    /**
    * Returns the pointer on the tail of the list
    *
    * @return the pointer on the tail of the list
    */
    Node <T>* get_tail();

    /**
     * Returns the pointer on the head of the list
     *
     * @return the pointer on the head of the list
     */
    Node <T>* get_head();

    /**
    * Function that adds the Element to the List
    *
    * @param val The value that would be added to the List
    */
    void add_node(T val) override;

    /**
     * Deletes the last element of the list
     *
     * @return the element in the tail of the list
     */
    bool pop_node() override;

    /**
     * Deletes the element from the list
     * @param element to delete
     * @return true if success
     */
    bool delete_node(T element) override ;

    /**
     * Checks whether the element is present in the list
     * @param element the element to check
     * @return true if present
     */
    bool is_present(T element) override;

    /**
     * Function returns the current size of the list
     */
    int get_curr_size() override;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override;

    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override;

    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override;
    /**
    * Function that performs the bucketsort sort algorithm
    */
    void bucketsort() override ;

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    T &operator[](int i) override;

    /**
     * @param name The KEY value tp find th server
     * @return the server with the inputted name
     */
    T* get_Server_by_serverID(string serverID) override;

    T* get_book_by_name(string name) override;

    bool change_companyName_by_serverID(string serverID, string newCompanyName) override;

    bool change_genre_by_name(string name, string newGenre) override ;

    bool add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) override ;

    bool add_book_by_name(string company, string author, int year, string genre, string name) override ;

    bool delete_Server_by_serverID(string serverID) override;

    bool delete_book_by_name(string name) override ;

    bool generate(int amount) override;

    DLList<T>* get_part_start(int amount) ;

    DLList<T>* get_part_end(int amount) ;

    DLList<T>* union_operation(DLList<T>* in);

    //ContainerInterface<T>* union_operation(ContainerInterface<T>* cont1) override;
};
template<class T>
DLList<T>* DLList<T>::union_operation(DLList<T> *in){
    DLList<T> *outputList = new DLList<T>;
    for(int i = 0 ; i < this->get_curr_size(); i++){
        if(!outputList->is_present((*this)[i])){
            outputList->add_node((*this)[i]);
        }
    }
    for(int i = 0 ; i < in->get_curr_size(); i++){
        if(!outputList->is_present((*in)[i])){
            outputList->add_node((*in)[i]);
        }
    }
    return outputList;
}
/**
 * UNION OPERATION
 */
template <class T>
DLList<T> operator + (DLList<T> l1, DLList<T> l2);

/**
 * INTERSECT OPERATION
 */
template <class T>
DLList<T> operator * (DLList<T> l1, DLList<T> l2);

/**
 * EXCEPT OPERATION
 */
template <class T>
DLList<T> operator - (DLList<T> l1, DLList<T> l2);

/**
 * SYMMETRIC EXCEPT OPERATION
 */
template <class T>
DLList<T> operator % (DLList<T> l1, DLList<T> l2);


template<class T>
std::string DLList<T>::to_string(int index)
{
    T element = this->get_by_index(index);
    return std::to_string(element);
}

template<>
inline std::string DLList<Server>::to_string(int index)
{
    Server element = this->get_by_index(index);
    return element.get_serverID();
}

template<>
inline std::string DLList<Book>::to_string(int index)
{
    Book element = this->get_by_index(index);
    return element.get_bookName();
}

/**
* Function returns the current size of the list
*/
template<class T>
int DLList<T>::get_curr_size() {
    return node_sum;
}

/**
* Returns the max int in the list
*
* @return the max int in the list
*/
template <class T>
int DLList <T> :: get_max_int(){
    if (typeid(T).name() != typeid(int).name()){
        cout << "Sorry, your values are not integers"<< endl;    //if elements are not int
        return 0;
    }
    int a = head->data;                 //parcing all the list. The biggest int is saved in 'a'
    Node <T> *start = head;
    while (start != nullptr){
        if (a < start->data)
            a = start->data;
        start = start->next;
    }
    return a;
}

/**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
template <class T>
void DLList <T> :: swap(Node <T> *a, Node <T> *b) {

    //cathing the possible error
    if(a == nullptr || b == nullptr){
        cout << "One of the nodes is empty. Nothing to swap." << endl;
        return;
    }

    T temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/**
* Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
*
* @param start The start of the linked list to sort
* @param finish The finish of the linked list to sort
* @return the Index of the end of the sorted part of the linked list
*/
template <class T>
Node <T>* DLList <T> :: partition_quicksort(Node <T> *start, Node <T> *finish){

    T piv_data = finish->data;      //data that pivot contain
    Node <T>* temp = start->prev;   //pointer on the place to swap the values
    Node <T>* j;                    //iterator

    //partition part
    for (j = start; j !=finish; j = j->next) {
        if (j->data <= piv_data) {
            if (temp == nullptr)
                temp = start;
            else
                temp = temp->next;
            swap(temp, j);
        }
    }

    //swapping the pivot
    if (temp == nullptr )
        temp = start;
    else
        temp = temp->next;
    swap (temp, j);

    return temp;
}

/**
* Function that performs the quicksort algorithm
*
* @param start The start of the sublist to sort
* @param finish The end of the sublist to sort
*/
template <class T>
void DLList <T> :: _quicksort(Node <T> *start, Node <T> *finish){

    if (finish != nullptr && start != finish && start != finish->next){
        Node <T> *pivot = partition_quicksort(start, finish);   //finding the place to pivot
        _quicksort(start, pivot->prev);            //doing the same to the left part
        _quicksort(pivot->next, finish);           //doing the same to the right part
    }
}

/**
* The function that divides the linked list in two linked lists
* The first linked list is saved in the **first, the second linked list is saved in the **second
*
* @param start The linked list to divide
* @param first The first part of the input linked list
* @param second The second part of the input linked list
*/
template <class T>
void DLList <T> :: listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

    //Catching the possible error
    if (start == nullptr){
        cout<<"Unexpected error."<<endl;
        return;
    }

    Node <T> *fast, *slow; //used in fast/slow pointer method to divide list on 2 halves
    fast = start->next;
    slow = start;

    //the algorithm on dividing the list on two lists
    while (fast != nullptr){
        fast = fast->next;
        if (fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = start;
    *second = slow->next;
    slow->next = nullptr;
}

/**
* The function that merges two linked lists in one
*
* @param first The first linked list
* @param second The second linked list
* @return The merged linked list
*/
template <class T>
Node <T>* DLList<T> :: merge(Node <T> *first, Node <T> *second){

    Node <T> *result;               //pointer on the result linked

    if (first == nullptr)              //basic cases
        return second;
    if (second == nullptr)
        return first;

    if (first->data <= second->data) {          //standard merge
        result = first;
        result->next = merge(first->next, second);
    }
    else {
        result = second;
        result->next = merge(first, second->next);
    }

    return (result);
}

/**
* Function that performs the mergesort algorithm
*
* @param source The pointer on the linked list that would be sorted
*/
template <class T>
void DLList <T> :: _mergesort(Node <T> **source)
{
    Node <T> *start = *source;
    Node <T> *first;
    Node <T> *second;

    //Basic case
    if (start == nullptr || start->next == nullptr) {
        return;
    }

    //splits the source on 2 halves
    listsplit_mergesort(start, &first, &second);

    //recursive sort
    _mergesort(&first);
    _mergesort(&second);

    //merging the 2 halves
    *source = merge(first, second);
    head = *source;

    //updating the head and the tail
    Node <T> *temp;
    temp = head;
    if (temp == nullptr)
        return;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    tail = temp;
}

/**
* Utility function for countingsort that fills the input arrays with zeros.
*
* @param in The input array to fill
* @param length The length of this array
*/
template <class T>
void DLList <T> :: fill_array_0(int in[], int length){
    for (int i = 0; i < length; i++){
        in[i] = 0;
    }
}

template<class T>
T DLList<T>::get_by_index(int index)
{

    Node<T>* temp = this->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

/**
* Returns the pointer on the tail of the list
*
* @return the pointer on the tail of the list
*/
template <class T>
Node <T>* DLList <T> :: get_tail(){
    return tail;
}

/**
 * Returns the pointer on the head of the list
 *
 * @return the pointer on the head of the list
 */
template <class T>
Node <T>* DLList <T> :: get_head(){
    return head;
}

/**
* Function that adds the Element to the List
*
* @param val The value that would be added to the List
*/
template <class T>
void DLList <T> :: add_node(T val){

    auto *new_node = new Node <T>;
    new_node->data = val;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == nullptr){
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = tail->next;
    }

    node_sum ++;                    //updated the number of the nodes
}

/**
* Function that prints all the data from the list on the screen
*/
template <class T>
void DLList <T> :: display(){

    Node<T> *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
void DLList <T> :: countingsort(int exp, int max_int) {
    cout << "You cannot use this sort for this type of data" << endl;
}

/**
* Function that performs the counting sort algorithm for the int type of data.
* Uses default arguments for simple countingsort.
* The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
* This sorting algorithm is valid only for the integers in [0,50)
*
* @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
*        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
* @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
*        value for a sorted integer
*/
template <>
inline void DLList <int> :: countingsort(int exp, int max_int){

    //exp is used to radix algorithm. If u want to use this sort in default conditions
    //the value of exp and ten must be = 1 and 50 respectively (just don't touch it)

    //I use "49" as maximum possible value to the given integer


    Node <int>* start = head;
    int num = get_curr_size();
    if (num < 2){
        cout << "nothing to sort" << endl;                  //if number of elements are 0 or 1
        return;
    }

    if (get_max_int() > 49){
        cout << "this algorithm is valid only for integers that <50" << endl;
        return;
    }

    int index[max_int];
    fill_array_0(index,max_int);                    //creating index array

    int out[num];                                   //output array
    int temp;

    //creating the index array
    while (start != nullptr){
        temp = (start->data / exp) % max_int;
        index[temp]++;                         //incrementing the index val of the current value
        start = start->next;
    }

    //modifying the index array
    for (int i = 1; i < max_int; i++){
        index[i] = index[i] + index[i - 1];
    }

    //creating the output array using index array
    if (max_int == 10){
        start = tail;
        // for (int s = num - 1; s >= 0; s--){
        while (start != nullptr){
            temp = start->data;
            out[index[(temp / exp) % max_int] - 1] = temp;
            index[(temp / exp) % max_int]--;
            start = start->prev;
        }
    } else {
        start = head;
        while (start != nullptr) {
            temp = start->data;
            out[index[(temp / exp) % max_int] - 1] = temp;
            index[(temp / exp) % max_int]--;
            start = start->next;
        }
    }

    //rewriting the values in the linked list from the output array
    start = head;
    for(int k = 0; k < num; k++) {
        start->data = out[k];
        start = start->next;
    }
}

template<class T>
bool DLList<T>::pop_node() {
    if(tail == nullptr)
        return false;
    Node<T>* temp = tail;
    if(tail->prev == nullptr){
        tail = nullptr;
        head = nullptr;
        delete  temp;
        node_sum --;
        return true;
    }
    tail = tail->prev;
    tail->next = nullptr;
    node_sum--;
    delete temp;
    return true;
}

/**
 * Deletes the element from the list
 * @param element to delete
 * @return true if success
 */
template<class T>
bool DLList<T>::delete_node(T element) {
    Node<T>* temp = get_head();

    while(temp){
        if(temp->data == element){
            if(temp->prev){
                temp->prev->next = temp->next;
            }
            if(temp->next){
                temp->next->prev = temp->prev;
            }
            delete(temp);
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/**
* Function that performs the selection sort algorithm
*/
template <class T>
void DLList <T> :: selection_sort() {

    Node <T> *curr = head;

    if (curr == nullptr || curr->next == nullptr){
        cout << "Nothing to sort" << endl;
        return;
    }

    Node <T> *iterator, *min;

    while(curr != nullptr){
        //save the smallest val in order to place it on the start of unsorted part of the array
        min = curr;
        iterator = curr->next;
        while(iterator != nullptr){
            if(iterator->data <= min->data)
                min = iterator;
            iterator = iterator->next;
        }
        swap(curr, min);
        curr = curr->next;
    }
}


/**
* Function that basically calls the _quicksort function that is in private section
*/
template <class T>
void DLList <T> :: quicksort(){
    _quicksort(get_head(),get_tail());  //calls the function
}

/**
* Function that basically calls the _mergesort function that is in private section
*/
template <class T>
void DLList <T> :: mergesort(){
    _mergesort(&head);          //calls the function
}

template<class T>
DLList<T>::DLList() {
    node_sum = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
T &DLList<T>::operator[](int i) {
    Node<T>* temp = this->head;
    for(int j = 0; j < i; j++){
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
T* DLList<T>::get_Server_by_serverID(string serverID) {
    return nullptr;
}

template <>
inline Server* DLList<Server>::get_Server_by_serverID(string serverID) {
    Node<Server>* iter = this->get_head();

    while(iter){
        if(iter->data.get_serverID() == serverID)
            return &(iter->data);
        iter = iter->next;
    }
    return nullptr;
}

template<class T>
bool DLList<T>::change_companyName_by_serverID(string serverID, string newCompanyName){
    return false;
}

template <>
inline bool DLList<Server>::change_companyName_by_serverID(string serverID, string newCompanyName){
    Server* temp = get_Server_by_serverID(serverID);
    if(temp){
        temp->set_companyName(newCompanyName);
        return true;
    }
    return false;
}

template<class T>
bool DLList<T>::add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) {
    return false;
}

template <>
inline bool DLList<Server>::add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel){
    if(!get_Server_by_serverID(serverID)){
        Server newServer(name, dataCenter, rackModel, serverID);
        this->add_node(newServer);
        return true;
    }
    return false;
}

template<class T>
bool DLList<T>::delete_Server_by_serverID(string serverID) {
    return false;
}

template<>
inline bool DLList<Server>::delete_Server_by_serverID(string serverID) {
    Server* temp = get_Server_by_serverID(serverID);
    if(temp){
        return delete_node(*temp);
    }
    return false;
}

template<class T>
bool DLList<T>::is_present(T element) {
    Node<T>* temp = get_head();
    while(temp){
        if(temp->data == element)
            return true;
        temp = temp->next;
    }
    return false;
}

template<class T>
DLList<T>* DLList<T>::get_part_end(int amount) {
    if(amount > this->get_curr_size() || amount <= 0)
        return nullptr;
    if(amount == this->get_curr_size())
        return this;
    else{
        auto* newList = new DLList();
        Node<T>* temp = this-get_tail();
        for(int i = 0; i < amount; i++){
            newList->add_node(temp[i]);
            temp = temp->prev;
        }
        return newList;
    }
}

template<class T>
DLList<T>* DLList<T>::get_part_start(int amount) {
    if(amount > this->get_curr_size() || amount <= 0)
        return nullptr;
    if(amount == this->get_curr_size())
        return this;
    else{
        auto* newList = new DLList();
        Node<T>* temp = this-get_head();
        for(int i = 0; i < amount; i++){
            newList->add_node(temp[i]);
            temp = temp->next;
        }
        return newList;
    }
}


template<class T>
bool DLList<T>::generate(int amount) {
    if(amount <= 0)
        return false;

    head = nullptr;
    tail = nullptr;
    node_sum = 0;

    Node<T> *temp = new Node<T>();

    for(int i = 0 ; i < amount; i++){
        temp->generate();
        add_node(temp->data);
    }
    return true;
}

template<class T>
T *DLList<T>::get_book_by_name(string name) {
    return nullptr;
}

template <>
inline Book *DLList<Book>::get_book_by_name(string name) {
    Node<Book>* iter = this->get_head();

    while(iter){
        if(iter->data.get_bookName() == name)
            return &(iter->data);
        iter = iter->next;
    }
    return nullptr;
}


template<class T>
bool DLList<T>::change_genre_by_name(string name, string newGenre) {
    return false;
}

template <>
inline bool DLList<Book>::change_genre_by_name(string name, string newGenre){
    Book* temp = get_book_by_name(name);
    if(temp){
        temp->set_genre(newGenre);
        return true;
    }
    return false;
}

template<class T>
bool DLList<T>::add_book_by_name(string company, string author, int year, string genre, string name) {
    return false;
}

template <>
inline bool DLList<Book>::add_book_by_name(string company, string author, int year, string genre, string name){
    if(!get_book_by_name(name)){
        Book newBook(company,  author,  year,  genre,  name);
        this->add_node(newBook);
        return true;
    }
    return false;
}

template<class T>
bool DLList<T>::delete_book_by_name(string name) {
    return false;
}

template<class T>
void DLList<T>::bucketsort() {
    std::vector<T> b[node_sum];

    Node<T> *temp = head;
    for (int i=0; i<node_sum; i++)
    {
        int index = node_sum * (temp->data);
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i=0; i<node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i=0; i<node_sum; i++)
        for (int j=0; j<b[i].size(); j++)
        {
            temp->data = b[i][j];
            temp = temp->next;
        }
}

template<>
inline void DLList<Book>::bucketsort() {
    std::vector<Book> b[node_sum];

    Node<Book> *temp = head;
    for (int i=0; i<node_sum; i++)
    {
        int index = node_sum * temp->data.get_year();
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i=0; i<node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i=0; i<node_sum; i++)
        for (int j=0; j<b[i].size(); j++)
        {
            temp->data = b[i][j];
            temp = temp->next;
        }
}

template<>
inline void DLList<Server>::bucketsort() {
    std::vector<Server> b[node_sum];

    Node<Server> *temp = head;
    for (int i=0; i<node_sum; i++)
    {
        int index = node_sum * (temp->data.get_companyName()[0]);
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i=0; i<node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i=0; i<node_sum; i++)
        for (int j=0; j<b[i].size(); j++)
        {
            temp->data = b[i][j];
            temp = temp->next;
        }
}

template<>
inline bool DLList<Book>::delete_book_by_name(string name) {
    Book* temp = get_book_by_name(name);
    if(temp){
        return delete_node(*temp);
    }
    return false;
}

template <class T>
DLList<T> operator + (DLList<T> l1, DLList<T> l2){
    DLList<T> outputList = l1;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(!outputList.is_present(l2[i])){
            outputList.add_node(l2[i]);
        }
    }
    return outputList;
}



template <class T>
DLList<T> operator * (DLList<T> l1, DLList<T> l2){
    DLList<T> outputList;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(l1.is_present(l2[i])){
            outputList.add_node(l2[i]);
        }
    }
    return outputList;
}

template <class T>
DLList<T> operator - (DLList<T> l1, DLList<T> l2){
    DLList<T> outputList = l1;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(!outputList.is_present(l2[i])){
            outputList.delete_node(l2[i]);
        }
    }
    return outputList;
}

template <class T>
DLList<T> operator % (DLList<T> l1, DLList<T> l2){
    DLList<T> outputList = l1 + l2 - (l1 * l2);
    return outputList;
}



/**
 * Template interface structure for the List structure that is based on the linked list
 */
template <class T>
class DLCircularList : public ContainerInterface <T>  {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    /**
     * Returns the max int in the list
     *
     * @return the max int in the list
    */
    int get_max_int();

    /**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
    void swap(Node <T> *a, Node <T> *b);

    /**
     * Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the linked list to sort
     * @param finish The finish of the linked list to sort
     * @return the Index of the end of the sorted part of the linked list
     */
    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the sublist to sort
     * @param finish The end of the sublist to sort
     */
    void _quicksort(Node <T>* start, Node <T>* finish);

    /**
     * The function that divides the linked list in two linked lists
     * The first linked list is saved in the **first, the second linked list is saved in the **second
     *
     * @param start The linked list to divide
     * @param first The first part of the input linked list
     * @param second The second part of the input linked list
     */
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second);

    /**
     * The function that merges two linked lists in one
     *
     * @param first The first linked list
     * @param second The second linked list
     * @return The merged linked list
     */
    Node <T> *merge(Node <T> *first, Node <T> *second);


    /**
    * Function that performs the mergesort algorithm
    *
    * @param source The pointer on the linked list that would be sorted
    */
    void _mergesort(Node <T> **source);

    /**
    * Utility function for countingsort that fills the input arrays with zeros.
    *
    * @param in The input array to fill
    * @param length The length of this array
    */
    void fill_array_0(int in[], int length);
public:

    /**
     * Default constructor
     */
    DLCircularList();

    /**
     * Function that get the data by index
     */
    T get_by_index(int index) override;

    /**
    * Returns the pointer on the tail of the list
    *
    * @return the pointer on the tail of the list
    */
    Node <T>* get_tail();

    /**
     * Returns the pointer on the head of the list
     *
     * @return the pointer on the head of the list
     */
    Node <T>* get_head();

    /**
    * Function that adds the Element to the List
    *
    * @param val The value that would be added to the List
    */
    void add_node(T val) override;

    /**
     * Deletes the last element of the list
     *
     * @return the element in the tail of the list
     */
    bool pop_node() override;

    /**
     * Deletes the element from the list
     * @param element to delete
     * @return true if success
     */
    bool delete_node(T element) override ;

    /**
     * Checks whether the element is present in the list
     * @param element the element to check
     * @return true if present
     */
    bool is_present(T element) override;

    /**
     * Function returns the current size of the list
     */
    int get_curr_size() override;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override;

    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override;

    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override;
    /**
    * Function that performs the bucketsort sort algorithm
    */
    void bucketsort() override ;

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    T &operator[](int i) override;

    /**
     * @param name The KEY value tp find th server
     * @return the server with the inputted name
     */
    T* get_Server_by_serverID(string serverID) override;

    T* get_book_by_name(string name) override;

    bool change_companyName_by_serverID(string serverID, string newCompanyName) override;

    std::string to_string(int index) override;

    bool change_genre_by_name(string name, string newGenre) override ;

    bool add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) override ;

    bool add_book_by_name(string company, string author, int year, string genre, string name) override ;

    bool delete_Server_by_serverID(string serverID) override;

    bool delete_book_by_name(string name) override ;

    bool generate(int amount) override;

    DLCircularList<T>* get_part_start(int amount) ;

    DLCircularList<T>* get_part_end(int amount) ;

    //ContainerInterface<T>* union_operation(ContainerInterface<T>* cont1) override;
};

/**
 * UNION OPERATION
 */
template <class T>
DLCircularList<T> operator + (DLCircularList<T> l1, DLCircularList<T> l2);

/**
 * INTERSECT OPERATION
 */
template <class T>
DLCircularList<T> operator * (DLCircularList<T> l1, DLCircularList<T> l2);

/**
 * EXCEPT OPERATION
 */
template <class T>
DLCircularList<T> operator - (DLCircularList<T> l1, DLCircularList<T> l2);

/**
 * SYMMETRIC EXCEPT OPERATION
 */
template <class T>
DLCircularList<T> operator % (DLCircularList<T> l1, DLCircularList<T> l2);


/**
* Function returns the current size of the list
*/
template<class T>
int DLCircularList<T>::get_curr_size() {
    return node_sum;
}

/**
* Returns the max int in the list
*
* @return the max int in the list
*/
template <class T>
int DLCircularList <T> :: get_max_int(){
    if (typeid(T).name() != typeid(int).name()){
        cout << "Sorry, your values are not integers"<< endl;    //if elements are not int
        return 0;
    }
    int a = head->data;                 //parcing all the list. The biggest int is saved in 'a'
    Node <T> *start = head->next;
    while (start != head){
        if (a < start->data)
            a = start->data;
        start = start->next;
    }
    return a;
}

template<class T>
std::string DLCircularList<T>::to_string(int index)
{
    T element = this->get_by_index(index);
    return std::to_string(element);
}

template<>
inline std::string DLCircularList<Server>::to_string(int index)
{
    Server element = this->get_by_index(index);
    return element.get_serverID();
}

template<>
inline std::string DLCircularList<Book>::to_string(int index)
{
    Book element = this->get_by_index(index);
    return element.get_bookName();
}

/**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
template <class T>
void DLCircularList <T> :: swap(Node <T> *a, Node <T> *b) {

    //cathing the possible error
    if(a == nullptr || b == nullptr){
        cout << "One of the nodes is empty. Nothing to swap." << endl;
        return;
    }

    T temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/**
* Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
*
* @param start The start of the linked list to sort
* @param finish The finish of the linked list to sort
* @return the Index of the end of the sorted part of the linked list
*/
template <class T>
Node <T>* DLCircularList <T> :: partition_quicksort(Node <T> *start, Node <T> *finish){

    T piv_data = finish->data;      //data that pivot contain
    Node <T>* temp = start->prev;   //pointer on the place to swap the values
    Node <T>* j;                    //iterator

    //partition part
    for (j = start; j !=finish; j = j->next) {
        if (j->data <= piv_data) {
            if (temp == finish)
                temp = start;
            else
                temp = temp->next;
            swap(temp, j);
        }
    }

    //swapping the pivot
    if (temp == finish)
        temp = start;
    else
        temp = temp->next;
    swap (temp, j);

    return temp;
}

/**
* Function that performs the quicksort algorithm
*
* @param start The start of the sublist to sort
* @param finish The end of the sublist to sort
*/
template <class T>
void DLCircularList <T> :: _quicksort(Node <T> *start, Node <T> *finish){

    if (finish != nullptr && start != finish){
        Node <T> *pivot = partition_quicksort(start, finish);   //finding the place to pivot
        if (pivot != start)
            _quicksort(start, pivot->prev);            //doing the same to the left part
        if (pivot != finish)
        _quicksort(pivot->next, finish);           //doing the same to the right part
    }
}

/**
* The function that divides the linked list in two linked lists
* The first linked list is saved in the **first, the second linked list is saved in the **second
*
* @param start The linked list to divide
* @param first The first part of the input linked list
* @param second The second part of the input linked list
*/
template <class T>
void DLCircularList <T> :: listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second){

    if(start->next == nullptr){
        cout << "wtd" << endl;
        return;
    }

    //Catching the possible error
    if (start == nullptr){
        cout<<"Unexpected error."<<endl;
        return;
    }

    Node <T> *fast, *slow; //used in fast/slow pointer method to divide list on 2 halves
    fast = start->next;
    slow = start;

    //the algorithm on dividing the list on two lists
    do {
        fast = fast->next;
        if (fast !=  this->head){
            slow = slow->next;
            fast = fast->next;
        }
    }while (fast != this->head);

    *first = start;
    *second = slow->next;
    slow->next = nullptr;
}

/**
* The function that merges two linked lists in one
*
* @param first The first linked list
* @param second The second linked list
* @return The merged linked list
*/
template <class T>
Node <T>* DLCircularList<T> :: merge(Node <T> *first, Node <T> *second){

    Node <T> *result;               //pointer on the result linked

    if (first == nullptr)              //basic cases
        return second;
    if (second == nullptr)
        return first;

    if (first->data <= second->data) {          //standard merge
        result = first;
        result->next = merge(first->next, second);
    }
    else {
        result = second;
        result->next = merge(first, second->next);
    }

    return (result);
}

/**
* Function that performs the mergesort algorithm
*
* @param source The pointer on the linked list that would be sorted
*/
template <class T>
void DLCircularList <T> :: _mergesort(Node <T> **source)
{
    Node <T> *start = *source;
    Node <T> *first;
    Node <T> *second;

    //Basic case
    if (start == nullptr || start->next == nullptr) {
        return;
    }

    //splits the source on 2 halves
    listsplit_mergesort(start, &first, &second);

    //recursive sort
    _mergesort(&first);
    _mergesort(&second);

    //merging the 2 halves
    *source = merge(first, second);
    head = *source;

    //updating the head and the tail
    Node <T> *temp;
    temp = head;
    if (temp == nullptr)
        return;
    while (temp->next != head){
        temp = temp->next;
    }
    tail = temp;
}

/**
* Utility function for countingsort that fills the input arrays with zeros.
*
* @param in The input array to fill
* @param length The length of this array
*/
template <class T>
void DLCircularList <T> :: fill_array_0(int in[], int length){
    for (int i = 0; i < length; i++){
        in[i] = 0;
    }
}

template<class T>
T DLCircularList<T>::get_by_index(int index)
{

    Node<T>* temp = this->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

/**
* Returns the pointer on the tail of the list
*
* @return the pointer on the tail of the list
*/
template <class T>
Node <T>* DLCircularList <T> :: get_tail(){
    return tail;
}

/**
 * Returns the pointer on the head of the list
 *
 * @return the pointer on the head of the list
 */
template <class T>
Node <T>* DLCircularList <T> :: get_head(){
    return head;
}

/**
* Function that adds the Node to the List
*
* @param val The value that would be added to the List
*/
template <class T>
void DLCircularList <T> :: add_node(T val){

    auto *new_node = new Node <T>;
    new_node->data = val;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == nullptr){
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
        tail->next = new_node;
        tail = tail->next;
    }

    node_sum ++;                    //updated the number of the nodes
}

/**
* Function that prints all the data from the list on the screen
*/
template <class T>
void DLCircularList <T> :: display(){
    int k = get_curr_size();
    Node<T> *temp = head;
    for (int i = 0;i < k; i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
* Function that shows the error message for all types of data that are not expected to use
*/
template <class T>
void DLCircularList <T> :: countingsort(int exp, int max_int) {
    cout << "You cannot use this sort for this type of data" << endl;
}

/**
* Function that performs the counting sort algorithm for the int type of data.
* Uses default arguments for simple countingsort.
* The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
* This sorting algorithm is valid only for the integers in [0,50)
*
* @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
*        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
* @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
*        value for a sorted integer
*/
template <>
inline void DLCircularList <int> :: countingsort(int exp, int max_int){

    //exp is used to radix algorithm. If u want to use this sort in default conditions
    //the value of exp and ten must be = 1 and 50 respectively (just don't touch it)

    //I use "49" as maximum possible value to the given integer


    Node <int>* start = head;
    int num = get_curr_size();
    if (num < 2){
        cout << "nothing to sort" << endl;                  //if number of elements are 0 or 1
        return;
    }

    if (get_max_int() > 49){
        cout << "this algorithm is valid only for integers that <50" << endl;
        return;
    }

    int index[max_int];
    fill_array_0(index,max_int);                    //creating index array

    int out[num];                                   //output array
    int temp;

    //creating the index array
    do{
        temp = (start->data / exp) % max_int;
        index[temp]++;                         //incrementing the index val of the current value
        start = start->next;
    }while (start != tail);

    //modifying the index array
    for (int i = 1; i < max_int; i++){
        index[i] = index[i] + index[i - 1];
    }

    //creating the output array using index array
    if (max_int == 10){
        start = tail;
        // for (int s = num - 1; s >= 0; s--){
        do {
            temp = start->data;
            out[index[(temp / exp) % max_int] - 1] = temp;
            index[(temp / exp) % max_int]--;
            start = start->prev;
        }while (start != head);
    } else {
        start = head;
        do {
            temp = start->data;
            out[index[(temp / exp) % max_int] - 1] = temp;
            index[(temp / exp) % max_int]--;
            start = start->next;
        }while (start != tail);
    }

    //rewriting the values in the linked list from the output array
    start = head;
    for(int k = 0; k < num; k++) {
        start->data = out[k];
        start = start->next;
    }
}

template<class T>
bool DLCircularList<T>::pop_node() {
    if(tail == nullptr)
        return false;
    Node<T>* temp = tail;
    if(tail->prev == nullptr){
        tail = nullptr;
        head = nullptr;
        delete  temp;
        node_sum --;
        return true;
    }
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    node_sum--;
    delete temp;
    return true;
}

/**
 * Deletes the element from the list
 * @param element to delete
 * @return true if success
 */
template<class T>
bool DLCircularList<T>::delete_node(T element) {
    Node<T>* temp = get_head();

    do {
        if(temp->data == element){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete(temp);
            return true;
        }
        temp = temp->next;
    }while(temp != tail);
    return false;
}

/**
* Function that performs the selection sort algorithm
*/
template <class T>
void DLCircularList <T> :: selection_sort() {

    Node <T> *curr = head;

    if (curr == nullptr || curr->next == nullptr){
        cout << "Nothing to sort" << endl;
        return;
    }

    Node <T> *iterator, *min;

    do {
        //save the smallest val in order to place it on the start of unsorted part of the array
        min = curr;
        iterator = curr->next;
        do {
            if(iterator->data <= min->data)
                min = iterator;
            iterator = iterator->next;
        }while(iterator != tail);
        swap(curr, min);
        curr = curr->next;
    }while(curr != tail);
}


/**
* Function that basically calls the _quicksort function that is in private section
*/
template <class T>
void DLCircularList <T> :: quicksort(){
    _quicksort(get_head(),get_tail());  //calls the function
}

/**
* Function that basically calls the _mergesort function that is in private section
*/
template <class T>
void DLCircularList <T> :: mergesort(){
    _mergesort(&head);          //calls the function
}

template<class T>
DLCircularList<T>::DLCircularList() {
    node_sum = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
T &DLCircularList<T>::operator[](int i) {
    Node<T>* temp = this->head;
    for(int j = 0; j < i; j++){
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
bool DLCircularList<T>::is_present(T element) {
    Node<T>* temp = get_head();
    {
        if(temp->data == element)
            return true;
        temp = temp->next;
    }while(temp != tail);
    return false;
}

template<class T>
DLCircularList<T>* DLCircularList<T>::get_part_end(int amount) {
    if(amount > this->get_curr_size() || amount <= 0)
        return nullptr;
    if(amount == this->get_curr_size())
        return this;
    else{
        auto* newList = new DLCircularList();
        Node<T>* temp = this-get_tail();
        for(int i = 0; i < amount; i++){
            newList->add_node(temp[i]);
            temp = temp->prev;
        }
        return newList;
    }
}

template<class T>
DLCircularList<T>* DLCircularList<T>::get_part_start(int amount) {
    if(amount > this->get_curr_size() || amount <= 0)
        return nullptr;
    if(amount == this->get_curr_size())
        return this;
    else{
        auto* newList = new DLCircularList();
        Node<T>* temp = this-get_head();
        for(int i = 0; i < amount; i++){
            newList->add_node(temp[i]);
            temp = temp->next;
        }
        return newList;
    }
}



template <class T>
DLCircularList<T> operator + (DLCircularList<T> l1, DLCircularList<T> l2){
    DLCircularList<T> outputList = l1;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(!outputList.is_present(l2[i])){
            outputList.add_node(l2[i]);
        }
    }
    return outputList;
}

template <class T>
DLCircularList<T> operator * (DLCircularList<T> l1, DLCircularList<T> l2){
    DLCircularList<T> outputList;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(l1.is_present(l2[i])){
            outputList.add_node(l2[i]);
        }
    }
    return outputList;
}

template <class T>
DLCircularList<T> operator - (DLCircularList<T> l1, DLCircularList<T> l2){
    DLCircularList<T> outputList = l1;
    for(int i = 0 ; i < l2.get_curr_size(); i++){
        if(!outputList.is_present(l2[i])){
            outputList.delete_node(l2[i]);
        }
    }
    return outputList;
}

template <class T>
DLCircularList<T> operator % (DLCircularList<T> l1, DLCircularList<T> l2) {
    DLCircularList <T> outputList = l1 + l2 - (l1 * l2);
    return outputList;
}


template<class T>
bool DLCircularList<T>::generate(int amount) {
    if(amount <= 0)
        return false;

    head = nullptr;
    tail = nullptr;
    node_sum = 0;

    Node<T> *temp = new Node<T>();

    for(int i = 0 ; i < amount; i++){
        temp->generate();
        add_node(temp->data);
    }
    return true;
}

template<class T>
T* DLCircularList<T>::get_Server_by_serverID(string serverID) {
    return nullptr;
}

template <>
inline Server* DLCircularList<Server>::get_Server_by_serverID(string serverID) {
    Node<Server>* iter = this->get_head();

    do {
        if(iter->data.get_serverID() == serverID)
            return &(iter->data);
        iter = iter->next;
    }while(iter != tail);
    return nullptr;
}

template<class T>
bool DLCircularList<T>::change_companyName_by_serverID(string serverID, string newCompanyName){
    return false;
}

template <>
inline bool DLCircularList<Server>::change_companyName_by_serverID(string serverID, string newCompanyName){
    Server* temp = get_Server_by_serverID(serverID);
    if(temp){
        temp->set_companyName(newCompanyName);
        return true;
    }
    return false;
}

template<class T>
bool DLCircularList<T>::add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) {
    return false;
}

template <>
inline bool DLCircularList<Server>::add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel){
    if(!get_Server_by_serverID(serverID)){
        Server newServer(name, dataCenter, rackModel, serverID);
        this->add_node(newServer);
        return true;
    }
    return false;
}

template<class T>
bool DLCircularList<T>::delete_Server_by_serverID(string serverID) {
    return false;
}

template<>
inline bool DLCircularList<Server>::delete_Server_by_serverID(string serverID) {
    Server* temp = get_Server_by_serverID(serverID);
    if(temp){
        return delete_node(*temp);
    }
    return false;
}

template<class T>
T *DLCircularList<T>::get_book_by_name(string name) {
    return nullptr;
}

template <>
inline Book *DLCircularList<Book>::get_book_by_name(string name) {
    Node<Book>* iter = this->get_head();

    do {
        if(iter->data.get_bookName() == name)
            return &(iter->data);
        iter = iter->next;
    }while(iter != tail);
    return nullptr;
}


template<class T>
bool DLCircularList<T>::change_genre_by_name(string name, string newGenre) {
    return false;
}

template <>
inline bool DLCircularList<Book>::change_genre_by_name(string name, string newGenre){
    Book* temp = get_book_by_name(name);
    if(temp){
        temp->set_genre(newGenre);
        return true;
    }
    return false;
}

template<class T>
bool DLCircularList<T>::add_book_by_name(string company, string author, int year, string genre, string name) {
    return false;
}

template <>
inline bool DLCircularList<Book>::add_book_by_name(string company, string author, int year, string genre, string name){
    if(!get_book_by_name(name)){
        Book newBook(company,  author,  year,  genre,  name);
        this->add_node(newBook);
        return true;
    }
    return false;
}

template<class T>
bool DLCircularList<T>::delete_book_by_name(string name) {
    return false;
}

template<>
inline bool DLCircularList<Book>::delete_book_by_name(string name) {
    Book* temp = get_book_by_name(name);
    if(temp){
        return delete_node(*temp);
    }
    return false;
}

template<class T>
void DLCircularList<T>::bucketsort() {
    std::vector<T> b[node_sum];

    Node<T> *temp = head;
    for (int i=0; i<node_sum; i++)
    {
        int index = node_sum * (temp->data);
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i=0; i<node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i=0; i<node_sum; i++)
        for (int j=0; j<b[i].size(); j++)
        {
            temp->data = b[i][j];
            temp = temp->next;
        }
}

template<>
inline void DLCircularList<Book>::bucketsort() {
    std::vector<Book> b[node_sum];

    Node<Book> *temp = head;
    for (int i=0; i<node_sum; i++)
    {
        int index = node_sum * temp->data.get_year();
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i=0; i<node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i=0; i<node_sum; i++)
        for (int j=0; j<b[i].size(); j++)
        {
            temp->data = b[i][j];
            temp = temp->next;
        }
}

template<>
inline void DLCircularList<Server>::bucketsort() {
    std::vector<Server> b[node_sum];

    Node<Server> *temp = head;
    for (int i = 0; i < node_sum; i++) {
        int index = node_sum * (temp->data.get_companyName()[0]);
        b[index].push_back(temp->data);
        temp = temp->next;
    }
    for (int i = 0; i < node_sum; i++)
        sort(b[i].begin(), b[i].end());
    temp = head;
    for (int i = 0; i < node_sum; i++)
        for (int j = 0; j < b[i].size(); j++) {
            temp->data = b[i][j];
            temp = temp->next;
        }
}


#endif //OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H
