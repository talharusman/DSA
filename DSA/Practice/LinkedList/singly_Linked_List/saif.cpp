void InsetrtAt_BeforeGivenPos(int New_value,int value){
    	Node* new_node = new Node(New_value);
        if(!head){
            head = new_node;
            return;
        }
        
        Node* temp = head;
        bool flage = false
        while(temp->next != NULL){
        	if(temp->next->next->value == value){
        		flage = true;
        		break;
			}else temp = temp->next;
        		
		}
		if(flage){
			New_Node->next= temp->next->next;
			temp->next=new_Node;
		}else cout<<"Error! this value is not exist"<<endl;
	}
