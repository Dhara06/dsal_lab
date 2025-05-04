#include <iostream>
#include <string>
using namespace std;


struct node{
    string name;
    int count;
    struct node *child[10];
}*root;

class book{
    public:
    book(){
        root = NULL;
    }

    void create(){
        root = new node;
        cout<<"Enter name of book: ";
        cin>>root->name;
        cout<<"\nEnter no. of chapters: ";
        cin>>root->count;
        for(int i = 0;i<root->count;i++){
            root->child[i] = new node;
            cout<<"\nEnter chapter "<<i+1<<" name: "; 
            cin>>root->child[i]->name;
            cout<<"\nEnter no. of sections: ";
            cin>>root->child[i]->count;
            for(int j =0 ; j<root->child[i]->count;j++){
                root->child[i]->child[j] = new node;
                cout<<"\nEnter section "<<j+1<<" name: ";
                cin>>root->child[i]->child[j]->name;
                cout<<"\nenter no. of subsections: ";
                cin>>root->child[i]->child[j]->count;
                for(int k =0 ;k<root->child[i]->child[j]->count;k++){
                    root->child[i]->child[j]->child[k] =new node;
                    cout<<"\nEnter subsection "<<k+1<<" name: ";
                    cin>>root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }

    void display(){
        cout<<"\nTREE STRUCTURE: ";
        cout<<root->name<<endl;
        for(int i = 0;i<root->count;i++){
            cout<<"\t"<<root->child[i]->name<<endl;
            for(int j =0;j<root->child[i]->count;j++){
                cout<<"\t\t"<<root->child[i]->child[j]->name<<endl;
                for(int k =0;k<root->child[i]->child[j]->count;k++){
                    cout<<"\t\t\t"<<root->child[i]->child[j]->child[k]->name<<endl;
                }
            }
        }
    }
};
int main(){
    book b;
    b.create();
    b.display();
    return 0;
}