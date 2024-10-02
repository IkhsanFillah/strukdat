#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node* next;
};
    
node *kepala, *NB, *bantu, *hapuslist;
int jmlnode = 0;

void buatlist();
bool listkosong();
void sisipnode(int IB);
void hapusnode(int IH);
void bacamaju();

int main(){
    cout << "LINKED LIST MELINGKAR" << endl;
    buatlist();
    sisipnode(10);
    sisipnode(15);
    sisipnode(5);
    sisipnode(20);
    cout << "List Awal          :";
    bacamaju();
    cout << endl;
    hapusnode(15);
    cout << "Hapus Node 20\n";
    cout << "List Setelah Hapus :";
    bacamaju();
    cout << endl;
}
    
void buatlist(){ 
    kepala = new node();
    kepala->info = 0;
    kepala->next = kepala;
}

bool listkosong(){ 
    if(kepala->next == kepala)
        return(true);
    else
        return(false); 
}

void sisipnode(int IB){ 
    NB = new node();
    NB->info = IB;
    NB->next = NULL;

    if(listkosong()){
        NB->next = kepala;
        kepala->next = NB;
        jmlnode++;
        kepala->info = jmlnode; 
    } else { 
        bantu = kepala;
        while(bantu->next->info < IB && bantu->next != kepala)
            bantu = bantu->next;

        if(bantu->next != kepala){ 
            NB->next = bantu->next;
            bantu->next = NB;
        } else { 
            NB->next = kepala;
            bantu->next = NB; 
        }
    }
 	jmlnode++;
	kepala->info = jmlnode;
}

void hapusnode(int IH){ 
    if(listkosong()){
        cout << "List Masih Kosong" << endl;
    } else { 
        bantu = kepala;
        while(bantu->next->info != IH && bantu->next != kepala)
            bantu=bantu->next;

        if(bantu->next != kepala){ 
            hapuslist = bantu->next;
            bantu->next = hapuslist->next;
            free(hapuslist);
        } else { 
            hapuslist = bantu->next;
            bantu->next = kepala;
            free(hapuslist);
        }
    jmlnode--;
    kepala->info = jmlnode;
	}
}

void bacamaju(){
	bantu = kepala->next;
	while(bantu != kepala){
        cout << " " << bantu->info;
		bantu = bantu->next;
	}
}