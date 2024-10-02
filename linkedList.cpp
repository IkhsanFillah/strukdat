#include <iostream>

struct node
{
    int info;
    node *next;
};

node *awal, *akhir, *listbaru, *bantu, *hapus;

void buatlist()
{
    awal = NULL;
    akhir = NULL;
}

void sisipdepan(int IB)
{
    listbaru = new node();
    listbaru->info = IB;
    listbaru->next = NULL;

    if (awal = NULL)
    {
        awal = listbaru;
        akhir = listbaru;
    }
    else
    {
        listbaru->next = awal;
        awal = listbaru;
    }
}
void sisiptengah(int IB)
{
    listbaru = new node();
    listbaru->info = IB;
    listbaru->next = NULL;

    bantu = awal;
    while (bantu->next->info < IB)
    {
        bantu = bantu->next;
    }

    listbaru->next = bantu->next;
    bantu->next = listbaru;
}
void sisipbelakang(int IB)
{
    listbaru = new node();
    listbaru->info = IB;
    listbaru->next = NULL;

    if (akhir = NULL)
    {
        awal = listbaru;
        akhir = listbaru;
    }
    else
    {
        akhir->next = listbaru;
        akhir = listbaru;
    }
}
void hapuslist(int IH)
{
    bantu = awal;
    if (bantu->info == IH)
    {
        awal = bantu->next;
        free(bantu);
    }
    else
    {
        while (bantu->next->info != IH && bantu->next != NULL)
        {
            bantu = bantu->next;
        }
        if (bantu->next->info == IH)
        {
            hapus = bantu->next;
            bantu->next = bantu->next->next;
            free(hapus);
        }
        else
            printf("data %d tidak ditemukan\n", IH);
    }
}
void cetaklist()
{
    bantu = awal;
    while (bantu != NULL)
    {
        printf("%d ", bantu->info);
        bantu = bantu->next;
    }
    printf("\n");
}

int main()
{
    buatlist();
    printf("isi list setelah sisip depan: ");
    cetaklist();
    sisipbelakang(30);
    sisipbelakang(40);
    printf("isi list setelah sisip belakang: ");
    cetaklist();
    sisiptengah(25);
    printf("isi list setelah sisip tengah: ");
    cetaklist();
    hapuslist(20);
    printf("isi list setelah hapus: ");
    cetaklist();
}