void insertionSort(List *head) {
    NodePtr sortedList = NULL;              //create a new ll that stores the sorted list
    NodePtr current = *head;                //create a nodeptr that points to the original list
    while (current != NULL) {               //while the original list basically is not empty && while 
        NodePtr next = current->link;       //pass original link pointer in to a new list
        sortedInsert(&sortedList, current); //enter insertion sort
        current = next;                     //current now points to the ll 
    }
    *head = sortedList;                     // 
}

void sortedInsert(NodePtr *headRef, NodePtr newNode) {

    NodePtr current;

    if (*headRef == NULL || (*headRef)->person.idNum >= newNode->person.idNum) {
        newNode->link = *headRef;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->link != NULL && current->link->person.idNum < newNode->person.idNum) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }

}






