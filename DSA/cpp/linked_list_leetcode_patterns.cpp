#include <iostream>
#include <vector>

// Example program
struct ListNode{
    int val;
    ListNode* nextptr;
    
    ListNode(): val(0), nextptr(nullptr){
        
    }
    
    ListNode(int x): val(x), nextptr(nullptr){
        
    }
    
    ListNode(int x, ListNode* node): val(x), nextptr(node){
        
    }
    
};

void printList(ListNode* start);

ListNode* reversalList(ListNode* start){
    ListNode* curr = start;
    ListNode* prev = nullptr;
    
    while(curr!= nullptr){
         ListNode* next = curr->nextptr;
         curr->nextptr = prev;
         prev = curr;
         curr = next;
    }
       
    return prev;
    
}

bool isPalindrome(ListNode* start){
     ListNode* slow = start;
     ListNode* fast = start;
     
     while(fast!=nullptr && fast->nextptr!=nullptr){
         slow = slow->nextptr;
         fast = fast->nextptr->nextptr;
     }
     
     
     ListNode* start_reversed = reversalList(slow);
     while(start!= nullptr && start_reversed!=nullptr){
            if(start->val != start_reversed->val){
                return false;
            }
            start =start->nextptr;
            start_reversed =start_reversed->nextptr;
        }
        
     
     return true;
     
}

    ListNode* removeElements(ListNode* start, int target) {
        ListNode* curr = start;
        ListNode* prev = nullptr;
        
        while(start!=nullptr){
            
            if(start->val == target){

                if(prev != nullptr)
                    prev->nextptr = start->nextptr;
                else
                    curr =curr->nextptr;
                start = start->nextptr;
            }
            else{
                prev = start;
                start = start->nextptr;
            }
        }
        return curr;
    }
    
    ListNode* deleteDuplicates(ListNode* start) {
        ListNode* curr = start;
        ListNode* prev = nullptr;
        
        while(start!=nullptr){
            if( (prev!=nullptr) && (prev->val == start->val) ){
                while(prev->val==start->val)
                    start=start->nextptr;
                prev->nextptr=start;
            }
            else{
                prev = start;
                start = start->nextptr;
            }
        }
        return curr;
    }

ListNode* setList(std::vector<int>& list_array){
    ListNode* start = new ListNode(list_array[0]);
    ListNode* curr = start;
    
    for(size_t i = 1; i<list_array.size(); i++){
        ListNode* element = new ListNode(list_array[i]);
        curr->nextptr= element;
        curr = curr->nextptr;
    }
    return start;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode* merge_list = new ListNode();
    
    ListNode* curr = merge_list;
    
    while(list1!=nullptr && list2!=nullptr){
        
        if(list1->val>list2->val){
            ListNode* ele = new ListNode(list2->val);
            curr->nextptr = ele;
            curr=curr->nextptr;
            list2 = list2->nextptr;
        }
        
        else{
            ListNode* ele = new ListNode(list1->val);
            curr->nextptr = ele;
            curr=curr->nextptr;
            list1 = list1->nextptr;
        }
    }
    
    while(list1!=nullptr){
        ListNode* ele = new ListNode(list1->val);
        curr->nextptr = ele;
        curr=curr->nextptr;
        list1 = list1->nextptr;
    }
    
    while(list2!=nullptr){
        ListNode* ele = new ListNode(list2->val);
        curr->nextptr = ele;
        curr=curr->nextptr;
        list2 = list2->nextptr;
    }
    
    return merge_list->nextptr;
    
}

void printList(ListNode* start){
    while(start!=nullptr){
        
        std::cout<<start->val<<"\n";
        start=start->nextptr;
    }
}

int main(){
    
    std::vector<int> v1 = {1,2,2,2,3,4,10};
    
    std::vector<int> v2 = {1,2,3,4,6,7,8};

    ListNode* list1 = setList(v1);
    ListNode* list2 = setList(v2);

    
    printList(mergeTwoLists(list1,list2));
    
    return 0;
}
