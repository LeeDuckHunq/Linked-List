#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu() {
    printf("\n=============================");
    printf("\n0. Exit!");
    printf("\n1. Xuat thong tin DSLK");
    printf("\n2. Them node (dau/cuoi/giua)");
    printf("\n3. Xoa node (dau/cuoi/giua)");
    printf("\n4. Sap xep tang/giam");
    printf("\n5. Xuat phan tu chan/le");
    printf("\n6. Xuat phan tu o vi tri chan/le");
    printf("\n7. Tim X trong DSLK");
    printf("\n8. Dem so phan tu cua DSLK");
    printf("\n9. Dem trong DSLK co bao nhieu X");
    printf("\n10. Tinh tong cac phan tu cua DSLK");
    printf("\n11. Dem so phan tu lon hon phan tu phia sau no");
    printf("\n12. Tim Min Max");
    printf("\n13. Tim Min Max so chan");
    printf("\n14. Tim Min Max so le");
    printf("\n15. Xoa phan tu Max/Min cua DSLK");
    printf("\n16. Them X vao DSLK sao cho X la phan tu cuc dai (lon hon cac ptu xung quanh)");
    printf("\n17. Kiem tra tang dan/ giam dan");
    printf("\n18. Kiem tra moi phan tu trong DSLK co chan/le khong");
    printf("\n19. Tim day con tang dan dai nhat trong DSLK");
    printf("\n20. Tao DSLK moi va luu tat ca cac so duong cua DSLK cu");
    printf("\n21. Them phan tu vao danh sach sao cho tang dan");
    printf("\n22. Xoa cac phan tu trung nhau trong danh sach, chi giu lai ptu dau tien");
    printf("\n23. Tron 2 DSLK co thu tu tang thang 1 DSLK cung co thu tu tang");
    printf("\n24. Chen 1 phan tu co khoa X vao vi tri bat ki trong DSLK");
}

void menu_them() {
    printf("\n==========THEM===========");
    printf("\n0. Exit!");
    printf("\n1. Them vao dau");
    printf("\n2. Them vao giua");
    printf("\n3. Them vao cuoi");
}

void menu_xoa() {
    printf("\n==========XOA===========");
    printf("\n0. Exit!");
    printf("\n1. Xoa dau");
    printf("\n2. Xoa giua");
    printf("\n3. Xoa cuoi");
}

void menu_sort() {
    printf("\n==========ACS/DESC===========");
    printf("\n0. Exit!");
    printf("\n1. Tang dan");
    printf("\n2. Giam dan");
}

void menu_even_odd() {
    printf("\n==========EVEN/ODD===========");
    printf("\n0. Exit!");
    printf("\n1. Chan");
    printf("\n2. Le");
}

typedef struct node {
    int data;
    struct node* link;
} node;

node* makeNode(int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->link = NULL;
    return newNode;
}

void xuat_thong_tin(node* head) {
    if (head == NULL) {
        printf("\nDSLK trong !");
        return;
    }
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->link;
    }
}

void them_dau(node** head, int x) {
    if (*head == NULL) {
        *head = makeNode(x);
        return;
    }
    node* newNode = makeNode(x);
    newNode->link = *head;
    *head = newNode;
}

int Size(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->link;
    }
    return count;
}

void them_cuoi(node** head, int x) {
    if (*head == NULL) {
        *head = makeNode(x);
        return;
    }
    node* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = makeNode(x);
}

void them_giua(node** head, int k, int x) {
    if (*head == NULL) {
        *head = makeNode(x);
        return;
    }
    int n = Size(*head);
    if (k == 1) {
        them_dau(head,x);
        return;
    }
    if (k == n) {
        them_cuoi(head,x);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < (k-1); i++) {
        temp = temp->link;
    }
    node* newNode = makeNode(x);
    newNode->link = temp->link;
    temp->link = newNode;
}

void xoa_dau(node** head) {
    if (*head == NULL) {
        printf("\nDSLK rong, khong the xoa");
        return;
    }
    node* toDel = *head;
    (*head) = (*head)->link;
    free(toDel);
}

void xoa_cuoi(node** head) {
    if (*head == NULL) {
        printf("\nDSLK rong, khong the xoa");
        return;
    }
    node* temp = *head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    node* toDel = temp->link;
    temp->link = NULL;
    free(toDel);
}

void xoa_giua(node** head, int k) {
    if (*head == NULL) {
        printf("\nDSLK rong, khong the xoa");
        return;
    }
    if (k == 1) {
        xoa_dau(head);
        return;
    }
    int n = Size(*head);
    if (k == n) {
        xoa_cuoi(head);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < (k-1); i++) {
        temp = temp->link;
    }
    node* toDel = temp->link;
    temp->link = toDel->link;
    free(toDel);
}

void tang_dan(node** head) {
    if (*head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    node* temp;
    for (node* q = *head; q->link != NULL; q = q->link) {
        for (node* p = q->link; p != NULL; p = p->link) {
            if (q->data > p->data) {
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
        }
    }
}

void giam_dan(node** head) {
    if (*head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    node* temp;
    for (node* q = *head; q->link != NULL; q = q->link) {
        for (node* p = q->link; p != NULL; p = p->link) {
            if (q->data < p->data) {
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
        }
    }
}

void xuat_chan(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    printf("\n");
    while (head != NULL) {
        if (head->data % 2 == 0) {
            printf("%d ",head->data);
        }
        head = head->link;
    }
}

void xuat_le(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    printf("\n");
    while (head != NULL) {
        if (head->data % 2 != 0) {
            printf("%d ",head->data);
        }
        head = head->link;
    }
}

void xuat_vitri(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int count = 0;
    printf("\nCac phan vi tri tu chan trong DSLK: ");
    node* temp = head;
    while (head != NULL) {
        count++;
        if (count % 2 == 0) {
            printf("%d ",head->data);
        }
        head = head->link;
    }
    printf("\nCac phan vi tri tu le trong DSLK: ");
    count = 0;
    head = temp;
    while (head != NULL) {
        count++;
        if (count % 2 != 0) {
            printf("%d ",head->data);
        }
        head = head->link;
    }
}

int check_X(node* head, int x) {
    while (head != NULL) {
        if (head->data == x) return 1;
        head = head->link;
    }
    return -1;
}

void tim_X(node* head, int x) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int n = Size(head);
    if (check_X(head,x) == -1) {
        printf("\nKhong ton tai X trong DSLK");
        return;
    }
    printf("\nX o cac vi tri: ");
    for (int i = 1; i <= n; i++) {
        if (head->data == x) {
            printf("%d ",i);
        }
        head = head->link;
    }
}

void count_X(node* head, int x) {
    int count = 0;
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (check_X(head,x) == -1) {
        printf("\nKhong ton tai X trong DSLK");
    }
    while (head != NULL) {
        if (head->data == x){
            count++;
        }
        head = head->link;
    }
    printf("\nTon tai %d X trong DSLK",count);
}

void tong_data(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int total = 0;
    while (head != NULL) {
        total += head->data;
        head = head->link;
    }
    printf("\nTong cac phan tu trong DSLK la: %d",total);
}

void dem_ptu_lon(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int count = 0;
    while (head != NULL) {
        if (head->link!= NULL && head->data > head->link->data){
            count++;
        }
        head = head->link;
    }
    printf("\nSo phan tu lon hon phan tu phia sau no: %d",count);
}

void tim_max_min(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int max = head->data;
    int min = max;
    while (head != NULL) {
        if (head-> data > max){
            max = head->data;
        }
        if (head-> data < min){
            min = head->data;
        }
        head = head->link;
    }
    printf("\nMax=%d\nMin=%d",max,min);
}

int even_check(node* head) {
    while (head != NULL) {
        if (head->data %2 == 0){
            return head->data;
        }
    }
    return -1;
}

int odd_check(node* head) {
    while (head != NULL) {
        if (head->data %2 != 0){
            return head->data;
        }
    }
    return 0;
}

void even_max(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (even_check(head) == -1) {
        printf("\nDSLK khong co so chan");
        return;
    }
    int max = even_check(head);
    int min = max;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        if (head->data < min) {
            min = head->data;
        }
        head = head->link;
    }
    printf("\nMax_even=%d\nMin_even=%d",max,min);
}

void xoa_max_min(node** head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int max = (*head)->data;
    int min = max;
    node* temp = *head;
    while (temp != NULL) {
        if (temp->data > max){
            max = temp->data;
        }
        if (temp->data < min){
            min = temp->data;
        }
        temp = temp->link;
    }
    temp = *head;
    int n = Size(*head);
    for (int i = 1; i <= n; i++) {
        if (temp->data == max) {
            xoa_giua(head,i);
            return;
        }
        temp = temp->link;
    }
}

void odd_max(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (odd_check(head) == 0) {
        printf("\nDSLK khong co so le");
        return;
    }
    int max = odd_check(head);
    int min = max;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        if (head->data < min) {
            min = head->data;
        }
        head = head->link;
    }
    printf("\nMax_odd=%d\nMin_odd=%d",max,min);
}

void them_max(node** head, int k) {
    if (*head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int n = Size(*head);
    int x;
    if (k == n) {
        node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        do{
            printf("\nNhap X: ");
            scanf("%d",&x);
        } while(x <= temp->data);
        them_cuoi(head,x);
        return;
    }
    if (k == 1) {
        do {
            printf("\nNhap X: ");
            scanf("%d",&x);
        } while(x <= (*head)->data);
        them_dau(head,x);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < (k-1); i++) {
        temp = temp->link;
    }
    do{
        printf("\nNhap X: ");
        scanf("%d",&x);
    } while(x <= temp->data || x <= temp->link->data);
    them_giua(head,k,x);
}

void check_asc(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    while (head->link != NULL) {
        if (head->data > head->link->data){
            printf("\nDSLK khong tang dan!");
            return;
        }
        head = head->link;
    }
    printf("\nDSLK tang dan!");
}

void check_all_even(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (odd_check(head) != 0) {
        printf("\nCo so le");
        return;
    }
    printf("\nToan la so chan");
}

void longest_arr(node* head) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    node* temp = head;
    int n = Size(head);
    int current_length = 1,max_length = 1;
    int end,i;
    for (i = 1; i < n; i++) {
        if (head->data <= head->link->data) {
            current_length++;
        }
        else {
            if (current_length > max_length) {
                max_length = current_length;
                end = i;
            }
            current_length = 1;
        }
        head = head->link;
    }
    if (current_length > max_length) {
        max_length = current_length;
        end = i;
    }

    //xuat
    head = temp;
    printf("\nDay con tang dan dai nhat la: \n");
    for (int i = 1; i <= n; i++) {
        if (i >= (end-max_length+1) && i <= end) {
            printf("%d ",head->data);
        }
        head = head->link;
    }
}

void positive_number(node* head, node** head1) {
    if (head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    while (head != NULL) {
        if (head->data >= 0) {
            them_cuoi(head1,head->data);
        }
        head = head->link;
    }
    xuat_thong_tin(*head1);
}

void add_tang_dan(node** head, int k, int x) {
    if (*head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (k == 1) {
        do {
            printf("\nNhap X: ");
            scanf("%d",&x);
        } while(x > (*head)->data);
        them_dau(head,x);
        return;
    }
    int n = Size(*head);
    if (k == n) {
        node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        do {
            printf("\nNhap X: ");
            scanf("%d",&x);
        } while(x < temp->data);
        them_cuoi(head,x);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < (k-1); i++) {
        temp = temp->link;
    }
    do {
        printf("\nNhap X: ");
        scanf("%d",&x);
    } while((x < temp->data) || (x > temp->link->data));
    them_giua(head,k,x);
}

void xoa_ptu_trung_nhau(node** head) {
    if (*head == NULL) {
        printf("\nDSLK rong");
        return;
    }
    int i = 0, k = 0;
    for (node* q = *head; q->link != NULL; q = q->link) {
        i++;
        k = i;
        node* p = q->link;
        for (; p != NULL; p = p->link) {
            k++;
            if (q->data == p->data) {
                xoa_giua(head,k);
                p = q->link;
            }
        }
    }
}

int check(node* head) {
    while (head->link != NULL) {
        if (head->data > head->link->data) {
            return -1;
        }
        head = head->link;
    }
    return 1;
}

void mix_asc(node** head, node** head1) {
    if ((*head) == NULL || (*head1) == NULL) {
        printf("\nDSLK rong");
        return;
    }
    if (check(*head) == -1 || check(*head1) == -1) {
        printf("\nDSLK khong tang dan");
        return;
    }
    node* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = (*head1);
    tang_dan(head);
}

int main() {
    node* head = NULL;
    node* head1 = NULL;
    int choose;
    do {
       menu();
       printf("\nNhap: ");
       scanf("%d",&choose);
       switch (choose) {
        case 1:
            {
                xuat_thong_tin(head);
                break;
            }
        case 2:
            {
                int choice;
                do {
                    menu_them();
                    printf("\nNhap: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            {
                                int n,x;
                                printf("\nThem bao nhieu? ");
                                scanf("%d",&n);
                                for (int i = 0; i < n; i++) {
                                    scanf("%d",&x);
                                    them_dau(&head,x);
                                }
                                printf("\nThem thanh cong!");
                                break;
                            }
                        case 2:
                            {
                                int k,x;
                                printf("\nVi tri muon them: ");
                                scanf("%d",&k);
                                printf("\nData: ");
                                scanf("%d",&x);
                                them_giua(&head,k,x);
                                printf("\nThem thanh cong!");
                                break;
                            }
                        case 3:
                            {
                                int n,x;
                                printf("\nThem bao nhieu? ");
                                scanf("%d",&n);
                                for (int i = 0; i < n; i++) {
                                    x = rand() % 10;
                                    them_cuoi(&head,x);
                                }
                                printf("\nThem thanh cong!");
                                break;
                            }
                    }
                } while(choice != 0);
                break;
            }
        case 3:
            {
                int choice;
                do {
                    menu_xoa();
                    printf("\nNhap: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            {
                                xoa_dau(&head);
                                printf("\nXoa thanh cong!");
                                break;
                            }
                        case 2:
                            {
                                int k;
                                printf("\nVi tri muon xoa: ");
                                scanf("%d",&k);
                                xoa_giua(&head,k);
                                printf("\nXoa thanh cong!");
                                break;
                            }
                        case 3:
                            {
                                xoa_cuoi(&head);
                                printf("\nXoa thanh cong!");
                                break;
                            }
                    }
                } while(choice != 0);
                break;
            }
        case 4:
            {
                int choice;
                do {
                    menu_sort();
                    printf("\nNhap: ");
                    scanf("%d",&choice);
                    switch(choice) {
                        case 1:
                            {
                                tang_dan(&head);
                                printf("\nSap xep thanh cong");
                                break;
                            }
                        case 2:
                            {
                                giam_dan(&head);
                                printf("\nSap xep thanh cong");
                                break;
                            }
                    }
                } while(choice != NULL);
                break;
            }
        case 5:
            {
                int choice;
                do {
                    menu_even_odd();
                    printf("\nNhap: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            {
                                xuat_chan(head);
                                break;
                            }
                        case 2:
                            {
                                xuat_le(head);
                                break;
                            }
                    }
                } while(choice != 0);
                break;
            }
        case 6:
            {
                xuat_vitri(head);
                break;
            }
        case 7:
            {
                int x;
                printf("\nNhap X: ");
                scanf("%d",&x);
                tim_X(head,x);
                break;
            }
        case 8:
            {
                printf("\nSo phan tu cua DSLK la: %d",Size(head));
                break;
            }
        case 9:
            {
                int x;
                printf("\nNhap X: ");
                scanf("%d",&x);
                count_X(head,x);
                break;
            }
        case 10:
            {
                tong_data(head);
                break;
            }
        case 11:
            {
                dem_ptu_lon(head);
                break;
            }
        case 12:
            {
                tim_max_min(head);
                break;
            }
        case 13:
            {
                even_max(head);
                break;
            }
        case 14:
            {
                odd_max(head);
                break;
            }
        case 15:
            {
                xoa_max_min(&head);
                break;
            }
        case 16:
            {
                int k;
                printf("\nNhap vi tri: ");
                scanf("%d",&k);
                them_max(&head,k);
                break;
            }
        case 17:
            {
                check_asc(head);
                break;
            }
        case 18:
            {
                check_all_even(head);
                break;
            }
        case 19:
            {
                longest_arr(head);
                break;
            }
        case 20:
            {
                node* head1 = NULL;
                positive_number(head,&head1);
                break;
            }
        case 21:
            {
                int k,x;
                printf("\nMhap vi tri: ");
                scanf("%d",&k);
                add_tang_dan(&head,k,x);
                break;
            }
        case 22:
            {
                xoa_ptu_trung_nhau(&head);
                break;
            }
        case 23:
            {
                int n,x;
                printf("\nThem bao nhieu? ");
                scanf("%d",&n);
                for (int i = 0; i < n; i++) {
                    x = rand() % 10;
                    them_cuoi(&head1,x);
                }
                tang_dan(&head1);
                printf("\nThem thanh cong!");
                xuat_thong_tin(head1);
                mix_asc(&head,&head1);
                break;
            }
       }
    } while(choose != 0);
    return 0;
}
