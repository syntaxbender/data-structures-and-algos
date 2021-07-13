#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define SIZE 5 // Specifying the maximum limit of the queue
#define FIFO true
#define LIFO false
#define OVERWRITE true
#define DISCARD false

#define FULL_OPERATION DISCARD

void enque(uint8_t value, bool* is_success);
void deque(uint8_t* value, bool* is_success);
void display(void);
uint8_t count();
void display();

uint8_t buff[SIZE];
uint8_t tail = 0;
uint8_t head = 0;
bool is_full = false;

void enque(uint8_t value, bool* is_success){
    printf("----enque----\n");
    if(is_full == true){
        if(FULL_OPERATION != OVERWRITE){
           *is_success = false;
           printf("----buffer is full, discard mode----\n");
           return;
        } 
        head = ++head%SIZE;
        
    }
    buff[tail] = value;
    tail = ++tail%SIZE;
    if(tail == head) is_full=true;
    *is_success = true;
    display();
}
void deque(uint8_t* value, bool* is_success){
    printf("----deque----\n");
    *is_success = (tail == head && is_full == false) ? false : true;
    
    if(!*is_success){
        printf("----empty buffer----\n");
        return;
    }
    is_full=false;
    *value = buff[head];
    head = ++head%SIZE;
    /*if(tail-1<0){
        tail = SIZE-1;
    }else{
        tail--;
    }
    *value = buff[tail];*/ /* LIFO next release */
    display();
}
uint8_t count(){
    return abs(tail-head);
}
void display(){
    uint8_t temp_head = head;
    uint8_t temp_tail = tail;
    uint8_t temp_buff[SIZE];
    for(int i=0; i<SIZE; i++){
        temp_buff[i] = 0;
    }
    if(is_full || temp_head != temp_tail){
        while(1){
            printf("..%d..",temp_head);
            temp_buff[temp_head] = buff[temp_head];
            temp_head = ++temp_head%SIZE;
            //printf("th:%d, ",temp_head);
            if(temp_tail == temp_head) break;
        }
    }
    printf("\n");
    for(int i=0; i<SIZE; i++){
        printf("%d:%d, ",i,temp_buff[i]);
    }
    printf("\nis_full : %d",is_full);
    printf("\n\n\n");
}
uint8_t main(){
    bool is_success;
    uint8_t callback_value;
    enque(2,&is_success);
    enque(3,&is_success);
    enque(4,&is_success);
    enque(5,&is_success);
    enque(6,&is_success);
    enque(7,&is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    enque(8,&is_success);
    enque(9,&is_success);
    enque(10,&is_success);
    enque(11,&is_success);
    enque(12,&is_success);
    enque(13,&is_success);
    enque(14,&is_success);
    enque(15,&is_success);
    enque(16,&is_success);
    deque(&callback_value, &is_success);
    enque(17,&is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
    deque(&callback_value, &is_success);
}
