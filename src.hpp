//
// Created by wzj on 2021/12/3.
//

#ifndef FINAL_SRC_HPP
#define FINAL_SRC_HPP

#include <string>
#include <vector>
using namespace std;

class LinkedHashMap;
struct Node{
    Node* next=nullptr;
    Node* timePre=nullptr;
    Node* timeNext=nullptr;

    int key=0;
    string value;
};

struct Data{
    int key;
    string value;
};

vector<Data> traverseByTime(const LinkedHashMap& obj);
vector<Data> traverseByIndex(const LinkedHashMap& obj);

class LinkedHashMap{
// todo: Modify "beg", "current" and related parts in the constructor as you wish.
// todo: 你可以根据自己写链表的习惯修改或删除头尾节点并对应修改构造函数。
public:
    int len;
    Node** array;
    Node* beg;
    Node* current;
    // todo: define a function pointer called "forEachMethod"
    // to be pointed to function "traverseByTime" or "traverseByDict".
    // todo: 定义一个名为forEachMethod的函数指针，用于对应travelByTime和travelByDict函数。
    vector<Data> (*forEachMethod)(const LinkedHashMap&);

    LinkedHashMap(int _len_,bool forEachByTime){
        len=_len_;
        beg=new Node();
        current=beg;
        array=new Node*[len];
        for(int i=0;i<len;i++)
            array[i]=nullptr;
        if(forEachByTime)
            forEachMethod=traverseByTime;
        else
            forEachMethod=traverseByIndex;
    }

    ~LinkedHashMap(){
        //todo
        // Free all nodes in the doubly-linked list
        Node* curr = beg->timeNext;
        while(curr != nullptr) {
            Node* next = curr->timeNext;
            delete curr;
            curr = next;
        }
        // Free the dummy head node
        delete beg;
        // Free the array
        delete[] array;
    }

    void insert(int key,string value){
        //todo
        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;
        
        // Insert at the head of the single linked list at array[key]
        newNode->next = array[key];
        array[key] = newNode;
        
        // Insert at the tail of the doubly-linked list
        newNode->timePre = current;
        newNode->timeNext = nullptr;
        current->timeNext = newNode;
        current = newNode;
    }

    void remove(int key,string value){
        //todo
        // Find and remove from single linked list
        Node* prev = nullptr;
        Node* curr = array[key];
        Node* toDelete = nullptr;
        
        while(curr != nullptr) {
            if(curr->value == value) {
                toDelete = curr;
                if(prev == nullptr) {
                    array[key] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
        // If found, remove from doubly-linked list
        if(toDelete != nullptr) {
            if(toDelete->timePre != nullptr) {
                toDelete->timePre->timeNext = toDelete->timeNext;
            }
            if(toDelete->timeNext != nullptr) {
                toDelete->timeNext->timePre = toDelete->timePre;
            }
            // Update current pointer if we're deleting the last node
            if(toDelete == current) {
                current = toDelete->timePre;
            }
            delete toDelete;
        }
    }

    vector<string> ask(int key)const{
        //todo
        vector<string> result;
        Node* curr = array[key];
        while(curr != nullptr) {
            result.push_back(curr->value);
            curr = curr->next;
        }
        return result;
    }

    vector<Data> forEach()const{
        return forEachMethod(*this);
    }
};

vector<Data> traverseByTime(const LinkedHashMap& obj){
    //todo
    vector<Data> result;
    Node* curr = obj.beg->timeNext;
    while(curr != nullptr) {
        Data d;
        d.key = curr->key;
        d.value = curr->value;
        result.push_back(d);
        curr = curr->timeNext;
    }
    return result;
}

vector<Data> traverseByIndex(const LinkedHashMap& obj){
    //todo
    vector<Data> result;
    for(int i = 0; i < obj.len; i++) {
        Node* curr = obj.array[i];
        while(curr != nullptr) {
            Data d;
            d.key = curr->key;
            d.value = curr->value;
            result.push_back(d);
            curr = curr->next;
        }
    }
    return result;
}

#endif //FINAL_SRC_HPP
