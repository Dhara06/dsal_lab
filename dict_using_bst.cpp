#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct node{
    string word, meaning;
    node *left,*right;
    node(string key,string val){
        word = key;
        meaning = val;
        left = NULL;
        right = NULL;
    };
};
class bst{
    private:
    node* root;
    int height(node* root){
        int l,r;
        if(root == NULL){
            return 0;
        }
        l = height(root->left);
        r = height(root->right);
        return 1+max(l,r);
    }
    node* insertnode(node* root, string key, string meaning){
        if(root==NULL){
            return new node(key,meaning);
        }
        if(key<root->word){
            root->left=insertnode(root->left,key,meaning);
        }
        else if(key>root->word){
            root->right = insertnode(root->right,key,meaning);
        }
        return root;
    }
        
    node* dltnode(node* root,string key){
        if(root == NULL){
            return NULL;
        }
        if(key < root->word){
            root->left = dltnode(root->left, key);
        }
        else if(key > root->word){
            root->right = dltnode(root->right, key);
        }
        else{
            if(root->left == NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            
                node* temp =inordersuc(root->right);
                root->word = temp->word;
                root->meaning = temp->meaning;
                root->right = dltnode(root->right, temp->word);
        }
        return root;
    }
    node* inordersuc(node* root){
        node* curr = root;
        while(curr && curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    node* update(node* root, string key){
        
        if(root ==NULL){
            cout<<"\nKeyword not found.";
            return nullptr;
        }
        if(key<root->word){
            root->left = update(root->left,key);
        }
        else if(key>root->word){
            root->right =update(root->right,key);
        }
        else{
            cout<<"enter meaning: ";
            cin>>root->meaning;
            cout<<"\nupdated succesfully";
        }
        return root;
    }

    void inorder(node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->word<<": "<<root->meaning<<endl;
        inorder(root->right); 
    }
    void descendingorder(node* root){
        if(root== NULL){
            return;
        }
        descendingorder(root->right);
        cout<<root->word<<": "<<root->meaning<<endl;
        descendingorder(root->left);
    }
  
    public:
        bst(){
            root = NULL;
        }
       
        void insertindict(string key, string meaning){
            root = insertnode(root,key,meaning); 
        }
        void deletenode(string key){
            root = dltnode(root , key);
        }
        void displayascending(){
            inorder(root);
        }
        void displaydescending(){
            descendingorder(root);
        }
        void modify(string key){
            root = update(root, key);
        }
        void maxcomp(){
            cout<<"\nMax comparisons: "<<height(root)<<endl;
        }
};
int main(){
    bst obj;
    char ans;
    string key;
    string val;
    int choice;
    do{
    cout<<"Menu:"<<endl;
    cout<<"1.Insert node\n2.Delete node\n3.ascending display\n4. descending display\n5.update word\n6.max comparisons.\nEnter ur choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"\nenter word: ";
        cin>>key;
        cout<<"\nEnter meaning: ";
        cin>>val;
        obj.insertindict(key,val);
        break;

        case 2:
        cout<<"Enter node to del: ";
        cin>>key;
        obj.deletenode(key);
        break;

        case 3:
        cout<<"\nDictionary in acscending order: \n";
        obj.displayascending();
        break;
        case 4:
        cout<<"\nDictionary in descending order: \n";
        obj.displaydescending();
        break;
        case 5:
        cout<<"endlEnter word to update: ";
        cin>>key;
        obj.modify(key);
        break;
        case 6:
        obj.maxcomp();
        break;
        case 7:
        return 0;
        default:
        cout<<"Invalid choice.";
    }
    }while(true);
    return 0;
}