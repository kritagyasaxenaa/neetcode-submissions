   class LL{
    public:
        LL(int val, int k){
            valu=val;
            ke=k;
        }
        LL* next=nullptr;   // tells the next
        int ke;
        int valu=-1;
        LL* prev;   // tells the prev
};
class LRUCache {
public:
    LRUCache(int capacity) {
        c=capacity;
    }
    int c;
    int count=0;
    map<int,LL*>m;
    LL* head=nullptr;
    LL* last=nullptr;
    int get(int key) {
        if(m[key]==nullptr||m[key]->valu==-1){
            return -1;
        }
        LL* temp =m[key];
         if(temp==last){
            return m[key]->valu;
        }
        if(temp==head){
            head=temp->next;
            head->prev=nullptr;
            temp->next=nullptr;
            last->next=temp;
            temp->prev=last;
            last=temp;
            return m[key]->valu;
        }
        LL* pre=temp->prev;
        LL* ne=temp->next;
        pre->next=ne;
        ne->prev=pre;
        temp->prev=last;
        temp->next=nullptr;
        last->next=temp;
        last=temp;
        return m[key]->valu;

    }
    
    void put(int key, int value) {
        if(!head){
            // uninitialised ll
            head = new LL(value, key);
            head->prev=nullptr;
            m[key]=head;
            last=head;
            count++;
            return;
        }
        else{
            if(m[key]==nullptr||m[key]->valu==-1){
                // there is no value stored for this key:
                LL* temp= new LL(value,key);
                last->next=temp;
                temp->prev=last;
                last=last->next;
                m[key]=last;
                count++;
                if(count>c){
                    LL* temp1=head;
                    head=head->next;
                    int k=temp1->ke;
                    m[k]=nullptr;
                    head->prev=nullptr;
                    delete temp1;
                    count--;
                }
                return;
            }
            else{
                LL* temp=m[key];
                temp->valu=value;
                if(temp==last){
                    return;
                }
                if(temp==head){
                    head=temp->next;
                    head->prev=nullptr;
                    temp->next=nullptr;
                    last->next=temp;
                    temp->prev=last;
                    last=temp;
                    return;
                }
                LL* pre=temp->prev;
                LL* ne=temp->next;
                pre->next=ne;
                ne->prev=pre;
                temp->prev=last;
                temp->next=nullptr;
                last->next=temp;
                last=temp;
                return;
            }
        }
        return;
    }
};
