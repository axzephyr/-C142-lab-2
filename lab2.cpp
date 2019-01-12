#include<iostream>
using namespace std;


//the class that defines every element of the list
class circle
{
    public:
    //the data storing variable
    int data;
    //the pointer for the next element in the list
    circle * next;
    //the constructor for the 'next' pointer to point toward NULL automatically after being created
    circle()
    {
        next=NULL;
    }

};


//creating the list itself; the class that contains functions for the list
//this class will contain member functions for all operations
 class listfun
 {
     public:
     //creating a head,tail and a temp for the list
     circle * head;
     circle * tail;
     circle * bleh;
     //the constructor for the head and tail to point towards NULL automatically
     listfun()
     {
         head=NULL;
         tail=NULL;
     }
     
     
     //the member function to insert elements and their value
     void elemadd(int value)
     {
         //storing the value in the temp
         bleh= new circle;
         bleh->data=value;
         //adding the element
         //for the first element
         if(head==NULL)
         {
             head=bleh;
         }
         //for the rest of the elements
         else
         {
             tail->next=bleh;
         }
         tail=bleh;

     }
     
     
     //the function to add the elements wherever you want
     void addwhere(int pos, int value, int i=1)
     {
         //create a temporary element and assign it a value
         bleh= new circle;
         //assign the value to the temporary element
         bleh->data=value;
         //create a circle that will take you to circle after which you want to add a circle
         circle * current= head;
         //run a loop to take you to the circle, while checking for the existence of the position
         circle * temp=head;
         int j=0;
         while(temp != tail)
         {
             j++;
             temp=temp->next;
         }
         j++;
         if(pos<j)
         {
            while(i<pos-1)
            {
             current=current->next;
             i++;
            }
            //link the temporary circle with the next element
            bleh->next=current->next;
            current->next=temp;
         }
         else
         {
             cout<<" list doesnt have that many elements "<<endl;
         }
     }
     
     
     //display the elements of the list
     void display()
     {
         //create a circle that will display the value and move on to the next element
         circle * current=head;
         //create a loop that will run the before mentioned circle through the list
         while(current != NULL)
         {
             cout<<current->data<<" --> ";
             current=current->next;
         }
         cout<<endl;
     }

     
     //the function for the deletion of the last element
     void lasttrasher()
     {
         //assign the tail to a temporary circle
         circle * hbleh=tail;
         //create a current element that will take you to the second last element
         circle * current=head;
         while(current->next != tail)
         {
             current=current->next;
         }
         //now make the pointer part of the current circle as null
         current->next=NULL;
         //assign the title of tail to the current element
         tail=current;
         delete hbleh;
     }
 };

 //the main function
 int main()
{
    //creating a list
    listfun a1;
    a1.elemadd(1);
    a1.elemadd(2);
    a1.elemadd(3);
    a1.elemadd(4);
    a1.display();
    a1.lasttrasher();
    a1.display();

    return 0;
}

